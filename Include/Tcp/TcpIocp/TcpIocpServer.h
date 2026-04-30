#pragma once
#include "Tcp/TcpIocp/TcpIocpBase.h"

class TcpIocpServer : public TcpIocpBase
{
public:
	TcpIocpServer(const char* addressName, int milliSeconds, int backlog = 5);
	virtual bool Init() override;

protected:
	virtual bool PostAccept() override;
	virtual void OnAcceptComplete(MyOverlapped* overlapped) override;

	SOCKET PrepareAcceptSocket();
};

