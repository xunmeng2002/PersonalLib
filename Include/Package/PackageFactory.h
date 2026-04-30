#pragma once
#include "Package/Package.h"

class PackageFactory
{
public:
	virtual Package* CreatePackage(UShortType packageID);
};
