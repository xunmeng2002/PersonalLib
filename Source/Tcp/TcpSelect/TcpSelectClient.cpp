#include "TcpSelectClient.h"
#include "TcpUtility.h"
#include "Logger.h"
#include <cstring>


TcpSelectClient::TcpSelectClient(const char* threadName, const char* addressName)
	:TcpSelectBase(ServerTypeType::Client, threadName, addressName)
{
}

