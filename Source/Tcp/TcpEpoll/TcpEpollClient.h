#pragma once
#include "TcpEpollBase.h"


class TcpEpollClient : public TcpEpollBase
{
public:
	TcpEpollClient(const char* threadName, const char* addressName, int milliSeconds);
	~TcpEpollClient();
};
