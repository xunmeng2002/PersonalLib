#pragma once
#include "TcpSelectBase.h"
#include "TcpServerBase.h"


class TcpSelectServer : public TcpSelectBase, public TcpServerBase
{
public:
	TcpSelectServer(const char* threadName, const char* addressName);

	//override TcpBase
	virtual void HandleTcpEvent() override;
protected:
	//override TcpSelectBase
	virtual void PrepareFds() override;
};