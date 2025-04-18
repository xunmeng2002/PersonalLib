#pragma once
#include "TcpIocpBase.h"

class TcpIocpServer : public TcpIocpBase
{
public:
	TcpIocpServer(const char* addressName, int milliSeconds, int backlog = 5);
};

