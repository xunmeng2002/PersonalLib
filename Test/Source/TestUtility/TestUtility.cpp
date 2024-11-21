#include "TestUtility.h"
#include "Logger.h"


using namespace std;
using namespace std::chrono;



IOTypeType g_IOType = IOTypeType::Shm;
TcpProtocolType g_ProtocolType = TcpProtocolType::Xtp;
//const char* g_Address = "127.0.0.1:10086";
const char* g_Address = "TestServerShm:8";
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
