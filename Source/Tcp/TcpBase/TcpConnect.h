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
	virtual void Free() override;

	virtual void Set(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void UpdateLastSendTime();


	SOCKET SocketID;
	std::chrono::steady_clock::time_point LastSendTimePoint;
};
