            
const i32 WMESSAGE_TOPIC_SUBSCRIBE = 6145;
struct SubscribeRequest
{
    1: i32 topicID;
}

struct EnumDesc
{
    1: string name;
    2: map<string, i32> values;
}

struct FieldDesc
{
    1: string name;
    2: string type;   //string, i32, i64, double, bool
}

struct TopicInfo
{
    1: string name;
    2: i32 topicID;
    3: list<FieldDesc> fields;
    4: map<string, EnumDesc> enums;
}

struct SubscribeResponse
{
    1: i32 status;
    2: string detail;
    3: TopicInfo info;
}

const i32 WMESSAGE_TOPIC_NOTIFY = 6146;
struct TopicNotify
{
    1: i32 topicID;
    2: i32 count;
}

const i32 WMESSAGE_TOPIC_UNSUBSCRIBE = 6147;
struct UnsubscribeRequest
{
    1: i32 topicID;
}

struct UnsubscribeResponse
{
    1: i32 topicID;
    2: i32 status;
    3: string detail;
}

const i32 WMESSAGE_TOPIC_SUBSCRIBE_UNIT = 6148;
struct SubscribeUnitRequest
{
    1: string unitName;
}

struct SubscribeUnitResponse
{
    1: i32 status;
    2: string detail;
    3: string unitName;
    4: list<TopicInfo> infos;    
}
