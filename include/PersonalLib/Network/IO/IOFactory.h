#pragma once
#include "PersonalLib/Network/IO/IOBase.h"


class IOFactory
{
public:
	static IOBase* CreateIO(ServerTypeType serverType, const char* address, int milliSeconds = 100);
};



