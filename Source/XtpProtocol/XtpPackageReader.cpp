#include "XtpPackageReader.h"
#include "XtpUtility.h"
#include "MemCacheTemplateSingleton.h"
#include "Logger.h"
#include <stdio.h>
#include <cstring>


namespace xtp
{
	XtpPackageReader::XtpPackageReader()
		:m_XtpPackageFactory(nullptr), m_SessionID(0LL)
	{
		memset(m_IPAddress, 0, sizeof(IPAddressType));
		memset(&m_Head, 0, sizeof(HeadField));
		memset(&m_Tail, 0, sizeof(TailField));
	}
	XtpPackageReader::XtpPackageReader(XtpPackageFactoryBase* xtpPackageFactory, SessionIDType sessionID, const char* ipAddress)
		:m_XtpPackageFactory(xtpPackageFactory), m_SessionID(sessionID)
	{
		strcpy(m_IPAddress, ipAddress);
		memset(&m_Head, 0, sizeof(HeadField));
		memset(&m_Tail, 0, sizeof(TailField));
	}
	XtpPackageReader* XtpPackageReader::Allocate(XtpPackageFactoryBase* xtpPackageFactory, SessionIDType sessionID, const char* ipAddress)
	{
		auto record = ::Allocate<XtpPackageReader>();
		record->m_XtpPackageFactory = xtpPackageFactory;
		record->m_Data = record->m_Buff;
		record->m_Length = 0;
		record->m_SessionID = sessionID;
		strcpy(record->m_IPAddress, ipAddress);
		memset(&(record->m_Head), 0, sizeof(HeadField));
		memset(&(record->m_Tail), 0, sizeof(TailField));
		return record;
	}
	void XtpPackageReader::Free()
	{
		Reset();
		MemCacheTemplateSingleton<XtpPackageReader>::GetInstance().Free(this);
	}
	bool XtpPackageReader::ParsePackage(XtpPackageBase*& xtpPackage)
	{
		if (m_Length < sizeof(HeadField))
			return true;
		memcpy(&m_Head, m_Data, sizeof(HeadField));
		if (m_Length < (m_Head.BodyLen + sizeof(HeadField) + sizeof(TailField)))
		{
			return true;
		}
		memcpy(&m_Tail, m_Data + sizeof(HeadField) + m_Head.BodyLen, sizeof(m_Tail));
		auto checkSum = CalculateSum((unsigned char*)m_Data, m_Head.BodyLen + sizeof(HeadField));
		if (checkSum != m_Tail.CheckSum)
		{
			WriteLog(LogLevel::Error, "CheckSum not Match. Tail.CheckSum:%d, CalculateSum:%d", m_Tail.CheckSum, checkSum);
			Reset();
			return false;
		}
		xtpPackage = m_XtpPackageFactory->CreateXtpPackage(m_Head.PackageID);
		if (xtpPackage == nullptr)
			return false;

		xtpPackage->SessionID = m_SessionID;
		strcpy(xtpPackage->IPAddress, m_IPAddress);
		xtpPackage->Head = m_Head;
		xtpPackage->Tail = m_Tail;
		auto ret = xtpPackage->FromProtocolStream(m_Data + sizeof(HeadField), m_Head.BodyLen);
		PopFront(sizeof(HeadField) + m_Head.BodyLen + sizeof(TailField));
		return ret;
	}
}
