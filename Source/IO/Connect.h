#pragma once
#include "Types.h"

class Connect
{
public:
	virtual void Free() = 0;

	SessionIDType SessionID;
	char RemoteAddress[40];
	int RemotePort;
};


