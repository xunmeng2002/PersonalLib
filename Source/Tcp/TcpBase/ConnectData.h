#pragma once
#include "SocketInit.h"
#include "Types.h"
#include <mutex>
#include <string>
#include <chrono>

class ConnectData
{
public:
	static ConnectData* Allocate(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void Free();

	void Set(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void UpdateLastSendTime();


	SessionIDType SessionID;
	SOCKET SocketID;
	char RemoteIP[40];
	char RemotePort[8];
	std::chrono::steady_clock::time_point LastSendTimePoint;
};
