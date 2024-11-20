#pragma once
#include "SocketInit.h"
#include "Types.h"
#include "Connect.h"
#include <mutex>
#include <string>
#include <chrono>

class TcpConnect : public Connect
{
public:
	static TcpConnect* Allocate(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void Free();

	void Set(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void UpdateLastSendTime();


	SOCKET SocketID;
	char RemoteIP[40];
	char RemotePort[8];
	std::chrono::steady_clock::time_point LastSendTimePoint;
};
