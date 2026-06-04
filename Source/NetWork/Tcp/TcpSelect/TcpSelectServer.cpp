#include "Network/Tcp/TcpSelect/TcpSelectServer.h"
#include "Core/Logger/Logger.h"
#include "Network/Tcp/TcpUtility.h"
#include <string.h>


TcpSelectServer::TcpSelectServer(const char* addressName, int milliSeconds)
	:TcpSelectBase(ServerTypeType::Server, addressName, milliSeconds)
{
}

