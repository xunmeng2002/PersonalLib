const i32 WMESSAGE_ORDER_INSERT = 9216
struct InsertOrderRequest
{
    1: string symbol;
    2: string account;
    3: string localId;
    4: string portfolio;
    5: string orderType; //GFD,FAK etc.
    6: double price;
    7: i32 qty;
    8: bool isBuy;
    9: bool isOpen;
    10: bool isYesterday;
}

struct InsertOrderResponse
{
    1: i32 status;
    2: string detail;
    3: string localId;
    4: i32 orderId;
}

const i32 WMESSAGE_ORDER_CANCEL = 9217
struct CancelOrderRequest
{
    1: i32 orderId;
}

struct CancelOrderResponse
{
    1: i32 status;
    2: string detail;
}

const i32 WMESSAGE_COMB_COMB = 9218
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

const i32 WMESSAGE_COMB_UNCOMB = 9219
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
