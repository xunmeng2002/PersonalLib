#include "TopicDecoder.h"
#include "Logger.h"


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
bool TopicDecoder::operator()(const TopicNotify& msg, std::shared_ptr<apache::thrift::protocol::TCompactProtocol> proto, std::vector<std::vector<std::any>>& values)
{
	auto it = m_Topics.find(msg.topicID);
	if (it == m_Topics.end())
	{
		WriteLog(LogLevel::Info, "Cannot Find Topic For TopicID:%d", msg.topicID);
		return false;
	}
	auto& topic = (*it).second;
	auto size = topic.fields.size();
	if (msg.topicID == 3)
	{
		WriteLog(LogLevel::Info, "OrderTopic");
	}
	for (auto i = 0; i < msg.count; ++i)
	{
		TType type;
		std::string name;
		int16_t id;

		vector<std::any> value;
		for (auto j = 0; j < size; ++j)
		{
			auto rsize = proto->readFieldBegin(name, type, id);
			if (rsize < 0)
			{
				break;
			}
			switch (type)
			{
			case T_STRING:
			{
				string s;
				proto->readString(s);
				value.push_back(s);
				break;
			}
			case T_I32:
			{
				int32_t v;
				proto->readI32(v);
				value.push_back(v);
				break;
			}
			case T_I64:
			{
				int64_t v;
				proto->readI64(v);
				value.push_back(v);
				break;
			}
			case T_DOUBLE:
			{
				double v;
				proto->readDouble(v);
				value.push_back(v);
				break;
			}
			case T_BOOL:
			{
				bool v;
				proto->readBool(v);
				value.push_back(v);
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