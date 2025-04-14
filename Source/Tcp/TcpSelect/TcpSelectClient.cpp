#include "TcpSelectClient.h"
#include "TcpUtility.h"
#include "Logger.h"
#include <cstring>


TcpSelectClient::TcpSelectClient(const char* threadName, const char* addressName, int milliSeconds)
	:TcpSelectBase(ServerTypeType::Client, threadName, addressName, milliSeconds)
{
}

