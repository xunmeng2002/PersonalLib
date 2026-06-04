#pragma once
#include "Network/Tcp/TcpSelect/TcpSelectBase.h"


class TcpSelectServer : public TcpSelectBase
{
public:
	TcpSelectServer(const char* addressName, int milliSeconds);
};