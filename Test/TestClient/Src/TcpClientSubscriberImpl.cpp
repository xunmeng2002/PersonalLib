#include "TcpClientSubscriberImpl.h"
#include "TcpSelectClient.h"
#include "Logger.h"
#include "Utility.h"
#include "Packages.h"
#include "Platform.h"
#include <cstring>


using namespace std;
using namespace std::chrono;

TcpClientSubscriberImpl::TcpClientSubscriberImpl(TcpBase* tcp)
    :m_IOThread(tcp)
{
    m_IOThread->Subscribe(this);
}
TcpClientSubscriberImpl::~TcpClientSubscriberImpl()
{
    m_IOThread->UnSubscribe();
}


void TcpClientSubscriberImpl::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
    WriteLog(LogLevel::Info, "TcpClientSubscriberImpl::OnConnect SessionID:[%lld], IP:[%s], Port:[%d]", sessionID, ip, port);
    m_MessageCounts.insert(std::make_pair(sessionID, 0));
    Send(sessionID);
}
void TcpClientSubscriberImpl::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
    WriteLog(LogLevel::Info, "TcpClientSubscriberImpl::OnDisConnect SessionID:[%lld], IP:[%s], Port:[%d]", sessionID, ip, port);
    m_MessageCounts.erase(sessionID);
}
void TcpClientSubscriberImpl::OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
    auto recvTime = high_resolution_clock::now();
    auto t = duration_cast<microseconds>(recvTime - m_LastSendTime);
    //WriteLog(LogLevel::Info, "TimeCost From Send to Recv:%lld us", t.count());

    WriteLog(LogLevel::Info, "TcpClientSubscriberImpl::OnRecv SessionID:[%lld], Length:[%d], Data:[%s]", sessionID, buffer->GetLength(), buffer->GetData());
    if (m_MessageCounts[sessionID] < 5)
    {
        Send(sessionID);
    }
    else
    {
        m_IOThread->DisConnect(sessionID);
        buffer->Free();
    }
}
void TcpClientSubscriberImpl::Send(SessionIDType sessionID)
{
    ++m_MessageCounts[sessionID];

    ReqInsertOrderPackage reqInsertOrder;
    reqInsertOrder.ReqInsertOrder = new ReqInsertOrderField();
    Strcpy(reqInsertOrder.ReqInsertOrder->AccountID, "Xunmeng001");
    Strcpy(reqInsertOrder.ReqInsertOrder->ExchangeID, "SHSE");
    Strcpy(reqInsertOrder.ReqInsertOrder->InstrumentID, "600036");
    reqInsertOrder.ReqInsertOrder->Direction = DirectionType::Buy;
    reqInsertOrder.ReqInsertOrder->OffsetFlag = OffsetFlagType::Open;
    reqInsertOrder.ReqInsertOrder->OrderPriceType = OrderPriceTypeType::LimitPrice;
    reqInsertOrder.ReqInsertOrder->Price = 88.88;
    reqInsertOrder.ReqInsertOrder->Volume = 1000;
    reqInsertOrder.ReqInsertOrder->ClientOrderID = 1;
    auto message = reqInsertOrder.GetDebugString();

    Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
    auto data = buffer->GetData();
    auto len = strlen(message);
    memcpy(data, message, len);
    buffer->SetLength((unsigned)len);

    m_LastSendTime = high_resolution_clock::now();
    auto sendLen = m_IOThread->Send(sessionID, buffer);
    if (sendLen <= 0)
    {
        WriteLog(LogLevel::Error, "m_IOThread->Send sendLen:%d, Errno:%d, buffer Len:%d, Data:%s", sendLen, GetLastError(), buffer->GetLength(), buffer->GetData());
    }
}
void TcpClientSubscriberImpl::SendCommand(SessionIDType sessionID, const char* cmd)
{
    ++m_MessageCounts[sessionID];
    Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
    int n = sprintf(buffer->GetData(), "%s\r\n", cmd);
    buffer->SetLength(n);
    m_IOThread->Send(sessionID, buffer);
}

