#pragma once
#include "PersonalLib/Core/Thread/ThreadBase.h"
#include "PersonalLib/Network/IO/IOBase.h"
#include "PersonalLib/Network/IO/IOThread.h"
#include "PersonalLib/Core/Utility/TimeUtility.h"
#include <map>
#include <chrono>


class ClientIOSubscriberImpl : public IOSubscriber
{
public:
	ClientIOSubscriberImpl(IOBase* io, IOThread* ioThread);
	~ClientIOSubscriberImpl();



	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

	void Send(SessionIDType sessionID);
	void SendCommand(SessionIDType sessionID, const char* cmd);
private:
	IOBase* m_IO;
	IOThread* m_IOThread;
	std::map<SessionIDType, int> m_MessageCounts;
	std::chrono::steady_clock::time_point m_StartSendTime;
};
