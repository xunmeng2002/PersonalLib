#pragma once
#include "IOThread.h"


class ShmSubscriberImpl : public IOSubscriber
{
public:
	ShmSubscriberImpl(IOThread* ioThread, ServerTypeType serverType);

	virtual void OnConnect(SessionIDType sessionID, const char* ip, const char* port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, const char* port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;


public:
	bool m_Connected;
	SessionIDType m_SessionID;
private:
	IOThread* m_IOThread;
	ServerTypeType m_ServerType;

	char* m_Buff;
	int m_Length;
	char* m_SendBuff;
};


