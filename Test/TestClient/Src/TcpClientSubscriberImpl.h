#pragma once
#include "ThreadBase.h"
#include "TcpBase.h"
#include "IOThread.h"
#include "TimeUtility.h"
#include <map>
#include <chrono>


class TcpClientSubscriberImpl : public IOSubscriber
{
public:
	TcpClientSubscriberImpl(TcpBase* tcp, IOThread* ioThread);
	~TcpClientSubscriberImpl();



	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

	void Send(SessionIDType sessionID);
	void SendCommand(SessionIDType sessionID, const char* cmd);
private:
	TcpBase* m_IO;
	IOThread* m_IOThread;
	std::map<SessionIDType, int> m_MessageCounts;
	std::chrono::steady_clock::time_point m_StartSendTime;
};
