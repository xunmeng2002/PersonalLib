#pragma once
#include "ThreadBase.h"
#include "Types.h"
#include "Buffer.h"
#include <string>
#include <mutex>
#include <list>


class IOSubscriber
{
public:
	virtual void OnConnect(SessionIDType sessionID, const char* ip, const char* port) = 0;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, const char* port) = 0;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) = 0;
};

class IOThread : public ThreadBase
{
public:
	IOThread(ServerTypeType serverType, const char* threadName, const char* addressName, int milliSeconds = 100);
	void Subscribe(IOSubscriber* subscriber);
	void UnSubscribe();

	virtual bool Init() { return true; }
	virtual void DisConnect(SessionIDType sessionID);
	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) = 0;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) = 0;

protected:
	SessionIDType GetSessionID();

protected:
	ServerTypeType m_ServerType;
	std::string	m_AddressName;
	IOSubscriber* m_IOSubscriber;
	SessionIDType m_LastSessionIndex;

	std::list<SessionIDType> m_DisConnectSessionIDs;
	std::mutex m_DisConnectSessionIDsMutex;
};

