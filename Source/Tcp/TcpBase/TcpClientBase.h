#pragma once
#include <list>
#include <mutex>
#include "SocketInit.h"
#include "TcpBase.h"



class TcpClientBase : public TcpBase
{
public:
	TcpClientBase(const char* threadName, const char* addressName = "");
	virtual bool Init() override;

	void SetConnectAddress(const char* addressName);
	virtual void CheckClientConnect();
protected:
	virtual bool Connect();


	//override ThreadBase
	virtual void Run() override;
	//override TcpBase
	virtual void RemoveConnect(ConnectData* connectData) override;

protected:
	std::string m_ConnectIP;
	std::string m_ConnectPort;
	addrinfo* m_ConnectAddressInfo;
	bool m_ConnectStatus;
};


