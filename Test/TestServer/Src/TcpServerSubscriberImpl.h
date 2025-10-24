#pragma once
#include "ThreadBase.h"
#include "TcpBase.h"
#include "IOThread.h"


class TcpServerSubscriberImpl : public IOSubscriber
{
public:
	TcpServerSubscriberImpl(TcpBase* tcp, IOThread* ioThread);
	~TcpServerSubscriberImpl();

	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

private:
	TcpBase* m_IO;
	IOThread* m_IOThread;

	std::map<SessionIDType, int> m_MessageCounts;
};