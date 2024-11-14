#include "ConnectData.h"
#include "Logger.h"
#include "MemCacheTemplateSingleton.h"
#include "TimeUtility.h"



ConnectData* ConnectData::Allocate(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	ConnectData* connectData = MemCacheTemplateSingleton<ConnectData>::GetInstance().Allocate();
	connectData->Set(sessionID, socketID, remoteIP, remotePort);
	return connectData;
}
void ConnectData::Free()
{
#ifdef WINDOWS
	shutdown(SocketID, SD_BOTH);
#endif
#ifdef LINUX
	shutdown(SocketID, SHUT_RDWR);
#endif
	closesocket(SocketID);
	MemCacheTemplateSingleton<ConnectData>::GetInstance().Free(this);
}

void ConnectData::Set(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	SessionID = sessionID;
	SocketID = socketID;
	strcpy(RemoteIP, remoteIP.c_str());
	strcpy(RemotePort, remotePort.c_str());
	LastSendTimePoint = std::chrono::steady_clock::now();
}
void ConnectData::UpdateLastSendTime()
{
	LastSendTimePoint = std::chrono::steady_clock::now();
}
