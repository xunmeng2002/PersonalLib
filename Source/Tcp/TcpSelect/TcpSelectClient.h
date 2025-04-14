#pragma once
#include "TcpSelectBase.h"


class TcpSelectClient : public TcpSelectBase
{
public:
	TcpSelectClient(const char* threadName, const char* addressName, int milliSeconds);
};

