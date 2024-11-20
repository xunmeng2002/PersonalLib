#pragma once
#include "SocketInit.h"
#include "ConnectData.h"
#include "IOThread.h"
#include "Buffer.h"
#include "Constant.h"
#include <list>
#include <map>
#include <mutex>


class TcpBase : public IOThread
{
public:
	TcpBase(const char* threadName, const char* addressName);
	virtual ~TcpBase();
	
	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) override;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;
protected:
	virtual void HandleTcpEvent() = 0;
	virtual void ThreadExit() override;

	virtual void DoDisConnect();
	virtual void DoRecv(ConnectData* connectData);
	virtual void AddConnect(ConnectData* connectData);
	virtual void RemoveConnect(ConnectData* connectData);
	virtual ConnectData* GetConnect(SessionIDType sessionID);

	bool InitSocket(SOCKET socketID);
	SOCKET PrepareSocket(int family);

protected:
	std::map<SessionIDType, ConnectData*> m_ConnectDatas;
	std::mutex m_ConnectDataMutex;
	std::mutex m_SendMutex;

	
	
	sockaddr_storage m_RemoteAddress;
#ifdef WINDOWS
	int m_RemoteAddressLen;
#endif
#ifdef LINUX
	unsigned int m_RemoteAddressLen;
#endif
};


