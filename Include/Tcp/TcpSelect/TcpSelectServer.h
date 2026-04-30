#pragma once
#include "TcpSelectBase.h"


class TcpSelectServer : public TcpSelectBase
{
public:
	TcpSelectServer(const char* addressName, int milliSeconds);
};