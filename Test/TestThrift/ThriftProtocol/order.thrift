const i32 WMESSAGE_ORDER_INSERT = 8193
struct InsertOrderReq
{
    1: string symbol;
    2: string account;
    3: string localId;
    4: string portfolio;
    5: double price;
    6: i32 qty;
    7: bool isBuy;
    8: bool isOpen;
    9: bool isYesterday;
}

struct InsertOrderResponse
{
    1: i32 status;
    2: string detail;
    3: string localId;
    4: i32 orderId;
}

const i32 WMESSAGE_ORDER_CANCEL = 8194
struct CancelOrderReq
{
    1: i32 orderId;
}

struct CancelOrderResponse
{
    1: i32 status;
    2: string detail;
}

const i32 WMESSAGE_COMB_COMB = 8195
struct SendCombRequest
{
    1: string combStrategy; #CNSJC, CXSJC, PNSJC, PXSJC, KS, KKS, ZBD
    2: string localCombId;
    3: string symbol1;
    4: bool isBuy1;
    5: string symbol2;
    6: bool isBuy2;
    7: i32 qty;
}

struct SendCombResponse
{
    1: i32 status;
    2: string detail;
    3: string localCombId;
    4: i32 combId;
}

const i32 WMESSAGE_COMB_UNCOMB = 8196
struct SendUncombRequest
{
    1: i32 combId;
    2: string systemCombId;
}

struct SendUncombResponse
{
    1: i32 status;
    2: string detail;
}
