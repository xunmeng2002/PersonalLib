#pragma once
#include "SocketInit.h"
#include "TcpConnect.h"
#include "IOThread.h"
#include "Buffer.h"
#include "Constant.h"
#include <list>
#include <map>
#include <mutex>
#include <string>


class TcpBase : public IOThread
{
public:
	TcpBase(ServerTypeType serverType, const char* threadName, const char* addressName);
	virtual ~TcpBase();
	
	virtual bool Init() override;

	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) override;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;
protected:
	virtual void HandleTcpEvent() = 0;
	virtual void ThreadExit() override;

	virtual void DoDisConnect();
	virtual void DoRecv(TcpConnect* tcpConnect);
	virtual void AddConnect(TcpConnect* tcpConnect);
	virtual void RemoveConnect(TcpConnect* tcpConnect);
	virtual TcpConnect* GetConnect(SessionIDType sessionID);

	bool InitSocket(SOCKET socketID);
	SOCKET PrepareSocket(int family);

protected:
	std::string m_IP;
	std::string m_Port;
	addrinfo* m_AddressInfo;
	SOCKET m_Socket;
	

	std::map<SessionIDType, TcpConnect*> m_ConnectDatas;
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


