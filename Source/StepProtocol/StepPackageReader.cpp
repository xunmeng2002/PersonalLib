#include "StepPackageReader.h"
#include "MemCacheTemplateSingleton.h"
#include "Logger.h"
#include <stdio.h>
#include <cstring>


namespace step
{
	StepPackageReader::StepPackageReader()
		:m_StepPackageFactory(nullptr), m_SessionID(0LL)
	{
		memset(m_IPAddress, 0, sizeof(IPAddressType));
		memset(&m_Head, 0, sizeof(StepHeadField));
		memset(&m_Tail, 0, sizeof(StepTailField));
	}
	StepPackageReader::StepPackageReader(StepPackageFactoryBase* stepPackageFactory, SessionIDType sessionID, const char* ipAddress)
		:m_StepPackageFactory(stepPackageFactory), m_SessionID(sessionID)
	{
		strcpy(m_IPAddress, ipAddress);
		memset(&m_Head, 0, sizeof(StepHeadField));
		memset(&m_Tail, 0, sizeof(StepTailField));
	}
	StepPackageReader* StepPackageReader::Allocate(StepPackageFactoryBase* stepPackageFactory, SessionIDType sessionID, const char* ipAddress)
	{
		auto record = ::Allocate<StepPackageReader>();
		record->m_StepPackageFactory = stepPackageFactory;
		record->m_SessionID = sessionID;
		strcpy(record->m_IPAddress, ipAddress);
		memset(&(record->m_Head), 0, sizeof(StepHeadField));
		memset(&(record->m_Tail), 0, sizeof(StepTailField));
		return record;
	}
	void StepPackageReader::Free()
	{
		Reset();
		MemCacheTemplateSingleton<StepPackageReader>::GetInstance().Free(this);
	}
	bool StepPackageReader::ParsePackage(StepPackageBase*& stepPackage)
	{
		if (m_Length < StepHeaderLen)
		{
			return true;
		}
		int packageStartIndex = 0;
		if (!GetPackageStart(m_Data, 0, m_Length, packageStartIndex))
		{
			WriteLog(LogLevel::Warning, "Cannot Find PackageStart Mark.");
			return false;
		}
		if (m_Length - packageStartIndex < StepHeaderLen)
		{
			return true;
		}
		::memset(&m_Head, 0, sizeof(m_Head));
		if (!HeadFromStream(m_Data, packageStartIndex, packageStartIndex + StepHeaderLen, &m_Head))
		{
			WriteLog(LogLevel::Warning, "Parse Head Failed.");
			return false;
		}
		if ((m_Length - packageStartIndex) < (StepHeaderLen + m_Head.BodyLen + StepTailLen))
		{
			return true;
		}
		if (!TailFromStream(m_Data, packageStartIndex + StepHeaderLen + m_Head.BodyLen, packageStartIndex + StepHeaderLen + m_Head.BodyLen + StepTailLen, &m_Tail))
		{
			WriteLog(LogLevel::Warning, "Parse Tail Failed.");
			return false;
		}
		auto checkSum = CalculateSum((unsigned char*)m_Data, packageStartIndex, packageStartIndex + StepHeaderLen + m_Head.BodyLen);
		if (checkSum != m_Tail.CheckSum)
		{
			WriteLog(LogLevel::Warning, "CheckSum not Match. Tail.CheckSum:%d, CalculateSum:%d", m_Tail.CheckSum, checkSum);
			Reset();
			return false;
		}
		stepPackage = m_StepPackageFactory->CreateStepPackage(m_Head.PackageID);
		if (stepPackage == nullptr)
			return false;

		stepPackage->SessionID = m_SessionID;
		strcpy(stepPackage->IPAddress, m_IPAddress);
		memcpy(&stepPackage->Head, &m_Head, sizeof(StepHeadField));
		memcpy(&stepPackage->Tail, &m_Tail, sizeof(StepTailField));
		auto ret = stepPackage->FromProtocolStream(m_Data, packageStartIndex + StepHeaderLen, packageStartIndex + StepHeaderLen + m_Head.BodyLen);
		PopFront(packageStartIndex + StepHeaderLen + m_Head.BodyLen + StepTailLen);
		return ret;
	}
}
