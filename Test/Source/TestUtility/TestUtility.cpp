#include "TestUtility.h"
#include "Logger.h"


using namespace std;
using namespace std::chrono;



TcpProtocolType g_ClientProtocolType = TcpProtocolType::TcpSelect;
TcpProtocolType g_ServerProtocolType = TcpProtocolType::TcpIocp;
const char* g_Address = "tcp://127.0.0.1:10001";
//const char* g_Address = "shm://TestServerShm:3";
const char* g_IocpServerAddress = "127.0.0.1:10001";
const char* g_IocpClientAddress = "127.0.0.1:10002";
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
