#pragma once
#include <stdint.h>
#include "Types.h"
#include "Head.h"

#define MaxPackageSize 2 * 64 * 1024


class Package
{
public:
	Package(PackageTypeType packageType)
		:PackageType(packageType), SessionID(0), IPAddress{0}
	{}
	virtual void Free() = 0;
	virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) = 0;
	virtual int MakePackage(char* buff, int size) = 0;
	virtual int ToProtocolStream(char* buff, int size) const = 0;
	virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) = 0;
	virtual const char* GetDebugString() const = 0;

public:
	PackageTypeType PackageType;
	SessionIDType SessionID;
	IPAddressType IPAddress;

	HeadField Head;
	TailField Tail;
};

