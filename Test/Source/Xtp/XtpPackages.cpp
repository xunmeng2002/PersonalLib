#include "XtpPackages.h"
#include "XtpUtility.h"
#include "MemCacheTemplateSingleton.h"
#include <cstring>


namespace xtp
{
 
	XtpSessionClosePackage::XtpSessionClosePackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpSessionClosePackage* XtpSessionClosePackage::Allocate()
	{
		return ::Allocate<XtpSessionClosePackage>();
	}
	void XtpSessionClosePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpSessionClosePackage>::GetInstance().Free(this);
	}
	void XtpSessionClosePackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpSessionClosePackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpSessionClosePackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpSessionClosePackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpSessionClosePackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqOfferLoginPackage::XtpReqOfferLoginPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqOfferLoginPackage* XtpReqOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqOfferLoginPackage>();
	}
	void XtpReqOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqOfferLoginPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqOfferLoginPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqOfferLoginPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqOfferLoginPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspOfferLoginPackage::XtpRspOfferLoginPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspOfferLoginPackage* XtpRspOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspOfferLoginPackage>();
	}
	void XtpRspOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspOfferLoginPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspOfferLoginPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspOfferLoginPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspOfferLoginPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqPrimaryAccountLoginPackage::XtpReqPrimaryAccountLoginPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqPrimaryAccountLoginPackage* XtpReqPrimaryAccountLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountLoginPackage>();
	}
	void XtpReqPrimaryAccountLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqPrimaryAccountLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountLoginPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqPrimaryAccountLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqPrimaryAccountLoginPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqPrimaryAccountLoginPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqPrimaryAccountLoginPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspPrimaryAccountLoginPackage::XtpRspPrimaryAccountLoginPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspPrimaryAccountLoginPackage* XtpRspPrimaryAccountLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspPrimaryAccountLoginPackage>();
	}
	void XtpRspPrimaryAccountLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspPrimaryAccountLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspPrimaryAccountLoginPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspPrimaryAccountLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspPrimaryAccountLoginPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspPrimaryAccountLoginPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspPrimaryAccountLoginPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqPrimaryAccountLogoutPackage::XtpReqPrimaryAccountLogoutPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqPrimaryAccountLogoutPackage* XtpReqPrimaryAccountLogoutPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountLogoutPackage>();
	}
	void XtpReqPrimaryAccountLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqPrimaryAccountLogoutPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountLogoutPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqPrimaryAccountLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqPrimaryAccountLogoutPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqPrimaryAccountLogoutPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqPrimaryAccountLogoutPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnPrimaryAccountLogoutPackage::XtpRtnPrimaryAccountLogoutPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnPrimaryAccountLogoutPackage* XtpRtnPrimaryAccountLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRtnPrimaryAccountLogoutPackage>();
	}
	void XtpRtnPrimaryAccountLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnPrimaryAccountLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRtnPrimaryAccountLogoutPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnPrimaryAccountLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnPrimaryAccountLogoutPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnPrimaryAccountLogoutPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnPrimaryAccountLogoutPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqPrimaryAccountInitPackage::XtpReqPrimaryAccountInitPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqPrimaryAccountInitPackage* XtpReqPrimaryAccountInitPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountInitPackage>();
	}
	void XtpReqPrimaryAccountInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqPrimaryAccountInitPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountInitPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqPrimaryAccountInitPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqPrimaryAccountInitPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqPrimaryAccountInitPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqPrimaryAccountInitPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspPrimaryAccountInitPackage::XtpRspPrimaryAccountInitPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspPrimaryAccountInitPackage* XtpRspPrimaryAccountInitPackage::Allocate()
	{
		return ::Allocate<XtpRspPrimaryAccountInitPackage>();
	}
	void XtpRspPrimaryAccountInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspPrimaryAccountInitPackage>::GetInstance().Free(this);
	}
	void XtpRspPrimaryAccountInitPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspPrimaryAccountInitPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspPrimaryAccountInitPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspPrimaryAccountInitPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspPrimaryAccountInitPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqPrimaryAccountQueryPackage::XtpReqPrimaryAccountQueryPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqPrimaryAccountQueryPackage* XtpReqPrimaryAccountQueryPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountQueryPackage>();
	}
	void XtpReqPrimaryAccountQueryPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqPrimaryAccountQueryPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountQueryPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqPrimaryAccountQueryPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqPrimaryAccountQueryPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqPrimaryAccountQueryPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqPrimaryAccountQueryPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspPrimaryAccountQueryPackage::XtpRspPrimaryAccountQueryPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspPrimaryAccountQueryPackage* XtpRspPrimaryAccountQueryPackage::Allocate()
	{
		return ::Allocate<XtpRspPrimaryAccountQueryPackage>();
	}
	void XtpRspPrimaryAccountQueryPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspPrimaryAccountQueryPackage>::GetInstance().Free(this);
	}
	void XtpRspPrimaryAccountQueryPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspPrimaryAccountQueryPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspPrimaryAccountQueryPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspPrimaryAccountQueryPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspPrimaryAccountQueryPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqQryOptionInstrumentPackage::XtpReqQryOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqQryOptionInstrumentPackage* XtpReqQryOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpReqQryOptionInstrumentPackage>();
	}
	void XtpReqQryOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqQryOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpReqQryOptionInstrumentPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqQryOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqQryOptionInstrumentPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqQryOptionInstrumentPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqQryOptionInstrumentPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspQryOptionInstrumentPackage::XtpRspQryOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspQryOptionInstrumentPackage* XtpRspQryOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRspQryOptionInstrumentPackage>();
	}
	void XtpRspQryOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspQryOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRspQryOptionInstrumentPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspQryOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspQryOptionInstrumentPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspQryOptionInstrumentPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspQryOptionInstrumentPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnOptionInstrumentPackage::XtpRtnOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnOptionInstrumentPackage* XtpRtnOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRtnOptionInstrumentPackage>();
	}
	void XtpRtnOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRtnOptionInstrumentPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnOptionInstrumentPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnOptionInstrumentPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnOptionInstrumentPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqInsertOrderPackage::XtpReqInsertOrderPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqInsertOrderPackage* XtpReqInsertOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqInsertOrderPackage>();
	}
	void XtpReqInsertOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqInsertOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqInsertOrderPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqInsertOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqInsertOrderPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqInsertOrderPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqInsertOrderPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqCancelOrderPackage::XtpReqCancelOrderPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqCancelOrderPackage* XtpReqCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqCancelOrderPackage>();
	}
	void XtpReqCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqCancelOrderPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqCancelOrderPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqCancelOrderPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqCancelOrderPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnOrderPackage::XtpRtnOrderPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnOrderPackage* XtpRtnOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnOrderPackage>();
	}
	void XtpRtnOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnOrderPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnOrderPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnOrderPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnOrderPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnTradePackage::XtpRtnTradePackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnTradePackage* XtpRtnTradePackage::Allocate()
	{
		return ::Allocate<XtpRtnTradePackage>();
	}
	void XtpRtnTradePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnTradePackage>::GetInstance().Free(this);
	}
	void XtpRtnTradePackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnTradePackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnTradePackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnTradePackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnTradePackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnErrorCancelOrderPackage::XtpRtnErrorCancelOrderPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnErrorCancelOrderPackage* XtpRtnErrorCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnErrorCancelOrderPackage>();
	}
	void XtpRtnErrorCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnErrorCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnErrorCancelOrderPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnErrorCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnErrorCancelOrderPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnErrorCancelOrderPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnErrorCancelOrderPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnCapitalPackage::XtpRtnCapitalPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnCapitalPackage* XtpRtnCapitalPackage::Allocate()
	{
		return ::Allocate<XtpRtnCapitalPackage>();
	}
	void XtpRtnCapitalPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnCapitalPackage>::GetInstance().Free(this);
	}
	void XtpRtnCapitalPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnCapitalPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnCapitalPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnCapitalPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnCapitalPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnPositionPackage::XtpRtnPositionPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnPositionPackage* XtpRtnPositionPackage::Allocate()
	{
		return ::Allocate<XtpRtnPositionPackage>();
	}
	void XtpRtnPositionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnPositionPackage>::GetInstance().Free(this);
	}
	void XtpRtnPositionPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnPositionPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnPositionPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnPositionPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnPositionPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqMDOfferLoginPackage::XtpReqMDOfferLoginPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqMDOfferLoginPackage* XtpReqMDOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqMDOfferLoginPackage>();
	}
	void XtpReqMDOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqMDOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqMDOfferLoginPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqMDOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqMDOfferLoginPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqMDOfferLoginPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqMDOfferLoginPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspMDOfferLoginPackage::XtpRspMDOfferLoginPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspMDOfferLoginPackage* XtpRspMDOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspMDOfferLoginPackage>();
	}
	void XtpRspMDOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspMDOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspMDOfferLoginPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspMDOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspMDOfferLoginPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspMDOfferLoginPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspMDOfferLoginPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqMDInitPackage::XtpReqMDInitPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqMDInitPackage* XtpReqMDInitPackage::Allocate()
	{
		return ::Allocate<XtpReqMDInitPackage>();
	}
	void XtpReqMDInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqMDInitPackage>::GetInstance().Free(this);
	}
	void XtpReqMDInitPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqMDInitPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqMDInitPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqMDInitPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqMDInitPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspMDInitPackage::XtpRspMDInitPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspMDInitPackage* XtpRspMDInitPackage::Allocate()
	{
		return ::Allocate<XtpRspMDInitPackage>();
	}
	void XtpRspMDInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspMDInitPackage>::GetInstance().Free(this);
	}
	void XtpRspMDInitPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspMDInitPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspMDInitPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspMDInitPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspMDInitPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpReqSubscribeMDPackage::XtpReqSubscribeMDPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpReqSubscribeMDPackage* XtpReqSubscribeMDPackage::Allocate()
	{
		return ::Allocate<XtpReqSubscribeMDPackage>();
	}
	void XtpReqSubscribeMDPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpReqSubscribeMDPackage>::GetInstance().Free(this);
	}
	void XtpReqSubscribeMDPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpReqSubscribeMDPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpReqSubscribeMDPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpReqSubscribeMDPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpReqSubscribeMDPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspSubscribeMDPackage::XtpRspSubscribeMDPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspSubscribeMDPackage* XtpRspSubscribeMDPackage::Allocate()
	{
		return ::Allocate<XtpRspSubscribeMDPackage>();
	}
	void XtpRspSubscribeMDPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspSubscribeMDPackage>::GetInstance().Free(this);
	}
	void XtpRspSubscribeMDPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspSubscribeMDPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspSubscribeMDPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspSubscribeMDPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspSubscribeMDPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnShortMDPackage::XtpRtnShortMDPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnShortMDPackage* XtpRtnShortMDPackage::Allocate()
	{
		return ::Allocate<XtpRtnShortMDPackage>();
	}
	void XtpRtnShortMDPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnShortMDPackage>::GetInstance().Free(this);
	}
	void XtpRtnShortMDPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnShortMDPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnShortMDPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnShortMDPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnShortMDPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnExchangeStatusPackage::XtpRtnExchangeStatusPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnExchangeStatusPackage* XtpRtnExchangeStatusPackage::Allocate()
	{
		return ::Allocate<XtpRtnExchangeStatusPackage>();
	}
	void XtpRtnExchangeStatusPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnExchangeStatusPackage>::GetInstance().Free(this);
	}
	void XtpRtnExchangeStatusPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnExchangeStatusPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnExchangeStatusPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnExchangeStatusPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnExchangeStatusPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnInstrumentPackage::XtpRtnInstrumentPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnInstrumentPackage* XtpRtnInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRtnInstrumentPackage>();
	}
	void XtpRtnInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRtnInstrumentPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnInstrumentPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnInstrumentPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnInstrumentPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnMDInitCompletedPackage::XtpRtnMDInitCompletedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnMDInitCompletedPackage* XtpRtnMDInitCompletedPackage::Allocate()
	{
		return ::Allocate<XtpRtnMDInitCompletedPackage>();
	}
	void XtpRtnMDInitCompletedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnMDInitCompletedPackage>::GetInstance().Free(this);
	}
	void XtpRtnMDInitCompletedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnMDInitCompletedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnMDInitCompletedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnMDInitCompletedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnMDInitCompletedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyMdClientConnectedPackage::XtpNotifyMdClientConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyMdClientConnectedPackage* XtpNotifyMdClientConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyMdClientConnectedPackage>();
	}
	void XtpNotifyMdClientConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyMdClientConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyMdClientConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyMdClientConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyMdClientConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyMdClientConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyMdClientConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyMdClientDisConnectedPackage::XtpNotifyMdClientDisConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyMdClientDisConnectedPackage* XtpNotifyMdClientDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyMdClientDisConnectedPackage>();
	}
	void XtpNotifyMdClientDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyMdClientDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyMdClientDisConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyMdClientDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyMdClientDisConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyMdClientDisConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyMdClientDisConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyRiskCheckClientConnectedPackage::XtpNotifyRiskCheckClientConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyRiskCheckClientConnectedPackage* XtpNotifyRiskCheckClientConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskCheckClientConnectedPackage>();
	}
	void XtpNotifyRiskCheckClientConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyRiskCheckClientConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskCheckClientConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyRiskCheckClientConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyRiskCheckClientConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyRiskCheckClientConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyRiskCheckClientConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyRiskCheckClientDisConnectedPackage::XtpNotifyRiskCheckClientDisConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyRiskCheckClientDisConnectedPackage* XtpNotifyRiskCheckClientDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskCheckClientDisConnectedPackage>();
	}
	void XtpNotifyRiskCheckClientDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyRiskCheckClientDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskCheckClientDisConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyRiskCheckClientDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyRiskCheckClientDisConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyRiskCheckClientDisConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyRiskCheckClientDisConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyTradeFrontConnectedPackage::XtpNotifyTradeFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyTradeFrontConnectedPackage* XtpNotifyTradeFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyTradeFrontConnectedPackage>();
	}
	void XtpNotifyTradeFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyTradeFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyTradeFrontConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyTradeFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyTradeFrontConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyTradeFrontConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyTradeFrontConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyTradeFrontDisConnectedPackage::XtpNotifyTradeFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyTradeFrontDisConnectedPackage* XtpNotifyTradeFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyTradeFrontDisConnectedPackage>();
	}
	void XtpNotifyTradeFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyTradeFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyTradeFrontDisConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyTradeFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyTradeFrontDisConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyTradeFrontDisConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyTradeFrontDisConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyRiskFrontConnectedPackage::XtpNotifyRiskFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyRiskFrontConnectedPackage* XtpNotifyRiskFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskFrontConnectedPackage>();
	}
	void XtpNotifyRiskFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyRiskFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskFrontConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyRiskFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyRiskFrontConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyRiskFrontConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyRiskFrontConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyRiskFrontDisConnectedPackage::XtpNotifyRiskFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyRiskFrontDisConnectedPackage* XtpNotifyRiskFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskFrontDisConnectedPackage>();
	}
	void XtpNotifyRiskFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyRiskFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskFrontDisConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyRiskFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyRiskFrontDisConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyRiskFrontDisConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyRiskFrontDisConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyAdminFrontConnectedPackage::XtpNotifyAdminFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyAdminFrontConnectedPackage* XtpNotifyAdminFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyAdminFrontConnectedPackage>();
	}
	void XtpNotifyAdminFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyAdminFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyAdminFrontConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyAdminFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyAdminFrontConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyAdminFrontConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyAdminFrontConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyAdminFrontDisConnectedPackage::XtpNotifyAdminFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyAdminFrontDisConnectedPackage* XtpNotifyAdminFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyAdminFrontDisConnectedPackage>();
	}
	void XtpNotifyAdminFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyAdminFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyAdminFrontDisConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyAdminFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyAdminFrontDisConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyAdminFrontDisConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyAdminFrontDisConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyOfferFrontConnectedPackage::XtpNotifyOfferFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyOfferFrontConnectedPackage* XtpNotifyOfferFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyOfferFrontConnectedPackage>();
	}
	void XtpNotifyOfferFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyOfferFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyOfferFrontConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyOfferFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyOfferFrontConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyOfferFrontConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyOfferFrontConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyOfferFrontDisConnectedPackage::XtpNotifyOfferFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyOfferFrontDisConnectedPackage* XtpNotifyOfferFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyOfferFrontDisConnectedPackage>();
	}
	void XtpNotifyOfferFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyOfferFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyOfferFrontDisConnectedPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyOfferFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyOfferFrontDisConnectedPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyOfferFrontDisConnectedPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyOfferFrontDisConnectedPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpNotifyInitCompletePackage::XtpNotifyInitCompletePackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpNotifyInitCompletePackage* XtpNotifyInitCompletePackage::Allocate()
	{
		return ::Allocate<XtpNotifyInitCompletePackage>();
	}
	void XtpNotifyInitCompletePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpNotifyInitCompletePackage>::GetInstance().Free(this);
	}
	void XtpNotifyInitCompletePackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpNotifyInitCompletePackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpNotifyInitCompletePackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpNotifyInitCompletePackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpNotifyInitCompletePackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRspNotifyInitCompletePackage::XtpRspNotifyInitCompletePackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRspNotifyInitCompletePackage* XtpRspNotifyInitCompletePackage::Allocate()
	{
		return ::Allocate<XtpRspNotifyInitCompletePackage>();
	}
	void XtpRspNotifyInitCompletePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRspNotifyInitCompletePackage>::GetInstance().Free(this);
	}
	void XtpRspNotifyInitCompletePackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRspNotifyInitCompletePackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRspNotifyInitCompletePackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRspNotifyInitCompletePackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRspNotifyInitCompletePackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
 
	XtpRtnRiskCheckOrderPackage::XtpRtnRiskCheckOrderPackage()
	{
		Head.PackageID = PackageID;
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
	}
	XtpRtnRiskCheckOrderPackage* XtpRtnRiskCheckOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnRiskCheckOrderPackage>();
	}
	void XtpRtnRiskCheckOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		Head.BodyLen = 0;
		Tail.CheckSum = 0;
		memset(&Field, 0, sizeof(Field));
		MemCacheTemplateSingleton<XtpRtnRiskCheckOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnRiskCheckOrderPackage::Prepare(SessionIDType sessionID)
	{
		SessionID = sessionID;
	}
	int XtpRtnRiskCheckOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		memcpy(buff, &Field, sizeof(Field));
		return sizeof(Field);
	}
	bool XtpRtnRiskCheckOrderPackage::FromProtocolStream(char* buff, int size)
	{
		if (size != sizeof(Field))
		{
			return false;
		}
		memcpy(&Field, buff, sizeof(Field));
		return true;
	}
	const char* XtpRtnRiskCheckOrderPackage::GetString() const
	{
		return Field.GetString();
	}
	const char* XtpRtnRiskCheckOrderPackage::GetDebugString() const
	{
		return Field.GetDebugString();
	}
	
}
