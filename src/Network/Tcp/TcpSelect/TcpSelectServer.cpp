#include "Tcp/TcpSelect/TcpSelectServer.h"
#include <PersonalLib/Core/Logger/Logger.h>
#include <PersonalLib/Network/Tcp/TcpUtility.h>
#include <string.h>


TcpSelectServer::TcpSelectServer(const char* addressName, int milliSeconds)
	:TcpSelectBase(ServerTypeType::Server, addressName, milliSeconds)
{
}

