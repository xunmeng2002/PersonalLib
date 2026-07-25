#pragma once
#include <PersonalLib/Network/NetworkExport.h>
#include <PersonalLib/Network/IO/IOBase.h>


class NETWORK_EXPORTS IOFactory
{
public:
	static IOBase* CreateIO(ServerTypeType serverType, const char* address,  IOModelType ioModel = IOModelType::Select, int milliSeconds = 100);
};



