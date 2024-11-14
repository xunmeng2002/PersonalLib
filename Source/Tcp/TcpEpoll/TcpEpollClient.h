#pragma once
#include "TcpEpollBase.h"
#include "TcpClientBase.h"


class TcpEpollClient : public TcpEpollBase, public TcpClientBase
{
public:
	TcpEpollClient(const char* threadName, const char* addressName);
	~TcpEpollClient();

	//override TcpBase
	virtual void HandleTcpEvent() override;
protected:
	//override TcpBase
	virtual void AddConnect(ConnectData* connectData) override;
	//override TcpClientBase
	virtual void RemoveConnect(ConnectData* connectData) override;
};
