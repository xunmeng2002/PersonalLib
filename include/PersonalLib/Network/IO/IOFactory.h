#pragma once
#include "NetworkExport.h"
#include "PersonalLib/Network/IO/IOBase.h"


class NETWORK_EXPORTS IOFactory
{
public:
	static IOBase* CreateIO(ServerTypeType serverType, const char* address, int milliSeconds = 100);
};



