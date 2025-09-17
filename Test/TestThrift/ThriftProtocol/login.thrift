const i32 WMESSAGE_LOGIN_LOGIN = 3073;
struct LoginRequest
{
    1: string name;
    2: string password;
}

struct GroceryInfo
{
    1: string hostname;
    2: string ip;
    3: i16 port;
    4: string token;
}

struct LoginResponse
{
    1: i32 status;
    2: string detail;
    3: i64 expireAt;
    4: list<GroceryInfo> groceries;
}