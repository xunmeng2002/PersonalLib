#pragma once
#include "Package.h"

class PackageFactory
{
public:
	virtual Package* CreatePackage(UShortType packageID);
};
