#include "Tcp/TcpBase/TcpConnect.h"
#include "Logger/Logger.h"
#include "MemCache/MemCacheTemplateSingleton.h"
#include "Utility/TimeUtility.h"
#include "Tcp/TcpBase/TcpUtility.h"



TcpConnect* TcpConnect::Allocate(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	TcpConnect* tcpConnect = MemCacheTemplateSingleton<TcpConnect>::GetInstance().Allocate();
	tcpConnect->Set(sessionID, socketID, remoteIP, remotePort);
	return tcpConnect;
}
void TcpConnect::Free()
{
	WriteLog(LogLevel::Info, "TcpConnect::Free SessionID:%lld, Socket:%lld", SessionID, SocketID);
#ifdef WINDOWS
	shutdown(SocketID, SD_BOTH);
#endif
#ifdef LINUX
	shutdown(SocketID, SHUT_RDWR);
#endif
	closesocket(SocketID);
	SocketID = INVALID_SOCKET;
	MemCacheTemplateSingleton<TcpConnect>::GetInstance().Free(this);
}

void TcpConnect::Set(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	SessionID = sessionID;
	SocketID = socketID;
	strcpy(RemoteAddress, remoteIP.c_str());
	RemotePort = atoi(remotePort.c_str());
	LastSendTimePoint = std::chrono::steady_clock::now();
}
void TcpConnect::UpdateLastSendTime()
{
	LastSendTimePoint = std::chrono::steady_clock::now();
}
