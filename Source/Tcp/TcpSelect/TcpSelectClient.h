#pragma once
#include "TcpSelectBase.h"


class TcpSelectClient : public TcpSelectBase
{
public:
	TcpSelectClient(const char* addressName, int milliSeconds);
};

