#include "XtpPackages.h"
#include "MemCacheTemplateSingleton.h"
#include <cstring>

thread_local char t_XtpDataStringBuffer[10240];


namespace xtp
{
 
	XtpReqOfferLoginPackage::XtpReqOfferLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqOfferLoginPackage* XtpReqOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqOfferLoginPackage>();
	}
	void XtpReqOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqOfferLogin != nullptr)
		{
			::Free<XtpReqOfferLoginField>(ReqOfferLogin);
			ReqOfferLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqOfferLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqOfferLogin, sizeof(XtpReqOfferLoginField));
		offset += sizeof(XtpReqOfferLoginField);
		return offset;
	}
	bool XtpReqOfferLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqOfferLogin = ::Allocate<XtpReqOfferLoginField>();
		memcpy(ReqOfferLogin, buff + offset, sizeof(XtpReqOfferLoginField));
		offset += sizeof(XtpReqOfferLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqOfferLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqOfferLogin:OfferID:[%d], OfferPassword:[%s]",
			ReqOfferLogin->OfferID, ReqOfferLogin->OfferPassword);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspOfferLoginPackage::XtpRspOfferLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspOfferLoginPackage* XtpRspOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspOfferLoginPackage>();
	}
	void XtpRspOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspOfferLogin != nullptr)
		{
			::Free<XtpRspOfferLoginField>(RspOfferLogin);
			RspOfferLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspOfferLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspOfferLogin, sizeof(XtpRspOfferLoginField));
		offset += sizeof(XtpRspOfferLoginField);
		return offset;
	}
	bool XtpRspOfferLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspOfferLogin = ::Allocate<XtpRspOfferLoginField>();
		memcpy(RspOfferLogin, buff + offset, sizeof(XtpRspOfferLoginField));
		offset += sizeof(XtpRspOfferLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspOfferLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspOfferLogin:ErrorID:[%d], ErrorMsg:[%s], OfferID:[%d], TradingDay:[%s]",
			RspOfferLogin->ErrorID, RspOfferLogin->ErrorMsg, RspOfferLogin->OfferID, RspOfferLogin->TradingDay);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqPrimaryAccountLoginPackage::XtpReqPrimaryAccountLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqPrimaryAccountLoginPackage* XtpReqPrimaryAccountLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountLoginPackage>();
	}
	void XtpReqPrimaryAccountLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqPrimaryAccountLogin != nullptr)
		{
			::Free<XtpReqPrimaryAccountLoginField>(ReqPrimaryAccountLogin);
			ReqPrimaryAccountLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqPrimaryAccountLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqPrimaryAccountLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqPrimaryAccountLogin, sizeof(XtpReqPrimaryAccountLoginField));
		offset += sizeof(XtpReqPrimaryAccountLoginField);
		return offset;
	}
	bool XtpReqPrimaryAccountLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountLogin = ::Allocate<XtpReqPrimaryAccountLoginField>();
		memcpy(ReqPrimaryAccountLogin, buff + offset, sizeof(XtpReqPrimaryAccountLoginField));
		offset += sizeof(XtpReqPrimaryAccountLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqPrimaryAccountLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqPrimaryAccountLogin:PrimaryAccountID:[%s], Password:[%s]",
			ReqPrimaryAccountLogin->PrimaryAccountID, ReqPrimaryAccountLogin->Password);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspPrimaryAccountLoginPackage::XtpRspPrimaryAccountLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspPrimaryAccountLoginPackage* XtpRspPrimaryAccountLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspPrimaryAccountLoginPackage>();
	}
	void XtpRspPrimaryAccountLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspPrimaryAccountLogin != nullptr)
		{
			::Free<XtpRspPrimaryAccountLoginField>(RspPrimaryAccountLogin);
			RspPrimaryAccountLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspPrimaryAccountLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspPrimaryAccountLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspPrimaryAccountLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspPrimaryAccountLogin, sizeof(XtpRspPrimaryAccountLoginField));
		offset += sizeof(XtpRspPrimaryAccountLoginField);
		return offset;
	}
	bool XtpRspPrimaryAccountLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspPrimaryAccountLogin = ::Allocate<XtpRspPrimaryAccountLoginField>();
		memcpy(RspPrimaryAccountLogin, buff + offset, sizeof(XtpRspPrimaryAccountLoginField));
		offset += sizeof(XtpRspPrimaryAccountLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspPrimaryAccountLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspPrimaryAccountLogin:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s]",
			RspPrimaryAccountLogin->ErrorID, RspPrimaryAccountLogin->ErrorMsg, RspPrimaryAccountLogin->TradingDay, RspPrimaryAccountLogin->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqPrimaryAccountLogoutPackage::XtpReqPrimaryAccountLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqPrimaryAccountLogoutPackage* XtpReqPrimaryAccountLogoutPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountLogoutPackage>();
	}
	void XtpReqPrimaryAccountLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqPrimaryAccountLogout != nullptr)
		{
			::Free<XtpReqPrimaryAccountLogoutField>(ReqPrimaryAccountLogout);
			ReqPrimaryAccountLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqPrimaryAccountLogoutPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqPrimaryAccountLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqPrimaryAccountLogout, sizeof(XtpReqPrimaryAccountLogoutField));
		offset += sizeof(XtpReqPrimaryAccountLogoutField);
		return offset;
	}
	bool XtpReqPrimaryAccountLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountLogout = ::Allocate<XtpReqPrimaryAccountLogoutField>();
		memcpy(ReqPrimaryAccountLogout, buff + offset, sizeof(XtpReqPrimaryAccountLogoutField));
		offset += sizeof(XtpReqPrimaryAccountLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqPrimaryAccountLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqPrimaryAccountLogout:TradingDay:[%s], PrimaryAccountID:[%s]",
			ReqPrimaryAccountLogout->TradingDay, ReqPrimaryAccountLogout->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnPrimaryAccountLogoutPackage::XtpRtnPrimaryAccountLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnPrimaryAccountLogoutPackage* XtpRtnPrimaryAccountLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRtnPrimaryAccountLogoutPackage>();
	}
	void XtpRtnPrimaryAccountLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnPrimaryAccountLogout != nullptr)
		{
			::Free<XtpRtnPrimaryAccountLogoutField>(RtnPrimaryAccountLogout);
			RtnPrimaryAccountLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnPrimaryAccountLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRtnPrimaryAccountLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnPrimaryAccountLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnPrimaryAccountLogout, sizeof(XtpRtnPrimaryAccountLogoutField));
		offset += sizeof(XtpRtnPrimaryAccountLogoutField);
		return offset;
	}
	bool XtpRtnPrimaryAccountLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnPrimaryAccountLogout = ::Allocate<XtpRtnPrimaryAccountLogoutField>();
		memcpy(RtnPrimaryAccountLogout, buff + offset, sizeof(XtpRtnPrimaryAccountLogoutField));
		offset += sizeof(XtpRtnPrimaryAccountLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnPrimaryAccountLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnPrimaryAccountLogout:TradingDay:[%s], PrimaryAccountID:[%s]",
			RtnPrimaryAccountLogout->TradingDay, RtnPrimaryAccountLogout->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqPrimaryAccountInitPackage::XtpReqPrimaryAccountInitPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqPrimaryAccountInitPackage* XtpReqPrimaryAccountInitPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountInitPackage>();
	}
	void XtpReqPrimaryAccountInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqPrimaryAccountInit != nullptr)
		{
			::Free<XtpReqPrimaryAccountInitField>(ReqPrimaryAccountInit);
			ReqPrimaryAccountInit = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqPrimaryAccountInitPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountInitPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqPrimaryAccountInitPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqPrimaryAccountInit, sizeof(XtpReqPrimaryAccountInitField));
		offset += sizeof(XtpReqPrimaryAccountInitField);
		return offset;
	}
	bool XtpReqPrimaryAccountInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountInit = ::Allocate<XtpReqPrimaryAccountInitField>();
		memcpy(ReqPrimaryAccountInit, buff + offset, sizeof(XtpReqPrimaryAccountInitField));
		offset += sizeof(XtpReqPrimaryAccountInitField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqPrimaryAccountInitPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqPrimaryAccountInit:PrimaryAccountID:[%s]",
			ReqPrimaryAccountInit->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspPrimaryAccountInitPackage::XtpRspPrimaryAccountInitPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspPrimaryAccountInitPackage* XtpRspPrimaryAccountInitPackage::Allocate()
	{
		return ::Allocate<XtpRspPrimaryAccountInitPackage>();
	}
	void XtpRspPrimaryAccountInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspPrimaryAccountInit != nullptr)
		{
			::Free<XtpRspPrimaryAccountInitField>(RspPrimaryAccountInit);
			RspPrimaryAccountInit = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspPrimaryAccountInitPackage>::GetInstance().Free(this);
	}
	void XtpRspPrimaryAccountInitPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspPrimaryAccountInitPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspPrimaryAccountInit, sizeof(XtpRspPrimaryAccountInitField));
		offset += sizeof(XtpRspPrimaryAccountInitField);
		return offset;
	}
	bool XtpRspPrimaryAccountInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspPrimaryAccountInit = ::Allocate<XtpRspPrimaryAccountInitField>();
		memcpy(RspPrimaryAccountInit, buff + offset, sizeof(XtpRspPrimaryAccountInitField));
		offset += sizeof(XtpRspPrimaryAccountInitField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspPrimaryAccountInitPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspPrimaryAccountInit:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			RspPrimaryAccountInit->ErrorID, RspPrimaryAccountInit->ErrorMsg, RspPrimaryAccountInit->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqPrimaryAccountQueryPackage::XtpReqPrimaryAccountQueryPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqPrimaryAccountQueryPackage* XtpReqPrimaryAccountQueryPackage::Allocate()
	{
		return ::Allocate<XtpReqPrimaryAccountQueryPackage>();
	}
	void XtpReqPrimaryAccountQueryPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqPrimaryAccountQuery != nullptr)
		{
			::Free<XtpReqPrimaryAccountQueryField>(ReqPrimaryAccountQuery);
			ReqPrimaryAccountQuery = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqPrimaryAccountQueryPackage>::GetInstance().Free(this);
	}
	void XtpReqPrimaryAccountQueryPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqPrimaryAccountQueryPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqPrimaryAccountQuery, sizeof(XtpReqPrimaryAccountQueryField));
		offset += sizeof(XtpReqPrimaryAccountQueryField);
		return offset;
	}
	bool XtpReqPrimaryAccountQueryPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountQuery = ::Allocate<XtpReqPrimaryAccountQueryField>();
		memcpy(ReqPrimaryAccountQuery, buff + offset, sizeof(XtpReqPrimaryAccountQueryField));
		offset += sizeof(XtpReqPrimaryAccountQueryField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqPrimaryAccountQueryPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqPrimaryAccountQuery:PrimaryAccountID:[%s]",
			ReqPrimaryAccountQuery->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspPrimaryAccountQueryPackage::XtpRspPrimaryAccountQueryPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspPrimaryAccountQueryPackage* XtpRspPrimaryAccountQueryPackage::Allocate()
	{
		return ::Allocate<XtpRspPrimaryAccountQueryPackage>();
	}
	void XtpRspPrimaryAccountQueryPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspPrimaryAccountQuery != nullptr)
		{
			::Free<XtpRspPrimaryAccountQueryField>(RspPrimaryAccountQuery);
			RspPrimaryAccountQuery = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspPrimaryAccountQueryPackage>::GetInstance().Free(this);
	}
	void XtpRspPrimaryAccountQueryPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspPrimaryAccountQueryPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspPrimaryAccountQuery, sizeof(XtpRspPrimaryAccountQueryField));
		offset += sizeof(XtpRspPrimaryAccountQueryField);
		return offset;
	}
	bool XtpRspPrimaryAccountQueryPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspPrimaryAccountQuery = ::Allocate<XtpRspPrimaryAccountQueryField>();
		memcpy(RspPrimaryAccountQuery, buff + offset, sizeof(XtpRspPrimaryAccountQueryField));
		offset += sizeof(XtpRspPrimaryAccountQueryField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspPrimaryAccountQueryPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspPrimaryAccountQuery:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			RspPrimaryAccountQuery->ErrorID, RspPrimaryAccountQuery->ErrorMsg, RspPrimaryAccountQuery->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqQryOptionInstrumentPackage::XtpReqQryOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryOptionInstrumentPackage* XtpReqQryOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpReqQryOptionInstrumentPackage>();
	}
	void XtpReqQryOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryOptionInstrument != nullptr)
		{
			::Free<XtpReqQryOptionInstrumentField>(ReqQryOptionInstrument);
			ReqQryOptionInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpReqQryOptionInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryOptionInstrument, sizeof(XtpReqQryOptionInstrumentField));
		offset += sizeof(XtpReqQryOptionInstrumentField);
		return offset;
	}
	bool XtpReqQryOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryOptionInstrument = ::Allocate<XtpReqQryOptionInstrumentField>();
		memcpy(ReqQryOptionInstrument, buff + offset, sizeof(XtpReqQryOptionInstrumentField));
		offset += sizeof(XtpReqQryOptionInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryOptionInstrument:PrimaryAccountID:[%s]",
			ReqQryOptionInstrument->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspQryOptionInstrumentPackage::XtpRspQryOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryOptionInstrumentPackage* XtpRspQryOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRspQryOptionInstrumentPackage>();
	}
	void XtpRspQryOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspQryOptionInstrument != nullptr)
		{
			::Free<XtpRspQryOptionInstrumentField>(RspQryOptionInstrument);
			RspQryOptionInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRspQryOptionInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspQryOptionInstrument, sizeof(XtpRspQryOptionInstrumentField));
		offset += sizeof(XtpRspQryOptionInstrumentField);
		return offset;
	}
	bool XtpRspQryOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspQryOptionInstrument = ::Allocate<XtpRspQryOptionInstrumentField>();
		memcpy(RspQryOptionInstrument, buff + offset, sizeof(XtpRspQryOptionInstrumentField));
		offset += sizeof(XtpRspQryOptionInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspQryOptionInstrument:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			RspQryOptionInstrument->ErrorID, RspQryOptionInstrument->ErrorMsg, RspQryOptionInstrument->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnOptionInstrumentPackage::XtpRtnOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOptionInstrumentPackage* XtpRtnOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRtnOptionInstrumentPackage>();
	}
	void XtpRtnOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnOptionInstrument != nullptr)
		{
			::Free<XtpRtnOptionInstrumentField>(RtnOptionInstrument);
			RtnOptionInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRtnOptionInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnOptionInstrument, sizeof(XtpRtnOptionInstrumentField));
		offset += sizeof(XtpRtnOptionInstrumentField);
		return offset;
	}
	bool XtpRtnOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnOptionInstrument = ::Allocate<XtpRtnOptionInstrumentField>();
		memcpy(RtnOptionInstrument, buff + offset, sizeof(XtpRtnOptionInstrumentField));
		offset += sizeof(XtpRtnOptionInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnOptionInstrument:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]",
			RtnOptionInstrument->TradingDay, RtnOptionInstrument->ExchangeID, RtnOptionInstrument->InstrumentID, RtnOptionInstrument->ExchangeInstID, RtnOptionInstrument->InstrumentName, RtnOptionInstrument->VolumeMultiple, (int)RtnOptionInstrument->OptionType, RtnOptionInstrument->UnderlyingInstrumentID, RtnOptionInstrument->ExecutePrice, RtnOptionInstrument->UnitMargin, RtnOptionInstrument->PriceTick, RtnOptionInstrument->MaxLimitOrderVolume, RtnOptionInstrument->MaxMarketOrderVolume, RtnOptionInstrument->ExpiringDate);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqInsertOrderPackage::XtpReqInsertOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqInsertOrderPackage* XtpReqInsertOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqInsertOrderPackage>();
	}
	void XtpReqInsertOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqInsertOrder != nullptr)
		{
			::Free<XtpReqInsertOrderField>(ReqInsertOrder);
			ReqInsertOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqInsertOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqInsertOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqInsertOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqInsertOrder, sizeof(XtpReqInsertOrderField));
		offset += sizeof(XtpReqInsertOrderField);
		return offset;
	}
	bool XtpReqInsertOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqInsertOrder = ::Allocate<XtpReqInsertOrderField>();
		memcpy(ReqInsertOrder, buff + offset, sizeof(XtpReqInsertOrderField));
		offset += sizeof(XtpReqInsertOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqInsertOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqInsertOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d]",
			ReqInsertOrder->TradingDay, ReqInsertOrder->PrimaryAccountID, ReqInsertOrder->ExchangeID, ReqInsertOrder->InstrumentID, (int)ReqInsertOrder->SecurityType, ReqInsertOrder->OrderID, (int)ReqInsertOrder->Direction, (int)ReqInsertOrder->OffsetFlag, (int)ReqInsertOrder->OrderPriceType, ReqInsertOrder->Price, ReqInsertOrder->Volume);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqCancelOrderPackage::XtpReqCancelOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqCancelOrderPackage* XtpReqCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqCancelOrderPackage>();
	}
	void XtpReqCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqCancelOrder != nullptr)
		{
			::Free<XtpReqCancelOrderField>(ReqCancelOrder);
			ReqCancelOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqCancelOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqCancelOrder, sizeof(XtpReqCancelOrderField));
		offset += sizeof(XtpReqCancelOrderField);
		return offset;
	}
	bool XtpReqCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqCancelOrder = ::Allocate<XtpReqCancelOrderField>();
		memcpy(ReqCancelOrder, buff + offset, sizeof(XtpReqCancelOrderField));
		offset += sizeof(XtpReqCancelOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqCancelOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			ReqCancelOrder->TradingDay, ReqCancelOrder->PrimaryAccountID, ReqCancelOrder->ExchangeID, ReqCancelOrder->InstrumentID, (int)ReqCancelOrder->SecurityType, (int)ReqCancelOrder->Direction, ReqCancelOrder->CancelOrderID, ReqCancelOrder->OrderID, ReqCancelOrder->OrderSysID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnOrderPackage::XtpRtnOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOrderPackage* XtpRtnOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnOrderPackage>();
	}
	void XtpRtnOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnOrder != nullptr)
		{
			::Free<XtpRtnOrderField>(RtnOrder);
			RtnOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnOrder, sizeof(XtpRtnOrderField));
		offset += sizeof(XtpRtnOrderField);
		return offset;
	}
	bool XtpRtnOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnOrder = ::Allocate<XtpRtnOrderField>();
		memcpy(RtnOrder, buff + offset, sizeof(XtpRtnOrderField));
		offset += sizeof(XtpRtnOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], IsNewOrder:[%d]",
			RtnOrder->TradingDay, RtnOrder->PrimaryAccountID, RtnOrder->ExchangeID, RtnOrder->InstrumentID, RtnOrder->OrderID, RtnOrder->OrderSysID, (int)RtnOrder->Direction, (int)RtnOrder->OffsetFlag, (int)RtnOrder->OrderPriceType, RtnOrder->Price, RtnOrder->Volume, RtnOrder->VolumeTotal, RtnOrder->VolumeTraded, (int)RtnOrder->OrderStatus, RtnOrder->StatusMsg, RtnOrder->OrderDate, RtnOrder->OrderTime, RtnOrder->CancelDate, RtnOrder->CancelTime, RtnOrder->IsNewOrder);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnTradePackage::XtpRtnTradePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnTradePackage* XtpRtnTradePackage::Allocate()
	{
		return ::Allocate<XtpRtnTradePackage>();
	}
	void XtpRtnTradePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnTrade != nullptr)
		{
			::Free<XtpRtnTradeField>(RtnTrade);
			RtnTrade = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnTradePackage>::GetInstance().Free(this);
	}
	void XtpRtnTradePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnTradePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnTrade, sizeof(XtpRtnTradeField));
		offset += sizeof(XtpRtnTradeField);
		return offset;
	}
	bool XtpRtnTradePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnTrade = ::Allocate<XtpRtnTradeField>();
		memcpy(RtnTrade, buff + offset, sizeof(XtpRtnTradeField));
		offset += sizeof(XtpRtnTradeField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnTradePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnTrade:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], TradeDate:[%s], TradeTime:[%s]",
			RtnTrade->TradingDay, RtnTrade->PrimaryAccountID, RtnTrade->ExchangeID, RtnTrade->InstrumentID, RtnTrade->OrderID, RtnTrade->OrderSysID, RtnTrade->TradeID, (int)RtnTrade->Direction, (int)RtnTrade->OffsetFlag, RtnTrade->Price, RtnTrade->Volume, RtnTrade->TradeDate, RtnTrade->TradeTime);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnErrorCancelOrderPackage::XtpRtnErrorCancelOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnErrorCancelOrderPackage* XtpRtnErrorCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnErrorCancelOrderPackage>();
	}
	void XtpRtnErrorCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnErrorCancelOrder != nullptr)
		{
			::Free<XtpRtnErrorCancelOrderField>(RtnErrorCancelOrder);
			RtnErrorCancelOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnErrorCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnErrorCancelOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnErrorCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnErrorCancelOrder, sizeof(XtpRtnErrorCancelOrderField));
		offset += sizeof(XtpRtnErrorCancelOrderField);
		return offset;
	}
	bool XtpRtnErrorCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnErrorCancelOrder = ::Allocate<XtpRtnErrorCancelOrderField>();
		memcpy(RtnErrorCancelOrder, buff + offset, sizeof(XtpRtnErrorCancelOrderField));
		offset += sizeof(XtpRtnErrorCancelOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnErrorCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnErrorCancelOrder:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			RtnErrorCancelOrder->ErrorID, RtnErrorCancelOrder->ErrorMsg, RtnErrorCancelOrder->TradingDay, RtnErrorCancelOrder->PrimaryAccountID, RtnErrorCancelOrder->ExchangeID, RtnErrorCancelOrder->InstrumentID, (int)RtnErrorCancelOrder->Direction, RtnErrorCancelOrder->CancelOrderID, RtnErrorCancelOrder->OrderID, RtnErrorCancelOrder->OrderSysID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnCapitalPackage::XtpRtnCapitalPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnCapitalPackage* XtpRtnCapitalPackage::Allocate()
	{
		return ::Allocate<XtpRtnCapitalPackage>();
	}
	void XtpRtnCapitalPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnCapital != nullptr)
		{
			::Free<XtpRtnCapitalField>(RtnCapital);
			RtnCapital = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnCapitalPackage>::GetInstance().Free(this);
	}
	void XtpRtnCapitalPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnCapitalPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnCapital, sizeof(XtpRtnCapitalField));
		offset += sizeof(XtpRtnCapitalField);
		return offset;
	}
	bool XtpRtnCapitalPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnCapital = ::Allocate<XtpRtnCapitalField>();
		memcpy(RtnCapital, buff + offset, sizeof(XtpRtnCapitalField));
		offset += sizeof(XtpRtnCapitalField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnCapitalPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnCapital:TradingDay:[%s], PrimaryAccountID:[%s], PreCashAsset:[%f]",
			RtnCapital->TradingDay, RtnCapital->PrimaryAccountID, RtnCapital->PreCashAsset);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnPositionPackage::XtpRtnPositionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnPositionPackage* XtpRtnPositionPackage::Allocate()
	{
		return ::Allocate<XtpRtnPositionPackage>();
	}
	void XtpRtnPositionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnPosition != nullptr)
		{
			::Free<XtpRtnPositionField>(RtnPosition);
			RtnPosition = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnPositionPackage>::GetInstance().Free(this);
	}
	void XtpRtnPositionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnPositionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnPosition, sizeof(XtpRtnPositionField));
		offset += sizeof(XtpRtnPositionField);
		return offset;
	}
	bool XtpRtnPositionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnPosition = ::Allocate<XtpRtnPositionField>();
		memcpy(RtnPosition, buff + offset, sizeof(XtpRtnPositionField));
		offset += sizeof(XtpRtnPositionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnPositionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnPosition:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TotalCostPrice:[%f], Margin:[%f], MarketValue:[%f]",
			RtnPosition->TradingDay, RtnPosition->PrimaryAccountID, RtnPosition->ExchangeID, RtnPosition->InstrumentID, (int)RtnPosition->PosiDirection, RtnPosition->TotalPosition, RtnPosition->PositionFrozen, RtnPosition->TotalCostPrice, RtnPosition->Margin, RtnPosition->MarketValue);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqMDOfferLoginPackage::XtpReqMDOfferLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqMDOfferLoginPackage* XtpReqMDOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqMDOfferLoginPackage>();
	}
	void XtpReqMDOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqMDOfferLogin != nullptr)
		{
			::Free<XtpReqMDOfferLoginField>(ReqMDOfferLogin);
			ReqMDOfferLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqMDOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqMDOfferLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqMDOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqMDOfferLogin, sizeof(XtpReqMDOfferLoginField));
		offset += sizeof(XtpReqMDOfferLoginField);
		return offset;
	}
	bool XtpReqMDOfferLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqMDOfferLogin = ::Allocate<XtpReqMDOfferLoginField>();
		memcpy(ReqMDOfferLogin, buff + offset, sizeof(XtpReqMDOfferLoginField));
		offset += sizeof(XtpReqMDOfferLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqMDOfferLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqMDOfferLogin:UserID:[%s], Password:[%s]",
			ReqMDOfferLogin->UserID, ReqMDOfferLogin->Password);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspMDOfferLoginPackage::XtpRspMDOfferLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspMDOfferLoginPackage* XtpRspMDOfferLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspMDOfferLoginPackage>();
	}
	void XtpRspMDOfferLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspMDOfferLogin != nullptr)
		{
			::Free<XtpRspMDOfferLoginField>(RspMDOfferLogin);
			RspMDOfferLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspMDOfferLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspMDOfferLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspMDOfferLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspMDOfferLogin, sizeof(XtpRspMDOfferLoginField));
		offset += sizeof(XtpRspMDOfferLoginField);
		return offset;
	}
	bool XtpRspMDOfferLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspMDOfferLogin = ::Allocate<XtpRspMDOfferLoginField>();
		memcpy(RspMDOfferLogin, buff + offset, sizeof(XtpRspMDOfferLoginField));
		offset += sizeof(XtpRspMDOfferLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspMDOfferLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspMDOfferLogin:ErrorID:[%d], ErrorMsg:[%s]",
			RspMDOfferLogin->ErrorID, RspMDOfferLogin->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqMDInitPackage::XtpReqMDInitPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqMDInitPackage* XtpReqMDInitPackage::Allocate()
	{
		return ::Allocate<XtpReqMDInitPackage>();
	}
	void XtpReqMDInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqMDInit != nullptr)
		{
			::Free<XtpReqMDInitField>(ReqMDInit);
			ReqMDInit = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqMDInitPackage>::GetInstance().Free(this);
	}
	void XtpReqMDInitPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqMDInitPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqMDInit, sizeof(XtpReqMDInitField));
		offset += sizeof(XtpReqMDInitField);
		return offset;
	}
	bool XtpReqMDInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqMDInit = ::Allocate<XtpReqMDInitField>();
		memcpy(ReqMDInit, buff + offset, sizeof(XtpReqMDInitField));
		offset += sizeof(XtpReqMDInitField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqMDInitPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqMDInit:ExchangeID:[%s], TradingDay:[%s]",
			ReqMDInit->ExchangeID, ReqMDInit->TradingDay);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspMDInitPackage::XtpRspMDInitPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspMDInitPackage* XtpRspMDInitPackage::Allocate()
	{
		return ::Allocate<XtpRspMDInitPackage>();
	}
	void XtpRspMDInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspMDInit != nullptr)
		{
			::Free<XtpRspMDInitField>(RspMDInit);
			RspMDInit = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspMDInitPackage>::GetInstance().Free(this);
	}
	void XtpRspMDInitPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspMDInitPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspMDInit, sizeof(XtpRspMDInitField));
		offset += sizeof(XtpRspMDInitField);
		return offset;
	}
	bool XtpRspMDInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspMDInit = ::Allocate<XtpRspMDInitField>();
		memcpy(RspMDInit, buff + offset, sizeof(XtpRspMDInitField));
		offset += sizeof(XtpRspMDInitField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspMDInitPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspMDInit:ExchangeID:[%s], TradingDay:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			RspMDInit->ExchangeID, RspMDInit->TradingDay, RspMDInit->ErrorID, RspMDInit->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpReqSubscribeMDPackage::XtpReqSubscribeMDPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqSubscribeMDPackage* XtpReqSubscribeMDPackage::Allocate()
	{
		return ::Allocate<XtpReqSubscribeMDPackage>();
	}
	void XtpReqSubscribeMDPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqSubscribeMD != nullptr)
		{
			::Free<XtpReqSubscribeMDField>(ReqSubscribeMD);
			ReqSubscribeMD = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqSubscribeMDPackage>::GetInstance().Free(this);
	}
	void XtpReqSubscribeMDPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqSubscribeMDPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqSubscribeMD, sizeof(XtpReqSubscribeMDField));
		offset += sizeof(XtpReqSubscribeMDField);
		return offset;
	}
	bool XtpReqSubscribeMDPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqSubscribeMD = ::Allocate<XtpReqSubscribeMDField>();
		memcpy(ReqSubscribeMD, buff + offset, sizeof(XtpReqSubscribeMDField));
		offset += sizeof(XtpReqSubscribeMDField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqSubscribeMDPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqSubscribeMD:ExchangeID:[%s], InstrumentID:[%s]",
			ReqSubscribeMD->ExchangeID, ReqSubscribeMD->InstrumentID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspSubscribeMDPackage::XtpRspSubscribeMDPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspSubscribeMDPackage* XtpRspSubscribeMDPackage::Allocate()
	{
		return ::Allocate<XtpRspSubscribeMDPackage>();
	}
	void XtpRspSubscribeMDPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspSubscribeMD != nullptr)
		{
			::Free<XtpRspSubscribeMDField>(RspSubscribeMD);
			RspSubscribeMD = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspSubscribeMDPackage>::GetInstance().Free(this);
	}
	void XtpRspSubscribeMDPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspSubscribeMDPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspSubscribeMD, sizeof(XtpRspSubscribeMDField));
		offset += sizeof(XtpRspSubscribeMDField);
		return offset;
	}
	bool XtpRspSubscribeMDPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspSubscribeMD = ::Allocate<XtpRspSubscribeMDField>();
		memcpy(RspSubscribeMD, buff + offset, sizeof(XtpRspSubscribeMDField));
		offset += sizeof(XtpRspSubscribeMDField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspSubscribeMDPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspSubscribeMD:ExchangeID:[%s], InstrumentID:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			RspSubscribeMD->ExchangeID, RspSubscribeMD->InstrumentID, RspSubscribeMD->ErrorID, RspSubscribeMD->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnShortMDPackage::XtpRtnShortMDPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnShortMDPackage* XtpRtnShortMDPackage::Allocate()
	{
		return ::Allocate<XtpRtnShortMDPackage>();
	}
	void XtpRtnShortMDPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnShortMD != nullptr)
		{
			::Free<XtpRtnShortMDField>(RtnShortMD);
			RtnShortMD = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnShortMDPackage>::GetInstance().Free(this);
	}
	void XtpRtnShortMDPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnShortMDPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnShortMD, sizeof(XtpRtnShortMDField));
		offset += sizeof(XtpRtnShortMDField);
		return offset;
	}
	bool XtpRtnShortMDPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnShortMD = ::Allocate<XtpRtnShortMDField>();
		memcpy(RtnShortMD, buff + offset, sizeof(XtpRtnShortMDField));
		offset += sizeof(XtpRtnShortMDField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnShortMDPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnShortMD:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], LastPrice:[%f], ClosePrice:[%f], PreClosePrice:[%f], SettlementPrice:[%f], PreSettlementPrice:[%f], UpperLimitPrice:[%f], LowerLimitPrice:[%f]",
			RtnShortMD->TradingDay, RtnShortMD->ExchangeID, RtnShortMD->InstrumentID, RtnShortMD->LastPrice, RtnShortMD->ClosePrice, RtnShortMD->PreClosePrice, RtnShortMD->SettlementPrice, RtnShortMD->PreSettlementPrice, RtnShortMD->UpperLimitPrice, RtnShortMD->LowerLimitPrice);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnExchangeStatusPackage::XtpRtnExchangeStatusPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnExchangeStatusPackage* XtpRtnExchangeStatusPackage::Allocate()
	{
		return ::Allocate<XtpRtnExchangeStatusPackage>();
	}
	void XtpRtnExchangeStatusPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnExchangeStatus != nullptr)
		{
			::Free<XtpRtnExchangeStatusField>(RtnExchangeStatus);
			RtnExchangeStatus = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnExchangeStatusPackage>::GetInstance().Free(this);
	}
	void XtpRtnExchangeStatusPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnExchangeStatusPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnExchangeStatus, sizeof(XtpRtnExchangeStatusField));
		offset += sizeof(XtpRtnExchangeStatusField);
		return offset;
	}
	bool XtpRtnExchangeStatusPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnExchangeStatus = ::Allocate<XtpRtnExchangeStatusField>();
		memcpy(RtnExchangeStatus, buff + offset, sizeof(XtpRtnExchangeStatusField));
		offset += sizeof(XtpRtnExchangeStatusField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnExchangeStatusPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnExchangeStatus:ExchangeID:[%s], ExchangeDate:[%s], ExchangeStatus:[%d]",
			RtnExchangeStatus->ExchangeID, RtnExchangeStatus->ExchangeDate, (int)RtnExchangeStatus->ExchangeStatus);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnInstrumentPackage::XtpRtnInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnInstrumentPackage* XtpRtnInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRtnInstrumentPackage>();
	}
	void XtpRtnInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnInstrument != nullptr)
		{
			::Free<XtpRtnInstrumentField>(RtnInstrument);
			RtnInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRtnInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnInstrument, sizeof(XtpRtnInstrumentField));
		offset += sizeof(XtpRtnInstrumentField);
		return offset;
	}
	bool XtpRtnInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnInstrument = ::Allocate<XtpRtnInstrumentField>();
		memcpy(RtnInstrument, buff + offset, sizeof(XtpRtnInstrumentField));
		offset += sizeof(XtpRtnInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnInstrument:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], SecurityType:[%d]",
			RtnInstrument->ExchangeID, RtnInstrument->InstrumentID, RtnInstrument->ExchangeInstID, RtnInstrument->InstrumentName, RtnInstrument->VolumeMultiple, (int)RtnInstrument->SecurityType);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnMDInitCompletedPackage::XtpRtnMDInitCompletedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnMDInitCompletedPackage* XtpRtnMDInitCompletedPackage::Allocate()
	{
		return ::Allocate<XtpRtnMDInitCompletedPackage>();
	}
	void XtpRtnMDInitCompletedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnMDInitCompleted != nullptr)
		{
			::Free<XtpRtnMDInitCompletedField>(RtnMDInitCompleted);
			RtnMDInitCompleted = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnMDInitCompletedPackage>::GetInstance().Free(this);
	}
	void XtpRtnMDInitCompletedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnMDInitCompletedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnMDInitCompleted, sizeof(XtpRtnMDInitCompletedField));
		offset += sizeof(XtpRtnMDInitCompletedField);
		return offset;
	}
	bool XtpRtnMDInitCompletedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnMDInitCompleted = ::Allocate<XtpRtnMDInitCompletedField>();
		memcpy(RtnMDInitCompleted, buff + offset, sizeof(XtpRtnMDInitCompletedField));
		offset += sizeof(XtpRtnMDInitCompletedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnMDInitCompletedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnMDInitCompleted:ExchangeID:[%s], TradingDay:[%s]",
			RtnMDInitCompleted->ExchangeID, RtnMDInitCompleted->TradingDay);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyMdClientConnectedPackage::XtpNotifyMdClientConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyMdClientConnectedPackage* XtpNotifyMdClientConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyMdClientConnectedPackage>();
	}
	void XtpNotifyMdClientConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyMdClientConnected != nullptr)
		{
			::Free<XtpNotifyMdClientConnectedField>(NotifyMdClientConnected);
			NotifyMdClientConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyMdClientConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyMdClientConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyMdClientConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyMdClientConnected, sizeof(XtpNotifyMdClientConnectedField));
		offset += sizeof(XtpNotifyMdClientConnectedField);
		return offset;
	}
	bool XtpNotifyMdClientConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyMdClientConnected = ::Allocate<XtpNotifyMdClientConnectedField>();
		memcpy(NotifyMdClientConnected, buff + offset, sizeof(XtpNotifyMdClientConnectedField));
		offset += sizeof(XtpNotifyMdClientConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyMdClientConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyMdClientConnected:SessionID:[%lld]",
			NotifyMdClientConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyMdClientDisConnectedPackage::XtpNotifyMdClientDisConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyMdClientDisConnectedPackage* XtpNotifyMdClientDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyMdClientDisConnectedPackage>();
	}
	void XtpNotifyMdClientDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyMdClientDisConnected != nullptr)
		{
			::Free<XtpNotifyMdClientDisConnectedField>(NotifyMdClientDisConnected);
			NotifyMdClientDisConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyMdClientDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyMdClientDisConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyMdClientDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyMdClientDisConnected, sizeof(XtpNotifyMdClientDisConnectedField));
		offset += sizeof(XtpNotifyMdClientDisConnectedField);
		return offset;
	}
	bool XtpNotifyMdClientDisConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyMdClientDisConnected = ::Allocate<XtpNotifyMdClientDisConnectedField>();
		memcpy(NotifyMdClientDisConnected, buff + offset, sizeof(XtpNotifyMdClientDisConnectedField));
		offset += sizeof(XtpNotifyMdClientDisConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyMdClientDisConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyMdClientDisConnected:SessionID:[%lld]",
			NotifyMdClientDisConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyRiskCheckClientConnectedPackage::XtpNotifyRiskCheckClientConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyRiskCheckClientConnectedPackage* XtpNotifyRiskCheckClientConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskCheckClientConnectedPackage>();
	}
	void XtpNotifyRiskCheckClientConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyRiskCheckClientConnected != nullptr)
		{
			::Free<XtpNotifyRiskCheckClientConnectedField>(NotifyRiskCheckClientConnected);
			NotifyRiskCheckClientConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyRiskCheckClientConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskCheckClientConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyRiskCheckClientConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyRiskCheckClientConnected, sizeof(XtpNotifyRiskCheckClientConnectedField));
		offset += sizeof(XtpNotifyRiskCheckClientConnectedField);
		return offset;
	}
	bool XtpNotifyRiskCheckClientConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyRiskCheckClientConnected = ::Allocate<XtpNotifyRiskCheckClientConnectedField>();
		memcpy(NotifyRiskCheckClientConnected, buff + offset, sizeof(XtpNotifyRiskCheckClientConnectedField));
		offset += sizeof(XtpNotifyRiskCheckClientConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyRiskCheckClientConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyRiskCheckClientConnected:SessionID:[%lld]",
			NotifyRiskCheckClientConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyRiskCheckClientDisConnectedPackage::XtpNotifyRiskCheckClientDisConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyRiskCheckClientDisConnectedPackage* XtpNotifyRiskCheckClientDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskCheckClientDisConnectedPackage>();
	}
	void XtpNotifyRiskCheckClientDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyRiskCheckClientDisConnected != nullptr)
		{
			::Free<XtpNotifyRiskCheckClientDisConnectedField>(NotifyRiskCheckClientDisConnected);
			NotifyRiskCheckClientDisConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyRiskCheckClientDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskCheckClientDisConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyRiskCheckClientDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyRiskCheckClientDisConnected, sizeof(XtpNotifyRiskCheckClientDisConnectedField));
		offset += sizeof(XtpNotifyRiskCheckClientDisConnectedField);
		return offset;
	}
	bool XtpNotifyRiskCheckClientDisConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyRiskCheckClientDisConnected = ::Allocate<XtpNotifyRiskCheckClientDisConnectedField>();
		memcpy(NotifyRiskCheckClientDisConnected, buff + offset, sizeof(XtpNotifyRiskCheckClientDisConnectedField));
		offset += sizeof(XtpNotifyRiskCheckClientDisConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyRiskCheckClientDisConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyRiskCheckClientDisConnected:SessionID:[%lld]",
			NotifyRiskCheckClientDisConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyTradeFrontConnectedPackage::XtpNotifyTradeFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyTradeFrontConnectedPackage* XtpNotifyTradeFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyTradeFrontConnectedPackage>();
	}
	void XtpNotifyTradeFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyTradeFrontConnected != nullptr)
		{
			::Free<XtpNotifyTradeFrontConnectedField>(NotifyTradeFrontConnected);
			NotifyTradeFrontConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyTradeFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyTradeFrontConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyTradeFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyTradeFrontConnected, sizeof(XtpNotifyTradeFrontConnectedField));
		offset += sizeof(XtpNotifyTradeFrontConnectedField);
		return offset;
	}
	bool XtpNotifyTradeFrontConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyTradeFrontConnected = ::Allocate<XtpNotifyTradeFrontConnectedField>();
		memcpy(NotifyTradeFrontConnected, buff + offset, sizeof(XtpNotifyTradeFrontConnectedField));
		offset += sizeof(XtpNotifyTradeFrontConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyTradeFrontConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyTradeFrontConnected:SessionID:[%lld]",
			NotifyTradeFrontConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyTradeFrontDisConnectedPackage::XtpNotifyTradeFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyTradeFrontDisConnectedPackage* XtpNotifyTradeFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyTradeFrontDisConnectedPackage>();
	}
	void XtpNotifyTradeFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyTradeFrontDisConnected != nullptr)
		{
			::Free<XtpNotifyTradeFrontDisConnectedField>(NotifyTradeFrontDisConnected);
			NotifyTradeFrontDisConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyTradeFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyTradeFrontDisConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyTradeFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyTradeFrontDisConnected, sizeof(XtpNotifyTradeFrontDisConnectedField));
		offset += sizeof(XtpNotifyTradeFrontDisConnectedField);
		return offset;
	}
	bool XtpNotifyTradeFrontDisConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyTradeFrontDisConnected = ::Allocate<XtpNotifyTradeFrontDisConnectedField>();
		memcpy(NotifyTradeFrontDisConnected, buff + offset, sizeof(XtpNotifyTradeFrontDisConnectedField));
		offset += sizeof(XtpNotifyTradeFrontDisConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyTradeFrontDisConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyTradeFrontDisConnected:SessionID:[%lld]",
			NotifyTradeFrontDisConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyRiskFrontConnectedPackage::XtpNotifyRiskFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyRiskFrontConnectedPackage* XtpNotifyRiskFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskFrontConnectedPackage>();
	}
	void XtpNotifyRiskFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyRiskFrontConnected != nullptr)
		{
			::Free<XtpNotifyRiskFrontConnectedField>(NotifyRiskFrontConnected);
			NotifyRiskFrontConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyRiskFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskFrontConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyRiskFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyRiskFrontConnected, sizeof(XtpNotifyRiskFrontConnectedField));
		offset += sizeof(XtpNotifyRiskFrontConnectedField);
		return offset;
	}
	bool XtpNotifyRiskFrontConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyRiskFrontConnected = ::Allocate<XtpNotifyRiskFrontConnectedField>();
		memcpy(NotifyRiskFrontConnected, buff + offset, sizeof(XtpNotifyRiskFrontConnectedField));
		offset += sizeof(XtpNotifyRiskFrontConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyRiskFrontConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyRiskFrontConnected:SessionID:[%lld]",
			NotifyRiskFrontConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyRiskFrontDisConnectedPackage::XtpNotifyRiskFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyRiskFrontDisConnectedPackage* XtpNotifyRiskFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyRiskFrontDisConnectedPackage>();
	}
	void XtpNotifyRiskFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyRiskFrontDisConnected != nullptr)
		{
			::Free<XtpNotifyRiskFrontDisConnectedField>(NotifyRiskFrontDisConnected);
			NotifyRiskFrontDisConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyRiskFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyRiskFrontDisConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyRiskFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyRiskFrontDisConnected, sizeof(XtpNotifyRiskFrontDisConnectedField));
		offset += sizeof(XtpNotifyRiskFrontDisConnectedField);
		return offset;
	}
	bool XtpNotifyRiskFrontDisConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyRiskFrontDisConnected = ::Allocate<XtpNotifyRiskFrontDisConnectedField>();
		memcpy(NotifyRiskFrontDisConnected, buff + offset, sizeof(XtpNotifyRiskFrontDisConnectedField));
		offset += sizeof(XtpNotifyRiskFrontDisConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyRiskFrontDisConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyRiskFrontDisConnected:SessionID:[%lld]",
			NotifyRiskFrontDisConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyAdminFrontConnectedPackage::XtpNotifyAdminFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyAdminFrontConnectedPackage* XtpNotifyAdminFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyAdminFrontConnectedPackage>();
	}
	void XtpNotifyAdminFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyAdminFrontConnected != nullptr)
		{
			::Free<XtpNotifyAdminFrontConnectedField>(NotifyAdminFrontConnected);
			NotifyAdminFrontConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyAdminFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyAdminFrontConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyAdminFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyAdminFrontConnected, sizeof(XtpNotifyAdminFrontConnectedField));
		offset += sizeof(XtpNotifyAdminFrontConnectedField);
		return offset;
	}
	bool XtpNotifyAdminFrontConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyAdminFrontConnected = ::Allocate<XtpNotifyAdminFrontConnectedField>();
		memcpy(NotifyAdminFrontConnected, buff + offset, sizeof(XtpNotifyAdminFrontConnectedField));
		offset += sizeof(XtpNotifyAdminFrontConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyAdminFrontConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyAdminFrontConnected:SessionID:[%lld]",
			NotifyAdminFrontConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyAdminFrontDisConnectedPackage::XtpNotifyAdminFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyAdminFrontDisConnectedPackage* XtpNotifyAdminFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyAdminFrontDisConnectedPackage>();
	}
	void XtpNotifyAdminFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyAdminFrontDisConnected != nullptr)
		{
			::Free<XtpNotifyAdminFrontDisConnectedField>(NotifyAdminFrontDisConnected);
			NotifyAdminFrontDisConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyAdminFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyAdminFrontDisConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyAdminFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyAdminFrontDisConnected, sizeof(XtpNotifyAdminFrontDisConnectedField));
		offset += sizeof(XtpNotifyAdminFrontDisConnectedField);
		return offset;
	}
	bool XtpNotifyAdminFrontDisConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyAdminFrontDisConnected = ::Allocate<XtpNotifyAdminFrontDisConnectedField>();
		memcpy(NotifyAdminFrontDisConnected, buff + offset, sizeof(XtpNotifyAdminFrontDisConnectedField));
		offset += sizeof(XtpNotifyAdminFrontDisConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyAdminFrontDisConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyAdminFrontDisConnected:SessionID:[%lld]",
			NotifyAdminFrontDisConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyOfferFrontConnectedPackage::XtpNotifyOfferFrontConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyOfferFrontConnectedPackage* XtpNotifyOfferFrontConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyOfferFrontConnectedPackage>();
	}
	void XtpNotifyOfferFrontConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyOfferFrontConnected != nullptr)
		{
			::Free<XtpNotifyOfferFrontConnectedField>(NotifyOfferFrontConnected);
			NotifyOfferFrontConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyOfferFrontConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyOfferFrontConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyOfferFrontConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyOfferFrontConnected, sizeof(XtpNotifyOfferFrontConnectedField));
		offset += sizeof(XtpNotifyOfferFrontConnectedField);
		return offset;
	}
	bool XtpNotifyOfferFrontConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyOfferFrontConnected = ::Allocate<XtpNotifyOfferFrontConnectedField>();
		memcpy(NotifyOfferFrontConnected, buff + offset, sizeof(XtpNotifyOfferFrontConnectedField));
		offset += sizeof(XtpNotifyOfferFrontConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyOfferFrontConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyOfferFrontConnected:SessionID:[%lld]",
			NotifyOfferFrontConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyOfferFrontDisConnectedPackage::XtpNotifyOfferFrontDisConnectedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyOfferFrontDisConnectedPackage* XtpNotifyOfferFrontDisConnectedPackage::Allocate()
	{
		return ::Allocate<XtpNotifyOfferFrontDisConnectedPackage>();
	}
	void XtpNotifyOfferFrontDisConnectedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyOfferFrontDisConnected != nullptr)
		{
			::Free<XtpNotifyOfferFrontDisConnectedField>(NotifyOfferFrontDisConnected);
			NotifyOfferFrontDisConnected = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyOfferFrontDisConnectedPackage>::GetInstance().Free(this);
	}
	void XtpNotifyOfferFrontDisConnectedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyOfferFrontDisConnectedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyOfferFrontDisConnected, sizeof(XtpNotifyOfferFrontDisConnectedField));
		offset += sizeof(XtpNotifyOfferFrontDisConnectedField);
		return offset;
	}
	bool XtpNotifyOfferFrontDisConnectedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyOfferFrontDisConnected = ::Allocate<XtpNotifyOfferFrontDisConnectedField>();
		memcpy(NotifyOfferFrontDisConnected, buff + offset, sizeof(XtpNotifyOfferFrontDisConnectedField));
		offset += sizeof(XtpNotifyOfferFrontDisConnectedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyOfferFrontDisConnectedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyOfferFrontDisConnected:SessionID:[%lld]",
			NotifyOfferFrontDisConnected->SessionID);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpNotifyInitCompletePackage::XtpNotifyInitCompletePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyInitCompletePackage* XtpNotifyInitCompletePackage::Allocate()
	{
		return ::Allocate<XtpNotifyInitCompletePackage>();
	}
	void XtpNotifyInitCompletePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyInitComplete != nullptr)
		{
			::Free<XtpNotifyInitCompleteField>(NotifyInitComplete);
			NotifyInitComplete = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyInitCompletePackage>::GetInstance().Free(this);
	}
	void XtpNotifyInitCompletePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyInitCompletePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyInitComplete, sizeof(XtpNotifyInitCompleteField));
		offset += sizeof(XtpNotifyInitCompleteField);
		return offset;
	}
	bool XtpNotifyInitCompletePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyInitComplete = ::Allocate<XtpNotifyInitCompleteField>();
		memcpy(NotifyInitComplete, buff + offset, sizeof(XtpNotifyInitCompleteField));
		offset += sizeof(XtpNotifyInitCompleteField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyInitCompletePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyInitComplete:TradingDay:[%s]",
			NotifyInitComplete->TradingDay);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRspNotifyInitCompletePackage::XtpRspNotifyInitCompletePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspNotifyInitCompletePackage* XtpRspNotifyInitCompletePackage::Allocate()
	{
		return ::Allocate<XtpRspNotifyInitCompletePackage>();
	}
	void XtpRspNotifyInitCompletePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspNotifyInitComplete != nullptr)
		{
			::Free<XtpRspNotifyInitCompleteField>(RspNotifyInitComplete);
			RspNotifyInitComplete = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspNotifyInitCompletePackage>::GetInstance().Free(this);
	}
	void XtpRspNotifyInitCompletePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspNotifyInitCompletePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspNotifyInitComplete, sizeof(XtpRspNotifyInitCompleteField));
		offset += sizeof(XtpRspNotifyInitCompleteField);
		return offset;
	}
	bool XtpRspNotifyInitCompletePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspNotifyInitComplete = ::Allocate<XtpRspNotifyInitCompleteField>();
		memcpy(RspNotifyInitComplete, buff + offset, sizeof(XtpRspNotifyInitCompleteField));
		offset += sizeof(XtpRspNotifyInitCompleteField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspNotifyInitCompletePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspNotifyInitComplete:TradingDay:[%s]",
			RspNotifyInitComplete->TradingDay);
		return t_XtpDataStringBuffer;
	}
	
 
	XtpRtnRiskCheckOrderPackage::XtpRtnRiskCheckOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnRiskCheckOrderPackage* XtpRtnRiskCheckOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnRiskCheckOrderPackage>();
	}
	void XtpRtnRiskCheckOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RtnRiskCheckOrder != nullptr)
		{
			::Free<XtpRtnRiskCheckOrderField>(RtnRiskCheckOrder);
			RtnRiskCheckOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnRiskCheckOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnRiskCheckOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnRiskCheckOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RtnRiskCheckOrder, sizeof(XtpRtnRiskCheckOrderField));
		offset += sizeof(XtpRtnRiskCheckOrderField);
		return offset;
	}
	bool XtpRtnRiskCheckOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnRiskCheckOrder = ::Allocate<XtpRtnRiskCheckOrderField>();
		memcpy(RtnRiskCheckOrder, buff + offset, sizeof(XtpRtnRiskCheckOrderField));
		offset += sizeof(XtpRtnRiskCheckOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnRiskCheckOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RtnRiskCheckOrder:TradingDay:[%s], AccountID:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], RiskID:[%d], RiskStatus:[%d], RiskMessage:[%s]",
			RtnRiskCheckOrder->TradingDay, RtnRiskCheckOrder->AccountID, RtnRiskCheckOrder->PrimaryAccountID, RtnRiskCheckOrder->ExchangeID, RtnRiskCheckOrder->InstrumentID, RtnRiskCheckOrder->OrderID, RtnRiskCheckOrder->RiskID, (int)RtnRiskCheckOrder->RiskStatus, RtnRiskCheckOrder->RiskMessage);
		return t_XtpDataStringBuffer;
	}
	
}
