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
#ifdef WINDOWS
	shutdown(SocketID, SD_BOTH);
#endif
#ifdef LINUX
	shutdown(SocketID, SHUT_RDWR);
#endif
	closesocket(SocketID);
	MemCacheTemplateSingleton<TcpConnect>::GetInstance().Free(this);
}

void TcpConnect::Set(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	SessionID = sessionID;
	SocketID = socketID;
	strcpy(RemoteIP, remoteIP.c_str());
	strcpy(RemotePort, remotePort.c_str());
	LastSendTimePoint = std::chrono::steady_clock::now();
}
void TcpConnect::UpdateLastSendTime()
{
	LastSendTimePoint = std::chrono::steady_clock::now();
}
