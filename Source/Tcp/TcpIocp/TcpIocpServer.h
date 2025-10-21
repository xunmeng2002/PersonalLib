#pragma once
#include "TcpIocpBase.h"

class TcpIocpServer : public TcpIocpBase
{
public:
	TcpIocpServer(const char* addressName, int milliSeconds, int backlog = 5);

protected:
	virtual bool PostAccept() override;
	virtual void OnAcceptComplete(MyOverlapped* overlapped) override;

	SOCKET PrepareAcceptSocket();
};

