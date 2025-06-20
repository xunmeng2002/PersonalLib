#pragma once
#include "Types.h"
#include "Buffer.h"
#include "Connect.h"
#include <string>
#include <chrono>
#include <mutex>
#include <list>
#include <map>
#include <condition_variable>

class IOSubscriber
{
public:
	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) = 0;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) = 0;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) = 0;
};

class IOBase
{
public:
	IOBase(ServerTypeType serverType, const char* addressName, int milliSeconds);
	~IOBase();
	void Subscribe(IOSubscriber* subscriber);
	void UnSubscribe();
	virtual void SetTimeOut(int milliSeconds);

	virtual void RegisterFront(const char* address);
	virtual bool Init() { return true; }
	virtual void DisConnect(SessionIDType sessionID);
	virtual void DisConnectAll();
	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) = 0;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) = 0;
	virtual void DoRecv(Connect* connect) = 0;
	virtual void HandleIOEvent() = 0;

protected:
	virtual void DoDisConnect();
	virtual void AddConnect(Connect* connect);
	virtual void RemoveConnect(Connect* connect);
	virtual Connect* GetConnect(SessionIDType sessionID);

	SessionIDType GetSessionID();
	

protected:
	ServerTypeType m_ServerType;
	std::string	m_AddressName;
	std::string m_Address;
	std::string m_Port;
	std::chrono::milliseconds m_TimeOut;
	IOSubscriber* m_IOSubscriber;
	SessionIDType m_LastSessionIndex;

	bool m_Connected;

	std::map<SessionIDType, Connect*> m_Connects;
	std::mutex m_ConnectsMutex;
	std::list<SessionIDType> m_DisConnectSessionIDs;
	std::mutex m_DisConnectSessionIDsMutex;

	std::mutex m_Mutex;
	std::condition_variable m_ThreadConditionVariable;
};