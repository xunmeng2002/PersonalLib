#pragma once
#include "NetworkExport.h"
#include "PersonalLib/Network/Protocol/Package.h"

class PackageFactory
{
public:
	virtual Package* CreatePackage(UShortType packageID);
};
