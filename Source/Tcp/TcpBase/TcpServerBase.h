#pragma once
#include "TcpBase.h"



class TcpServerBase : public TcpBase
{
public:
	TcpServerBase(const char* threadName, const char* addressName);
	virtual ~TcpServerBase();
	
	virtual bool Init() override;

protected:
	virtual void DoAccept();

	//override ThreadBase
	virtual void Run() override;

protected:
	SOCKET m_ListenSocket;
	addrinfo* m_BindAddressInfo;
	std::string m_BindIP;
	std::string m_BindPort;
};

