const i32 WMESSAGE_MONITOR_LIST_ACCOUNT = 8193;
struct ListAccountRequest
{
    1: string unitName;
}

struct AccountInfo
{
    1: string tradeFundName;  //833
    2: string exchange; //SSE
    3: string accountName; //MKT_833_SSE
}

struct ListAccountResponse
{
    1: i32 status;
    2: string detail;
    3: string unitName;
    4: map<string, i32> topics;
    //blance topic->timestamp, total, available, margin
    //status topic->timestamp, who, status, detail
    //opt_position topic->timestamp,symbol,short_comb,short,long,long_comb
    //fut_position topic->timestamp,symbol,yst_short,yst_long,td_short,td_long,total_long,total_short,net
    //order_event topic->timestamp, id, symbol, way, offset, orderType, orderStatus, price, size, leaveSize, sendTime, lastupdateTime
    //trade_event topic->timestamp, order_id, symbol, way, offset, orderType, price, size, execTime
    //comb_position topic->timestamp, id, comb_strategy, symbol1, way1, symbol2, way2, status    
    5: list<AccountInfo> accounts;
}