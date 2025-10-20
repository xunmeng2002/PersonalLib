#pragma once
#include "IOBase.h"
#include "IOThread.h"
#include "Buffer.h"

class ShmSubscriberImpl : public IOSubscriber
{
public:
	ShmSubscriberImpl(IOBase* ioBase, ServerTypeType serverType);

	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;


public:
	bool m_Connected;
	SessionIDType m_SessionID;
private:
	IOBase* m_IOBase;
	ServerTypeType m_ServerType;

	char* m_Buff;
	int m_Length;
	Buffer<BuffSize>* m_SendBuff;
};


