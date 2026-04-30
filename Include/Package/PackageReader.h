#pragma once
#include "Package/Package.h"
#include "Package/PackageFactory.h"


class PackageReader
{
public:
	PackageReader();
	~PackageReader();
	static PackageReader* Allocate(ProtocolTypeType protocolType, PackageFactory* packageFactory, SessionIDType sessionID, const char* ipAddress);
	void Free();

	void Reset();
	void PopFront(unsigned int len);
	char* Data();
	int Length();
	char* Tail();
	unsigned int TailSize();
	void Shift(unsigned int len);
	unsigned int Append(char* data, unsigned  int len);

	bool ParsePackage(Package*& package);

protected:
	bool ParseXtpPackage(Package*& package);
	bool ParseStepPackage(Package*& package);

protected:
	ProtocolTypeType m_ProtocolType;
	PackageFactory* m_PackageFactory;
	SessionIDType m_SessionID;
	IPAddressType m_IPAddress;
	HeadField m_Head;
	TailField m_Tail;

	char m_Buff[MaxPackageSize * 2];
	char* m_Data;
	unsigned int m_Length;
};

