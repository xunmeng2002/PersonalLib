#pragma once
#include <PersonalLib/Network/NetworkExport.h>
#include <PersonalLib/Network/Tcp/TcpIocp/TcpIocpBase.h>

class NETWORK_EXPORTS TcpIocpServer : public TcpIocpBase
{
public:
	TcpIocpServer(const char* addressName, int milliSeconds, int backlog = 5);
	virtual bool Init() override;

protected:
	virtual bool PostAccept() override;
	virtual void OnAcceptComplete(MyOverlapped* overlapped) override;

	SOCKET PrepareAcceptSocket();
};

