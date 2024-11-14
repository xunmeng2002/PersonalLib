#pragma once
#include "TcpEpollBase.h"
#include "TcpServerBase.h"


class TcpEpollServer : public TcpEpollBase, public TcpServerBase
{
public:
	TcpEpollServer(const char* threadName, const char* addressName);
	~TcpEpollServer();

	//override TcpBase
	virtual bool Init() override;
	virtual void HandleTcpEvent() override;

protected:
	virtual void AddConnect(ConnectData* connectData) override;
	virtual void RemoveConnect(ConnectData* connectData) override;
};
