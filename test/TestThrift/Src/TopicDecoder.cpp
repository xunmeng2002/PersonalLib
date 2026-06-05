#include "TopicDecoder.h"
#include "PersonalLib/Core/Logger/Logger.h"


using namespace std;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

TopicDecoder::TopicDecoder(const SessionIDType& sessionID)
	:m_SessionID(sessionID)
{
}
void TopicDecoder::AddTopic(const TopicInfo& toppic)
{
	m_Topics[toppic.topicID] = toppic;
}
TopicInfo& TopicDecoder::GetTopic(int topicID)
{
	return m_Topics[topicID];
}
bool TopicDecoder::operator()(const TopicNotify& msg, std::shared_ptr<apache::thrift::protocol::TCompactProtocol> proto, std::vector<std::vector<DecodeItem*>>& values)
{
	auto it = m_Topics.find(msg.topicID);
	if (it == m_Topics.end())
	{
		WriteLog(LogLevel::Info, "Cannot Find Topic For TopicID:%d", msg.topicID);
		return false;
	}
	auto& topic = (*it).second;
	auto size = topic.fields.size();
	for (auto i = 0; i < msg.count; ++i)
	{
		
		std::string name;
		int16_t id;
		vector<DecodeItem*> value;
		for (auto j = 0; j < size; ++j)
		{
			DecodeItem* item = new DecodeItem();
			value.push_back(item);
			auto rsize = proto->readFieldBegin(name, item->Type, id);
			if (rsize < 0)
			{
				break;
			}
			switch (item->Type)
			{
			case T_STRING:
			{
				string s;
				proto->readString(s);
				item->value = s;;
				break;
			}
			case T_I32:
			{
				int32_t v;
				proto->readI32(v);
				item->value = v;
				break;
			}
			case T_I64:
			{
				int64_t v;
				proto->readI64(v);
				item->value = v;
				break;
			}
			case T_DOUBLE:
			{
				double v;
				proto->readDouble(v);
				item->value = v;
				break;
			}
			case T_BOOL:
			{
				bool v;
				proto->readBool(v);
				item->value = v;
				break;
			}
			default:
				break;
			}
		}
		values.push_back(value);
	}
	return true;
}
