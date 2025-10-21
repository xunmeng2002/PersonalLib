#pragma once
#include "TcpIocpBase.h"


class TcpIocpClient : public TcpIocpBase
{
public:
	TcpIocpClient(const char* localAddressName, const char* remoteAddressName, int milliSeconds, int backlog = 5);

	virtual bool Init() override;
	virtual bool ConnectToServer(const char* ip, unsigned short port) override;
protected:
	virtual bool PostConnect() override;
	virtual void OnConnectComplete(MyOverlapped* overlapped) override;

	SOCKET PrepareConnectSocket();

private:
	std::string m_RemoteAddress;
	std::string m_RemotePort;
	addrinfo* m_RemoteAddressInfo;
};

