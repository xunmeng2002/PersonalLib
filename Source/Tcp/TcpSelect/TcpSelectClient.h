#pragma once
#include "TcpSelectBase.h"
#include "TcpClientBase.h"


class TcpSelectClient : public TcpSelectBase, public TcpClientBase
{
public:
	TcpSelectClient(const char* threadName, const char* addressName = "");
	
	//override TcpBase
	virtual void HandleTcpEvent() override;

protected:
	//override TcpSelectBase
	virtual void PrepareFds() override;
};

