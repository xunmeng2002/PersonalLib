#include "TcpEpollServer.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>


TcpEpollServer::TcpEpollServer(const char* threadName, const char* addressName, int milliSeconds)
	:TcpEpollBase(ServerTypeType::Server, threadName, addressName, milliSeconds)
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



