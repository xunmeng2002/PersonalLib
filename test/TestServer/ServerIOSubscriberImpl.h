#pragma once
#include <PersonalLib/Core/Thread/ThreadBase.h>
#include <PersonalLib/Network/IO/IOBase.h>
#include <PersonalLib/Network/IO/IOThread.h>


class ServerIOSubscriberImpl : public IOSubscriber
{
public:
	ServerIOSubscriberImpl(IOBase* io, IOThread* ioThread);
	~ServerIOSubscriberImpl();

	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

private:
	IOBase* m_IO;
	IOThread* m_IOThread;

	std::map<SessionIDType, int> m_MessageCounts;
};