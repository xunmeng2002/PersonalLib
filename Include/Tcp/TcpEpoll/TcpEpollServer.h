#pragma once
#include "TcpEpollBase.h"


class TcpEpollServer : public TcpEpollBase
{
public:
	TcpEpollServer(const char* addressName, int milliSeconds);
	~TcpEpollServer();

	virtual bool Init() override;

};
