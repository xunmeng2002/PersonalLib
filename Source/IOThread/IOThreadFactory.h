#pragma once
#include "IOThread.h"


class IOThreadFactory
{
public:
	static IOThread* CreateIOThread(ServerTypeType serverType, IOTypeType ioType, const char* threadName, const char* addressName);
};



