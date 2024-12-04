#pragma once
#include "PackageReader.h"
#include "StepUtility.h"
#include "StepPackageFactoryBase.h"
#include <map>
#include <unordered_map>

namespace step
{
	class StepPackageReader : public PackageReader
	{
	public:
		StepPackageReader();
		StepPackageReader(StepPackageFactoryBase* stepPackageFactory, SessionIDType sessionID, const char* ipAddress);
		static StepPackageReader* Allocate(StepPackageFactoryBase* stepPackageFactory, SessionIDType sessionID, const char* ipAddress);
		void Free();
		bool ParsePackage(StepPackageBase*& stepPackage);

	public:
		StepPackageFactoryBase* m_StepPackageFactory;
		SessionIDType m_SessionID;
		IPAddressType m_IPAddress;
		HeadField m_Head;
		TailField m_Tail;
	};
}
