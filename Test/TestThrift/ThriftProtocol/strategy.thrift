const i32 WMESSAGE_MONITOR_LIST_STRATEGY = 5121;
struct ListStrategyRequest
{
    1: string unitName;
}

struct LegInfo
{
    1: string name; // HO
    2: i32 leg; //0, 1, 2
    3: string future;  // IH2502.CFFEX
    4: string optionChain;  //HO.2502
    5: bool countFuture; // true
}

struct RiskInfo
{
    1: string name; //Delta, Vega, Slop, Curv, Gamma, Thetha
    2: string shortcut; //D, V, S, C, G, T
    3: string lpgName;
}

struct AlphaInfo
{
    1: i32 id;
    2: string name;
    3: string lpgName;
}

struct StrategyInfo
{
    1: string name; // 50ETF502_1
    2: map<string, string> attributes; //{"fund": "DFQ", "type": "CA", "group": "50ETF2502"}
    3: list<LegInfo> legs; //{{IH2502.CFFEX, 510050.2502, false}, {IF2502.CFFEX, 510300.2502, false}, {IH2502.CFFEX, HO.2502, true}}
    6: list<RiskInfo> risks;
    7: list<AlphaInfo> alphas;
    8: map<string, i32> topics;
    9: list<string> extraLpgs;
    //risk, topic-> timestamp, leg, shortcut, risk
    //fitting, topic->timestamp, leg, strke, callOrPut, moneyness, syncWeight, fittingWeight, delta, gamma, vega, theta, slop, curv
    //trading, topic->timestamp, leg, strke, callOrPut, takingOn, makingOn, tradingOn,impliedVol, tradingVol, delta, vega, slopeRisk, curvRisk, rr, takingMargin, makingMargin, fairPrice, mktPrice, tradingPrice
    //alphaPnL, topic->timestamp, name, theoricalPnL, riskPnL
    //position, topic->timestamp, symbol, pos
    //pendingOrder, topic->timestamp, id, symbol, way, offset, orderType, orderStatus, price, size, leaveSize, sendTime
    //errorOrder, topic->timestamp, id, symbol, way, offset, orderType, orderStatus, price, size, leaveSize, sendTime, reason
    //status, topic->timestamp, who, status, detail
}

struct ListStrategyResponse
{
    1: i32 status;
    2: string detail;
    3: string unitName;
    4: list<StrategyInfo> strategies;
}

const i32 WMESSAGE_MONITOR_START_STRATEGY = 5122;
enum StrategyTradingMode
{
    UNKNOWN = 0;
    TAKING = 1;
    MAKING = 2;
    TRADING = 3;
}

struct StartStrategyRequest
{
    1: string unitName;
    2: string strategyName;
    3: StrategyTradingMode mode;
}

struct StartStrategyResponse
{
    1: i32 status;
    2: string detail;
}

const i32 WMESSAGE_MONITOR_STOP_STRATEGY = 5123;
struct StopStrategyRequest
{
    1: string unitName;
    2: string strategyName;
    3: StrategyTradingMode mode;
}

struct StopStrategyResponse
{
    1: i32 status;
    2: string detail;
}
