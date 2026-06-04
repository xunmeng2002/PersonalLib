#include "Tcp/TcpSelect/TcpSelectServer.h"
#include "Logger/Logger.h"
#include "Tcp/TcpBase/TcpUtility.h"
#include <string.h>


TcpSelectServer::TcpSelectServer(const char* addressName, int milliSeconds)
	:TcpSelectBase(ServerTypeType::Server, addressName, milliSeconds)
{
}

