#pragma once
#include "TcpEpollBase.h"


class TcpEpollServer : public TcpEpollBase
{
public:
	TcpEpollServer(const char* threadName, const char* addressName);
	~TcpEpollServer();

	virtual bool Init() override;

};
