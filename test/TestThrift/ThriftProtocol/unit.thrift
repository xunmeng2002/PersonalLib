const i32 WMESSAGE_MONITOR_UNIT_LIST = 4097;

struct ListUnitsRequest
{
    1: string hostname;
}

struct UnitInfo
{
    1: string name;
    2: string type; //strategy,account,mo
}

struct ListUnitsResponse
{
    1: i32 status;
    2: string detail;
    3: string hostname;
    4: list<UnitInfo> units;
}
