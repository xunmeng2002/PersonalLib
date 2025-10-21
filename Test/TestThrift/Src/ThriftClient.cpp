#include "ThriftClient.h"
#include "Logger.h"
#include "Utility.h"
#include "TimeUtility.h"
#include "Platform.h"
#include "TcpBase.h"
#include "MD5.h"
#include "Decode.h"
#include "Buffer.h"



using namespace std;
using namespace std::chrono;
using namespace apache::thrift;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;


ThriftClient::ThriftClient(IOBase* io)
    :m_IO(io), m_UserID("kaiqiang.zhang"), m_Password("123456"), m_LoginSessionID(0LL)
{
    m_IO->Subscribe(this);
}
ThriftClient::~ThriftClient()
{
    m_IO->UnSubscribe();
}
void ThriftClient::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
    WriteLog(LogLevel::Info, "ThriftClient::OnConnect SessionID:[%lld], IP:[%s], Port:[%d]", sessionID, ip, port);
    auto key = string(ip) + to_string(port);
    if (m_AddressServices.find(key) != m_AddressServices.end())
    {
        auto& groceryInfo = m_AddressServices[key];
        m_SessionServices.insert(make_pair(sessionID, groceryInfo));
        m_SessionDecoders.insert(make_pair(sessionID, new TopicDecoder(sessionID)));
        QryUnit(sessionID, groceryInfo.hostname);
    }
    else
    {
        m_LoginSessionID = sessionID;
        ReqLogin();
    }
}
void ThriftClient::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
    WriteLog(LogLevel::Info, "ThriftClient::OnDisConnect SessionID:[%lld], IP:[%s], Port:[%d]", sessionID, ip, port);
}
void ThriftClient::OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
    WriteLog(LogLevel::Info, "ThriftClient::OnRecv SessionID:[%lld], Length:[%d]", sessionID, buffer->GetLength());
    auto buff = buffer->GetData();
    auto len = buffer->GetLength();
    if (m_Buffer.GetLength() != 0)
    {
        m_Buffer.Append(buffer->GetData(), buffer->GetLength());
        buff = m_Buffer.GetData();
        len = m_Buffer.GetLength();
    }
    auto remainLen = len;
    while (remainLen > sizeof(OpMsgHeader))
    {
        OpMsgHeader* head = (OpMsgHeader*)(buff);
        auto msgLen = sizeof(OpMsgHeader) + head->bodyLen;
        WriteLog(LogLevel::Info, "MsgType:%d, MsgLen:%d, RemainLen:%d, ", head->type, msgLen, remainLen);
        if (remainLen < msgLen)
        {
            WriteLog(LogLevel::Info, "RemainLen Less Than MsgLen");
            break;
        }
        if (head->type == g_login_constants.WMESSAGE_LOGIN_LOGIN)
        {
            LoginResponse rsp;
            OpDecoder::decode((const char*)buff + sizeof(OpMsgHeader), head->bodyLen, rsp);
            OnRspLogin(sessionID, rsp);
        }
        else if (head->type == g_unit_constants.WMESSAGE_MONITOR_UNIT_LIST)
        {
            ListUnitsResponse rsp;
            OpDecoder::decode((const char*)buff + sizeof(OpMsgHeader), head->bodyLen, rsp);
            OnRspQryUnit(sessionID, rsp);
        }
        else if (head->type == g_instrument_constants.WMESSAGE_MONITOR_LIST_UNIT_INSTRUMENT)
        {
            ListUnitInstrumentResponse rsp;
            OpDecoder::decode((const char*)buff + sizeof(OpMsgHeader), head->bodyLen, rsp);
            OnRspQryInstrument(sessionID, rsp);
        }
        else if (head->type == g_account_constants.WMESSAGE_MONITOR_LIST_ACCOUNT)
        {
            ListAccountResponse rsp;
            OpDecoder::decode((const char*)buff + sizeof(OpMsgHeader), head->bodyLen, rsp);
            OnRspQryAccount(sessionID, rsp);
        }
        else if (head->type == g_strategy_constants.WMESSAGE_MONITOR_LIST_STRATEGY)
        {
            ListStrategyResponse rsp;
            OpDecoder::decode((const char*)buff + sizeof(OpMsgHeader), head->bodyLen, rsp);
            OnRspQryStrategy(sessionID, rsp);
        }
        else if (head->type == g_topic_constants.WMESSAGE_TOPIC_SUBSCRIBE_UNIT)
        {
            SubscribeUnitResponse rsp;
            OpDecoder::decode((const char*)buff + sizeof(OpMsgHeader), head->bodyLen, rsp);
            OnRspQryAndSubscribeUnitTopic(sessionID, rsp);
        }
        else if (head->type == g_topic_constants.WMESSAGE_TOPIC_NOTIFY)
        {
            TopicNotify rsp;
            auto topicDecoder = m_SessionDecoders[sessionID];
            auto memBuffer = std::make_shared<TMemoryBuffer>((uint8_t*)(buff + sizeof(OpMsgHeader)), head->bodyLen);
            auto zlibTransport = std::make_shared<TZlibTransport>(memBuffer);
            auto compactProto = std::make_shared<TCompactProtocol>(zlibTransport);
            rsp.read(compactProto.get());

            OnRtnTopicNofity(sessionID, rsp, compactProto);
        }
        else
        {
            printf("Unexpected Msg. Type:%d, peerAddress:%d, bodyLen:%d\n", head->type, head->peerAddress, head->type);
        }
        buff += msgLen;
        remainLen -= msgLen;
    }
    if (m_Buffer.GetLength() > 0)
    {
        if (remainLen == 0)
        {
            m_Buffer.Reset();
        }
        else
        {
            m_Buffer.Shift(len - remainLen);
            m_Buffer.MemMove();
        }
    }
    else
    {
        if (remainLen > 0)
        {
            buffer->Shift(len - remainLen);
            m_Buffer.Append(buffer->GetData(), buffer->GetLength());
        }
    }
}
void ThriftClient::ReqLogin()
{
    LoginRequest req;
    req.name = "kaiqiang.zhang";
    req.password = getMD5((const unsigned char*)"123456", 6);
    auto msg = OpEncoder::encode(g_login_constants.WMESSAGE_LOGIN_LOGIN, 0, req);
    Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
    sendBuff->Append(msg.c_str(), msg.length());
    m_IO->Send(m_LoginSessionID, sendBuff);
    WriteLog(LogLevel::Info, "ReqLogin: MsgLen:%d", msg.length());
}
void ThriftClient::QryUnit(const SessionIDType& sessionID, const std::string& hostname)
{
    ListUnitsRequest req;
    req.hostname = hostname;
    auto msg = OpEncoder::encode(g_unit_constants.WMESSAGE_MONITOR_UNIT_LIST, 0, req);
    Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
    sendBuff->Append(msg.c_str(), msg.length());
    m_IO->Send(sessionID, sendBuff);
    WriteLog(LogLevel::Info, "QryUnit: MsgLen:%d", msg.length());
}
void ThriftClient::QryInstrument(const SessionIDType& sessionID, const std::string& unitname)
{
    ListUnitInstrumentRequest req;
    req.unitName = unitname;
    auto msg = OpEncoder::encode(g_instrument_constants.WMESSAGE_MONITOR_LIST_UNIT_INSTRUMENT, 0, req);
    Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
    sendBuff->Append(msg.c_str(), msg.length());
    m_IO->Send(sessionID, sendBuff);
    WriteLog(LogLevel::Info, "QryInstrument: MsgLen:%d", msg.length());
}
void ThriftClient::QryAccount(const SessionIDType& sessionID, const std::string& unitname)
{
    ListAccountRequest req;
    req.unitName = unitname;
    auto msg = OpEncoder::encode(g_account_constants.WMESSAGE_MONITOR_LIST_ACCOUNT, 0, req);
    Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
    sendBuff->Append(msg.c_str(), msg.length());
    m_IO->Send(sessionID, sendBuff);
    WriteLog(LogLevel::Info, "QryAccount: MsgLen:%d", msg.length());
}
void ThriftClient::QryStrategy(const SessionIDType& sessionID, const std::string& unitname)
{
    ListStrategyRequest req;
    req.unitName = unitname;
    auto msg = OpEncoder::encode(g_strategy_constants.WMESSAGE_MONITOR_LIST_STRATEGY, 0, req);
    Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
    sendBuff->Append(msg.c_str(), msg.length());
    m_IO->Send(sessionID, sendBuff);
    WriteLog(LogLevel::Info, "QryStrategy: MsgLen:%d", msg.length());
}
void ThriftClient::QryAndSubscribeUnitTopic(const SessionIDType& sessionID, const std::string& unitname)
{
    SubscribeUnitRequest req;
    req.unitName = unitname;
    auto msg = OpEncoder::encode(g_topic_constants.WMESSAGE_TOPIC_SUBSCRIBE_UNIT, 0, req);
    Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
    sendBuff->Append(msg.c_str(), msg.length());
    m_IO->Send(sessionID, sendBuff);
    WriteLog(LogLevel::Info, "QryAndSubscribeUnitTopic: MsgLen:%d", msg.length());
}

void ThriftClient::OnRspLogin(const SessionIDType& sessionID, const LoginResponse& rsp)
{
    WriteLog(LogLevel::Info, "OnRspLogin Status:%d, Detail:%s, ExpireAt:%lld, GroceriesSize:%d", rsp.status, rsp.detail.c_str(), rsp.expireAt, rsp.groceries.size());
    for (auto& groceryInfo : rsp.groceries)
    {
        WriteLog(LogLevel::Info, "GroceryInfo HostName:%s, IP:%s, Port:%d, Token:%s", groceryInfo.hostname.c_str(), groceryInfo.ip.c_str(), groceryInfo.port, groceryInfo.token.c_str());
        
        m_AddressServices.insert(make_pair(groceryInfo.ip + to_string(groceryInfo.port), groceryInfo));
        ((TcpBase*)m_IO)->ConnectToServer(groceryInfo.ip.c_str(), groceryInfo.port);
    }
}
void ThriftClient::OnRspQryUnit(const SessionIDType& sessionID, const ListUnitsResponse& rsp)
{
    WriteLog(LogLevel::Info, "OnRspQryUnit Status:%d, Detail:%s, HostName:%s, GroceriesSize:%d", rsp.status, rsp.detail.c_str(), rsp.hostname.c_str(), rsp.units.size());
    for (auto& unitInfo : rsp.units)
    {
        WriteLog(LogLevel::Info, "ListUnitsResponse Name:%s, Type:%s", unitInfo.name.c_str(), unitInfo.type.c_str());
        QryInstrument(sessionID, unitInfo.name);
        if (unitInfo.type == "account")
        {
            QryAccount(sessionID, unitInfo.name);
        }
        else if (unitInfo.type == "strategy")
        {
            QryStrategy(sessionID, unitInfo.name);
        }
    }
}
void ThriftClient::OnRspQryInstrument(const SessionIDType& sessionID, const ListUnitInstrumentResponse& rsp)
{
    WriteLog(LogLevel::Info, "OnRspQryInstrument Status:%d, Detail:%s, InstrumentSize:%d", rsp.status, rsp.detail.c_str(), rsp.instruments.size());
    for (auto& it : rsp.instruments)
    {
        WriteLog(LogLevel::Info, "InstrumentInfo Name:%s, Type:%s, Underlying:%s, Multiplier:%f, Strike:%f, TickSize:%f, Expiration:%lld",
            it.name.c_str(), it.type.c_str(), it.underlying.c_str(), it.multiplier, it.strike, it.tickSize, it.expiration);
    }
}
void ThriftClient::OnRspQryAccount(const SessionIDType& sessionID, const ListAccountResponse& rsp)
{
    WriteLog(LogLevel::Info, "OnRspQryAccount Status:%d, Detail:%s, UnitName:%s, TopicsSize:%d, AccountsSize:%d", rsp.status, rsp.detail.c_str(), rsp.unitName.c_str(), rsp.topics.size(), rsp.accounts.size());
    for (auto& it : rsp.topics)
    {
        WriteLog(LogLevel::Info, "Topic Name:%s, ID:%d", it.first.c_str(), it.second);
    }
    for (auto& accountInfo : rsp.accounts)
    {
        WriteLog(LogLevel::Info, "AccountInfo TradeFundName:%s, Exchange:%s, AccountName:%s", accountInfo.tradeFundName.c_str(), accountInfo.exchange.c_str(), accountInfo.accountName.c_str());
    }
    //QryLiveParam(socket, rsp.unitName);
    QryAndSubscribeUnitTopic(sessionID, rsp.unitName);
}
void ThriftClient::OnRspQryStrategy(const SessionIDType& sessionID, const ListStrategyResponse& rsp)
{
    WriteLog(LogLevel::Info, "OnRspQryStrategy Status:%d, Detail:%s, UnitName:%s, StrategySize:%d, AccountsSize:%d", rsp.status, rsp.detail.c_str(), rsp.unitName.c_str(), rsp.strategies.size(), rsp.accounts.size());

    for (auto& account : rsp.accounts)
    {
        WriteLog(LogLevel::Info, "StrategyUnit Account:%s", account.c_str());
    }
    for (auto& strategyInfo : rsp.strategies)
    {
        WriteLog(LogLevel::Info, "StrategyInfo Name:%s", strategyInfo.name.c_str());
        for (auto& it : strategyInfo.attributes)
        {
            WriteLog(LogLevel::Info, "Attributes Key:%s, Value:%s", it.first.c_str(), it.second.c_str());
        }
        for (auto& legInfo : strategyInfo.legs)
        {
            WriteLog(LogLevel::Info, "LegInfo Name:%s, Leg:%d, Future:%s, OptionChain:%s, CountFuture:%d", legInfo.name.c_str(), legInfo.leg, legInfo.future.c_str(), legInfo.optionChain.c_str(), legInfo.countFuture);
        }
        for (auto& risk : strategyInfo.risks)
        {
            WriteLog(LogLevel::Info, "RiskInfo Name:%s, ShortCut:%s, LpgName:%s", risk.name.c_str(), risk.shortcut.c_str(), risk.lpgName.c_str());
        }
        for (auto& alpha : strategyInfo.alphas)
        {
            WriteLog(LogLevel::Info, "AlphaInfo Id:%d, Name:%s, LpgName:%s", alpha.id, alpha.name.c_str(), alpha.lpgName.c_str());
        }
        for (auto& it : strategyInfo.topics)
        {
            WriteLog(LogLevel::Info, "Topic Key:%s, Value:%d", it.first.c_str(), it.second);
        }
        for (auto& extraLpg : strategyInfo.extraLpgs)
        {
            WriteLog(LogLevel::Info, "StrategyUnit ExtraLpg:%s", extraLpg.c_str());
        }
    }
    QryAndSubscribeUnitTopic(sessionID, rsp.unitName);
}
void ThriftClient::OnRspQryAndSubscribeUnitTopic(const SessionIDType& sessionID, const SubscribeUnitResponse& rsp)
{
    WriteLog(LogLevel::Info, "OnRspQryAndSubscribeUnitTopic Status:%d, Detail:%s, UnitName:%s, InfosSize:%d", rsp.status, rsp.detail.c_str(), rsp.unitName.c_str(), rsp.infos.size());
    auto topicDecoder = m_SessionDecoders[sessionID];
    for (auto& topicInfo : rsp.infos)
    {
        WriteLog(LogLevel::Info, "TopicInfo Name:%s, TopicID:%d, FieldsSize:%d, EnumsSize:%d", topicInfo.name.c_str(), topicInfo.topicID, topicInfo.fields.size(), topicInfo.enums.size());
        for (auto& field : topicInfo.fields)
        {
            WriteLog(LogLevel::Info, "FieldDesc Name:%s, Type:%s", field.name.c_str(), field.type.c_str());
        }
        for (auto& enumIt : topicInfo.enums)
        {
            WriteLog(LogLevel::Info, "Enums Key:%s, Name:%s, ValuesSize:%d", enumIt.first.c_str(), enumIt.second.name.c_str(), enumIt.second.values.size());
            for (auto& valueIt : enumIt.second.values)
            {
                WriteLog(LogLevel::Info, "EnumDesc Key:%s, Value:%d", valueIt.first.c_str(), valueIt.second);
            }
        }
        topicDecoder->AddTopic(topicInfo);
    }
}

void ThriftClient::OnRtnTopicNofity(const SessionIDType& sessionID, const TopicNotify& topic, std::shared_ptr<apache::thrift::protocol::TCompactProtocol> proto)
{
    auto topicDecoder = m_SessionDecoders[sessionID];
    std::vector<vector<DecodeItem*>> values;
    auto ret = (*topicDecoder)(topic, proto, values);
    WriteLog(LogLevel::Warning, "OnRtnTopicNofity TopicDecoder ret:%d, TopicNotify.count:%d, valuesSize:%d", ret, topic.count, values.size());
    if (!ret)
        return;
    auto& topicInfo = topicDecoder->GetTopic(topic.topicID);
    for (auto i = 0; i < values.size(); ++i)
    {
        WriteLog(LogLevel::Info, "TopicInfo Name:%s, TopicID:%d", topicInfo.name.c_str(), topicInfo.topicID);
        for (auto j = 0; j < topicInfo.fields.size(); ++j)
        {
            auto& type = topicInfo.fields[j].type;
            auto item = values[i][j];
            if (type.starts_with("s"))
            {
                WriteLog(LogLevel::Info, "Name:%s, Type:%s, Value:%s", topicInfo.fields[j].name.c_str(), topicInfo.fields[j].type.c_str(), any_cast<string>(item->value).c_str());
            }
            else if (type.starts_with("f"))
            {
                WriteLog(LogLevel::Info, "Name:%s, Type:%s, Value:%f", topicInfo.fields[j].name.c_str(), topicInfo.fields[j].type.c_str(), any_cast<double>(item->value));
            }
            else if (type.starts_with("i64") || type.starts_with("u64"))
            {
                WriteLog(LogLevel::Info, "Name:%s, Type:%s, Value:%lld", topicInfo.fields[j].name.c_str(), topicInfo.fields[j].type.c_str(), any_cast<int64_t>(item->value));
            }
            else if (type.starts_with("i") || type.starts_with("u"))
            {
                WriteLog(LogLevel::Info, "Name:%s, Type:%s, Value:%d", topicInfo.fields[j].name.c_str(), topicInfo.fields[j].type.c_str(), any_cast<int32_t>(item->value));
            }
            else if (type == "bool")
            {
                WriteLog(LogLevel::Info, "Name:%s, Type:%s, Value:%d", topicInfo.fields[j].name.c_str(), topicInfo.fields[j].type.c_str(), any_cast<bool>(item->value));
            }
            else
            {
                auto it = topicInfo.enums.find(type);
                if (it != topicInfo.enums.end())
                {
                    auto& enumDesc = it->second;
                    auto enumValue = any_cast<int32_t>(item->value);
                    string enumName;
                    for (auto& enumIt : enumDesc.values)
                    {
                        if (enumIt.second == enumValue)
                        {
                            enumName = enumIt.first;
                            break;
                        }
                    }
                    WriteLog(LogLevel::Info, "Name:%s, Type:%s, EnumName:%s, EnumValue:%d", topicInfo.fields[j].name.c_str(), topicInfo.fields[j].type.c_str(), enumName.c_str(), enumValue);
                }
                else
                {
                    WriteLog(LogLevel::Info, "Unexpected Type. Name:%s, Type:%s", topicInfo.fields[j].name.c_str(), topicInfo.fields[j].type.c_str());
                }
            }
        }
    }
}


