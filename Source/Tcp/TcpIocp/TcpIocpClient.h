#pragma once
#include "TcpIocpBase.h"


class TcpIocpClient : public TcpIocpBase
{
public:
	TcpIocpClient(const char* localAddressName, const char* remoteAddressName, int milliSeconds, int backlog = 5);

	virtual bool Init() override;
	virtual bool PostConnect() override;
	virtual void DoConnect(MyOverlapped* overlapped) override;
protected:
	SOCKET PrepareConnectSocket();

private:
	std::string	m_RemoteAddressName;
	std::string m_RemoteAddress;
	std::string m_RemotePort;
	addrinfo* m_RemoteAddressInfo;
};

