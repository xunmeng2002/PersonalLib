#pragma once
#include "NetworkExport.h"
#include "PersonalLib/Network/Tcp/SocketInit.h"
#include "PersonalLib/Types.h"
#include "PersonalLib/Network/IO/Connect.h"
#include <mutex>
#include <string>
#include <chrono>
#include <atomic>

class NETWORK_EXPORTS TcpConnect : public Connect
{
public:
	TcpConnect(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	virtual ~TcpConnect();

	static TcpConnect* Allocate(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	virtual void Deallocate() override;

	virtual void Set(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void UpdateLastSendTime();


	SOCKET SocketID;
	std::chrono::steady_clock::time_point LastSendTimePoint;
};
