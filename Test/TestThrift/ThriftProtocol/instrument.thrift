const i32 WMESSAGE_MONITOR_LIST_INSTRUMENT = 7169;

struct ListInstrumentRequest
{
    1: string prodMat;  //IH.2502, HO.2502, IH2502.CFFEX, HO.CFFEX
}

struct InstrumentInfo
{
    1: string name; //IH2502.CFFEX, HO2502-C-2500.CFFEX
    2: string type; //Future, OptionCall, OptionPut, Index
    3: string underlying; //510050.2502
    4: double multiplier; //1.0
    5: double strike; //2500
    6: double tickSize; //0.001
    7: i64 expiration; //ns from 1970-01-01
}

struct ListInstrumentResponse
{
    1: i32 status;
    2: string detail;
    3: string name;
    4: list<InstrumentInfo> instruments;
}

const i32 WMESSAGE_MONITOR_LIST_UNIT_INSTRUMENT = 7170;

struct ListUnitInstrumentRequest
{
    1: string unitName;
}

struct ListUnitInstrumentResponse
{
    1: i32 status;
    2: string detail;
    3: list<InstrumentInfo> instruments;
}