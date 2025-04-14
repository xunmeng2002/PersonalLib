#pragma once
#include "IOThread.h"


class IOThreadFactory
{
public:
	static IOThread* CreateIOThread(ServerTypeType serverType, const char* threadName, const char* address, int milliSeconds = 100);
};



