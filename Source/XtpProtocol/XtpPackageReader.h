#pragma once
#include "PackageReader.h"
#include "XtpPackageFactoryBase.h"
#include <map>
#include <unordered_map>

namespace xtp
{
	class XtpPackageReader : public PackageReader
	{
	public:
		XtpPackageReader();
		XtpPackageReader(XtpPackageFactoryBase* xtpPackageFactory, SessionIDType sessionID, const char* ipAddress);
		static XtpPackageReader* Allocate(XtpPackageFactoryBase* stepPackageFactory, SessionIDType sessionID, const char* ipAddress);
		void Free();
		bool ParsePackage(XtpPackageBase*& xtpPackage);

	public:
		XtpPackageFactoryBase* m_XtpPackageFactory;
		SessionIDType m_SessionID;
		IPAddressType m_IPAddress;
		HeadField m_Head;
		TailField m_Tail;
	};
}
