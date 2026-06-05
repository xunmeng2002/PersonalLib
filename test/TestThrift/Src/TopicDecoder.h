#pragma once
#include "topic_constants.h"
#include "PersonalLib/Types.h"
#include <map>
#include <vector>
#include <any>
#include <string>
#include <thrift/protocol/TCompactProtocol.h>

struct DecodeItem
{
	apache::thrift::protocol::TType Type;
	std::any value;
};

class TopicDecoder
{
public:
	TopicDecoder(const SessionIDType& sessionID);
	void AddTopic(const TopicInfo& toppic);
	TopicInfo& GetTopic(int topicID);
	bool operator()(const TopicNotify& msg, std::shared_ptr<apache::thrift::protocol::TCompactProtocol> proto, std::vector<std::vector<DecodeItem*>>& values);

private:
	SessionIDType m_SessionID;
	std::map<int, TopicInfo> m_Topics;
};



