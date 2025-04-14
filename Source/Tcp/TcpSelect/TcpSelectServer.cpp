#include "TcpSelectServer.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectServer::TcpSelectServer(const char* threadName, const char* addressName, int milliSeconds)
	:TcpSelectBase(ServerTypeType::Server, threadName, addressName, milliSeconds)
{
}

