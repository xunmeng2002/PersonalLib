#include "TcpIocpServer.h"


TcpIocpServer::TcpIocpServer(const char* addressName, int milliSeconds, int backlog)
	:TcpIocpBase(ServerTypeType::Server, addressName, milliSeconds, backlog)
{

}

