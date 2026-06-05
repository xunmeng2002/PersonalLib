#pragma once
#include "NetworkExport.h"
#include "PersonalLib/Network/Tcp/TcpSelect/TcpSelectBase.h"


class NETWORK_EXPORTS TcpSelectServer : public TcpSelectBase
{
public:
	TcpSelectServer(const char* addressName, int milliSeconds);
};