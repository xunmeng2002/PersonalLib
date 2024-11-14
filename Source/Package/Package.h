#pragma once
#include <stdint.h>
#include "Types.h"


#define MaxPackageSize 2 * 64 * 1024


class Package
{
public:
	Package(PackageTypeType packageType)
		:PackageType(packageType), SessionID(0), IPAddress{0}
	{}
	virtual void Free() = 0;

public:
	PackageTypeType PackageType;
	SessionIDType SessionID;
	IPAddressType IPAddress;
};

