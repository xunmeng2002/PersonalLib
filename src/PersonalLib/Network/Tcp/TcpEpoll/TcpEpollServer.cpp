#include "PersonalLib/Network/Tcp/TcpEpoll/TcpEpollServer.h"
#include "PersonalLib/Core/Logger/Logger.h"
#include "PersonalLib/Network/Tcp/TcpUtility.h"
#include <string.h>


TcpEpollServer::TcpEpollServer(const char* addressName, int milliSeconds)
	:TcpEpollBase(ServerTypeType::Server, addressName, milliSeconds)
{
}
TcpEpollServer::~TcpEpollServer()
{
}
bool TcpEpollServer::Init()
{
	if (!TcpEpollBase::Init())
	{
		return false;
	}
	TcpConnect* connect = TcpConnect::Allocate(0, m_Socket, m_Address, m_Port);
	AddEpollEvent(connect);
	return true;
}



