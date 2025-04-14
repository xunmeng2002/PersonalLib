#pragma once
#include "ThreadBase.h"
#include "Types.h"
#include "Buffer.h"
#include "Connect.h"
#include <string>
#include <mutex>
#include <list>
#include <map>


class IOSubscriber
{
public:
	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) = 0;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) = 0;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) = 0;
};

class IOThread : public ThreadBase
{
public:
	IOThread(ServerTypeType serverType, const char* threadName, const char* addressName, int milliSeconds = 100);
	~IOThread();
	void Subscribe(IOSubscriber* subscriber);
	void UnSubscribe();

	virtual void RegisterFront(const char* address);
	virtual bool Init() { return true; }
	virtual void DisConnect(SessionIDType sessionID);
	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) = 0;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) = 0;
	virtual void DoRecv(SessionIDType sessionID) = 0;

protected:
	virtual void ThreadExit() override;
	virtual void DoDisConnect();
	virtual void AddConnect(Connect* connect);
	virtual void RemoveConnect(Connect* connect);
	virtual Connect* GetConnect(SessionIDType sessionID);
	
	SessionIDType GetSessionID();
	void DisConnectAll();

protected:
	ServerTypeType m_ServerType;
	std::string	m_AddressName;
	std::string m_Address;
	std::string m_Port;
	IOSubscriber* m_IOSubscriber;
	SessionIDType m_LastSessionIndex;

	bool m_Connected;

	std::map<SessionIDType, Connect*> m_Connects;
	std::mutex m_ConnectsMutex;
	std::list<SessionIDType> m_DisConnectSessionIDs;
	std::mutex m_DisConnectSessionIDsMutex;
};

