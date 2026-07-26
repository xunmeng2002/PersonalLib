#pragma once
#include <Spark/Network/NetworkExport.h>
#include <Spark/Network/Protocol/Package.h>

class PackageFactory
{
public:
	virtual Package* CreatePackage(UShortType packageID);
};
