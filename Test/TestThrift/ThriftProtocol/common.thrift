const i32 WMESSAGE_COMMON_HEARTBEAT = 1025;
struct HeartbeatRequest
{
    1: i64 timestamp;
}

struct HeartbeatResponse
{
    1: i64 timestamp;
}

const i32 WMESSAGE_COMMON_CHECK_TOKEN = 1026;
struct CheckTokenRequest
{
    1: string token;
}

struct CheckTokenResponse
{
    1: i32 status;
    2: string detail;
    3: string token;
    4: list<string> permissions;
}
