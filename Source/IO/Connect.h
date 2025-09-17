#pragma once
#include "Types.h"

struct Connect
{
public:
	virtual void Free() = 0;

	SessionIDType SessionID;
	ConnectStatusType ConnectStatus;
	char RemoteAddress[40];
	int RemotePort;
};


