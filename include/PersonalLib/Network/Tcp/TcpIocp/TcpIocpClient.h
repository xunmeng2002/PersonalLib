#pragma once
#include <PersonalLib/Network/NetworkExport.h>
#include <PersonalLib/Network/Tcp/TcpIocp/TcpIocpBase.h>


class NETWORK_EXPORTS TcpIocpClient : public TcpIocpBase
{
public:
	TcpIocpClient(const char* addressName, int milliSeconds, int backlog = 5);

	virtual bool Init() override;
	virtual bool ConnectToServer(const char* ip, unsigned short port) override;
protected:
	virtual bool PostConnect() override;
	virtual void OnConnectComplete(MyOverlapped* overlapped) override;

	SOCKET PrepareConnectSocket();

private:
	addrinfo* m_ClientLocalAddressInfo;
};

