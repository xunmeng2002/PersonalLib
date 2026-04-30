#include "TestUtility.h"
#include "Logger/Logger.h"


using namespace std;
using namespace std::chrono;



TcpProtocolType g_ClientProtocolType = TcpProtocolType::Shm;
TcpProtocolType g_ServerProtocolType = TcpProtocolType::Shm;
//const char* g_Address = "tcp://127.0.0.1:20001";
const char* g_Address = "shm://TestShm:4";
#ifdef WINDOWS
const char* g_ShmName = "../TestShm";
const char* g_SemName = "../OnlySem";
#endif
#ifdef LINUX
const char* g_ShmName = "TestShm";
const char* g_SemName = "OnlySem";
#endif

void PrintTimeCost(const char* name, time_point<system_clock, milliseconds> startTime, time_point<system_clock, milliseconds> endTime)
{
	WriteLog(LogLevel::Info, "%s: %lldms", name, (endTime - startTime).count());
}
