#include "TcpConnect.h"
#include "Logger.h"
#include "MemCacheTemplateSingleton.h"
#include "TimeUtility.h"



TcpConnect* TcpConnect::Allocate(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	TcpConnect* connectData = MemCacheTemplateSingleton<TcpConnect>::GetInstance().Allocate();
	connectData->Set(sessionID, socketID, remoteIP, remotePort);
	return connectData;
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
