include "topic.thrift"

const i32 WMESSAGE_LIVEPARAMGROUP_LIST = 2049;
struct LiveParamGroupListRequest
{
    1: string unitName;
}

struct LiveParamInfo
{
    1: string type; //one onf [i32, i64, double, string, enum1, enum2]
    2: string name;
    3: string value;
}

struct LiveParamGroupInfo
{
    1: string name;
    2: list<LiveParamInfo> params;
    3: map<string, topic.EnumDesc> enums;
}

struct LiveParamGroupListResponse
{
    1: i32 status;
    2: string detail;
    3: string unitName;
    4: list<LiveParamGroupInfo> groups;
}

const i32 WMESSAGE_LIVEPARAM_SET = 2050;
struct LiveParamSetRequest
{
   1: string unitName;
   2: string grpName;
   3: map<string, string> params;
}

struct LiveParamSetResponse
{
    1: i32 status;
    2: string detail;
    3: string unitName;
}