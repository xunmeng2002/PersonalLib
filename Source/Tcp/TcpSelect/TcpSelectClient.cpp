#include "TcpSelectClient.h"
#include "TcpUtility.h"
#include "Logger.h"
#include <cstring>


TcpSelectClient::TcpSelectClient(const char* addressName, int milliSeconds)
	:TcpSelectBase(ServerTypeType::Client, addressName, milliSeconds)
{
}

