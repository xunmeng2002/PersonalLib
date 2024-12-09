#include "XtpPackages.h"
#include "MemCacheTemplateSingleton.h"
#include <cstring>

thread_local char t_XtpDataStringBuffer[10240];


namespace xtp
{
 
	XtpNotifyComponentConnectStatusPackage::XtpNotifyComponentConnectStatusPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpNotifyComponentConnectStatusPackage* XtpNotifyComponentConnectStatusPackage::Allocate()
	{
		return ::Allocate<XtpNotifyComponentConnectStatusPackage>();
	}
	void XtpNotifyComponentConnectStatusPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (NotifyComponentConnectStatus != nullptr)
		{
			::Free<NotifyComponentConnectStatusField>(NotifyComponentConnectStatus);
			NotifyComponentConnectStatus = nullptr;
		}
		MemCacheTemplateSingleton<XtpNotifyComponentConnectStatusPackage>::GetInstance().Free(this);
	}
	void XtpNotifyComponentConnectStatusPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpNotifyComponentConnectStatusPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, NotifyComponentConnectStatus, sizeof(NotifyComponentConnectStatusField));
		offset += sizeof(NotifyComponentConnectStatusField);
		return offset;
	}
	bool XtpNotifyComponentConnectStatusPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		NotifyComponentConnectStatus = ::Allocate<NotifyComponentConnectStatusField>();
		memcpy(NotifyComponentConnectStatus, buff + offset, sizeof(NotifyComponentConnectStatusField));
		offset += sizeof(NotifyComponentConnectStatusField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpNotifyComponentConnectStatusPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "NotifyComponentConnectStatus:SessionID:[%lld], Component:[%d], IsConnected:[%d]",
			NotifyComponentConnectStatus->SessionID, (int)NotifyComponentConnectStatus->Component, NotifyComponentConnectStatus->IsConnected);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAccountLoginPackage::XtpReqAccountLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAccountLoginPackage* XtpReqAccountLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqAccountLoginPackage>();
	}
	void XtpReqAccountLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAccountLogin != nullptr)
		{
			::Free<ReqAccountLoginField>(ReqAccountLogin);
			ReqAccountLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAccountLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqAccountLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAccountLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAccountLogin, sizeof(ReqAccountLoginField));
		offset += sizeof(ReqAccountLoginField);
		return offset;
	}
	bool XtpReqAccountLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAccountLogin = ::Allocate<ReqAccountLoginField>();
		memcpy(ReqAccountLogin, buff + offset, sizeof(ReqAccountLoginField));
		offset += sizeof(ReqAccountLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAccountLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAccountLogin:AccountID:[%s], Password:[%s]",
			ReqAccountLogin->AccountID, ReqAccountLogin->Password);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAccountLoginPackage::XtpRspAccountLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAccountLoginPackage* XtpRspAccountLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspAccountLoginPackage>();
	}
	void XtpRspAccountLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAccountLogin != nullptr)
		{
			::Free<RspAccountLoginField>(RspAccountLogin);
			RspAccountLogin = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAccountLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspAccountLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAccountLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAccountLogin, sizeof(RspAccountLoginField));
		offset += sizeof(RspAccountLoginField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAccountLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAccountLogin = ::Allocate<RspAccountLoginField>();
		memcpy(RspAccountLogin, buff + offset, sizeof(RspAccountLoginField));
		offset += sizeof(RspAccountLoginField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAccountLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAccountLogin:AccountID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]",
			RspAccountLogin->AccountID, RspAccountLogin->LoginDate, RspAccountLogin->LoginTime, RspAccountLogin->SessionID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAccountLogoutPackage::XtpReqAccountLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAccountLogoutPackage* XtpReqAccountLogoutPackage::Allocate()
	{
		return ::Allocate<XtpReqAccountLogoutPackage>();
	}
	void XtpReqAccountLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAccountLogout != nullptr)
		{
			::Free<ReqAccountLogoutField>(ReqAccountLogout);
			ReqAccountLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAccountLogoutPackage>::GetInstance().Free(this);
	}
	void XtpReqAccountLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAccountLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAccountLogout, sizeof(ReqAccountLogoutField));
		offset += sizeof(ReqAccountLogoutField);
		return offset;
	}
	bool XtpReqAccountLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAccountLogout = ::Allocate<ReqAccountLogoutField>();
		memcpy(ReqAccountLogout, buff + offset, sizeof(ReqAccountLogoutField));
		offset += sizeof(ReqAccountLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAccountLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAccountLogout:AccountID:[%s]",
			ReqAccountLogout->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAccountLogoutPackage::XtpRspAccountLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAccountLogoutPackage* XtpRspAccountLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRspAccountLogoutPackage>();
	}
	void XtpRspAccountLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAccountLogout != nullptr)
		{
			::Free<RspAccountLogoutField>(RspAccountLogout);
			RspAccountLogout = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAccountLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRspAccountLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAccountLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAccountLogout, sizeof(RspAccountLogoutField));
		offset += sizeof(RspAccountLogoutField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAccountLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAccountLogout = ::Allocate<RspAccountLogoutField>();
		memcpy(RspAccountLogout, buff + offset, sizeof(RspAccountLogoutField));
		offset += sizeof(RspAccountLogoutField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAccountLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAccountLogout:AccountID:[%s]",
			RspAccountLogout->AccountID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryAccountPackage::XtpReqQryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryAccountPackage* XtpReqQryAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqQryAccountPackage>();
	}
	void XtpReqQryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryAccount != nullptr)
		{
			::Free<ReqQryAccountField>(ReqQryAccount);
			ReqQryAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqQryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryAccount, sizeof(ReqQryAccountField));
		offset += sizeof(ReqQryAccountField);
		return offset;
	}
	bool XtpReqQryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryAccount = ::Allocate<ReqQryAccountField>();
		memcpy(ReqQryAccount, buff + offset, sizeof(ReqQryAccountField));
		offset += sizeof(ReqQryAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryAccount:AccountID:[%s]",
			ReqQryAccount->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryAccountPackage::XtpRspQryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryAccountPackage* XtpRspQryAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspQryAccountPackage>();
	}
	void XtpRspQryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Account != nullptr)
		{
			::Free<AccountField>(Account);
			Account = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspQryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Account, sizeof(AccountField));
		offset += sizeof(AccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Account = ::Allocate<AccountField>();
		memcpy(Account, buff + offset, sizeof(AccountField));
		offset += sizeof(AccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Account:AccountID:[%s], AccountType:[%d], AccountStatus:[%d], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d]",
			Account->AccountID, (int)Account->AccountType, (int)Account->AccountStatus, Account->TradeGroupID, Account->RiskGroupID, Account->CommissionGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryHolderAccountPackage::XtpReqQryHolderAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryHolderAccountPackage* XtpReqQryHolderAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqQryHolderAccountPackage>();
	}
	void XtpReqQryHolderAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryHolderAccount != nullptr)
		{
			::Free<ReqQryHolderAccountField>(ReqQryHolderAccount);
			ReqQryHolderAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryHolderAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqQryHolderAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryHolderAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryHolderAccount, sizeof(ReqQryHolderAccountField));
		offset += sizeof(ReqQryHolderAccountField);
		return offset;
	}
	bool XtpReqQryHolderAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryHolderAccount = ::Allocate<ReqQryHolderAccountField>();
		memcpy(ReqQryHolderAccount, buff + offset, sizeof(ReqQryHolderAccountField));
		offset += sizeof(ReqQryHolderAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryHolderAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryHolderAccount:AccountID:[%s]",
			ReqQryHolderAccount->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryHolderAccountPackage::XtpRspQryHolderAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryHolderAccountPackage* XtpRspQryHolderAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspQryHolderAccountPackage>();
	}
	void XtpRspQryHolderAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (HolderAccount != nullptr)
		{
			::Free<HolderAccountField>(HolderAccount);
			HolderAccount = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryHolderAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspQryHolderAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryHolderAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, HolderAccount, sizeof(HolderAccountField));
		offset += sizeof(HolderAccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryHolderAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		HolderAccount = ::Allocate<HolderAccountField>();
		memcpy(HolderAccount, buff + offset, sizeof(HolderAccountField));
		offset += sizeof(HolderAccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryHolderAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "HolderAccount:ExchangeID:[%s], HolderAccountID:[%s], PrimaryFlag:[%d]",
			HolderAccount->ExchangeID, HolderAccount->HolderAccountID, HolderAccount->PrimaryFlag);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryCapitalPackage::XtpReqQryCapitalPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryCapitalPackage* XtpReqQryCapitalPackage::Allocate()
	{
		return ::Allocate<XtpReqQryCapitalPackage>();
	}
	void XtpReqQryCapitalPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryCapital != nullptr)
		{
			::Free<ReqQryCapitalField>(ReqQryCapital);
			ReqQryCapital = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryCapitalPackage>::GetInstance().Free(this);
	}
	void XtpReqQryCapitalPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryCapitalPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryCapital, sizeof(ReqQryCapitalField));
		offset += sizeof(ReqQryCapitalField);
		return offset;
	}
	bool XtpReqQryCapitalPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryCapital = ::Allocate<ReqQryCapitalField>();
		memcpy(ReqQryCapital, buff + offset, sizeof(ReqQryCapitalField));
		offset += sizeof(ReqQryCapitalField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryCapitalPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryCapital:AccountID:[%s]",
			ReqQryCapital->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryCapitalPackage::XtpRspQryCapitalPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryCapitalPackage* XtpRspQryCapitalPackage::Allocate()
	{
		return ::Allocate<XtpRspQryCapitalPackage>();
	}
	void XtpRspQryCapitalPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Capital != nullptr)
		{
			::Free<CapitalField>(Capital);
			Capital = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryCapitalPackage>::GetInstance().Free(this);
	}
	void XtpRspQryCapitalPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryCapitalPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Capital, sizeof(CapitalField));
		offset += sizeof(CapitalField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryCapitalPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Capital = ::Allocate<CapitalField>();
		memcpy(Capital, buff + offset, sizeof(CapitalField));
		offset += sizeof(CapitalField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryCapitalPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Capital:TradingDay:[%s], AccountID:[%s], AccountType:[%d], Asset:[%f], PreAsset:[%f], CashAsset:[%f], PreCashAsset:[%f], Available:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f], MarketValue:[%f], TotalProfit:[%f], TodayProfit:[%f], Deposit:[%f], Withdraw:[%f]",
			Capital->TradingDay, Capital->AccountID, (int)Capital->AccountType, Capital->Asset, Capital->PreAsset, Capital->CashAsset, Capital->PreCashAsset, Capital->Available, Capital->CashIn, Capital->CashOut, Capital->Margin, Capital->Commission, Capital->StampTax, Capital->TransferFee, Capital->FrozenCash, Capital->FrozenMargin, Capital->FrozenCommission, Capital->FrozenStampTax, Capital->FrozenTransferFee, Capital->MarketValue, Capital->TotalProfit, Capital->TodayProfit, Capital->Deposit, Capital->Withdraw);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryPositionPackage::XtpReqQryPositionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryPositionPackage* XtpReqQryPositionPackage::Allocate()
	{
		return ::Allocate<XtpReqQryPositionPackage>();
	}
	void XtpReqQryPositionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryPosition != nullptr)
		{
			::Free<ReqQryPositionField>(ReqQryPosition);
			ReqQryPosition = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryPositionPackage>::GetInstance().Free(this);
	}
	void XtpReqQryPositionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryPositionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryPosition, sizeof(ReqQryPositionField));
		offset += sizeof(ReqQryPositionField);
		return offset;
	}
	bool XtpReqQryPositionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryPosition = ::Allocate<ReqQryPositionField>();
		memcpy(ReqQryPosition, buff + offset, sizeof(ReqQryPositionField));
		offset += sizeof(ReqQryPositionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryPositionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryPosition:AccountID:[%s]",
			ReqQryPosition->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryPositionPackage::XtpRspQryPositionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryPositionPackage* XtpRspQryPositionPackage::Allocate()
	{
		return ::Allocate<XtpRspQryPositionPackage>();
	}
	void XtpRspQryPositionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Position != nullptr)
		{
			::Free<PositionField>(Position);
			Position = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryPositionPackage>::GetInstance().Free(this);
	}
	void XtpRspQryPositionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryPositionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Position, sizeof(PositionField));
		offset += sizeof(PositionField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryPositionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Position = ::Allocate<PositionField>();
		memcpy(Position, buff + offset, sizeof(PositionField));
		offset += sizeof(PositionField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryPositionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Position:TradingDay:[%s], AccountID:[%s], AccountType:[%d], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TodayPosition:[%d], TotalCostPrice:[%f], TodayCostPrice:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], MarketValue:[%f], VolumeMultiple:[%d], TotalCost:[%f], TodayCost:[%f], TotalProfit:[%f], TodayProfit:[%f], LastPrice:[%f], PrePrice:[%f]",
			Position->TradingDay, Position->AccountID, (int)Position->AccountType, Position->ExchangeID, Position->InstrumentID, (int)Position->SecurityType, (int)Position->PosiDirection, Position->TotalPosition, Position->PositionFrozen, Position->TodayPosition, Position->TotalCostPrice, Position->TodayCostPrice, Position->CashIn, Position->CashOut, Position->Margin, Position->Commission, Position->StampTax, Position->TransferFee, Position->MarketValue, Position->VolumeMultiple, Position->TotalCost, Position->TodayCost, Position->TotalProfit, Position->TodayProfit, Position->LastPrice, Position->PrePrice);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryOrderPackage::XtpReqQryOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryOrderPackage* XtpReqQryOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqQryOrderPackage>();
	}
	void XtpReqQryOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryOrder != nullptr)
		{
			::Free<ReqQryOrderField>(ReqQryOrder);
			ReqQryOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqQryOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryOrder, sizeof(ReqQryOrderField));
		offset += sizeof(ReqQryOrderField);
		return offset;
	}
	bool XtpReqQryOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryOrder = ::Allocate<ReqQryOrderField>();
		memcpy(ReqQryOrder, buff + offset, sizeof(ReqQryOrderField));
		offset += sizeof(ReqQryOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryOrder:AccountID:[%s]",
			ReqQryOrder->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryOrderPackage::XtpRspQryOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryOrderPackage* XtpRspQryOrderPackage::Allocate()
	{
		return ::Allocate<XtpRspQryOrderPackage>();
	}
	void XtpRspQryOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Order != nullptr)
		{
			::Free<OrderField>(Order);
			Order = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryOrderPackage>::GetInstance().Free(this);
	}
	void XtpRspQryOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Order, sizeof(OrderField));
		offset += sizeof(OrderField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Order = ::Allocate<OrderField>();
		memcpy(Order, buff + offset, sizeof(OrderField));
		offset += sizeof(OrderField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Order:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]",
			Order->TradingDay, Order->AccountID, Order->ExchangeID, Order->InstrumentID, (int)Order->SecurityType, Order->OrderID, Order->OrderSysID, (int)Order->Direction, (int)Order->OffsetFlag, (int)Order->OrderPriceType, Order->Price, Order->Volume, Order->VolumeTotal, Order->VolumeTraded, Order->VolumeMultiple, (int)Order->OrderStatus, Order->StatusMsg, Order->OrderDate, Order->OrderTime, Order->CancelDate, Order->CancelTime, Order->SessionID, Order->ClientOrderID, Order->RequestID, Order->FrozenCash, Order->FrozenMargin, Order->FrozenCommission, Order->FrozenStampTax, Order->FrozenTransferFee);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryTradePackage::XtpReqQryTradePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryTradePackage* XtpReqQryTradePackage::Allocate()
	{
		return ::Allocate<XtpReqQryTradePackage>();
	}
	void XtpReqQryTradePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryTrade != nullptr)
		{
			::Free<ReqQryTradeField>(ReqQryTrade);
			ReqQryTrade = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryTradePackage>::GetInstance().Free(this);
	}
	void XtpReqQryTradePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryTradePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryTrade, sizeof(ReqQryTradeField));
		offset += sizeof(ReqQryTradeField);
		return offset;
	}
	bool XtpReqQryTradePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryTrade = ::Allocate<ReqQryTradeField>();
		memcpy(ReqQryTrade, buff + offset, sizeof(ReqQryTradeField));
		offset += sizeof(ReqQryTradeField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryTradePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryTrade:AccountID:[%s]",
			ReqQryTrade->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryTradePackage::XtpRspQryTradePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryTradePackage* XtpRspQryTradePackage::Allocate()
	{
		return ::Allocate<XtpRspQryTradePackage>();
	}
	void XtpRspQryTradePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Trade != nullptr)
		{
			::Free<TradeField>(Trade);
			Trade = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryTradePackage>::GetInstance().Free(this);
	}
	void XtpRspQryTradePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryTradePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Trade, sizeof(TradeField));
		offset += sizeof(TradeField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryTradePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Trade = ::Allocate<TradeField>();
		memcpy(Trade, buff + offset, sizeof(TradeField));
		offset += sizeof(TradeField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryTradePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Trade:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], VolumeMultiple:[%d], TradeAmount:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], TradeDate:[%s], TradeTime:[%s]",
			Trade->TradingDay, Trade->AccountID, Trade->ExchangeID, Trade->InstrumentID, (int)Trade->SecurityType, Trade->OrderID, Trade->OrderSysID, Trade->TradeID, (int)Trade->Direction, (int)Trade->OffsetFlag, Trade->Price, Trade->Volume, Trade->VolumeMultiple, Trade->TradeAmount, Trade->Commission, Trade->StampTax, Trade->TransferFee, Trade->TradeDate, Trade->TradeTime);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryInstrumentPackage::XtpReqQryInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryInstrumentPackage* XtpReqQryInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpReqQryInstrumentPackage>();
	}
	void XtpReqQryInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryInstrument != nullptr)
		{
			::Free<ReqQryInstrumentField>(ReqQryInstrument);
			ReqQryInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpReqQryInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryInstrument, sizeof(ReqQryInstrumentField));
		offset += sizeof(ReqQryInstrumentField);
		return offset;
	}
	bool XtpReqQryInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryInstrument = ::Allocate<ReqQryInstrumentField>();
		memcpy(ReqQryInstrument, buff + offset, sizeof(ReqQryInstrumentField));
		offset += sizeof(ReqQryInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryInstrument:ExchangeID:[%s], InstrumentID:[%s]",
			ReqQryInstrument->ExchangeID, ReqQryInstrument->InstrumentID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryInstrumentPackage::XtpRspQryInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryInstrumentPackage* XtpRspQryInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRspQryInstrumentPackage>();
	}
	void XtpRspQryInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Instrument != nullptr)
		{
			::Free<InstrumentField>(Instrument);
			Instrument = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRspQryInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Instrument, sizeof(InstrumentField));
		offset += sizeof(InstrumentField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Instrument = ::Allocate<InstrumentField>();
		memcpy(Instrument, buff + offset, sizeof(InstrumentField));
		offset += sizeof(InstrumentField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Instrument:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], SecurityType:[%d]",
			Instrument->ExchangeID, Instrument->InstrumentID, Instrument->ExchangeInstID, Instrument->InstrumentName, Instrument->VolumeMultiple, (int)Instrument->SecurityType);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
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
			::Free<ReqQryOptionInstrumentField>(ReqQryOptionInstrument);
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
		memcpy(buff + offset, ReqQryOptionInstrument, sizeof(ReqQryOptionInstrumentField));
		offset += sizeof(ReqQryOptionInstrumentField);
		return offset;
	}
	bool XtpReqQryOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryOptionInstrument = ::Allocate<ReqQryOptionInstrumentField>();
		memcpy(ReqQryOptionInstrument, buff + offset, sizeof(ReqQryOptionInstrumentField));
		offset += sizeof(ReqQryOptionInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryOptionInstrument:ExchangeID:[%s], InstrumentID:[%s]",
			ReqQryOptionInstrument->ExchangeID, ReqQryOptionInstrument->InstrumentID);
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
		if (OptionInstrument != nullptr)
		{
			::Free<OptionInstrumentField>(OptionInstrument);
			OptionInstrument = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
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
		memcpy(buff + offset, OptionInstrument, sizeof(OptionInstrumentField));
		offset += sizeof(OptionInstrumentField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		OptionInstrument = ::Allocate<OptionInstrumentField>();
		memcpy(OptionInstrument, buff + offset, sizeof(OptionInstrumentField));
		offset += sizeof(OptionInstrumentField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "OptionInstrument:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]",
			OptionInstrument->ExchangeID, OptionInstrument->InstrumentID, OptionInstrument->ExchangeInstID, OptionInstrument->InstrumentName, OptionInstrument->VolumeMultiple, (int)OptionInstrument->OptionType, OptionInstrument->UnderlyingInstrumentID, OptionInstrument->ExecutePrice, OptionInstrument->UnitMargin, OptionInstrument->PriceTick, OptionInstrument->MaxLimitOrderVolume, OptionInstrument->MaxMarketOrderVolume, OptionInstrument->ExpiringDate);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryCommissionRatePackage::XtpReqQryCommissionRatePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryCommissionRatePackage* XtpReqQryCommissionRatePackage::Allocate()
	{
		return ::Allocate<XtpReqQryCommissionRatePackage>();
	}
	void XtpReqQryCommissionRatePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryCommissionRate != nullptr)
		{
			::Free<ReqQryCommissionRateField>(ReqQryCommissionRate);
			ReqQryCommissionRate = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryCommissionRatePackage>::GetInstance().Free(this);
	}
	void XtpReqQryCommissionRatePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryCommissionRatePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryCommissionRate, sizeof(ReqQryCommissionRateField));
		offset += sizeof(ReqQryCommissionRateField);
		return offset;
	}
	bool XtpReqQryCommissionRatePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryCommissionRate = ::Allocate<ReqQryCommissionRateField>();
		memcpy(ReqQryCommissionRate, buff + offset, sizeof(ReqQryCommissionRateField));
		offset += sizeof(ReqQryCommissionRateField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryCommissionRatePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryCommissionRate:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d]",
			ReqQryCommissionRate->AccountID, ReqQryCommissionRate->ExchangeID, (int)ReqQryCommissionRate->SecurityType);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryCommissionRatePackage::XtpRspQryCommissionRatePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryCommissionRatePackage* XtpRspQryCommissionRatePackage::Allocate()
	{
		return ::Allocate<XtpRspQryCommissionRatePackage>();
	}
	void XtpRspQryCommissionRatePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (CommissionRate != nullptr)
		{
			::Free<CommissionRateField>(CommissionRate);
			CommissionRate = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryCommissionRatePackage>::GetInstance().Free(this);
	}
	void XtpRspQryCommissionRatePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryCommissionRatePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, CommissionRate, sizeof(CommissionRateField));
		offset += sizeof(CommissionRateField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryCommissionRatePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		CommissionRate = ::Allocate<CommissionRateField>();
		memcpy(CommissionRate, buff + offset, sizeof(CommissionRateField));
		offset += sizeof(CommissionRateField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryCommissionRatePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "CommissionRate:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]",
			CommissionRate->AccountID, CommissionRate->ExchangeID, (int)CommissionRate->SecurityType, CommissionRate->OpenBuyByMoney, CommissionRate->OpenSellByMoney, CommissionRate->CloseBuyByMoney, CommissionRate->CloseSellByMoney, CommissionRate->OpenBuyByVolume, CommissionRate->OpenSellByVolume, CommissionRate->CloseBuyByVolume, CommissionRate->CloseSellByVolume, CommissionRate->MinCommission, CommissionRate->MaxCommission);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryMoneyTransferPackage::XtpReqQryMoneyTransferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryMoneyTransferPackage* XtpReqQryMoneyTransferPackage::Allocate()
	{
		return ::Allocate<XtpReqQryMoneyTransferPackage>();
	}
	void XtpReqQryMoneyTransferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryMoneyTransfer != nullptr)
		{
			::Free<ReqQryMoneyTransferField>(ReqQryMoneyTransfer);
			ReqQryMoneyTransfer = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryMoneyTransferPackage>::GetInstance().Free(this);
	}
	void XtpReqQryMoneyTransferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryMoneyTransferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryMoneyTransfer, sizeof(ReqQryMoneyTransferField));
		offset += sizeof(ReqQryMoneyTransferField);
		return offset;
	}
	bool XtpReqQryMoneyTransferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryMoneyTransfer = ::Allocate<ReqQryMoneyTransferField>();
		memcpy(ReqQryMoneyTransfer, buff + offset, sizeof(ReqQryMoneyTransferField));
		offset += sizeof(ReqQryMoneyTransferField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryMoneyTransferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryMoneyTransfer:AccountID:[%s]",
			ReqQryMoneyTransfer->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryMoneyTransferPackage::XtpRspQryMoneyTransferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryMoneyTransferPackage* XtpRspQryMoneyTransferPackage::Allocate()
	{
		return ::Allocate<XtpRspQryMoneyTransferPackage>();
	}
	void XtpRspQryMoneyTransferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (MoneyTransfer != nullptr)
		{
			::Free<MoneyTransferField>(MoneyTransfer);
			MoneyTransfer = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryMoneyTransferPackage>::GetInstance().Free(this);
	}
	void XtpRspQryMoneyTransferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryMoneyTransferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, MoneyTransfer, sizeof(MoneyTransferField));
		offset += sizeof(MoneyTransferField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryMoneyTransferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		MoneyTransfer = ::Allocate<MoneyTransferField>();
		memcpy(MoneyTransfer, buff + offset, sizeof(MoneyTransferField));
		offset += sizeof(MoneyTransferField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryMoneyTransferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "MoneyTransfer:TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]",
			MoneyTransfer->TradingDay, MoneyTransfer->AccountID, MoneyTransfer->MoneyTransferID, (int)MoneyTransfer->AccountType, (int)MoneyTransfer->TransferDirection, MoneyTransfer->TransferAmount, MoneyTransfer->InfoMessage, MoneyTransfer->UserID, MoneyTransfer->TransferDate, MoneyTransfer->TransferTime);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
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
			::Free<ReqInsertOrderField>(ReqInsertOrder);
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
		memcpy(buff + offset, ReqInsertOrder, sizeof(ReqInsertOrderField));
		offset += sizeof(ReqInsertOrderField);
		return offset;
	}
	bool XtpReqInsertOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqInsertOrder = ::Allocate<ReqInsertOrderField>();
		memcpy(ReqInsertOrder, buff + offset, sizeof(ReqInsertOrderField));
		offset += sizeof(ReqInsertOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqInsertOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqInsertOrder:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d]",
			ReqInsertOrder->AccountID, ReqInsertOrder->ExchangeID, ReqInsertOrder->InstrumentID, (int)ReqInsertOrder->Direction, (int)ReqInsertOrder->OffsetFlag, (int)ReqInsertOrder->OrderPriceType, ReqInsertOrder->Price, ReqInsertOrder->Volume, ReqInsertOrder->ClientOrderID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspInsertOrderPackage::XtpRspInsertOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspInsertOrderPackage* XtpRspInsertOrderPackage::Allocate()
	{
		return ::Allocate<XtpRspInsertOrderPackage>();
	}
	void XtpRspInsertOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Order != nullptr)
		{
			::Free<OrderField>(Order);
			Order = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspInsertOrderPackage>::GetInstance().Free(this);
	}
	void XtpRspInsertOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspInsertOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Order, sizeof(OrderField));
		offset += sizeof(OrderField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspInsertOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Order = ::Allocate<OrderField>();
		memcpy(Order, buff + offset, sizeof(OrderField));
		offset += sizeof(OrderField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspInsertOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Order:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]",
			Order->TradingDay, Order->AccountID, Order->ExchangeID, Order->InstrumentID, (int)Order->SecurityType, Order->OrderID, Order->OrderSysID, (int)Order->Direction, (int)Order->OffsetFlag, (int)Order->OrderPriceType, Order->Price, Order->Volume, Order->VolumeTotal, Order->VolumeTraded, Order->VolumeMultiple, (int)Order->OrderStatus, Order->StatusMsg, Order->OrderDate, Order->OrderTime, Order->CancelDate, Order->CancelTime, Order->SessionID, Order->ClientOrderID, Order->RequestID, Order->FrozenCash, Order->FrozenMargin, Order->FrozenCommission, Order->FrozenStampTax, Order->FrozenTransferFee);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
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
			::Free<ReqCancelOrderField>(ReqCancelOrder);
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
		memcpy(buff + offset, ReqCancelOrder, sizeof(ReqCancelOrderField));
		offset += sizeof(ReqCancelOrderField);
		return offset;
	}
	bool XtpReqCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqCancelOrder = ::Allocate<ReqCancelOrderField>();
		memcpy(ReqCancelOrder, buff + offset, sizeof(ReqCancelOrderField));
		offset += sizeof(ReqCancelOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqCancelOrder:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]",
			ReqCancelOrder->AccountID, ReqCancelOrder->ExchangeID, ReqCancelOrder->InstrumentID, ReqCancelOrder->ClientCancelOrderID, ReqCancelOrder->OrderID, ReqCancelOrder->OrderSysID, ReqCancelOrder->ClientOrderID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspCancelOrderPackage::XtpRspCancelOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspCancelOrderPackage* XtpRspCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpRspCancelOrderPackage>();
	}
	void XtpRspCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (CancelOrder != nullptr)
		{
			::Free<CancelOrderField>(CancelOrder);
			CancelOrder = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpRspCancelOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, CancelOrder, sizeof(CancelOrderField));
		offset += sizeof(CancelOrderField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		CancelOrder = ::Allocate<CancelOrderField>();
		memcpy(CancelOrder, buff + offset, sizeof(CancelOrderField));
		offset += sizeof(CancelOrderField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "CancelOrder:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]",
			CancelOrder->AccountID, CancelOrder->ExchangeID, CancelOrder->InstrumentID, CancelOrder->ClientCancelOrderID, CancelOrder->OrderID, CancelOrder->OrderSysID, CancelOrder->ClientOrderID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
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
		if (Order != nullptr)
		{
			::Free<OrderField>(Order);
			Order = nullptr;
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
		memcpy(buff + offset, Order, sizeof(OrderField));
		offset += sizeof(OrderField);
		return offset;
	}
	bool XtpRtnOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Order = ::Allocate<OrderField>();
		memcpy(Order, buff + offset, sizeof(OrderField));
		offset += sizeof(OrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Order:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]",
			Order->TradingDay, Order->AccountID, Order->ExchangeID, Order->InstrumentID, (int)Order->SecurityType, Order->OrderID, Order->OrderSysID, (int)Order->Direction, (int)Order->OffsetFlag, (int)Order->OrderPriceType, Order->Price, Order->Volume, Order->VolumeTotal, Order->VolumeTraded, Order->VolumeMultiple, (int)Order->OrderStatus, Order->StatusMsg, Order->OrderDate, Order->OrderTime, Order->CancelDate, Order->CancelTime, Order->SessionID, Order->ClientOrderID, Order->RequestID, Order->FrozenCash, Order->FrozenMargin, Order->FrozenCommission, Order->FrozenStampTax, Order->FrozenTransferFee);
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
		if (Trade != nullptr)
		{
			::Free<TradeField>(Trade);
			Trade = nullptr;
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
		memcpy(buff + offset, Trade, sizeof(TradeField));
		offset += sizeof(TradeField);
		return offset;
	}
	bool XtpRtnTradePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Trade = ::Allocate<TradeField>();
		memcpy(Trade, buff + offset, sizeof(TradeField));
		offset += sizeof(TradeField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnTradePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Trade:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], VolumeMultiple:[%d], TradeAmount:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], TradeDate:[%s], TradeTime:[%s]",
			Trade->TradingDay, Trade->AccountID, Trade->ExchangeID, Trade->InstrumentID, (int)Trade->SecurityType, Trade->OrderID, Trade->OrderSysID, Trade->TradeID, (int)Trade->Direction, (int)Trade->OffsetFlag, Trade->Price, Trade->Volume, Trade->VolumeMultiple, Trade->TradeAmount, Trade->Commission, Trade->StampTax, Trade->TransferFee, Trade->TradeDate, Trade->TradeTime);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnMoneyTransferPackage::XtpRtnMoneyTransferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnMoneyTransferPackage* XtpRtnMoneyTransferPackage::Allocate()
	{
		return ::Allocate<XtpRtnMoneyTransferPackage>();
	}
	void XtpRtnMoneyTransferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (MoneyTransfer != nullptr)
		{
			::Free<MoneyTransferField>(MoneyTransfer);
			MoneyTransfer = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnMoneyTransferPackage>::GetInstance().Free(this);
	}
	void XtpRtnMoneyTransferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnMoneyTransferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, MoneyTransfer, sizeof(MoneyTransferField));
		offset += sizeof(MoneyTransferField);
		return offset;
	}
	bool XtpRtnMoneyTransferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		MoneyTransfer = ::Allocate<MoneyTransferField>();
		memcpy(MoneyTransfer, buff + offset, sizeof(MoneyTransferField));
		offset += sizeof(MoneyTransferField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnMoneyTransferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "MoneyTransfer:TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]",
			MoneyTransfer->TradingDay, MoneyTransfer->AccountID, MoneyTransfer->MoneyTransferID, (int)MoneyTransfer->AccountType, (int)MoneyTransfer->TransferDirection, MoneyTransfer->TransferAmount, MoneyTransfer->InfoMessage, MoneyTransfer->UserID, MoneyTransfer->TransferDate, MoneyTransfer->TransferTime);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnAccountLogoutPackage::XtpRtnAccountLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnAccountLogoutPackage* XtpRtnAccountLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRtnAccountLogoutPackage>();
	}
	void XtpRtnAccountLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AccountLogout != nullptr)
		{
			::Free<AccountLogoutField>(AccountLogout);
			AccountLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnAccountLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRtnAccountLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnAccountLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AccountLogout, sizeof(AccountLogoutField));
		offset += sizeof(AccountLogoutField);
		return offset;
	}
	bool XtpRtnAccountLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AccountLogout = ::Allocate<AccountLogoutField>();
		memcpy(AccountLogout, buff + offset, sizeof(AccountLogoutField));
		offset += sizeof(AccountLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnAccountLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AccountLogout:AccountID:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			AccountLogout->AccountID, AccountLogout->ErrorID, AccountLogout->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRiskUserLoginPackage::XtpReqRiskUserLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRiskUserLoginPackage* XtpReqRiskUserLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqRiskUserLoginPackage>();
	}
	void XtpReqRiskUserLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRiskUserLogin != nullptr)
		{
			::Free<ReqRiskUserLoginField>(ReqRiskUserLogin);
			ReqRiskUserLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRiskUserLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqRiskUserLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRiskUserLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRiskUserLogin, sizeof(ReqRiskUserLoginField));
		offset += sizeof(ReqRiskUserLoginField);
		return offset;
	}
	bool XtpReqRiskUserLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRiskUserLogin = ::Allocate<ReqRiskUserLoginField>();
		memcpy(ReqRiskUserLogin, buff + offset, sizeof(ReqRiskUserLoginField));
		offset += sizeof(ReqRiskUserLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRiskUserLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRiskUserLogin:UserID:[%s], Password:[%s]",
			ReqRiskUserLogin->UserID, ReqRiskUserLogin->Password);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRiskUserLoginPackage::XtpRspRiskUserLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRiskUserLoginPackage* XtpRspRiskUserLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspRiskUserLoginPackage>();
	}
	void XtpRspRiskUserLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRiskUserLogin != nullptr)
		{
			::Free<RspRiskUserLoginField>(RspRiskUserLogin);
			RspRiskUserLogin = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRiskUserLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspRiskUserLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRiskUserLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRiskUserLogin, sizeof(RspRiskUserLoginField));
		offset += sizeof(RspRiskUserLoginField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRiskUserLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRiskUserLogin = ::Allocate<RspRiskUserLoginField>();
		memcpy(RspRiskUserLogin, buff + offset, sizeof(RspRiskUserLoginField));
		offset += sizeof(RspRiskUserLoginField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRiskUserLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRiskUserLogin:UserID:[%s], RiskGroupID:[%d], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]",
			RspRiskUserLogin->UserID, RspRiskUserLogin->RiskGroupID, RspRiskUserLogin->LoginDate, RspRiskUserLogin->LoginTime, RspRiskUserLogin->SessionID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRiskUserLogoutPackage::XtpReqRiskUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRiskUserLogoutPackage* XtpReqRiskUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpReqRiskUserLogoutPackage>();
	}
	void XtpReqRiskUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRiskUserLogout != nullptr)
		{
			::Free<ReqRiskUserLogoutField>(ReqRiskUserLogout);
			ReqRiskUserLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRiskUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpReqRiskUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRiskUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRiskUserLogout, sizeof(ReqRiskUserLogoutField));
		offset += sizeof(ReqRiskUserLogoutField);
		return offset;
	}
	bool XtpReqRiskUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRiskUserLogout = ::Allocate<ReqRiskUserLogoutField>();
		memcpy(ReqRiskUserLogout, buff + offset, sizeof(ReqRiskUserLogoutField));
		offset += sizeof(ReqRiskUserLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRiskUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRiskUserLogout:UserID:[%s]",
			ReqRiskUserLogout->UserID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRiskUserLogoutPackage::XtpRspRiskUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRiskUserLogoutPackage* XtpRspRiskUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRspRiskUserLogoutPackage>();
	}
	void XtpRspRiskUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRiskUserLogout != nullptr)
		{
			::Free<RspRiskUserLogoutField>(RspRiskUserLogout);
			RspRiskUserLogout = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRiskUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRspRiskUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRiskUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRiskUserLogout, sizeof(RspRiskUserLogoutField));
		offset += sizeof(RspRiskUserLogoutField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRiskUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRiskUserLogout = ::Allocate<RspRiskUserLogoutField>();
		memcpy(RspRiskUserLogout, buff + offset, sizeof(RspRiskUserLogoutField));
		offset += sizeof(RspRiskUserLogoutField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRiskUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRiskUserLogout:UserID:[%s]",
			RspRiskUserLogout->UserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnRiskUserLogoutPackage::XtpRtnRiskUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnRiskUserLogoutPackage* XtpRtnRiskUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRtnRiskUserLogoutPackage>();
	}
	void XtpRtnRiskUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RiskUserLogout != nullptr)
		{
			::Free<RiskUserLogoutField>(RiskUserLogout);
			RiskUserLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnRiskUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRtnRiskUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnRiskUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RiskUserLogout, sizeof(RiskUserLogoutField));
		offset += sizeof(RiskUserLogoutField);
		return offset;
	}
	bool XtpRtnRiskUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RiskUserLogout = ::Allocate<RiskUserLogoutField>();
		memcpy(RiskUserLogout, buff + offset, sizeof(RiskUserLogoutField));
		offset += sizeof(RiskUserLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnRiskUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RiskUserLogout:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			RiskUserLogout->UserID, RiskUserLogout->ErrorID, RiskUserLogout->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnAccountPackage::XtpRtnAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnAccountPackage* XtpRtnAccountPackage::Allocate()
	{
		return ::Allocate<XtpRtnAccountPackage>();
	}
	void XtpRtnAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Account != nullptr)
		{
			::Free<AccountField>(Account);
			Account = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnAccountPackage>::GetInstance().Free(this);
	}
	void XtpRtnAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Account, sizeof(AccountField));
		offset += sizeof(AccountField);
		return offset;
	}
	bool XtpRtnAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Account = ::Allocate<AccountField>();
		memcpy(Account, buff + offset, sizeof(AccountField));
		offset += sizeof(AccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Account:AccountID:[%s], AccountType:[%d], AccountStatus:[%d], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d]",
			Account->AccountID, (int)Account->AccountType, (int)Account->AccountStatus, Account->TradeGroupID, Account->RiskGroupID, Account->CommissionGroupID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnAccountDeletePackage::XtpRtnAccountDeletePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnAccountDeletePackage* XtpRtnAccountDeletePackage::Allocate()
	{
		return ::Allocate<XtpRtnAccountDeletePackage>();
	}
	void XtpRtnAccountDeletePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AccountDelete != nullptr)
		{
			::Free<AccountDeleteField>(AccountDelete);
			AccountDelete = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnAccountDeletePackage>::GetInstance().Free(this);
	}
	void XtpRtnAccountDeletePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnAccountDeletePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AccountDelete, sizeof(AccountDeleteField));
		offset += sizeof(AccountDeleteField);
		return offset;
	}
	bool XtpRtnAccountDeletePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AccountDelete = ::Allocate<AccountDeleteField>();
		memcpy(AccountDelete, buff + offset, sizeof(AccountDeleteField));
		offset += sizeof(AccountDeleteField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnAccountDeletePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AccountDelete:AccountID:[%s]",
			AccountDelete->AccountID);
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
		if (Position != nullptr)
		{
			::Free<PositionField>(Position);
			Position = nullptr;
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
		memcpy(buff + offset, Position, sizeof(PositionField));
		offset += sizeof(PositionField);
		return offset;
	}
	bool XtpRtnPositionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Position = ::Allocate<PositionField>();
		memcpy(Position, buff + offset, sizeof(PositionField));
		offset += sizeof(PositionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnPositionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Position:TradingDay:[%s], AccountID:[%s], AccountType:[%d], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TodayPosition:[%d], TotalCostPrice:[%f], TodayCostPrice:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], MarketValue:[%f], VolumeMultiple:[%d], TotalCost:[%f], TodayCost:[%f], TotalProfit:[%f], TodayProfit:[%f], LastPrice:[%f], PrePrice:[%f]",
			Position->TradingDay, Position->AccountID, (int)Position->AccountType, Position->ExchangeID, Position->InstrumentID, (int)Position->SecurityType, (int)Position->PosiDirection, Position->TotalPosition, Position->PositionFrozen, Position->TodayPosition, Position->TotalCostPrice, Position->TodayCostPrice, Position->CashIn, Position->CashOut, Position->Margin, Position->Commission, Position->StampTax, Position->TransferFee, Position->MarketValue, Position->VolumeMultiple, Position->TotalCost, Position->TodayCost, Position->TotalProfit, Position->TodayProfit, Position->LastPrice, Position->PrePrice);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnAccountRiskPackage::XtpRtnAccountRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnAccountRiskPackage* XtpRtnAccountRiskPackage::Allocate()
	{
		return ::Allocate<XtpRtnAccountRiskPackage>();
	}
	void XtpRtnAccountRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AccountRisk != nullptr)
		{
			::Free<AccountRiskField>(AccountRisk);
			AccountRisk = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnAccountRiskPackage>::GetInstance().Free(this);
	}
	void XtpRtnAccountRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnAccountRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AccountRisk, sizeof(AccountRiskField));
		offset += sizeof(AccountRiskField);
		return offset;
	}
	bool XtpRtnAccountRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AccountRisk = ::Allocate<AccountRiskField>();
		memcpy(AccountRisk, buff + offset, sizeof(AccountRiskField));
		offset += sizeof(AccountRiskField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnAccountRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AccountRisk:AccountID:[%s], RiskID:[%d], RiskStatus:[%d]",
			AccountRisk->AccountID, AccountRisk->RiskID, (int)AccountRisk->RiskStatus);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnAccountRiskDeletePackage::XtpRtnAccountRiskDeletePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnAccountRiskDeletePackage* XtpRtnAccountRiskDeletePackage::Allocate()
	{
		return ::Allocate<XtpRtnAccountRiskDeletePackage>();
	}
	void XtpRtnAccountRiskDeletePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AccountRiskDelete != nullptr)
		{
			::Free<AccountRiskDeleteField>(AccountRiskDelete);
			AccountRiskDelete = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnAccountRiskDeletePackage>::GetInstance().Free(this);
	}
	void XtpRtnAccountRiskDeletePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnAccountRiskDeletePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AccountRiskDelete, sizeof(AccountRiskDeleteField));
		offset += sizeof(AccountRiskDeleteField);
		return offset;
	}
	bool XtpRtnAccountRiskDeletePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AccountRiskDelete = ::Allocate<AccountRiskDeleteField>();
		memcpy(AccountRiskDelete, buff + offset, sizeof(AccountRiskDeleteField));
		offset += sizeof(AccountRiskDeleteField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnAccountRiskDeletePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AccountRiskDelete:AccountID:[%s], RiskID:[%d]",
			AccountRiskDelete->AccountID, AccountRiskDelete->RiskID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnAccountRiskNotifyPackage::XtpRtnAccountRiskNotifyPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnAccountRiskNotifyPackage* XtpRtnAccountRiskNotifyPackage::Allocate()
	{
		return ::Allocate<XtpRtnAccountRiskNotifyPackage>();
	}
	void XtpRtnAccountRiskNotifyPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AccountRiskNotify != nullptr)
		{
			::Free<AccountRiskNotifyField>(AccountRiskNotify);
			AccountRiskNotify = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnAccountRiskNotifyPackage>::GetInstance().Free(this);
	}
	void XtpRtnAccountRiskNotifyPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnAccountRiskNotifyPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AccountRiskNotify, sizeof(AccountRiskNotifyField));
		offset += sizeof(AccountRiskNotifyField);
		return offset;
	}
	bool XtpRtnAccountRiskNotifyPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AccountRiskNotify = ::Allocate<AccountRiskNotifyField>();
		memcpy(AccountRiskNotify, buff + offset, sizeof(AccountRiskNotifyField));
		offset += sizeof(AccountRiskNotifyField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnAccountRiskNotifyPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AccountRiskNotify:NotifyDate:[%s], NotifyTime:[%s], AccountID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskStatus:[%d], RiskMessage:[%s]",
			AccountRiskNotify->NotifyDate, AccountRiskNotify->NotifyTime, AccountRiskNotify->AccountID, AccountRiskNotify->RiskID, AccountRiskNotify->RiskRuleID, (int)AccountRiskNotify->RiskStatus, AccountRiskNotify->RiskMessage);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryRiskGroupAccountPackage::XtpReqQryRiskGroupAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryRiskGroupAccountPackage* XtpReqQryRiskGroupAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqQryRiskGroupAccountPackage>();
	}
	void XtpReqQryRiskGroupAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryRiskGroupAccount != nullptr)
		{
			::Free<ReqQryRiskGroupAccountField>(ReqQryRiskGroupAccount);
			ReqQryRiskGroupAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryRiskGroupAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqQryRiskGroupAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryRiskGroupAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryRiskGroupAccount, sizeof(ReqQryRiskGroupAccountField));
		offset += sizeof(ReqQryRiskGroupAccountField);
		return offset;
	}
	bool XtpReqQryRiskGroupAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryRiskGroupAccount = ::Allocate<ReqQryRiskGroupAccountField>();
		memcpy(ReqQryRiskGroupAccount, buff + offset, sizeof(ReqQryRiskGroupAccountField));
		offset += sizeof(ReqQryRiskGroupAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryRiskGroupAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryRiskGroupAccount:UserID:[%s]",
			ReqQryRiskGroupAccount->UserID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryRiskGroupAccountPackage::XtpRspQryRiskGroupAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryRiskGroupAccountPackage* XtpRspQryRiskGroupAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspQryRiskGroupAccountPackage>();
	}
	void XtpRspQryRiskGroupAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Account != nullptr)
		{
			::Free<AccountField>(Account);
			Account = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryRiskGroupAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspQryRiskGroupAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryRiskGroupAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Account, sizeof(AccountField));
		offset += sizeof(AccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryRiskGroupAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Account = ::Allocate<AccountField>();
		memcpy(Account, buff + offset, sizeof(AccountField));
		offset += sizeof(AccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryRiskGroupAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Account:AccountID:[%s], AccountType:[%d], AccountStatus:[%d], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d]",
			Account->AccountID, (int)Account->AccountType, (int)Account->AccountStatus, Account->TradeGroupID, Account->RiskGroupID, Account->CommissionGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryRiskGroupCapitalPackage::XtpReqQryRiskGroupCapitalPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryRiskGroupCapitalPackage* XtpReqQryRiskGroupCapitalPackage::Allocate()
	{
		return ::Allocate<XtpReqQryRiskGroupCapitalPackage>();
	}
	void XtpReqQryRiskGroupCapitalPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryRiskGroupCapital != nullptr)
		{
			::Free<ReqQryRiskGroupCapitalField>(ReqQryRiskGroupCapital);
			ReqQryRiskGroupCapital = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryRiskGroupCapitalPackage>::GetInstance().Free(this);
	}
	void XtpReqQryRiskGroupCapitalPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryRiskGroupCapitalPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryRiskGroupCapital, sizeof(ReqQryRiskGroupCapitalField));
		offset += sizeof(ReqQryRiskGroupCapitalField);
		return offset;
	}
	bool XtpReqQryRiskGroupCapitalPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryRiskGroupCapital = ::Allocate<ReqQryRiskGroupCapitalField>();
		memcpy(ReqQryRiskGroupCapital, buff + offset, sizeof(ReqQryRiskGroupCapitalField));
		offset += sizeof(ReqQryRiskGroupCapitalField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryRiskGroupCapitalPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryRiskGroupCapital:UserID:[%s], AccountID:[%s]",
			ReqQryRiskGroupCapital->UserID, ReqQryRiskGroupCapital->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryRiskGroupCapitalPackage::XtpRspQryRiskGroupCapitalPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryRiskGroupCapitalPackage* XtpRspQryRiskGroupCapitalPackage::Allocate()
	{
		return ::Allocate<XtpRspQryRiskGroupCapitalPackage>();
	}
	void XtpRspQryRiskGroupCapitalPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Capital != nullptr)
		{
			::Free<CapitalField>(Capital);
			Capital = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryRiskGroupCapitalPackage>::GetInstance().Free(this);
	}
	void XtpRspQryRiskGroupCapitalPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryRiskGroupCapitalPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Capital, sizeof(CapitalField));
		offset += sizeof(CapitalField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryRiskGroupCapitalPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Capital = ::Allocate<CapitalField>();
		memcpy(Capital, buff + offset, sizeof(CapitalField));
		offset += sizeof(CapitalField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryRiskGroupCapitalPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Capital:TradingDay:[%s], AccountID:[%s], AccountType:[%d], Asset:[%f], PreAsset:[%f], CashAsset:[%f], PreCashAsset:[%f], Available:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f], MarketValue:[%f], TotalProfit:[%f], TodayProfit:[%f], Deposit:[%f], Withdraw:[%f]",
			Capital->TradingDay, Capital->AccountID, (int)Capital->AccountType, Capital->Asset, Capital->PreAsset, Capital->CashAsset, Capital->PreCashAsset, Capital->Available, Capital->CashIn, Capital->CashOut, Capital->Margin, Capital->Commission, Capital->StampTax, Capital->TransferFee, Capital->FrozenCash, Capital->FrozenMargin, Capital->FrozenCommission, Capital->FrozenStampTax, Capital->FrozenTransferFee, Capital->MarketValue, Capital->TotalProfit, Capital->TodayProfit, Capital->Deposit, Capital->Withdraw);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryRiskGroupPositionPackage::XtpReqQryRiskGroupPositionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryRiskGroupPositionPackage* XtpReqQryRiskGroupPositionPackage::Allocate()
	{
		return ::Allocate<XtpReqQryRiskGroupPositionPackage>();
	}
	void XtpReqQryRiskGroupPositionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryRiskGroupPosition != nullptr)
		{
			::Free<ReqQryRiskGroupPositionField>(ReqQryRiskGroupPosition);
			ReqQryRiskGroupPosition = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryRiskGroupPositionPackage>::GetInstance().Free(this);
	}
	void XtpReqQryRiskGroupPositionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryRiskGroupPositionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryRiskGroupPosition, sizeof(ReqQryRiskGroupPositionField));
		offset += sizeof(ReqQryRiskGroupPositionField);
		return offset;
	}
	bool XtpReqQryRiskGroupPositionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryRiskGroupPosition = ::Allocate<ReqQryRiskGroupPositionField>();
		memcpy(ReqQryRiskGroupPosition, buff + offset, sizeof(ReqQryRiskGroupPositionField));
		offset += sizeof(ReqQryRiskGroupPositionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryRiskGroupPositionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryRiskGroupPosition:UserID:[%s], AccountID:[%s]",
			ReqQryRiskGroupPosition->UserID, ReqQryRiskGroupPosition->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryRiskGroupPositionPackage::XtpRspQryRiskGroupPositionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryRiskGroupPositionPackage* XtpRspQryRiskGroupPositionPackage::Allocate()
	{
		return ::Allocate<XtpRspQryRiskGroupPositionPackage>();
	}
	void XtpRspQryRiskGroupPositionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Position != nullptr)
		{
			::Free<PositionField>(Position);
			Position = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryRiskGroupPositionPackage>::GetInstance().Free(this);
	}
	void XtpRspQryRiskGroupPositionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryRiskGroupPositionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Position, sizeof(PositionField));
		offset += sizeof(PositionField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryRiskGroupPositionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Position = ::Allocate<PositionField>();
		memcpy(Position, buff + offset, sizeof(PositionField));
		offset += sizeof(PositionField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryRiskGroupPositionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Position:TradingDay:[%s], AccountID:[%s], AccountType:[%d], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TodayPosition:[%d], TotalCostPrice:[%f], TodayCostPrice:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], MarketValue:[%f], VolumeMultiple:[%d], TotalCost:[%f], TodayCost:[%f], TotalProfit:[%f], TodayProfit:[%f], LastPrice:[%f], PrePrice:[%f]",
			Position->TradingDay, Position->AccountID, (int)Position->AccountType, Position->ExchangeID, Position->InstrumentID, (int)Position->SecurityType, (int)Position->PosiDirection, Position->TotalPosition, Position->PositionFrozen, Position->TodayPosition, Position->TotalCostPrice, Position->TodayCostPrice, Position->CashIn, Position->CashOut, Position->Margin, Position->Commission, Position->StampTax, Position->TransferFee, Position->MarketValue, Position->VolumeMultiple, Position->TotalCost, Position->TodayCost, Position->TotalProfit, Position->TodayProfit, Position->LastPrice, Position->PrePrice);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryRiskGroupOrderPackage::XtpReqQryRiskGroupOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryRiskGroupOrderPackage* XtpReqQryRiskGroupOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqQryRiskGroupOrderPackage>();
	}
	void XtpReqQryRiskGroupOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryRiskGroupOrder != nullptr)
		{
			::Free<ReqQryRiskGroupOrderField>(ReqQryRiskGroupOrder);
			ReqQryRiskGroupOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryRiskGroupOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqQryRiskGroupOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryRiskGroupOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryRiskGroupOrder, sizeof(ReqQryRiskGroupOrderField));
		offset += sizeof(ReqQryRiskGroupOrderField);
		return offset;
	}
	bool XtpReqQryRiskGroupOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryRiskGroupOrder = ::Allocate<ReqQryRiskGroupOrderField>();
		memcpy(ReqQryRiskGroupOrder, buff + offset, sizeof(ReqQryRiskGroupOrderField));
		offset += sizeof(ReqQryRiskGroupOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryRiskGroupOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryRiskGroupOrder:UserID:[%s], AccountID:[%s]",
			ReqQryRiskGroupOrder->UserID, ReqQryRiskGroupOrder->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryRiskGroupOrderPackage::XtpRspQryRiskGroupOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryRiskGroupOrderPackage* XtpRspQryRiskGroupOrderPackage::Allocate()
	{
		return ::Allocate<XtpRspQryRiskGroupOrderPackage>();
	}
	void XtpRspQryRiskGroupOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Order != nullptr)
		{
			::Free<OrderField>(Order);
			Order = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryRiskGroupOrderPackage>::GetInstance().Free(this);
	}
	void XtpRspQryRiskGroupOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryRiskGroupOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Order, sizeof(OrderField));
		offset += sizeof(OrderField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryRiskGroupOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Order = ::Allocate<OrderField>();
		memcpy(Order, buff + offset, sizeof(OrderField));
		offset += sizeof(OrderField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryRiskGroupOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Order:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]",
			Order->TradingDay, Order->AccountID, Order->ExchangeID, Order->InstrumentID, (int)Order->SecurityType, Order->OrderID, Order->OrderSysID, (int)Order->Direction, (int)Order->OffsetFlag, (int)Order->OrderPriceType, Order->Price, Order->Volume, Order->VolumeTotal, Order->VolumeTraded, Order->VolumeMultiple, (int)Order->OrderStatus, Order->StatusMsg, Order->OrderDate, Order->OrderTime, Order->CancelDate, Order->CancelTime, Order->SessionID, Order->ClientOrderID, Order->RequestID, Order->FrozenCash, Order->FrozenMargin, Order->FrozenCommission, Order->FrozenStampTax, Order->FrozenTransferFee);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryRiskGroupTradePackage::XtpReqQryRiskGroupTradePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryRiskGroupTradePackage* XtpReqQryRiskGroupTradePackage::Allocate()
	{
		return ::Allocate<XtpReqQryRiskGroupTradePackage>();
	}
	void XtpReqQryRiskGroupTradePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryRiskGroupTrade != nullptr)
		{
			::Free<ReqQryRiskGroupTradeField>(ReqQryRiskGroupTrade);
			ReqQryRiskGroupTrade = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryRiskGroupTradePackage>::GetInstance().Free(this);
	}
	void XtpReqQryRiskGroupTradePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryRiskGroupTradePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryRiskGroupTrade, sizeof(ReqQryRiskGroupTradeField));
		offset += sizeof(ReqQryRiskGroupTradeField);
		return offset;
	}
	bool XtpReqQryRiskGroupTradePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryRiskGroupTrade = ::Allocate<ReqQryRiskGroupTradeField>();
		memcpy(ReqQryRiskGroupTrade, buff + offset, sizeof(ReqQryRiskGroupTradeField));
		offset += sizeof(ReqQryRiskGroupTradeField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryRiskGroupTradePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryRiskGroupTrade:UserID:[%s], AccountID:[%s]",
			ReqQryRiskGroupTrade->UserID, ReqQryRiskGroupTrade->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryRiskGroupTradePackage::XtpRspQryRiskGroupTradePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryRiskGroupTradePackage* XtpRspQryRiskGroupTradePackage::Allocate()
	{
		return ::Allocate<XtpRspQryRiskGroupTradePackage>();
	}
	void XtpRspQryRiskGroupTradePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Trade != nullptr)
		{
			::Free<TradeField>(Trade);
			Trade = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryRiskGroupTradePackage>::GetInstance().Free(this);
	}
	void XtpRspQryRiskGroupTradePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryRiskGroupTradePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Trade, sizeof(TradeField));
		offset += sizeof(TradeField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryRiskGroupTradePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Trade = ::Allocate<TradeField>();
		memcpy(Trade, buff + offset, sizeof(TradeField));
		offset += sizeof(TradeField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryRiskGroupTradePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Trade:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], VolumeMultiple:[%d], TradeAmount:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], TradeDate:[%s], TradeTime:[%s]",
			Trade->TradingDay, Trade->AccountID, Trade->ExchangeID, Trade->InstrumentID, (int)Trade->SecurityType, Trade->OrderID, Trade->OrderSysID, Trade->TradeID, (int)Trade->Direction, (int)Trade->OffsetFlag, Trade->Price, Trade->Volume, Trade->VolumeMultiple, Trade->TradeAmount, Trade->Commission, Trade->StampTax, Trade->TransferFee, Trade->TradeDate, Trade->TradeTime);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryRiskGroupAccountRiskPackage::XtpReqQryRiskGroupAccountRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryRiskGroupAccountRiskPackage* XtpReqQryRiskGroupAccountRiskPackage::Allocate()
	{
		return ::Allocate<XtpReqQryRiskGroupAccountRiskPackage>();
	}
	void XtpReqQryRiskGroupAccountRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryRiskGroupAccountRisk != nullptr)
		{
			::Free<ReqQryRiskGroupAccountRiskField>(ReqQryRiskGroupAccountRisk);
			ReqQryRiskGroupAccountRisk = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryRiskGroupAccountRiskPackage>::GetInstance().Free(this);
	}
	void XtpReqQryRiskGroupAccountRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryRiskGroupAccountRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryRiskGroupAccountRisk, sizeof(ReqQryRiskGroupAccountRiskField));
		offset += sizeof(ReqQryRiskGroupAccountRiskField);
		return offset;
	}
	bool XtpReqQryRiskGroupAccountRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryRiskGroupAccountRisk = ::Allocate<ReqQryRiskGroupAccountRiskField>();
		memcpy(ReqQryRiskGroupAccountRisk, buff + offset, sizeof(ReqQryRiskGroupAccountRiskField));
		offset += sizeof(ReqQryRiskGroupAccountRiskField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryRiskGroupAccountRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryRiskGroupAccountRisk:UserID:[%s], AccountID:[%s]",
			ReqQryRiskGroupAccountRisk->UserID, ReqQryRiskGroupAccountRisk->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryRiskGroupAccountRiskPackage::XtpRspQryRiskGroupAccountRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryRiskGroupAccountRiskPackage* XtpRspQryRiskGroupAccountRiskPackage::Allocate()
	{
		return ::Allocate<XtpRspQryRiskGroupAccountRiskPackage>();
	}
	void XtpRspQryRiskGroupAccountRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AccountRisk != nullptr)
		{
			::Free<AccountRiskField>(AccountRisk);
			AccountRisk = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryRiskGroupAccountRiskPackage>::GetInstance().Free(this);
	}
	void XtpRspQryRiskGroupAccountRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryRiskGroupAccountRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AccountRisk, sizeof(AccountRiskField));
		offset += sizeof(AccountRiskField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryRiskGroupAccountRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AccountRisk = ::Allocate<AccountRiskField>();
		memcpy(AccountRisk, buff + offset, sizeof(AccountRiskField));
		offset += sizeof(AccountRiskField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryRiskGroupAccountRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AccountRisk:AccountID:[%s], RiskID:[%d], RiskStatus:[%d]",
			AccountRisk->AccountID, AccountRisk->RiskID, (int)AccountRisk->RiskStatus);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqQryRiskGroupAccountRiskNotifyPackage::XtpReqQryRiskGroupAccountRiskNotifyPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryRiskGroupAccountRiskNotifyPackage* XtpReqQryRiskGroupAccountRiskNotifyPackage::Allocate()
	{
		return ::Allocate<XtpReqQryRiskGroupAccountRiskNotifyPackage>();
	}
	void XtpReqQryRiskGroupAccountRiskNotifyPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryRiskGroupAccountRiskNotify != nullptr)
		{
			::Free<ReqQryRiskGroupAccountRiskNotifyField>(ReqQryRiskGroupAccountRiskNotify);
			ReqQryRiskGroupAccountRiskNotify = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryRiskGroupAccountRiskNotifyPackage>::GetInstance().Free(this);
	}
	void XtpReqQryRiskGroupAccountRiskNotifyPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryRiskGroupAccountRiskNotifyPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryRiskGroupAccountRiskNotify, sizeof(ReqQryRiskGroupAccountRiskNotifyField));
		offset += sizeof(ReqQryRiskGroupAccountRiskNotifyField);
		return offset;
	}
	bool XtpReqQryRiskGroupAccountRiskNotifyPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryRiskGroupAccountRiskNotify = ::Allocate<ReqQryRiskGroupAccountRiskNotifyField>();
		memcpy(ReqQryRiskGroupAccountRiskNotify, buff + offset, sizeof(ReqQryRiskGroupAccountRiskNotifyField));
		offset += sizeof(ReqQryRiskGroupAccountRiskNotifyField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryRiskGroupAccountRiskNotifyPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryRiskGroupAccountRiskNotify:UserID:[%s], AccountID:[%s]",
			ReqQryRiskGroupAccountRiskNotify->UserID, ReqQryRiskGroupAccountRiskNotify->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryRiskGroupAccountRiskNotifyPackage::XtpRspQryRiskGroupAccountRiskNotifyPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryRiskGroupAccountRiskNotifyPackage* XtpRspQryRiskGroupAccountRiskNotifyPackage::Allocate()
	{
		return ::Allocate<XtpRspQryRiskGroupAccountRiskNotifyPackage>();
	}
	void XtpRspQryRiskGroupAccountRiskNotifyPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AccountRiskNotify != nullptr)
		{
			::Free<AccountRiskNotifyField>(AccountRiskNotify);
			AccountRiskNotify = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryRiskGroupAccountRiskNotifyPackage>::GetInstance().Free(this);
	}
	void XtpRspQryRiskGroupAccountRiskNotifyPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryRiskGroupAccountRiskNotifyPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AccountRiskNotify, sizeof(AccountRiskNotifyField));
		offset += sizeof(AccountRiskNotifyField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspQryRiskGroupAccountRiskNotifyPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AccountRiskNotify = ::Allocate<AccountRiskNotifyField>();
		memcpy(AccountRiskNotify, buff + offset, sizeof(AccountRiskNotifyField));
		offset += sizeof(AccountRiskNotifyField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryRiskGroupAccountRiskNotifyPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AccountRiskNotify:NotifyDate:[%s], NotifyTime:[%s], AccountID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskStatus:[%d], RiskMessage:[%s]",
			AccountRiskNotify->NotifyDate, AccountRiskNotify->NotifyTime, AccountRiskNotify->AccountID, AccountRiskNotify->RiskID, AccountRiskNotify->RiskRuleID, (int)AccountRiskNotify->RiskStatus, AccountRiskNotify->RiskMessage);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRiskInsertOrderPackage::XtpReqRiskInsertOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRiskInsertOrderPackage* XtpReqRiskInsertOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqRiskInsertOrderPackage>();
	}
	void XtpReqRiskInsertOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRiskInsertOrder != nullptr)
		{
			::Free<ReqRiskInsertOrderField>(ReqRiskInsertOrder);
			ReqRiskInsertOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRiskInsertOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqRiskInsertOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRiskInsertOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRiskInsertOrder, sizeof(ReqRiskInsertOrderField));
		offset += sizeof(ReqRiskInsertOrderField);
		return offset;
	}
	bool XtpReqRiskInsertOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRiskInsertOrder = ::Allocate<ReqRiskInsertOrderField>();
		memcpy(ReqRiskInsertOrder, buff + offset, sizeof(ReqRiskInsertOrderField));
		offset += sizeof(ReqRiskInsertOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRiskInsertOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRiskInsertOrder:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d], IsForceClose:[%d]",
			ReqRiskInsertOrder->UserID, ReqRiskInsertOrder->AccountID, ReqRiskInsertOrder->ExchangeID, ReqRiskInsertOrder->InstrumentID, (int)ReqRiskInsertOrder->Direction, (int)ReqRiskInsertOrder->OffsetFlag, (int)ReqRiskInsertOrder->OrderPriceType, ReqRiskInsertOrder->Price, ReqRiskInsertOrder->Volume, ReqRiskInsertOrder->ClientOrderID, ReqRiskInsertOrder->IsForceClose);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRiskInsertOrderPackage::XtpRspRiskInsertOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRiskInsertOrderPackage* XtpRspRiskInsertOrderPackage::Allocate()
	{
		return ::Allocate<XtpRspRiskInsertOrderPackage>();
	}
	void XtpRspRiskInsertOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (Order != nullptr)
		{
			::Free<OrderField>(Order);
			Order = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRiskInsertOrderPackage>::GetInstance().Free(this);
	}
	void XtpRspRiskInsertOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRiskInsertOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, Order, sizeof(OrderField));
		offset += sizeof(OrderField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRiskInsertOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		Order = ::Allocate<OrderField>();
		memcpy(Order, buff + offset, sizeof(OrderField));
		offset += sizeof(OrderField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRiskInsertOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "Order:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]",
			Order->TradingDay, Order->AccountID, Order->ExchangeID, Order->InstrumentID, (int)Order->SecurityType, Order->OrderID, Order->OrderSysID, (int)Order->Direction, (int)Order->OffsetFlag, (int)Order->OrderPriceType, Order->Price, Order->Volume, Order->VolumeTotal, Order->VolumeTraded, Order->VolumeMultiple, (int)Order->OrderStatus, Order->StatusMsg, Order->OrderDate, Order->OrderTime, Order->CancelDate, Order->CancelTime, Order->SessionID, Order->ClientOrderID, Order->RequestID, Order->FrozenCash, Order->FrozenMargin, Order->FrozenCommission, Order->FrozenStampTax, Order->FrozenTransferFee);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRiskCancelOrderPackage::XtpReqRiskCancelOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRiskCancelOrderPackage* XtpReqRiskCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqRiskCancelOrderPackage>();
	}
	void XtpReqRiskCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRiskCancelOrder != nullptr)
		{
			::Free<ReqRiskCancelOrderField>(ReqRiskCancelOrder);
			ReqRiskCancelOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRiskCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqRiskCancelOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRiskCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRiskCancelOrder, sizeof(ReqRiskCancelOrderField));
		offset += sizeof(ReqRiskCancelOrderField);
		return offset;
	}
	bool XtpReqRiskCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRiskCancelOrder = ::Allocate<ReqRiskCancelOrderField>();
		memcpy(ReqRiskCancelOrder, buff + offset, sizeof(ReqRiskCancelOrderField));
		offset += sizeof(ReqRiskCancelOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRiskCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRiskCancelOrder:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]",
			ReqRiskCancelOrder->UserID, ReqRiskCancelOrder->AccountID, ReqRiskCancelOrder->ExchangeID, ReqRiskCancelOrder->InstrumentID, ReqRiskCancelOrder->ClientCancelOrderID, ReqRiskCancelOrder->OrderID, ReqRiskCancelOrder->OrderSysID, ReqRiskCancelOrder->ClientOrderID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRiskCancelOrderPackage::XtpRspRiskCancelOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRiskCancelOrderPackage* XtpRspRiskCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpRspRiskCancelOrderPackage>();
	}
	void XtpRspRiskCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (CancelOrder != nullptr)
		{
			::Free<CancelOrderField>(CancelOrder);
			CancelOrder = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRiskCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpRspRiskCancelOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRiskCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, CancelOrder, sizeof(CancelOrderField));
		offset += sizeof(CancelOrderField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRiskCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		CancelOrder = ::Allocate<CancelOrderField>();
		memcpy(CancelOrder, buff + offset, sizeof(CancelOrderField));
		offset += sizeof(CancelOrderField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRiskCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "CancelOrder:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]",
			CancelOrder->AccountID, CancelOrder->ExchangeID, CancelOrder->InstrumentID, CancelOrder->ClientCancelOrderID, CancelOrder->OrderID, CancelOrder->OrderSysID, CancelOrder->ClientOrderID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqMdUserLoginPackage::XtpReqMdUserLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqMdUserLoginPackage* XtpReqMdUserLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqMdUserLoginPackage>();
	}
	void XtpReqMdUserLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqMdUserLogin != nullptr)
		{
			::Free<ReqMdUserLoginField>(ReqMdUserLogin);
			ReqMdUserLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqMdUserLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqMdUserLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqMdUserLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqMdUserLogin, sizeof(ReqMdUserLoginField));
		offset += sizeof(ReqMdUserLoginField);
		return offset;
	}
	bool XtpReqMdUserLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqMdUserLogin = ::Allocate<ReqMdUserLoginField>();
		memcpy(ReqMdUserLogin, buff + offset, sizeof(ReqMdUserLoginField));
		offset += sizeof(ReqMdUserLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqMdUserLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqMdUserLogin:MdUserID:[%s], Password:[%s]",
			ReqMdUserLogin->MdUserID, ReqMdUserLogin->Password);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspMdUserLoginPackage::XtpRspMdUserLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspMdUserLoginPackage* XtpRspMdUserLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspMdUserLoginPackage>();
	}
	void XtpRspMdUserLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspMdUserLogin != nullptr)
		{
			::Free<RspMdUserLoginField>(RspMdUserLogin);
			RspMdUserLogin = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspMdUserLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspMdUserLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspMdUserLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspMdUserLogin, sizeof(RspMdUserLoginField));
		offset += sizeof(RspMdUserLoginField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspMdUserLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspMdUserLogin = ::Allocate<RspMdUserLoginField>();
		memcpy(RspMdUserLogin, buff + offset, sizeof(RspMdUserLoginField));
		offset += sizeof(RspMdUserLoginField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspMdUserLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspMdUserLogin:MdUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]",
			RspMdUserLogin->MdUserID, RspMdUserLogin->LoginDate, RspMdUserLogin->LoginTime, RspMdUserLogin->SessionID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqMdUserLogoutPackage::XtpReqMdUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqMdUserLogoutPackage* XtpReqMdUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpReqMdUserLogoutPackage>();
	}
	void XtpReqMdUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqMdUserLogout != nullptr)
		{
			::Free<ReqMdUserLogoutField>(ReqMdUserLogout);
			ReqMdUserLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqMdUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpReqMdUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqMdUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqMdUserLogout, sizeof(ReqMdUserLogoutField));
		offset += sizeof(ReqMdUserLogoutField);
		return offset;
	}
	bool XtpReqMdUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqMdUserLogout = ::Allocate<ReqMdUserLogoutField>();
		memcpy(ReqMdUserLogout, buff + offset, sizeof(ReqMdUserLogoutField));
		offset += sizeof(ReqMdUserLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqMdUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqMdUserLogout:MdUserID:[%s]",
			ReqMdUserLogout->MdUserID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspMdUserLogoutPackage::XtpRspMdUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspMdUserLogoutPackage* XtpRspMdUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRspMdUserLogoutPackage>();
	}
	void XtpRspMdUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspMdUserLogout != nullptr)
		{
			::Free<RspMdUserLogoutField>(RspMdUserLogout);
			RspMdUserLogout = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspMdUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRspMdUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspMdUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspMdUserLogout, sizeof(RspMdUserLogoutField));
		offset += sizeof(RspMdUserLogoutField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspMdUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspMdUserLogout = ::Allocate<RspMdUserLogoutField>();
		memcpy(RspMdUserLogout, buff + offset, sizeof(RspMdUserLogoutField));
		offset += sizeof(RspMdUserLogoutField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspMdUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspMdUserLogout:MdUserID:[%s]",
			RspMdUserLogout->MdUserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqMdInitPackage::XtpReqMdInitPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqMdInitPackage* XtpReqMdInitPackage::Allocate()
	{
		return ::Allocate<XtpReqMdInitPackage>();
	}
	void XtpReqMdInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqMdInit != nullptr)
		{
			::Free<ReqMdInitField>(ReqMdInit);
			ReqMdInit = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqMdInitPackage>::GetInstance().Free(this);
	}
	void XtpReqMdInitPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqMdInitPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqMdInit, sizeof(ReqMdInitField));
		offset += sizeof(ReqMdInitField);
		return offset;
	}
	bool XtpReqMdInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqMdInit = ::Allocate<ReqMdInitField>();
		memcpy(ReqMdInit, buff + offset, sizeof(ReqMdInitField));
		offset += sizeof(ReqMdInitField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqMdInitPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqMdInit:ExchangeID:[%s], TradingDay:[%s]",
			ReqMdInit->ExchangeID, ReqMdInit->TradingDay);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspMdInitPackage::XtpRspMdInitPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspMdInitPackage* XtpRspMdInitPackage::Allocate()
	{
		return ::Allocate<XtpRspMdInitPackage>();
	}
	void XtpRspMdInitPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspMdInit != nullptr)
		{
			::Free<RspMdInitField>(RspMdInit);
			RspMdInit = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspMdInitPackage>::GetInstance().Free(this);
	}
	void XtpRspMdInitPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspMdInitPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspMdInit, sizeof(RspMdInitField));
		offset += sizeof(RspMdInitField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspMdInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspMdInit = ::Allocate<RspMdInitField>();
		memcpy(RspMdInit, buff + offset, sizeof(RspMdInitField));
		offset += sizeof(RspMdInitField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspMdInitPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspMdInit:ExchangeID:[%s], TradingDay:[%s]",
			RspMdInit->ExchangeID, RspMdInit->TradingDay);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqSubscribeMdPackage::XtpReqSubscribeMdPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqSubscribeMdPackage* XtpReqSubscribeMdPackage::Allocate()
	{
		return ::Allocate<XtpReqSubscribeMdPackage>();
	}
	void XtpReqSubscribeMdPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqSubscribeMd != nullptr)
		{
			::Free<ReqSubscribeMdField>(ReqSubscribeMd);
			ReqSubscribeMd = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqSubscribeMdPackage>::GetInstance().Free(this);
	}
	void XtpReqSubscribeMdPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqSubscribeMdPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqSubscribeMd, sizeof(ReqSubscribeMdField));
		offset += sizeof(ReqSubscribeMdField);
		return offset;
	}
	bool XtpReqSubscribeMdPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqSubscribeMd = ::Allocate<ReqSubscribeMdField>();
		memcpy(ReqSubscribeMd, buff + offset, sizeof(ReqSubscribeMdField));
		offset += sizeof(ReqSubscribeMdField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqSubscribeMdPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqSubscribeMd:ExchangeID:[%s], InstrumentID:[%s]",
			ReqSubscribeMd->ExchangeID, ReqSubscribeMd->InstrumentID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspSubscribeMdPackage::XtpRspSubscribeMdPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspSubscribeMdPackage* XtpRspSubscribeMdPackage::Allocate()
	{
		return ::Allocate<XtpRspSubscribeMdPackage>();
	}
	void XtpRspSubscribeMdPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspSubscribeMd != nullptr)
		{
			::Free<RspSubscribeMdField>(RspSubscribeMd);
			RspSubscribeMd = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspSubscribeMdPackage>::GetInstance().Free(this);
	}
	void XtpRspSubscribeMdPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspSubscribeMdPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspSubscribeMd, sizeof(RspSubscribeMdField));
		offset += sizeof(RspSubscribeMdField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspSubscribeMdPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspSubscribeMd = ::Allocate<RspSubscribeMdField>();
		memcpy(RspSubscribeMd, buff + offset, sizeof(RspSubscribeMdField));
		offset += sizeof(RspSubscribeMdField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspSubscribeMdPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspSubscribeMd:ExchangeID:[%s], InstrumentID:[%s]",
			RspSubscribeMd->ExchangeID, RspSubscribeMd->InstrumentID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnShortMdPackage::XtpRtnShortMdPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnShortMdPackage* XtpRtnShortMdPackage::Allocate()
	{
		return ::Allocate<XtpRtnShortMdPackage>();
	}
	void XtpRtnShortMdPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ShortMd != nullptr)
		{
			::Free<ShortMdField>(ShortMd);
			ShortMd = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnShortMdPackage>::GetInstance().Free(this);
	}
	void XtpRtnShortMdPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnShortMdPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ShortMd, sizeof(ShortMdField));
		offset += sizeof(ShortMdField);
		return offset;
	}
	bool XtpRtnShortMdPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ShortMd = ::Allocate<ShortMdField>();
		memcpy(ShortMd, buff + offset, sizeof(ShortMdField));
		offset += sizeof(ShortMdField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnShortMdPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ShortMd:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], LastPrice:[%f], ClosePrice:[%f], PreClosePrice:[%f], SettlementPrice:[%f], PreSettlementPrice:[%f], UpperLimitPrice:[%f], LowerLimitPrice:[%f]",
			ShortMd->TradingDay, ShortMd->ExchangeID, ShortMd->InstrumentID, ShortMd->LastPrice, ShortMd->ClosePrice, ShortMd->PreClosePrice, ShortMd->SettlementPrice, ShortMd->PreSettlementPrice, ShortMd->UpperLimitPrice, ShortMd->LowerLimitPrice);
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
			::Free<RtnExchangeStatusField>(RtnExchangeStatus);
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
		memcpy(buff + offset, RtnExchangeStatus, sizeof(RtnExchangeStatusField));
		offset += sizeof(RtnExchangeStatusField);
		return offset;
	}
	bool XtpRtnExchangeStatusPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnExchangeStatus = ::Allocate<RtnExchangeStatusField>();
		memcpy(RtnExchangeStatus, buff + offset, sizeof(RtnExchangeStatusField));
		offset += sizeof(RtnExchangeStatusField);
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
 
	XtpRtnMdInitCompletedPackage::XtpRtnMdInitCompletedPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnMdInitCompletedPackage* XtpRtnMdInitCompletedPackage::Allocate()
	{
		return ::Allocate<XtpRtnMdInitCompletedPackage>();
	}
	void XtpRtnMdInitCompletedPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (MdInitCompleted != nullptr)
		{
			::Free<MdInitCompletedField>(MdInitCompleted);
			MdInitCompleted = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnMdInitCompletedPackage>::GetInstance().Free(this);
	}
	void XtpRtnMdInitCompletedPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnMdInitCompletedPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, MdInitCompleted, sizeof(MdInitCompletedField));
		offset += sizeof(MdInitCompletedField);
		return offset;
	}
	bool XtpRtnMdInitCompletedPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		MdInitCompleted = ::Allocate<MdInitCompletedField>();
		memcpy(MdInitCompleted, buff + offset, sizeof(MdInitCompletedField));
		offset += sizeof(MdInitCompletedField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnMdInitCompletedPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "MdInitCompleted:ExchangeID:[%s], TradingDay:[%s]",
			MdInitCompleted->ExchangeID, MdInitCompleted->TradingDay);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAdminUserLoginPackage::XtpReqAdminUserLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAdminUserLoginPackage* XtpReqAdminUserLoginPackage::Allocate()
	{
		return ::Allocate<XtpReqAdminUserLoginPackage>();
	}
	void XtpReqAdminUserLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAdminUserLogin != nullptr)
		{
			::Free<ReqAdminUserLoginField>(ReqAdminUserLogin);
			ReqAdminUserLogin = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAdminUserLoginPackage>::GetInstance().Free(this);
	}
	void XtpReqAdminUserLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAdminUserLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAdminUserLogin, sizeof(ReqAdminUserLoginField));
		offset += sizeof(ReqAdminUserLoginField);
		return offset;
	}
	bool XtpReqAdminUserLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAdminUserLogin = ::Allocate<ReqAdminUserLoginField>();
		memcpy(ReqAdminUserLogin, buff + offset, sizeof(ReqAdminUserLoginField));
		offset += sizeof(ReqAdminUserLoginField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAdminUserLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAdminUserLogin:AdminUserID:[%s], Password:[%s]",
			ReqAdminUserLogin->AdminUserID, ReqAdminUserLogin->Password);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAdminUserLoginPackage::XtpRspAdminUserLoginPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAdminUserLoginPackage* XtpRspAdminUserLoginPackage::Allocate()
	{
		return ::Allocate<XtpRspAdminUserLoginPackage>();
	}
	void XtpRspAdminUserLoginPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAdminUserLogin != nullptr)
		{
			::Free<RspAdminUserLoginField>(RspAdminUserLogin);
			RspAdminUserLogin = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAdminUserLoginPackage>::GetInstance().Free(this);
	}
	void XtpRspAdminUserLoginPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAdminUserLoginPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAdminUserLogin, sizeof(RspAdminUserLoginField));
		offset += sizeof(RspAdminUserLoginField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAdminUserLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAdminUserLogin = ::Allocate<RspAdminUserLoginField>();
		memcpy(RspAdminUserLogin, buff + offset, sizeof(RspAdminUserLoginField));
		offset += sizeof(RspAdminUserLoginField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAdminUserLoginPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAdminUserLogin:AdminUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]",
			RspAdminUserLogin->AdminUserID, RspAdminUserLogin->LoginDate, RspAdminUserLogin->LoginTime, RspAdminUserLogin->SessionID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAdminUserLogoutPackage::XtpReqAdminUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAdminUserLogoutPackage* XtpReqAdminUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpReqAdminUserLogoutPackage>();
	}
	void XtpReqAdminUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAdminUserLogout != nullptr)
		{
			::Free<ReqAdminUserLogoutField>(ReqAdminUserLogout);
			ReqAdminUserLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAdminUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpReqAdminUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAdminUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAdminUserLogout, sizeof(ReqAdminUserLogoutField));
		offset += sizeof(ReqAdminUserLogoutField);
		return offset;
	}
	bool XtpReqAdminUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAdminUserLogout = ::Allocate<ReqAdminUserLogoutField>();
		memcpy(ReqAdminUserLogout, buff + offset, sizeof(ReqAdminUserLogoutField));
		offset += sizeof(ReqAdminUserLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAdminUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAdminUserLogout:AdminUserID:[%s]",
			ReqAdminUserLogout->AdminUserID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAdminUserLogoutPackage::XtpRspAdminUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAdminUserLogoutPackage* XtpRspAdminUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRspAdminUserLogoutPackage>();
	}
	void XtpRspAdminUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAdminUserLogout != nullptr)
		{
			::Free<RspAdminUserLogoutField>(RspAdminUserLogout);
			RspAdminUserLogout = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAdminUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRspAdminUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAdminUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAdminUserLogout, sizeof(RspAdminUserLogoutField));
		offset += sizeof(RspAdminUserLogoutField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAdminUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAdminUserLogout = ::Allocate<RspAdminUserLogoutField>();
		memcpy(RspAdminUserLogout, buff + offset, sizeof(RspAdminUserLogoutField));
		offset += sizeof(RspAdminUserLogoutField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAdminUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAdminUserLogout:AdminUserID:[%s]",
			RspAdminUserLogout->AdminUserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnAdminUserLogoutPackage::XtpRtnAdminUserLogoutPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnAdminUserLogoutPackage* XtpRtnAdminUserLogoutPackage::Allocate()
	{
		return ::Allocate<XtpRtnAdminUserLogoutPackage>();
	}
	void XtpRtnAdminUserLogoutPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (AdminUserLogout != nullptr)
		{
			::Free<AdminUserLogoutField>(AdminUserLogout);
			AdminUserLogout = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnAdminUserLogoutPackage>::GetInstance().Free(this);
	}
	void XtpRtnAdminUserLogoutPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnAdminUserLogoutPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, AdminUserLogout, sizeof(AdminUserLogoutField));
		offset += sizeof(AdminUserLogoutField);
		return offset;
	}
	bool XtpRtnAdminUserLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		AdminUserLogout = ::Allocate<AdminUserLogoutField>();
		memcpy(AdminUserLogout, buff + offset, sizeof(AdminUserLogoutField));
		offset += sizeof(AdminUserLogoutField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnAdminUserLogoutPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "AdminUserLogout:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			AdminUserLogout->UserID, AdminUserLogout->ErrorID, AdminUserLogout->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddRiskUserPackage::XtpReqAddRiskUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddRiskUserPackage* XtpReqAddRiskUserPackage::Allocate()
	{
		return ::Allocate<XtpReqAddRiskUserPackage>();
	}
	void XtpReqAddRiskUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddRiskUser != nullptr)
		{
			::Free<ReqAddRiskUserField>(ReqAddRiskUser);
			ReqAddRiskUser = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddRiskUserPackage>::GetInstance().Free(this);
	}
	void XtpReqAddRiskUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddRiskUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddRiskUser, sizeof(ReqAddRiskUserField));
		offset += sizeof(ReqAddRiskUserField);
		return offset;
	}
	bool XtpReqAddRiskUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddRiskUser = ::Allocate<ReqAddRiskUserField>();
		memcpy(ReqAddRiskUser, buff + offset, sizeof(ReqAddRiskUserField));
		offset += sizeof(ReqAddRiskUserField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddRiskUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddRiskUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]",
			ReqAddRiskUser->AdminUserID, ReqAddRiskUser->UserID, ReqAddRiskUser->UserName, ReqAddRiskUser->Password, ReqAddRiskUser->RiskGroupID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddRiskUserPackage::XtpRspAddRiskUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddRiskUserPackage* XtpRspAddRiskUserPackage::Allocate()
	{
		return ::Allocate<XtpRspAddRiskUserPackage>();
	}
	void XtpRspAddRiskUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddRiskUser != nullptr)
		{
			::Free<RspAddRiskUserField>(RspAddRiskUser);
			RspAddRiskUser = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddRiskUserPackage>::GetInstance().Free(this);
	}
	void XtpRspAddRiskUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddRiskUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddRiskUser, sizeof(RspAddRiskUserField));
		offset += sizeof(RspAddRiskUserField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddRiskUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddRiskUser = ::Allocate<RspAddRiskUserField>();
		memcpy(RspAddRiskUser, buff + offset, sizeof(RspAddRiskUserField));
		offset += sizeof(RspAddRiskUserField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddRiskUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddRiskUser:AdminUserID:[%s], UserID:[%s]",
			RspAddRiskUser->AdminUserID, RspAddRiskUser->UserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateRiskUserPackage::XtpReqUpdateRiskUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateRiskUserPackage* XtpReqUpdateRiskUserPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateRiskUserPackage>();
	}
	void XtpReqUpdateRiskUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateRiskUser != nullptr)
		{
			::Free<ReqUpdateRiskUserField>(ReqUpdateRiskUser);
			ReqUpdateRiskUser = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateRiskUserPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateRiskUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateRiskUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateRiskUser, sizeof(ReqUpdateRiskUserField));
		offset += sizeof(ReqUpdateRiskUserField);
		return offset;
	}
	bool XtpReqUpdateRiskUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateRiskUser = ::Allocate<ReqUpdateRiskUserField>();
		memcpy(ReqUpdateRiskUser, buff + offset, sizeof(ReqUpdateRiskUserField));
		offset += sizeof(ReqUpdateRiskUserField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateRiskUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateRiskUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]",
			ReqUpdateRiskUser->AdminUserID, ReqUpdateRiskUser->UserID, ReqUpdateRiskUser->UserName, ReqUpdateRiskUser->Password, ReqUpdateRiskUser->RiskGroupID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateRiskUserPackage::XtpRspUpdateRiskUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateRiskUserPackage* XtpRspUpdateRiskUserPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateRiskUserPackage>();
	}
	void XtpRspUpdateRiskUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateRiskUser != nullptr)
		{
			::Free<RspUpdateRiskUserField>(RspUpdateRiskUser);
			RspUpdateRiskUser = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateRiskUserPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateRiskUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateRiskUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateRiskUser, sizeof(RspUpdateRiskUserField));
		offset += sizeof(RspUpdateRiskUserField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateRiskUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateRiskUser = ::Allocate<RspUpdateRiskUserField>();
		memcpy(RspUpdateRiskUser, buff + offset, sizeof(RspUpdateRiskUserField));
		offset += sizeof(RspUpdateRiskUserField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateRiskUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateRiskUser:AdminUserID:[%s], UserID:[%s]",
			RspUpdateRiskUser->AdminUserID, RspUpdateRiskUser->UserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveRiskUserPackage::XtpReqRemoveRiskUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveRiskUserPackage* XtpReqRemoveRiskUserPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveRiskUserPackage>();
	}
	void XtpReqRemoveRiskUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveRiskUser != nullptr)
		{
			::Free<ReqRemoveRiskUserField>(ReqRemoveRiskUser);
			ReqRemoveRiskUser = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveRiskUserPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveRiskUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveRiskUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveRiskUser, sizeof(ReqRemoveRiskUserField));
		offset += sizeof(ReqRemoveRiskUserField);
		return offset;
	}
	bool XtpReqRemoveRiskUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveRiskUser = ::Allocate<ReqRemoveRiskUserField>();
		memcpy(ReqRemoveRiskUser, buff + offset, sizeof(ReqRemoveRiskUserField));
		offset += sizeof(ReqRemoveRiskUserField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveRiskUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveRiskUser:AdminUserID:[%s], UserID:[%s]",
			ReqRemoveRiskUser->AdminUserID, ReqRemoveRiskUser->UserID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveRiskUserPackage::XtpRspRemoveRiskUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveRiskUserPackage* XtpRspRemoveRiskUserPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveRiskUserPackage>();
	}
	void XtpRspRemoveRiskUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveRiskUser != nullptr)
		{
			::Free<RspRemoveRiskUserField>(RspRemoveRiskUser);
			RspRemoveRiskUser = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveRiskUserPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveRiskUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveRiskUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveRiskUser, sizeof(RspRemoveRiskUserField));
		offset += sizeof(RspRemoveRiskUserField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveRiskUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveRiskUser = ::Allocate<RspRemoveRiskUserField>();
		memcpy(RspRemoveRiskUser, buff + offset, sizeof(RspRemoveRiskUserField));
		offset += sizeof(RspRemoveRiskUserField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveRiskUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveRiskUser:AdminUserID:[%s], UserID:[%s]",
			RspRemoveRiskUser->AdminUserID, RspRemoveRiskUser->UserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddAdminUserPackage::XtpReqAddAdminUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddAdminUserPackage* XtpReqAddAdminUserPackage::Allocate()
	{
		return ::Allocate<XtpReqAddAdminUserPackage>();
	}
	void XtpReqAddAdminUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddAdminUser != nullptr)
		{
			::Free<ReqAddAdminUserField>(ReqAddAdminUser);
			ReqAddAdminUser = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddAdminUserPackage>::GetInstance().Free(this);
	}
	void XtpReqAddAdminUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddAdminUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddAdminUser, sizeof(ReqAddAdminUserField));
		offset += sizeof(ReqAddAdminUserField);
		return offset;
	}
	bool XtpReqAddAdminUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddAdminUser = ::Allocate<ReqAddAdminUserField>();
		memcpy(ReqAddAdminUser, buff + offset, sizeof(ReqAddAdminUserField));
		offset += sizeof(ReqAddAdminUserField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddAdminUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddAdminUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]",
			ReqAddAdminUser->AdminUserID, ReqAddAdminUser->UserID, ReqAddAdminUser->UserName, ReqAddAdminUser->Password);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddAdminUserPackage::XtpRspAddAdminUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddAdminUserPackage* XtpRspAddAdminUserPackage::Allocate()
	{
		return ::Allocate<XtpRspAddAdminUserPackage>();
	}
	void XtpRspAddAdminUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddAdminUser != nullptr)
		{
			::Free<RspAddAdminUserField>(RspAddAdminUser);
			RspAddAdminUser = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddAdminUserPackage>::GetInstance().Free(this);
	}
	void XtpRspAddAdminUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddAdminUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddAdminUser, sizeof(RspAddAdminUserField));
		offset += sizeof(RspAddAdminUserField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddAdminUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddAdminUser = ::Allocate<RspAddAdminUserField>();
		memcpy(RspAddAdminUser, buff + offset, sizeof(RspAddAdminUserField));
		offset += sizeof(RspAddAdminUserField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddAdminUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddAdminUser:AdminUserID:[%s], UserID:[%s]",
			RspAddAdminUser->AdminUserID, RspAddAdminUser->UserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateAdminUserPackage::XtpReqUpdateAdminUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateAdminUserPackage* XtpReqUpdateAdminUserPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateAdminUserPackage>();
	}
	void XtpReqUpdateAdminUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateAdminUser != nullptr)
		{
			::Free<ReqUpdateAdminUserField>(ReqUpdateAdminUser);
			ReqUpdateAdminUser = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateAdminUserPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateAdminUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateAdminUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateAdminUser, sizeof(ReqUpdateAdminUserField));
		offset += sizeof(ReqUpdateAdminUserField);
		return offset;
	}
	bool XtpReqUpdateAdminUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateAdminUser = ::Allocate<ReqUpdateAdminUserField>();
		memcpy(ReqUpdateAdminUser, buff + offset, sizeof(ReqUpdateAdminUserField));
		offset += sizeof(ReqUpdateAdminUserField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateAdminUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateAdminUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]",
			ReqUpdateAdminUser->AdminUserID, ReqUpdateAdminUser->UserID, ReqUpdateAdminUser->UserName, ReqUpdateAdminUser->Password);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateAdminUserPackage::XtpRspUpdateAdminUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateAdminUserPackage* XtpRspUpdateAdminUserPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateAdminUserPackage>();
	}
	void XtpRspUpdateAdminUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateAdminUser != nullptr)
		{
			::Free<RspUpdateAdminUserField>(RspUpdateAdminUser);
			RspUpdateAdminUser = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateAdminUserPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateAdminUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateAdminUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateAdminUser, sizeof(RspUpdateAdminUserField));
		offset += sizeof(RspUpdateAdminUserField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateAdminUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateAdminUser = ::Allocate<RspUpdateAdminUserField>();
		memcpy(RspUpdateAdminUser, buff + offset, sizeof(RspUpdateAdminUserField));
		offset += sizeof(RspUpdateAdminUserField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateAdminUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateAdminUser:AdminUserID:[%s], UserID:[%s]",
			RspUpdateAdminUser->AdminUserID, RspUpdateAdminUser->UserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveAdminUserPackage::XtpReqRemoveAdminUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveAdminUserPackage* XtpReqRemoveAdminUserPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveAdminUserPackage>();
	}
	void XtpReqRemoveAdminUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveAdminUser != nullptr)
		{
			::Free<ReqRemoveAdminUserField>(ReqRemoveAdminUser);
			ReqRemoveAdminUser = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveAdminUserPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveAdminUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveAdminUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveAdminUser, sizeof(ReqRemoveAdminUserField));
		offset += sizeof(ReqRemoveAdminUserField);
		return offset;
	}
	bool XtpReqRemoveAdminUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveAdminUser = ::Allocate<ReqRemoveAdminUserField>();
		memcpy(ReqRemoveAdminUser, buff + offset, sizeof(ReqRemoveAdminUserField));
		offset += sizeof(ReqRemoveAdminUserField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveAdminUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveAdminUser:AdminUserID:[%s], UserID:[%s]",
			ReqRemoveAdminUser->AdminUserID, ReqRemoveAdminUser->UserID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveAdminUserPackage::XtpRspRemoveAdminUserPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveAdminUserPackage* XtpRspRemoveAdminUserPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveAdminUserPackage>();
	}
	void XtpRspRemoveAdminUserPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveAdminUser != nullptr)
		{
			::Free<RspRemoveAdminUserField>(RspRemoveAdminUser);
			RspRemoveAdminUser = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveAdminUserPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveAdminUserPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveAdminUserPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveAdminUser, sizeof(RspRemoveAdminUserField));
		offset += sizeof(RspRemoveAdminUserField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveAdminUserPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveAdminUser = ::Allocate<RspRemoveAdminUserField>();
		memcpy(RspRemoveAdminUser, buff + offset, sizeof(RspRemoveAdminUserField));
		offset += sizeof(RspRemoveAdminUserField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveAdminUserPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveAdminUser:AdminUserID:[%s], UserID:[%s]",
			RspRemoveAdminUser->AdminUserID, RspRemoveAdminUser->UserID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddPrimaryAccountPackage::XtpReqAddPrimaryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddPrimaryAccountPackage* XtpReqAddPrimaryAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqAddPrimaryAccountPackage>();
	}
	void XtpReqAddPrimaryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddPrimaryAccount != nullptr)
		{
			::Free<ReqAddPrimaryAccountField>(ReqAddPrimaryAccount);
			ReqAddPrimaryAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddPrimaryAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqAddPrimaryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddPrimaryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddPrimaryAccount, sizeof(ReqAddPrimaryAccountField));
		offset += sizeof(ReqAddPrimaryAccountField);
		return offset;
	}
	bool XtpReqAddPrimaryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddPrimaryAccount = ::Allocate<ReqAddPrimaryAccountField>();
		memcpy(ReqAddPrimaryAccount, buff + offset, sizeof(ReqAddPrimaryAccountField));
		offset += sizeof(ReqAddPrimaryAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddPrimaryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddPrimaryAccount:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]",
			ReqAddPrimaryAccount->AdminUserID, ReqAddPrimaryAccount->TradingDay, ReqAddPrimaryAccount->PrimaryAccountID, ReqAddPrimaryAccount->PrimaryAccountName, (int)ReqAddPrimaryAccount->AccountClass, ReqAddPrimaryAccount->BrokerPassword, ReqAddPrimaryAccount->OfferID, ReqAddPrimaryAccount->IsAllowLogin, ReqAddPrimaryAccount->IsSimulateAccount, (int)ReqAddPrimaryAccount->AccountStatus, ReqAddPrimaryAccount->Password, ReqAddPrimaryAccount->RiskGroupID, ReqAddPrimaryAccount->CommissionGroupID, ReqAddPrimaryAccount->IsAutoAudit);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddPrimaryAccountPackage::XtpRspAddPrimaryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddPrimaryAccountPackage* XtpRspAddPrimaryAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspAddPrimaryAccountPackage>();
	}
	void XtpRspAddPrimaryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddPrimaryAccount != nullptr)
		{
			::Free<RspAddPrimaryAccountField>(RspAddPrimaryAccount);
			RspAddPrimaryAccount = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddPrimaryAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspAddPrimaryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddPrimaryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddPrimaryAccount, sizeof(RspAddPrimaryAccountField));
		offset += sizeof(RspAddPrimaryAccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddPrimaryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddPrimaryAccount = ::Allocate<RspAddPrimaryAccountField>();
		memcpy(RspAddPrimaryAccount, buff + offset, sizeof(RspAddPrimaryAccountField));
		offset += sizeof(RspAddPrimaryAccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddPrimaryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddPrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]",
			RspAddPrimaryAccount->AdminUserID, RspAddPrimaryAccount->PrimaryAccountID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdatePrimaryAccountPackage::XtpReqUpdatePrimaryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdatePrimaryAccountPackage* XtpReqUpdatePrimaryAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdatePrimaryAccountPackage>();
	}
	void XtpReqUpdatePrimaryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdatePrimaryAccount != nullptr)
		{
			::Free<ReqUpdatePrimaryAccountField>(ReqUpdatePrimaryAccount);
			ReqUpdatePrimaryAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdatePrimaryAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdatePrimaryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdatePrimaryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdatePrimaryAccount, sizeof(ReqUpdatePrimaryAccountField));
		offset += sizeof(ReqUpdatePrimaryAccountField);
		return offset;
	}
	bool XtpReqUpdatePrimaryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdatePrimaryAccount = ::Allocate<ReqUpdatePrimaryAccountField>();
		memcpy(ReqUpdatePrimaryAccount, buff + offset, sizeof(ReqUpdatePrimaryAccountField));
		offset += sizeof(ReqUpdatePrimaryAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdatePrimaryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdatePrimaryAccount:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]",
			ReqUpdatePrimaryAccount->AdminUserID, ReqUpdatePrimaryAccount->TradingDay, ReqUpdatePrimaryAccount->PrimaryAccountID, ReqUpdatePrimaryAccount->PrimaryAccountName, (int)ReqUpdatePrimaryAccount->AccountClass, ReqUpdatePrimaryAccount->BrokerPassword, ReqUpdatePrimaryAccount->OfferID, ReqUpdatePrimaryAccount->IsAllowLogin, ReqUpdatePrimaryAccount->IsSimulateAccount, (int)ReqUpdatePrimaryAccount->AccountStatus, ReqUpdatePrimaryAccount->Password, ReqUpdatePrimaryAccount->RiskGroupID, ReqUpdatePrimaryAccount->CommissionGroupID, ReqUpdatePrimaryAccount->IsAutoAudit);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdatePrimaryAccountPackage::XtpRspUpdatePrimaryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdatePrimaryAccountPackage* XtpRspUpdatePrimaryAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdatePrimaryAccountPackage>();
	}
	void XtpRspUpdatePrimaryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdatePrimaryAccount != nullptr)
		{
			::Free<RspUpdatePrimaryAccountField>(RspUpdatePrimaryAccount);
			RspUpdatePrimaryAccount = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdatePrimaryAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdatePrimaryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdatePrimaryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdatePrimaryAccount, sizeof(RspUpdatePrimaryAccountField));
		offset += sizeof(RspUpdatePrimaryAccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdatePrimaryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdatePrimaryAccount = ::Allocate<RspUpdatePrimaryAccountField>();
		memcpy(RspUpdatePrimaryAccount, buff + offset, sizeof(RspUpdatePrimaryAccountField));
		offset += sizeof(RspUpdatePrimaryAccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdatePrimaryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdatePrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]",
			RspUpdatePrimaryAccount->AdminUserID, RspUpdatePrimaryAccount->PrimaryAccountID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemovePrimaryAccountPackage::XtpReqRemovePrimaryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemovePrimaryAccountPackage* XtpReqRemovePrimaryAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqRemovePrimaryAccountPackage>();
	}
	void XtpReqRemovePrimaryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemovePrimaryAccount != nullptr)
		{
			::Free<ReqRemovePrimaryAccountField>(ReqRemovePrimaryAccount);
			ReqRemovePrimaryAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemovePrimaryAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqRemovePrimaryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemovePrimaryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemovePrimaryAccount, sizeof(ReqRemovePrimaryAccountField));
		offset += sizeof(ReqRemovePrimaryAccountField);
		return offset;
	}
	bool XtpReqRemovePrimaryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemovePrimaryAccount = ::Allocate<ReqRemovePrimaryAccountField>();
		memcpy(ReqRemovePrimaryAccount, buff + offset, sizeof(ReqRemovePrimaryAccountField));
		offset += sizeof(ReqRemovePrimaryAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemovePrimaryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemovePrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]",
			ReqRemovePrimaryAccount->AdminUserID, ReqRemovePrimaryAccount->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemovePrimaryAccountPackage::XtpRspRemovePrimaryAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemovePrimaryAccountPackage* XtpRspRemovePrimaryAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspRemovePrimaryAccountPackage>();
	}
	void XtpRspRemovePrimaryAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemovePrimaryAccount != nullptr)
		{
			::Free<RspRemovePrimaryAccountField>(RspRemovePrimaryAccount);
			RspRemovePrimaryAccount = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemovePrimaryAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspRemovePrimaryAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemovePrimaryAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemovePrimaryAccount, sizeof(RspRemovePrimaryAccountField));
		offset += sizeof(RspRemovePrimaryAccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemovePrimaryAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemovePrimaryAccount = ::Allocate<RspRemovePrimaryAccountField>();
		memcpy(RspRemovePrimaryAccount, buff + offset, sizeof(RspRemovePrimaryAccountField));
		offset += sizeof(RspRemovePrimaryAccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemovePrimaryAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemovePrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]",
			RspRemovePrimaryAccount->AdminUserID, RspRemovePrimaryAccount->PrimaryAccountID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddAccountPackage::XtpReqAddAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddAccountPackage* XtpReqAddAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqAddAccountPackage>();
	}
	void XtpReqAddAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddAccount != nullptr)
		{
			::Free<ReqAddAccountField>(ReqAddAccount);
			ReqAddAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqAddAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddAccount, sizeof(ReqAddAccountField));
		offset += sizeof(ReqAddAccountField);
		return offset;
	}
	bool XtpReqAddAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddAccount = ::Allocate<ReqAddAccountField>();
		memcpy(ReqAddAccount, buff + offset, sizeof(ReqAddAccountField));
		offset += sizeof(ReqAddAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddAccount:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]",
			ReqAddAccount->AdminUserID, ReqAddAccount->TradingDay, ReqAddAccount->AccountID, ReqAddAccount->AccountName, (int)ReqAddAccount->AccountStatus, ReqAddAccount->Password, ReqAddAccount->TradeGroupID, ReqAddAccount->RiskGroupID, ReqAddAccount->CommissionGroupID, ReqAddAccount->IsAutoAudit);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddAccountPackage::XtpRspAddAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddAccountPackage* XtpRspAddAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspAddAccountPackage>();
	}
	void XtpRspAddAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddAccount != nullptr)
		{
			::Free<RspAddAccountField>(RspAddAccount);
			RspAddAccount = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspAddAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddAccount, sizeof(RspAddAccountField));
		offset += sizeof(RspAddAccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddAccount = ::Allocate<RspAddAccountField>();
		memcpy(RspAddAccount, buff + offset, sizeof(RspAddAccountField));
		offset += sizeof(RspAddAccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddAccount:AdminUserID:[%s], AccountID:[%s]",
			RspAddAccount->AdminUserID, RspAddAccount->AccountID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateAccountPackage::XtpReqUpdateAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateAccountPackage* XtpReqUpdateAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateAccountPackage>();
	}
	void XtpReqUpdateAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateAccount != nullptr)
		{
			::Free<ReqUpdateAccountField>(ReqUpdateAccount);
			ReqUpdateAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateAccount, sizeof(ReqUpdateAccountField));
		offset += sizeof(ReqUpdateAccountField);
		return offset;
	}
	bool XtpReqUpdateAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateAccount = ::Allocate<ReqUpdateAccountField>();
		memcpy(ReqUpdateAccount, buff + offset, sizeof(ReqUpdateAccountField));
		offset += sizeof(ReqUpdateAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateAccount:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]",
			ReqUpdateAccount->AdminUserID, ReqUpdateAccount->TradingDay, ReqUpdateAccount->AccountID, ReqUpdateAccount->AccountName, (int)ReqUpdateAccount->AccountStatus, ReqUpdateAccount->Password, ReqUpdateAccount->TradeGroupID, ReqUpdateAccount->RiskGroupID, ReqUpdateAccount->CommissionGroupID, ReqUpdateAccount->IsAutoAudit);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateAccountPackage::XtpRspUpdateAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateAccountPackage* XtpRspUpdateAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateAccountPackage>();
	}
	void XtpRspUpdateAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateAccount != nullptr)
		{
			::Free<RspUpdateAccountField>(RspUpdateAccount);
			RspUpdateAccount = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateAccount, sizeof(RspUpdateAccountField));
		offset += sizeof(RspUpdateAccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateAccount = ::Allocate<RspUpdateAccountField>();
		memcpy(RspUpdateAccount, buff + offset, sizeof(RspUpdateAccountField));
		offset += sizeof(RspUpdateAccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateAccount:AdminUserID:[%s], AccountID:[%s]",
			RspUpdateAccount->AdminUserID, RspUpdateAccount->AccountID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveAccountPackage::XtpReqRemoveAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveAccountPackage* XtpReqRemoveAccountPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveAccountPackage>();
	}
	void XtpReqRemoveAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveAccount != nullptr)
		{
			::Free<ReqRemoveAccountField>(ReqRemoveAccount);
			ReqRemoveAccount = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveAccountPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveAccount, sizeof(ReqRemoveAccountField));
		offset += sizeof(ReqRemoveAccountField);
		return offset;
	}
	bool XtpReqRemoveAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveAccount = ::Allocate<ReqRemoveAccountField>();
		memcpy(ReqRemoveAccount, buff + offset, sizeof(ReqRemoveAccountField));
		offset += sizeof(ReqRemoveAccountField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveAccount:AdminUserID:[%s], AccountID:[%s]",
			ReqRemoveAccount->AdminUserID, ReqRemoveAccount->AccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveAccountPackage::XtpRspRemoveAccountPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveAccountPackage* XtpRspRemoveAccountPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveAccountPackage>();
	}
	void XtpRspRemoveAccountPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveAccount != nullptr)
		{
			::Free<RspRemoveAccountField>(RspRemoveAccount);
			RspRemoveAccount = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveAccountPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveAccountPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveAccountPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveAccount, sizeof(RspRemoveAccountField));
		offset += sizeof(RspRemoveAccountField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveAccountPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveAccount = ::Allocate<RspRemoveAccountField>();
		memcpy(RspRemoveAccount, buff + offset, sizeof(RspRemoveAccountField));
		offset += sizeof(RspRemoveAccountField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveAccountPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveAccount:AdminUserID:[%s], AccountID:[%s]",
			RspRemoveAccount->AdminUserID, RspRemoveAccount->AccountID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddBaseCommissionPackage::XtpReqAddBaseCommissionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddBaseCommissionPackage* XtpReqAddBaseCommissionPackage::Allocate()
	{
		return ::Allocate<XtpReqAddBaseCommissionPackage>();
	}
	void XtpReqAddBaseCommissionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddBaseCommission != nullptr)
		{
			::Free<ReqAddBaseCommissionField>(ReqAddBaseCommission);
			ReqAddBaseCommission = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddBaseCommissionPackage>::GetInstance().Free(this);
	}
	void XtpReqAddBaseCommissionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddBaseCommissionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddBaseCommission, sizeof(ReqAddBaseCommissionField));
		offset += sizeof(ReqAddBaseCommissionField);
		return offset;
	}
	bool XtpReqAddBaseCommissionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddBaseCommission = ::Allocate<ReqAddBaseCommissionField>();
		memcpy(ReqAddBaseCommission, buff + offset, sizeof(ReqAddBaseCommissionField));
		offset += sizeof(ReqAddBaseCommissionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddBaseCommissionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]",
			ReqAddBaseCommission->AdminUserID, ReqAddBaseCommission->TradingDay, ReqAddBaseCommission->ExchangeID, (int)ReqAddBaseCommission->SecurityType, ReqAddBaseCommission->OpenStampTaxByMoney, ReqAddBaseCommission->CloseStampTaxByMoney, ReqAddBaseCommission->OpenTransferFeeByMoney, ReqAddBaseCommission->CloseTransferFeeByMoney);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddBaseCommissionPackage::XtpRspAddBaseCommissionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddBaseCommissionPackage* XtpRspAddBaseCommissionPackage::Allocate()
	{
		return ::Allocate<XtpRspAddBaseCommissionPackage>();
	}
	void XtpRspAddBaseCommissionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddBaseCommission != nullptr)
		{
			::Free<RspAddBaseCommissionField>(RspAddBaseCommission);
			RspAddBaseCommission = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddBaseCommissionPackage>::GetInstance().Free(this);
	}
	void XtpRspAddBaseCommissionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddBaseCommissionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddBaseCommission, sizeof(RspAddBaseCommissionField));
		offset += sizeof(RspAddBaseCommissionField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddBaseCommissionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddBaseCommission = ::Allocate<RspAddBaseCommissionField>();
		memcpy(RspAddBaseCommission, buff + offset, sizeof(RspAddBaseCommissionField));
		offset += sizeof(RspAddBaseCommissionField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddBaseCommissionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]",
			RspAddBaseCommission->AdminUserID, RspAddBaseCommission->TradingDay, RspAddBaseCommission->ExchangeID, (int)RspAddBaseCommission->SecurityType);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateBaseCommissionPackage::XtpReqUpdateBaseCommissionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateBaseCommissionPackage* XtpReqUpdateBaseCommissionPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateBaseCommissionPackage>();
	}
	void XtpReqUpdateBaseCommissionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateBaseCommission != nullptr)
		{
			::Free<ReqUpdateBaseCommissionField>(ReqUpdateBaseCommission);
			ReqUpdateBaseCommission = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateBaseCommissionPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateBaseCommissionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateBaseCommissionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateBaseCommission, sizeof(ReqUpdateBaseCommissionField));
		offset += sizeof(ReqUpdateBaseCommissionField);
		return offset;
	}
	bool XtpReqUpdateBaseCommissionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateBaseCommission = ::Allocate<ReqUpdateBaseCommissionField>();
		memcpy(ReqUpdateBaseCommission, buff + offset, sizeof(ReqUpdateBaseCommissionField));
		offset += sizeof(ReqUpdateBaseCommissionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateBaseCommissionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]",
			ReqUpdateBaseCommission->AdminUserID, ReqUpdateBaseCommission->TradingDay, ReqUpdateBaseCommission->ExchangeID, (int)ReqUpdateBaseCommission->SecurityType, ReqUpdateBaseCommission->OpenStampTaxByMoney, ReqUpdateBaseCommission->CloseStampTaxByMoney, ReqUpdateBaseCommission->OpenTransferFeeByMoney, ReqUpdateBaseCommission->CloseTransferFeeByMoney);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateBaseCommissionPackage::XtpRspUpdateBaseCommissionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateBaseCommissionPackage* XtpRspUpdateBaseCommissionPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateBaseCommissionPackage>();
	}
	void XtpRspUpdateBaseCommissionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateBaseCommission != nullptr)
		{
			::Free<RspUpdateBaseCommissionField>(RspUpdateBaseCommission);
			RspUpdateBaseCommission = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateBaseCommissionPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateBaseCommissionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateBaseCommissionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateBaseCommission, sizeof(RspUpdateBaseCommissionField));
		offset += sizeof(RspUpdateBaseCommissionField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateBaseCommissionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateBaseCommission = ::Allocate<RspUpdateBaseCommissionField>();
		memcpy(RspUpdateBaseCommission, buff + offset, sizeof(RspUpdateBaseCommissionField));
		offset += sizeof(RspUpdateBaseCommissionField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateBaseCommissionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]",
			RspUpdateBaseCommission->AdminUserID, RspUpdateBaseCommission->TradingDay, RspUpdateBaseCommission->ExchangeID, (int)RspUpdateBaseCommission->SecurityType);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveBaseCommissionPackage::XtpReqRemoveBaseCommissionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveBaseCommissionPackage* XtpReqRemoveBaseCommissionPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveBaseCommissionPackage>();
	}
	void XtpReqRemoveBaseCommissionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveBaseCommission != nullptr)
		{
			::Free<ReqRemoveBaseCommissionField>(ReqRemoveBaseCommission);
			ReqRemoveBaseCommission = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveBaseCommissionPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveBaseCommissionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveBaseCommissionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveBaseCommission, sizeof(ReqRemoveBaseCommissionField));
		offset += sizeof(ReqRemoveBaseCommissionField);
		return offset;
	}
	bool XtpReqRemoveBaseCommissionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveBaseCommission = ::Allocate<ReqRemoveBaseCommissionField>();
		memcpy(ReqRemoveBaseCommission, buff + offset, sizeof(ReqRemoveBaseCommissionField));
		offset += sizeof(ReqRemoveBaseCommissionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveBaseCommissionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]",
			ReqRemoveBaseCommission->AdminUserID, ReqRemoveBaseCommission->TradingDay, ReqRemoveBaseCommission->ExchangeID, (int)ReqRemoveBaseCommission->SecurityType);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveBaseCommissionPackage::XtpRspRemoveBaseCommissionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveBaseCommissionPackage* XtpRspRemoveBaseCommissionPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveBaseCommissionPackage>();
	}
	void XtpRspRemoveBaseCommissionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		if (RspRemoveBaseCommission != nullptr)
		{
			::Free<RspRemoveBaseCommissionField>(RspRemoveBaseCommission);
			RspRemoveBaseCommission = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveBaseCommissionPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveBaseCommissionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveBaseCommissionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		memcpy(buff + offset, RspRemoveBaseCommission, sizeof(RspRemoveBaseCommissionField));
		offset += sizeof(RspRemoveBaseCommissionField);
		return offset;
	}
	bool XtpRspRemoveBaseCommissionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		RspRemoveBaseCommission = ::Allocate<RspRemoveBaseCommissionField>();
		memcpy(RspRemoveBaseCommission, buff + offset, sizeof(RspRemoveBaseCommissionField));
		offset += sizeof(RspRemoveBaseCommissionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveBaseCommissionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]",
			RspRemoveBaseCommission->AdminUserID, RspRemoveBaseCommission->TradingDay, RspRemoveBaseCommission->ExchangeID, (int)RspRemoveBaseCommission->SecurityType);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddCommissionGroupPackage::XtpReqAddCommissionGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddCommissionGroupPackage* XtpReqAddCommissionGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqAddCommissionGroupPackage>();
	}
	void XtpReqAddCommissionGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddCommissionGroup != nullptr)
		{
			::Free<ReqAddCommissionGroupField>(ReqAddCommissionGroup);
			ReqAddCommissionGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddCommissionGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqAddCommissionGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddCommissionGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddCommissionGroup, sizeof(ReqAddCommissionGroupField));
		offset += sizeof(ReqAddCommissionGroupField);
		return offset;
	}
	bool XtpReqAddCommissionGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddCommissionGroup = ::Allocate<ReqAddCommissionGroupField>();
		memcpy(ReqAddCommissionGroup, buff + offset, sizeof(ReqAddCommissionGroupField));
		offset += sizeof(ReqAddCommissionGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddCommissionGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]",
			ReqAddCommissionGroup->AdminUserID, ReqAddCommissionGroup->TradingDay, ReqAddCommissionGroup->CommissionGroupID, ReqAddCommissionGroup->CommissionGroupName, ReqAddCommissionGroup->ExchangeID, (int)ReqAddCommissionGroup->SecurityType, ReqAddCommissionGroup->OpenBuyByMoney, ReqAddCommissionGroup->OpenSellByMoney, ReqAddCommissionGroup->CloseBuyByMoney, ReqAddCommissionGroup->CloseSellByMoney, ReqAddCommissionGroup->OpenBuyByVolume, ReqAddCommissionGroup->OpenSellByVolume, ReqAddCommissionGroup->CloseBuyByVolume, ReqAddCommissionGroup->CloseSellByVolume, ReqAddCommissionGroup->MinCommission, ReqAddCommissionGroup->MaxCommission);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddCommissionGroupPackage::XtpRspAddCommissionGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddCommissionGroupPackage* XtpRspAddCommissionGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspAddCommissionGroupPackage>();
	}
	void XtpRspAddCommissionGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddCommissionGroup != nullptr)
		{
			::Free<RspAddCommissionGroupField>(RspAddCommissionGroup);
			RspAddCommissionGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddCommissionGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspAddCommissionGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddCommissionGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddCommissionGroup, sizeof(RspAddCommissionGroupField));
		offset += sizeof(RspAddCommissionGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddCommissionGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddCommissionGroup = ::Allocate<RspAddCommissionGroupField>();
		memcpy(RspAddCommissionGroup, buff + offset, sizeof(RspAddCommissionGroupField));
		offset += sizeof(RspAddCommissionGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddCommissionGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]",
			RspAddCommissionGroup->AdminUserID, RspAddCommissionGroup->TradingDay, RspAddCommissionGroup->CommissionGroupID, RspAddCommissionGroup->ExchangeID, (int)RspAddCommissionGroup->SecurityType);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateCommissionGroupPackage::XtpReqUpdateCommissionGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateCommissionGroupPackage* XtpReqUpdateCommissionGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateCommissionGroupPackage>();
	}
	void XtpReqUpdateCommissionGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateCommissionGroup != nullptr)
		{
			::Free<ReqUpdateCommissionGroupField>(ReqUpdateCommissionGroup);
			ReqUpdateCommissionGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateCommissionGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateCommissionGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateCommissionGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateCommissionGroup, sizeof(ReqUpdateCommissionGroupField));
		offset += sizeof(ReqUpdateCommissionGroupField);
		return offset;
	}
	bool XtpReqUpdateCommissionGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateCommissionGroup = ::Allocate<ReqUpdateCommissionGroupField>();
		memcpy(ReqUpdateCommissionGroup, buff + offset, sizeof(ReqUpdateCommissionGroupField));
		offset += sizeof(ReqUpdateCommissionGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateCommissionGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]",
			ReqUpdateCommissionGroup->AdminUserID, ReqUpdateCommissionGroup->TradingDay, ReqUpdateCommissionGroup->CommissionGroupID, ReqUpdateCommissionGroup->CommissionGroupName, ReqUpdateCommissionGroup->ExchangeID, (int)ReqUpdateCommissionGroup->SecurityType, ReqUpdateCommissionGroup->OpenBuyByMoney, ReqUpdateCommissionGroup->OpenSellByMoney, ReqUpdateCommissionGroup->CloseBuyByMoney, ReqUpdateCommissionGroup->CloseSellByMoney, ReqUpdateCommissionGroup->OpenBuyByVolume, ReqUpdateCommissionGroup->OpenSellByVolume, ReqUpdateCommissionGroup->CloseBuyByVolume, ReqUpdateCommissionGroup->CloseSellByVolume, ReqUpdateCommissionGroup->MinCommission, ReqUpdateCommissionGroup->MaxCommission);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateCommissionGroupPackage::XtpRspUpdateCommissionGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateCommissionGroupPackage* XtpRspUpdateCommissionGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateCommissionGroupPackage>();
	}
	void XtpRspUpdateCommissionGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateCommissionGroup != nullptr)
		{
			::Free<RspUpdateCommissionGroupField>(RspUpdateCommissionGroup);
			RspUpdateCommissionGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateCommissionGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateCommissionGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateCommissionGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateCommissionGroup, sizeof(RspUpdateCommissionGroupField));
		offset += sizeof(RspUpdateCommissionGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateCommissionGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateCommissionGroup = ::Allocate<RspUpdateCommissionGroupField>();
		memcpy(RspUpdateCommissionGroup, buff + offset, sizeof(RspUpdateCommissionGroupField));
		offset += sizeof(RspUpdateCommissionGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateCommissionGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]",
			RspUpdateCommissionGroup->AdminUserID, RspUpdateCommissionGroup->TradingDay, RspUpdateCommissionGroup->CommissionGroupID, RspUpdateCommissionGroup->ExchangeID, (int)RspUpdateCommissionGroup->SecurityType);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveCommissionGroupPackage::XtpReqRemoveCommissionGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveCommissionGroupPackage* XtpReqRemoveCommissionGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveCommissionGroupPackage>();
	}
	void XtpReqRemoveCommissionGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveCommissionGroup != nullptr)
		{
			::Free<ReqRemoveCommissionGroupField>(ReqRemoveCommissionGroup);
			ReqRemoveCommissionGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveCommissionGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveCommissionGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveCommissionGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveCommissionGroup, sizeof(ReqRemoveCommissionGroupField));
		offset += sizeof(ReqRemoveCommissionGroupField);
		return offset;
	}
	bool XtpReqRemoveCommissionGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveCommissionGroup = ::Allocate<ReqRemoveCommissionGroupField>();
		memcpy(ReqRemoveCommissionGroup, buff + offset, sizeof(ReqRemoveCommissionGroupField));
		offset += sizeof(ReqRemoveCommissionGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveCommissionGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]",
			ReqRemoveCommissionGroup->AdminUserID, ReqRemoveCommissionGroup->TradingDay, ReqRemoveCommissionGroup->CommissionGroupID, ReqRemoveCommissionGroup->ExchangeID, (int)ReqRemoveCommissionGroup->SecurityType);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveCommissionGroupPackage::XtpRspRemoveCommissionGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveCommissionGroupPackage* XtpRspRemoveCommissionGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveCommissionGroupPackage>();
	}
	void XtpRspRemoveCommissionGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveCommissionGroup != nullptr)
		{
			::Free<RspRemoveCommissionGroupField>(RspRemoveCommissionGroup);
			RspRemoveCommissionGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveCommissionGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveCommissionGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveCommissionGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveCommissionGroup, sizeof(RspRemoveCommissionGroupField));
		offset += sizeof(RspRemoveCommissionGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveCommissionGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveCommissionGroup = ::Allocate<RspRemoveCommissionGroupField>();
		memcpy(RspRemoveCommissionGroup, buff + offset, sizeof(RspRemoveCommissionGroupField));
		offset += sizeof(RspRemoveCommissionGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveCommissionGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]",
			RspRemoveCommissionGroup->AdminUserID, RspRemoveCommissionGroup->TradingDay, RspRemoveCommissionGroup->CommissionGroupID, RspRemoveCommissionGroup->ExchangeID, (int)RspRemoveCommissionGroup->SecurityType);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddOptionMarginParamPackage::XtpReqAddOptionMarginParamPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddOptionMarginParamPackage* XtpReqAddOptionMarginParamPackage::Allocate()
	{
		return ::Allocate<XtpReqAddOptionMarginParamPackage>();
	}
	void XtpReqAddOptionMarginParamPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddOptionMarginParam != nullptr)
		{
			::Free<ReqAddOptionMarginParamField>(ReqAddOptionMarginParam);
			ReqAddOptionMarginParam = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddOptionMarginParamPackage>::GetInstance().Free(this);
	}
	void XtpReqAddOptionMarginParamPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddOptionMarginParamPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddOptionMarginParam, sizeof(ReqAddOptionMarginParamField));
		offset += sizeof(ReqAddOptionMarginParamField);
		return offset;
	}
	bool XtpReqAddOptionMarginParamPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddOptionMarginParam = ::Allocate<ReqAddOptionMarginParamField>();
		memcpy(ReqAddOptionMarginParam, buff + offset, sizeof(ReqAddOptionMarginParamField));
		offset += sizeof(ReqAddOptionMarginParamField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddOptionMarginParamPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddOptionMarginParam:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]",
			ReqAddOptionMarginParam->AdminUserID, ReqAddOptionMarginParam->TradingDay, ReqAddOptionMarginParam->ExchangeID, ReqAddOptionMarginParam->Param1, ReqAddOptionMarginParam->Param2);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddOptionMarginParamPackage::XtpRspAddOptionMarginParamPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddOptionMarginParamPackage* XtpRspAddOptionMarginParamPackage::Allocate()
	{
		return ::Allocate<XtpRspAddOptionMarginParamPackage>();
	}
	void XtpRspAddOptionMarginParamPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddOptionMarginParam != nullptr)
		{
			::Free<RspAddOptionMarginParamField>(RspAddOptionMarginParam);
			RspAddOptionMarginParam = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddOptionMarginParamPackage>::GetInstance().Free(this);
	}
	void XtpRspAddOptionMarginParamPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddOptionMarginParamPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddOptionMarginParam, sizeof(RspAddOptionMarginParamField));
		offset += sizeof(RspAddOptionMarginParamField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddOptionMarginParamPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddOptionMarginParam = ::Allocate<RspAddOptionMarginParamField>();
		memcpy(RspAddOptionMarginParam, buff + offset, sizeof(RspAddOptionMarginParamField));
		offset += sizeof(RspAddOptionMarginParamField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddOptionMarginParamPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]",
			RspAddOptionMarginParam->AdminUserID, RspAddOptionMarginParam->ExchangeID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateOptionMarginParamPackage::XtpReqUpdateOptionMarginParamPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateOptionMarginParamPackage* XtpReqUpdateOptionMarginParamPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateOptionMarginParamPackage>();
	}
	void XtpReqUpdateOptionMarginParamPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateOptionMarginParam != nullptr)
		{
			::Free<ReqUpdateOptionMarginParamField>(ReqUpdateOptionMarginParam);
			ReqUpdateOptionMarginParam = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateOptionMarginParamPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateOptionMarginParamPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateOptionMarginParamPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateOptionMarginParam, sizeof(ReqUpdateOptionMarginParamField));
		offset += sizeof(ReqUpdateOptionMarginParamField);
		return offset;
	}
	bool XtpReqUpdateOptionMarginParamPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateOptionMarginParam = ::Allocate<ReqUpdateOptionMarginParamField>();
		memcpy(ReqUpdateOptionMarginParam, buff + offset, sizeof(ReqUpdateOptionMarginParamField));
		offset += sizeof(ReqUpdateOptionMarginParamField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateOptionMarginParamPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateOptionMarginParam:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]",
			ReqUpdateOptionMarginParam->AdminUserID, ReqUpdateOptionMarginParam->TradingDay, ReqUpdateOptionMarginParam->ExchangeID, ReqUpdateOptionMarginParam->Param1, ReqUpdateOptionMarginParam->Param2);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateOptionMarginParamPackage::XtpRspUpdateOptionMarginParamPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateOptionMarginParamPackage* XtpRspUpdateOptionMarginParamPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateOptionMarginParamPackage>();
	}
	void XtpRspUpdateOptionMarginParamPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateOptionMarginParam != nullptr)
		{
			::Free<RspUpdateOptionMarginParamField>(RspUpdateOptionMarginParam);
			RspUpdateOptionMarginParam = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateOptionMarginParamPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateOptionMarginParamPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateOptionMarginParamPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateOptionMarginParam, sizeof(RspUpdateOptionMarginParamField));
		offset += sizeof(RspUpdateOptionMarginParamField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateOptionMarginParamPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateOptionMarginParam = ::Allocate<RspUpdateOptionMarginParamField>();
		memcpy(RspUpdateOptionMarginParam, buff + offset, sizeof(RspUpdateOptionMarginParamField));
		offset += sizeof(RspUpdateOptionMarginParamField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateOptionMarginParamPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]",
			RspUpdateOptionMarginParam->AdminUserID, RspUpdateOptionMarginParam->ExchangeID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveOptionMarginParamPackage::XtpReqRemoveOptionMarginParamPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveOptionMarginParamPackage* XtpReqRemoveOptionMarginParamPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveOptionMarginParamPackage>();
	}
	void XtpReqRemoveOptionMarginParamPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveOptionMarginParam != nullptr)
		{
			::Free<ReqRemoveOptionMarginParamField>(ReqRemoveOptionMarginParam);
			ReqRemoveOptionMarginParam = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveOptionMarginParamPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveOptionMarginParamPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveOptionMarginParamPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveOptionMarginParam, sizeof(ReqRemoveOptionMarginParamField));
		offset += sizeof(ReqRemoveOptionMarginParamField);
		return offset;
	}
	bool XtpReqRemoveOptionMarginParamPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveOptionMarginParam = ::Allocate<ReqRemoveOptionMarginParamField>();
		memcpy(ReqRemoveOptionMarginParam, buff + offset, sizeof(ReqRemoveOptionMarginParamField));
		offset += sizeof(ReqRemoveOptionMarginParamField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveOptionMarginParamPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]",
			ReqRemoveOptionMarginParam->AdminUserID, ReqRemoveOptionMarginParam->ExchangeID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveOptionMarginParamPackage::XtpRspRemoveOptionMarginParamPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveOptionMarginParamPackage* XtpRspRemoveOptionMarginParamPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveOptionMarginParamPackage>();
	}
	void XtpRspRemoveOptionMarginParamPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveOptionMarginParam != nullptr)
		{
			::Free<RspRemoveOptionMarginParamField>(RspRemoveOptionMarginParam);
			RspRemoveOptionMarginParam = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveOptionMarginParamPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveOptionMarginParamPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveOptionMarginParamPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveOptionMarginParam, sizeof(RspRemoveOptionMarginParamField));
		offset += sizeof(RspRemoveOptionMarginParamField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveOptionMarginParamPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveOptionMarginParam = ::Allocate<RspRemoveOptionMarginParamField>();
		memcpy(RspRemoveOptionMarginParam, buff + offset, sizeof(RspRemoveOptionMarginParamField));
		offset += sizeof(RspRemoveOptionMarginParamField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveOptionMarginParamPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]",
			RspRemoveOptionMarginParam->AdminUserID, RspRemoveOptionMarginParam->ExchangeID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddTradeOfferPackage::XtpReqAddTradeOfferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddTradeOfferPackage* XtpReqAddTradeOfferPackage::Allocate()
	{
		return ::Allocate<XtpReqAddTradeOfferPackage>();
	}
	void XtpReqAddTradeOfferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddTradeOffer != nullptr)
		{
			::Free<ReqAddTradeOfferField>(ReqAddTradeOffer);
			ReqAddTradeOffer = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddTradeOfferPackage>::GetInstance().Free(this);
	}
	void XtpReqAddTradeOfferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddTradeOfferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddTradeOffer, sizeof(ReqAddTradeOfferField));
		offset += sizeof(ReqAddTradeOfferField);
		return offset;
	}
	bool XtpReqAddTradeOfferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddTradeOffer = ::Allocate<ReqAddTradeOfferField>();
		memcpy(ReqAddTradeOffer, buff + offset, sizeof(ReqAddTradeOfferField));
		offset += sizeof(ReqAddTradeOfferField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddTradeOfferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddTradeOffer:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]",
			ReqAddTradeOffer->AdminUserID, ReqAddTradeOffer->OfferID, ReqAddTradeOffer->OfferName, (int)ReqAddTradeOffer->OfferType, ReqAddTradeOffer->OfferPassword);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddTradeOfferPackage::XtpRspAddTradeOfferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddTradeOfferPackage* XtpRspAddTradeOfferPackage::Allocate()
	{
		return ::Allocate<XtpRspAddTradeOfferPackage>();
	}
	void XtpRspAddTradeOfferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddTradeOffer != nullptr)
		{
			::Free<RspAddTradeOfferField>(RspAddTradeOffer);
			RspAddTradeOffer = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddTradeOfferPackage>::GetInstance().Free(this);
	}
	void XtpRspAddTradeOfferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddTradeOfferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddTradeOffer, sizeof(RspAddTradeOfferField));
		offset += sizeof(RspAddTradeOfferField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddTradeOfferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddTradeOffer = ::Allocate<RspAddTradeOfferField>();
		memcpy(RspAddTradeOffer, buff + offset, sizeof(RspAddTradeOfferField));
		offset += sizeof(RspAddTradeOfferField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddTradeOfferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddTradeOffer:AdminUserID:[%s], OfferID:[%d]",
			RspAddTradeOffer->AdminUserID, RspAddTradeOffer->OfferID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateTradeOfferPackage::XtpReqUpdateTradeOfferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateTradeOfferPackage* XtpReqUpdateTradeOfferPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateTradeOfferPackage>();
	}
	void XtpReqUpdateTradeOfferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateTradeOffer != nullptr)
		{
			::Free<ReqUpdateTradeOfferField>(ReqUpdateTradeOffer);
			ReqUpdateTradeOffer = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateTradeOfferPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateTradeOfferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateTradeOfferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateTradeOffer, sizeof(ReqUpdateTradeOfferField));
		offset += sizeof(ReqUpdateTradeOfferField);
		return offset;
	}
	bool XtpReqUpdateTradeOfferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateTradeOffer = ::Allocate<ReqUpdateTradeOfferField>();
		memcpy(ReqUpdateTradeOffer, buff + offset, sizeof(ReqUpdateTradeOfferField));
		offset += sizeof(ReqUpdateTradeOfferField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateTradeOfferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateTradeOffer:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]",
			ReqUpdateTradeOffer->AdminUserID, ReqUpdateTradeOffer->OfferID, ReqUpdateTradeOffer->OfferName, (int)ReqUpdateTradeOffer->OfferType, ReqUpdateTradeOffer->OfferPassword);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateTradeOfferPackage::XtpRspUpdateTradeOfferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateTradeOfferPackage* XtpRspUpdateTradeOfferPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateTradeOfferPackage>();
	}
	void XtpRspUpdateTradeOfferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateTradeOffer != nullptr)
		{
			::Free<RspUpdateTradeOfferField>(RspUpdateTradeOffer);
			RspUpdateTradeOffer = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateTradeOfferPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateTradeOfferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateTradeOfferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateTradeOffer, sizeof(RspUpdateTradeOfferField));
		offset += sizeof(RspUpdateTradeOfferField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateTradeOfferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateTradeOffer = ::Allocate<RspUpdateTradeOfferField>();
		memcpy(RspUpdateTradeOffer, buff + offset, sizeof(RspUpdateTradeOfferField));
		offset += sizeof(RspUpdateTradeOfferField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateTradeOfferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateTradeOffer:AdminUserID:[%s], OfferID:[%d]",
			RspUpdateTradeOffer->AdminUserID, RspUpdateTradeOffer->OfferID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveTradeOfferPackage::XtpReqRemoveTradeOfferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveTradeOfferPackage* XtpReqRemoveTradeOfferPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveTradeOfferPackage>();
	}
	void XtpReqRemoveTradeOfferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveTradeOffer != nullptr)
		{
			::Free<ReqRemoveTradeOfferField>(ReqRemoveTradeOffer);
			ReqRemoveTradeOffer = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveTradeOfferPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveTradeOfferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveTradeOfferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveTradeOffer, sizeof(ReqRemoveTradeOfferField));
		offset += sizeof(ReqRemoveTradeOfferField);
		return offset;
	}
	bool XtpReqRemoveTradeOfferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveTradeOffer = ::Allocate<ReqRemoveTradeOfferField>();
		memcpy(ReqRemoveTradeOffer, buff + offset, sizeof(ReqRemoveTradeOfferField));
		offset += sizeof(ReqRemoveTradeOfferField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveTradeOfferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveTradeOffer:AdminUserID:[%s], OfferID:[%d]",
			ReqRemoveTradeOffer->AdminUserID, ReqRemoveTradeOffer->OfferID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveTradeOfferPackage::XtpRspRemoveTradeOfferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveTradeOfferPackage* XtpRspRemoveTradeOfferPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveTradeOfferPackage>();
	}
	void XtpRspRemoveTradeOfferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveTradeOffer != nullptr)
		{
			::Free<RspRemoveTradeOfferField>(RspRemoveTradeOffer);
			RspRemoveTradeOffer = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveTradeOfferPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveTradeOfferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveTradeOfferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveTradeOffer, sizeof(RspRemoveTradeOfferField));
		offset += sizeof(RspRemoveTradeOfferField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveTradeOfferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveTradeOffer = ::Allocate<RspRemoveTradeOfferField>();
		memcpy(RspRemoveTradeOffer, buff + offset, sizeof(RspRemoveTradeOfferField));
		offset += sizeof(RspRemoveTradeOfferField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveTradeOfferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveTradeOffer:AdminUserID:[%s], OfferID:[%d]",
			RspRemoveTradeOffer->AdminUserID, RspRemoveTradeOffer->OfferID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddTradeGroupPackage::XtpReqAddTradeGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddTradeGroupPackage* XtpReqAddTradeGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqAddTradeGroupPackage>();
	}
	void XtpReqAddTradeGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddTradeGroup != nullptr)
		{
			::Free<ReqAddTradeGroupField>(ReqAddTradeGroup);
			ReqAddTradeGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddTradeGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqAddTradeGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddTradeGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddTradeGroup, sizeof(ReqAddTradeGroupField));
		offset += sizeof(ReqAddTradeGroupField);
		return offset;
	}
	bool XtpReqAddTradeGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddTradeGroup = ::Allocate<ReqAddTradeGroupField>();
		memcpy(ReqAddTradeGroup, buff + offset, sizeof(ReqAddTradeGroupField));
		offset += sizeof(ReqAddTradeGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddTradeGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddTradeGroup:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]",
			ReqAddTradeGroup->AdminUserID, ReqAddTradeGroup->TradeGroupID, ReqAddTradeGroup->TradeGroupName);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddTradeGroupPackage::XtpRspAddTradeGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddTradeGroupPackage* XtpRspAddTradeGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspAddTradeGroupPackage>();
	}
	void XtpRspAddTradeGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddTradeGroup != nullptr)
		{
			::Free<RspAddTradeGroupField>(RspAddTradeGroup);
			RspAddTradeGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddTradeGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspAddTradeGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddTradeGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddTradeGroup, sizeof(RspAddTradeGroupField));
		offset += sizeof(RspAddTradeGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddTradeGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddTradeGroup = ::Allocate<RspAddTradeGroupField>();
		memcpy(RspAddTradeGroup, buff + offset, sizeof(RspAddTradeGroupField));
		offset += sizeof(RspAddTradeGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddTradeGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]",
			RspAddTradeGroup->AdminUserID, RspAddTradeGroup->TradeGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateTradeGroupPackage::XtpReqUpdateTradeGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateTradeGroupPackage* XtpReqUpdateTradeGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateTradeGroupPackage>();
	}
	void XtpReqUpdateTradeGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateTradeGroup != nullptr)
		{
			::Free<ReqUpdateTradeGroupField>(ReqUpdateTradeGroup);
			ReqUpdateTradeGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateTradeGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateTradeGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateTradeGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateTradeGroup, sizeof(ReqUpdateTradeGroupField));
		offset += sizeof(ReqUpdateTradeGroupField);
		return offset;
	}
	bool XtpReqUpdateTradeGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateTradeGroup = ::Allocate<ReqUpdateTradeGroupField>();
		memcpy(ReqUpdateTradeGroup, buff + offset, sizeof(ReqUpdateTradeGroupField));
		offset += sizeof(ReqUpdateTradeGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateTradeGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateTradeGroup:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]",
			ReqUpdateTradeGroup->AdminUserID, ReqUpdateTradeGroup->TradeGroupID, ReqUpdateTradeGroup->TradeGroupName);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateTradeGroupPackage::XtpRspUpdateTradeGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateTradeGroupPackage* XtpRspUpdateTradeGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateTradeGroupPackage>();
	}
	void XtpRspUpdateTradeGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateTradeGroup != nullptr)
		{
			::Free<RspUpdateTradeGroupField>(RspUpdateTradeGroup);
			RspUpdateTradeGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateTradeGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateTradeGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateTradeGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateTradeGroup, sizeof(RspUpdateTradeGroupField));
		offset += sizeof(RspUpdateTradeGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateTradeGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateTradeGroup = ::Allocate<RspUpdateTradeGroupField>();
		memcpy(RspUpdateTradeGroup, buff + offset, sizeof(RspUpdateTradeGroupField));
		offset += sizeof(RspUpdateTradeGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateTradeGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]",
			RspUpdateTradeGroup->AdminUserID, RspUpdateTradeGroup->TradeGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveTradeGroupPackage::XtpReqRemoveTradeGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveTradeGroupPackage* XtpReqRemoveTradeGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveTradeGroupPackage>();
	}
	void XtpReqRemoveTradeGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveTradeGroup != nullptr)
		{
			::Free<ReqRemoveTradeGroupField>(ReqRemoveTradeGroup);
			ReqRemoveTradeGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveTradeGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveTradeGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveTradeGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveTradeGroup, sizeof(ReqRemoveTradeGroupField));
		offset += sizeof(ReqRemoveTradeGroupField);
		return offset;
	}
	bool XtpReqRemoveTradeGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveTradeGroup = ::Allocate<ReqRemoveTradeGroupField>();
		memcpy(ReqRemoveTradeGroup, buff + offset, sizeof(ReqRemoveTradeGroupField));
		offset += sizeof(ReqRemoveTradeGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveTradeGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]",
			ReqRemoveTradeGroup->AdminUserID, ReqRemoveTradeGroup->TradeGroupID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveTradeGroupPackage::XtpRspRemoveTradeGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveTradeGroupPackage* XtpRspRemoveTradeGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveTradeGroupPackage>();
	}
	void XtpRspRemoveTradeGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveTradeGroup != nullptr)
		{
			::Free<RspRemoveTradeGroupField>(RspRemoveTradeGroup);
			RspRemoveTradeGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveTradeGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveTradeGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveTradeGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveTradeGroup, sizeof(RspRemoveTradeGroupField));
		offset += sizeof(RspRemoveTradeGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveTradeGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveTradeGroup = ::Allocate<RspRemoveTradeGroupField>();
		memcpy(RspRemoveTradeGroup, buff + offset, sizeof(RspRemoveTradeGroupField));
		offset += sizeof(RspRemoveTradeGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveTradeGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]",
			RspRemoveTradeGroup->AdminUserID, RspRemoveTradeGroup->TradeGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddTradeGroupItemPackage::XtpReqAddTradeGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddTradeGroupItemPackage* XtpReqAddTradeGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpReqAddTradeGroupItemPackage>();
	}
	void XtpReqAddTradeGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddTradeGroupItem != nullptr)
		{
			::Free<ReqAddTradeGroupItemField>(ReqAddTradeGroupItem);
			ReqAddTradeGroupItem = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddTradeGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpReqAddTradeGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddTradeGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddTradeGroupItem, sizeof(ReqAddTradeGroupItemField));
		offset += sizeof(ReqAddTradeGroupItemField);
		return offset;
	}
	bool XtpReqAddTradeGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddTradeGroupItem = ::Allocate<ReqAddTradeGroupItemField>();
		memcpy(ReqAddTradeGroupItem, buff + offset, sizeof(ReqAddTradeGroupItemField));
		offset += sizeof(ReqAddTradeGroupItemField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddTradeGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]",
			ReqAddTradeGroupItem->AdminUserID, ReqAddTradeGroupItem->TradeGroupID, (int)ReqAddTradeGroupItem->AccountClass, ReqAddTradeGroupItem->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddTradeGroupItemPackage::XtpRspAddTradeGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddTradeGroupItemPackage* XtpRspAddTradeGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpRspAddTradeGroupItemPackage>();
	}
	void XtpRspAddTradeGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddTradeGroupItem != nullptr)
		{
			::Free<RspAddTradeGroupItemField>(RspAddTradeGroupItem);
			RspAddTradeGroupItem = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddTradeGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpRspAddTradeGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddTradeGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddTradeGroupItem, sizeof(RspAddTradeGroupItemField));
		offset += sizeof(RspAddTradeGroupItemField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddTradeGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddTradeGroupItem = ::Allocate<RspAddTradeGroupItemField>();
		memcpy(RspAddTradeGroupItem, buff + offset, sizeof(RspAddTradeGroupItemField));
		offset += sizeof(RspAddTradeGroupItemField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddTradeGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]",
			RspAddTradeGroupItem->AdminUserID, RspAddTradeGroupItem->TradeGroupID, (int)RspAddTradeGroupItem->AccountClass);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateTradeGroupItemPackage::XtpReqUpdateTradeGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateTradeGroupItemPackage* XtpReqUpdateTradeGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateTradeGroupItemPackage>();
	}
	void XtpReqUpdateTradeGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateTradeGroupItem != nullptr)
		{
			::Free<ReqUpdateTradeGroupItemField>(ReqUpdateTradeGroupItem);
			ReqUpdateTradeGroupItem = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateTradeGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateTradeGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateTradeGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateTradeGroupItem, sizeof(ReqUpdateTradeGroupItemField));
		offset += sizeof(ReqUpdateTradeGroupItemField);
		return offset;
	}
	bool XtpReqUpdateTradeGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateTradeGroupItem = ::Allocate<ReqUpdateTradeGroupItemField>();
		memcpy(ReqUpdateTradeGroupItem, buff + offset, sizeof(ReqUpdateTradeGroupItemField));
		offset += sizeof(ReqUpdateTradeGroupItemField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateTradeGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]",
			ReqUpdateTradeGroupItem->AdminUserID, ReqUpdateTradeGroupItem->TradeGroupID, (int)ReqUpdateTradeGroupItem->AccountClass, ReqUpdateTradeGroupItem->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateTradeGroupItemPackage::XtpRspUpdateTradeGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateTradeGroupItemPackage* XtpRspUpdateTradeGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateTradeGroupItemPackage>();
	}
	void XtpRspUpdateTradeGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateTradeGroupItem != nullptr)
		{
			::Free<RspUpdateTradeGroupItemField>(RspUpdateTradeGroupItem);
			RspUpdateTradeGroupItem = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateTradeGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateTradeGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateTradeGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateTradeGroupItem, sizeof(RspUpdateTradeGroupItemField));
		offset += sizeof(RspUpdateTradeGroupItemField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateTradeGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateTradeGroupItem = ::Allocate<RspUpdateTradeGroupItemField>();
		memcpy(RspUpdateTradeGroupItem, buff + offset, sizeof(RspUpdateTradeGroupItemField));
		offset += sizeof(RspUpdateTradeGroupItemField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateTradeGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]",
			RspUpdateTradeGroupItem->AdminUserID, RspUpdateTradeGroupItem->TradeGroupID, (int)RspUpdateTradeGroupItem->AccountClass);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveTradeGroupItemPackage::XtpReqRemoveTradeGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveTradeGroupItemPackage* XtpReqRemoveTradeGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveTradeGroupItemPackage>();
	}
	void XtpReqRemoveTradeGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveTradeGroupItem != nullptr)
		{
			::Free<ReqRemoveTradeGroupItemField>(ReqRemoveTradeGroupItem);
			ReqRemoveTradeGroupItem = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveTradeGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveTradeGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveTradeGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveTradeGroupItem, sizeof(ReqRemoveTradeGroupItemField));
		offset += sizeof(ReqRemoveTradeGroupItemField);
		return offset;
	}
	bool XtpReqRemoveTradeGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveTradeGroupItem = ::Allocate<ReqRemoveTradeGroupItemField>();
		memcpy(ReqRemoveTradeGroupItem, buff + offset, sizeof(ReqRemoveTradeGroupItemField));
		offset += sizeof(ReqRemoveTradeGroupItemField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveTradeGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]",
			ReqRemoveTradeGroupItem->AdminUserID, ReqRemoveTradeGroupItem->TradeGroupID, (int)ReqRemoveTradeGroupItem->AccountClass);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveTradeGroupItemPackage::XtpRspRemoveTradeGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveTradeGroupItemPackage* XtpRspRemoveTradeGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveTradeGroupItemPackage>();
	}
	void XtpRspRemoveTradeGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveTradeGroupItem != nullptr)
		{
			::Free<RspRemoveTradeGroupItemField>(RspRemoveTradeGroupItem);
			RspRemoveTradeGroupItem = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveTradeGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveTradeGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveTradeGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveTradeGroupItem, sizeof(RspRemoveTradeGroupItemField));
		offset += sizeof(RspRemoveTradeGroupItemField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveTradeGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveTradeGroupItem = ::Allocate<RspRemoveTradeGroupItemField>();
		memcpy(RspRemoveTradeGroupItem, buff + offset, sizeof(RspRemoveTradeGroupItemField));
		offset += sizeof(RspRemoveTradeGroupItemField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveTradeGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]",
			RspRemoveTradeGroupItem->AdminUserID, RspRemoveTradeGroupItem->TradeGroupID, (int)RspRemoveTradeGroupItem->AccountClass);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddRiskGroupPackage::XtpReqAddRiskGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddRiskGroupPackage* XtpReqAddRiskGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqAddRiskGroupPackage>();
	}
	void XtpReqAddRiskGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddRiskGroup != nullptr)
		{
			::Free<ReqAddRiskGroupField>(ReqAddRiskGroup);
			ReqAddRiskGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddRiskGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqAddRiskGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddRiskGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddRiskGroup, sizeof(ReqAddRiskGroupField));
		offset += sizeof(ReqAddRiskGroupField);
		return offset;
	}
	bool XtpReqAddRiskGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddRiskGroup = ::Allocate<ReqAddRiskGroupField>();
		memcpy(ReqAddRiskGroup, buff + offset, sizeof(ReqAddRiskGroupField));
		offset += sizeof(ReqAddRiskGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddRiskGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddRiskGroup:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]",
			ReqAddRiskGroup->AdminUserID, ReqAddRiskGroup->RiskGroupID, ReqAddRiskGroup->RiskGroupName);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddRiskGroupPackage::XtpRspAddRiskGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddRiskGroupPackage* XtpRspAddRiskGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspAddRiskGroupPackage>();
	}
	void XtpRspAddRiskGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddRiskGroup != nullptr)
		{
			::Free<RspAddRiskGroupField>(RspAddRiskGroup);
			RspAddRiskGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddRiskGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspAddRiskGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddRiskGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddRiskGroup, sizeof(RspAddRiskGroupField));
		offset += sizeof(RspAddRiskGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddRiskGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddRiskGroup = ::Allocate<RspAddRiskGroupField>();
		memcpy(RspAddRiskGroup, buff + offset, sizeof(RspAddRiskGroupField));
		offset += sizeof(RspAddRiskGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddRiskGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]",
			RspAddRiskGroup->AdminUserID, RspAddRiskGroup->RiskGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateRiskGroupPackage::XtpReqUpdateRiskGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateRiskGroupPackage* XtpReqUpdateRiskGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateRiskGroupPackage>();
	}
	void XtpReqUpdateRiskGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateRiskGroup != nullptr)
		{
			::Free<ReqUpdateRiskGroupField>(ReqUpdateRiskGroup);
			ReqUpdateRiskGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateRiskGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateRiskGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateRiskGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateRiskGroup, sizeof(ReqUpdateRiskGroupField));
		offset += sizeof(ReqUpdateRiskGroupField);
		return offset;
	}
	bool XtpReqUpdateRiskGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateRiskGroup = ::Allocate<ReqUpdateRiskGroupField>();
		memcpy(ReqUpdateRiskGroup, buff + offset, sizeof(ReqUpdateRiskGroupField));
		offset += sizeof(ReqUpdateRiskGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateRiskGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateRiskGroup:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]",
			ReqUpdateRiskGroup->AdminUserID, ReqUpdateRiskGroup->RiskGroupID, ReqUpdateRiskGroup->RiskGroupName);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateRiskGroupPackage::XtpRspUpdateRiskGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateRiskGroupPackage* XtpRspUpdateRiskGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateRiskGroupPackage>();
	}
	void XtpRspUpdateRiskGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateRiskGroup != nullptr)
		{
			::Free<RspUpdateRiskGroupField>(RspUpdateRiskGroup);
			RspUpdateRiskGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateRiskGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateRiskGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateRiskGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateRiskGroup, sizeof(RspUpdateRiskGroupField));
		offset += sizeof(RspUpdateRiskGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateRiskGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateRiskGroup = ::Allocate<RspUpdateRiskGroupField>();
		memcpy(RspUpdateRiskGroup, buff + offset, sizeof(RspUpdateRiskGroupField));
		offset += sizeof(RspUpdateRiskGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateRiskGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]",
			RspUpdateRiskGroup->AdminUserID, RspUpdateRiskGroup->RiskGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveRiskGroupPackage::XtpReqRemoveRiskGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveRiskGroupPackage* XtpReqRemoveRiskGroupPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveRiskGroupPackage>();
	}
	void XtpReqRemoveRiskGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveRiskGroup != nullptr)
		{
			::Free<ReqRemoveRiskGroupField>(ReqRemoveRiskGroup);
			ReqRemoveRiskGroup = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveRiskGroupPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveRiskGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveRiskGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveRiskGroup, sizeof(ReqRemoveRiskGroupField));
		offset += sizeof(ReqRemoveRiskGroupField);
		return offset;
	}
	bool XtpReqRemoveRiskGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveRiskGroup = ::Allocate<ReqRemoveRiskGroupField>();
		memcpy(ReqRemoveRiskGroup, buff + offset, sizeof(ReqRemoveRiskGroupField));
		offset += sizeof(ReqRemoveRiskGroupField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveRiskGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]",
			ReqRemoveRiskGroup->AdminUserID, ReqRemoveRiskGroup->RiskGroupID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveRiskGroupPackage::XtpRspRemoveRiskGroupPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveRiskGroupPackage* XtpRspRemoveRiskGroupPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveRiskGroupPackage>();
	}
	void XtpRspRemoveRiskGroupPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveRiskGroup != nullptr)
		{
			::Free<RspRemoveRiskGroupField>(RspRemoveRiskGroup);
			RspRemoveRiskGroup = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveRiskGroupPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveRiskGroupPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveRiskGroupPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveRiskGroup, sizeof(RspRemoveRiskGroupField));
		offset += sizeof(RspRemoveRiskGroupField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveRiskGroupPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveRiskGroup = ::Allocate<RspRemoveRiskGroupField>();
		memcpy(RspRemoveRiskGroup, buff + offset, sizeof(RspRemoveRiskGroupField));
		offset += sizeof(RspRemoveRiskGroupField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveRiskGroupPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]",
			RspRemoveRiskGroup->AdminUserID, RspRemoveRiskGroup->RiskGroupID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddRiskGroupItemPackage::XtpReqAddRiskGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddRiskGroupItemPackage* XtpReqAddRiskGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpReqAddRiskGroupItemPackage>();
	}
	void XtpReqAddRiskGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddRiskGroupItem != nullptr)
		{
			::Free<ReqAddRiskGroupItemField>(ReqAddRiskGroupItem);
			ReqAddRiskGroupItem = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddRiskGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpReqAddRiskGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddRiskGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddRiskGroupItem, sizeof(ReqAddRiskGroupItemField));
		offset += sizeof(ReqAddRiskGroupItemField);
		return offset;
	}
	bool XtpReqAddRiskGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddRiskGroupItem = ::Allocate<ReqAddRiskGroupItemField>();
		memcpy(ReqAddRiskGroupItem, buff + offset, sizeof(ReqAddRiskGroupItemField));
		offset += sizeof(ReqAddRiskGroupItemField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddRiskGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]",
			ReqAddRiskGroupItem->AdminUserID, ReqAddRiskGroupItem->RiskGroupID, ReqAddRiskGroupItem->RiskID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddRiskGroupItemPackage::XtpRspAddRiskGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddRiskGroupItemPackage* XtpRspAddRiskGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpRspAddRiskGroupItemPackage>();
	}
	void XtpRspAddRiskGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddRiskGroupItem != nullptr)
		{
			::Free<RspAddRiskGroupItemField>(RspAddRiskGroupItem);
			RspAddRiskGroupItem = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddRiskGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpRspAddRiskGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddRiskGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddRiskGroupItem, sizeof(RspAddRiskGroupItemField));
		offset += sizeof(RspAddRiskGroupItemField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddRiskGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddRiskGroupItem = ::Allocate<RspAddRiskGroupItemField>();
		memcpy(RspAddRiskGroupItem, buff + offset, sizeof(RspAddRiskGroupItemField));
		offset += sizeof(RspAddRiskGroupItemField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddRiskGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]",
			RspAddRiskGroupItem->AdminUserID, RspAddRiskGroupItem->RiskGroupID, RspAddRiskGroupItem->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqUpdateRiskGroupItemPackage::XtpReqUpdateRiskGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqUpdateRiskGroupItemPackage* XtpReqUpdateRiskGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpReqUpdateRiskGroupItemPackage>();
	}
	void XtpReqUpdateRiskGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqUpdateRiskGroupItem != nullptr)
		{
			::Free<ReqUpdateRiskGroupItemField>(ReqUpdateRiskGroupItem);
			ReqUpdateRiskGroupItem = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqUpdateRiskGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpReqUpdateRiskGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqUpdateRiskGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqUpdateRiskGroupItem, sizeof(ReqUpdateRiskGroupItemField));
		offset += sizeof(ReqUpdateRiskGroupItemField);
		return offset;
	}
	bool XtpReqUpdateRiskGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqUpdateRiskGroupItem = ::Allocate<ReqUpdateRiskGroupItemField>();
		memcpy(ReqUpdateRiskGroupItem, buff + offset, sizeof(ReqUpdateRiskGroupItemField));
		offset += sizeof(ReqUpdateRiskGroupItemField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqUpdateRiskGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqUpdateRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]",
			ReqUpdateRiskGroupItem->AdminUserID, ReqUpdateRiskGroupItem->RiskGroupID, ReqUpdateRiskGroupItem->RiskID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspUpdateRiskGroupItemPackage::XtpRspUpdateRiskGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspUpdateRiskGroupItemPackage* XtpRspUpdateRiskGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpRspUpdateRiskGroupItemPackage>();
	}
	void XtpRspUpdateRiskGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspUpdateRiskGroupItem != nullptr)
		{
			::Free<RspUpdateRiskGroupItemField>(RspUpdateRiskGroupItem);
			RspUpdateRiskGroupItem = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspUpdateRiskGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpRspUpdateRiskGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspUpdateRiskGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspUpdateRiskGroupItem, sizeof(RspUpdateRiskGroupItemField));
		offset += sizeof(RspUpdateRiskGroupItemField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspUpdateRiskGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspUpdateRiskGroupItem = ::Allocate<RspUpdateRiskGroupItemField>();
		memcpy(RspUpdateRiskGroupItem, buff + offset, sizeof(RspUpdateRiskGroupItemField));
		offset += sizeof(RspUpdateRiskGroupItemField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspUpdateRiskGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspUpdateRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]",
			RspUpdateRiskGroupItem->AdminUserID, RspUpdateRiskGroupItem->RiskGroupID, RspUpdateRiskGroupItem->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveRiskGroupItemPackage::XtpReqRemoveRiskGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveRiskGroupItemPackage* XtpReqRemoveRiskGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveRiskGroupItemPackage>();
	}
	void XtpReqRemoveRiskGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveRiskGroupItem != nullptr)
		{
			::Free<ReqRemoveRiskGroupItemField>(ReqRemoveRiskGroupItem);
			ReqRemoveRiskGroupItem = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveRiskGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveRiskGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveRiskGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveRiskGroupItem, sizeof(ReqRemoveRiskGroupItemField));
		offset += sizeof(ReqRemoveRiskGroupItemField);
		return offset;
	}
	bool XtpReqRemoveRiskGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveRiskGroupItem = ::Allocate<ReqRemoveRiskGroupItemField>();
		memcpy(ReqRemoveRiskGroupItem, buff + offset, sizeof(ReqRemoveRiskGroupItemField));
		offset += sizeof(ReqRemoveRiskGroupItemField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveRiskGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]",
			ReqRemoveRiskGroupItem->AdminUserID, ReqRemoveRiskGroupItem->RiskGroupID, ReqRemoveRiskGroupItem->RiskID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveRiskGroupItemPackage::XtpRspRemoveRiskGroupItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveRiskGroupItemPackage* XtpRspRemoveRiskGroupItemPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveRiskGroupItemPackage>();
	}
	void XtpRspRemoveRiskGroupItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveRiskGroupItem != nullptr)
		{
			::Free<RspRemoveRiskGroupItemField>(RspRemoveRiskGroupItem);
			RspRemoveRiskGroupItem = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveRiskGroupItemPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveRiskGroupItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveRiskGroupItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveRiskGroupItem, sizeof(RspRemoveRiskGroupItemField));
		offset += sizeof(RspRemoveRiskGroupItemField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveRiskGroupItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveRiskGroupItem = ::Allocate<RspRemoveRiskGroupItemField>();
		memcpy(RspRemoveRiskGroupItem, buff + offset, sizeof(RspRemoveRiskGroupItemField));
		offset += sizeof(RspRemoveRiskGroupItemField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveRiskGroupItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]",
			RspRemoveRiskGroupItem->AdminUserID, RspRemoveRiskGroupItem->RiskGroupID, RspRemoveRiskGroupItem->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddOrUpdateRiskPackage::XtpReqAddOrUpdateRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddOrUpdateRiskPackage* XtpReqAddOrUpdateRiskPackage::Allocate()
	{
		return ::Allocate<XtpReqAddOrUpdateRiskPackage>();
	}
	void XtpReqAddOrUpdateRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddOrUpdateRisk != nullptr)
		{
			::Free<ReqAddOrUpdateRiskField>(ReqAddOrUpdateRisk);
			ReqAddOrUpdateRisk = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddOrUpdateRiskPackage>::GetInstance().Free(this);
	}
	void XtpReqAddOrUpdateRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddOrUpdateRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddOrUpdateRisk, sizeof(ReqAddOrUpdateRiskField));
		offset += sizeof(ReqAddOrUpdateRiskField);
		return offset;
	}
	bool XtpReqAddOrUpdateRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddOrUpdateRisk = ::Allocate<ReqAddOrUpdateRiskField>();
		memcpy(ReqAddOrUpdateRisk, buff + offset, sizeof(ReqAddOrUpdateRiskField));
		offset += sizeof(ReqAddOrUpdateRiskField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddOrUpdateRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddOrUpdateRisk:AdminUserID:[%s], RiskID:[%d], RiskName:[%s], RiskClassID:[%d]",
			ReqAddOrUpdateRisk->AdminUserID, ReqAddOrUpdateRisk->RiskID, ReqAddOrUpdateRisk->RiskName, (int)ReqAddOrUpdateRisk->RiskClassID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddOrUpdateRiskPackage::XtpRspAddOrUpdateRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddOrUpdateRiskPackage* XtpRspAddOrUpdateRiskPackage::Allocate()
	{
		return ::Allocate<XtpRspAddOrUpdateRiskPackage>();
	}
	void XtpRspAddOrUpdateRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddOrUpdateRisk != nullptr)
		{
			::Free<RspAddOrUpdateRiskField>(RspAddOrUpdateRisk);
			RspAddOrUpdateRisk = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddOrUpdateRiskPackage>::GetInstance().Free(this);
	}
	void XtpRspAddOrUpdateRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddOrUpdateRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddOrUpdateRisk, sizeof(RspAddOrUpdateRiskField));
		offset += sizeof(RspAddOrUpdateRiskField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddOrUpdateRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddOrUpdateRisk = ::Allocate<RspAddOrUpdateRiskField>();
		memcpy(RspAddOrUpdateRisk, buff + offset, sizeof(RspAddOrUpdateRiskField));
		offset += sizeof(RspAddOrUpdateRiskField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddOrUpdateRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddOrUpdateRisk:AdminUserID:[%s], RiskID:[%d]",
			RspAddOrUpdateRisk->AdminUserID, RspAddOrUpdateRisk->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveRiskPackage::XtpReqRemoveRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveRiskPackage* XtpReqRemoveRiskPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveRiskPackage>();
	}
	void XtpReqRemoveRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveRisk != nullptr)
		{
			::Free<ReqRemoveRiskField>(ReqRemoveRisk);
			ReqRemoveRisk = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveRiskPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveRisk, sizeof(ReqRemoveRiskField));
		offset += sizeof(ReqRemoveRiskField);
		return offset;
	}
	bool XtpReqRemoveRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveRisk = ::Allocate<ReqRemoveRiskField>();
		memcpy(ReqRemoveRisk, buff + offset, sizeof(ReqRemoveRiskField));
		offset += sizeof(ReqRemoveRiskField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveRisk:AdminUserID:[%s], RiskID:[%d]",
			ReqRemoveRisk->AdminUserID, ReqRemoveRisk->RiskID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveRiskPackage::XtpRspRemoveRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveRiskPackage* XtpRspRemoveRiskPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveRiskPackage>();
	}
	void XtpRspRemoveRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveRisk != nullptr)
		{
			::Free<RspRemoveRiskField>(RspRemoveRisk);
			RspRemoveRisk = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveRiskPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveRisk, sizeof(RspRemoveRiskField));
		offset += sizeof(RspRemoveRiskField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveRisk = ::Allocate<RspRemoveRiskField>();
		memcpy(RspRemoveRisk, buff + offset, sizeof(RspRemoveRiskField));
		offset += sizeof(RspRemoveRiskField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveRisk:AdminUserID:[%s], RiskID:[%d]",
			RspRemoveRisk->AdminUserID, RspRemoveRisk->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddRiskRulePackage::XtpReqAddRiskRulePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddRiskRulePackage* XtpReqAddRiskRulePackage::Allocate()
	{
		return ::Allocate<XtpReqAddRiskRulePackage>();
	}
	void XtpReqAddRiskRulePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddRiskRule != nullptr)
		{
			::Free<ReqAddRiskRuleField>(ReqAddRiskRule);
			ReqAddRiskRule = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddRiskRulePackage>::GetInstance().Free(this);
	}
	void XtpReqAddRiskRulePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddRiskRulePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddRiskRule, sizeof(ReqAddRiskRuleField));
		offset += sizeof(ReqAddRiskRuleField);
		return offset;
	}
	bool XtpReqAddRiskRulePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddRiskRule = ::Allocate<ReqAddRiskRuleField>();
		memcpy(ReqAddRiskRule, buff + offset, sizeof(ReqAddRiskRuleField));
		offset += sizeof(ReqAddRiskRuleField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddRiskRulePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddRiskRule:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleStyle:[%d], FormatRiskMessage:[%s]",
			ReqAddRiskRule->AdminUserID, ReqAddRiskRule->RiskID, ReqAddRiskRule->RiskRuleID, (int)ReqAddRiskRule->RiskRuleStyle, ReqAddRiskRule->FormatRiskMessage);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddRiskRulePackage::XtpRspAddRiskRulePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddRiskRulePackage* XtpRspAddRiskRulePackage::Allocate()
	{
		return ::Allocate<XtpRspAddRiskRulePackage>();
	}
	void XtpRspAddRiskRulePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddRiskRule != nullptr)
		{
			::Free<RspAddRiskRuleField>(RspAddRiskRule);
			RspAddRiskRule = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddRiskRulePackage>::GetInstance().Free(this);
	}
	void XtpRspAddRiskRulePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddRiskRulePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddRiskRule, sizeof(RspAddRiskRuleField));
		offset += sizeof(RspAddRiskRuleField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddRiskRulePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddRiskRule = ::Allocate<RspAddRiskRuleField>();
		memcpy(RspAddRiskRule, buff + offset, sizeof(RspAddRiskRuleField));
		offset += sizeof(RspAddRiskRuleField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddRiskRulePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddRiskRule:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d]",
			RspAddRiskRule->AdminUserID, RspAddRiskRule->RiskID, RspAddRiskRule->RiskRuleID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddRiskRuleItemPackage::XtpReqAddRiskRuleItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddRiskRuleItemPackage* XtpReqAddRiskRuleItemPackage::Allocate()
	{
		return ::Allocate<XtpReqAddRiskRuleItemPackage>();
	}
	void XtpReqAddRiskRuleItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddRiskRuleItem != nullptr)
		{
			::Free<ReqAddRiskRuleItemField>(ReqAddRiskRuleItem);
			ReqAddRiskRuleItem = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddRiskRuleItemPackage>::GetInstance().Free(this);
	}
	void XtpReqAddRiskRuleItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddRiskRuleItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddRiskRuleItem, sizeof(ReqAddRiskRuleItemField));
		offset += sizeof(ReqAddRiskRuleItemField);
		return offset;
	}
	bool XtpReqAddRiskRuleItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddRiskRuleItem = ::Allocate<ReqAddRiskRuleItemField>();
		memcpy(ReqAddRiskRuleItem, buff + offset, sizeof(ReqAddRiskRuleItemField));
		offset += sizeof(ReqAddRiskRuleItemField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddRiskRuleItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddRiskRuleItem:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d], RiskIndexType:[%d], RiskIndexID:[%d], RiskIndexTextRef:[%d], IndexParam1:[%s], IndexParam2:[%s], IndexParam3:[%s], IndexParam4:[%s], IndexParam5:[%s], IndexParam6:[%s], LogicFunc:[%d], LogicParamType1:[%d], LogicParam1:[%s], LogicParam1TextRef:[%d], LogicParamType2:[%d], LogicParam2:[%s], LogicParam2TextRef:[%d]",
			ReqAddRiskRuleItem->AdminUserID, ReqAddRiskRuleItem->RiskID, ReqAddRiskRuleItem->RiskRuleID, ReqAddRiskRuleItem->RiskRuleItemID, (int)ReqAddRiskRuleItem->RiskIndexType, ReqAddRiskRuleItem->RiskIndexID, ReqAddRiskRuleItem->RiskIndexTextRef, ReqAddRiskRuleItem->IndexParam1, ReqAddRiskRuleItem->IndexParam2, ReqAddRiskRuleItem->IndexParam3, ReqAddRiskRuleItem->IndexParam4, ReqAddRiskRuleItem->IndexParam5, ReqAddRiskRuleItem->IndexParam6, (int)ReqAddRiskRuleItem->LogicFunc, (int)ReqAddRiskRuleItem->LogicParamType1, ReqAddRiskRuleItem->LogicParam1, ReqAddRiskRuleItem->LogicParam1TextRef, (int)ReqAddRiskRuleItem->LogicParamType2, ReqAddRiskRuleItem->LogicParam2, ReqAddRiskRuleItem->LogicParam2TextRef);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddRiskRuleItemPackage::XtpRspAddRiskRuleItemPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddRiskRuleItemPackage* XtpRspAddRiskRuleItemPackage::Allocate()
	{
		return ::Allocate<XtpRspAddRiskRuleItemPackage>();
	}
	void XtpRspAddRiskRuleItemPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddRiskRuleItem != nullptr)
		{
			::Free<RspAddRiskRuleItemField>(RspAddRiskRuleItem);
			RspAddRiskRuleItem = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddRiskRuleItemPackage>::GetInstance().Free(this);
	}
	void XtpRspAddRiskRuleItemPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddRiskRuleItemPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddRiskRuleItem, sizeof(RspAddRiskRuleItemField));
		offset += sizeof(RspAddRiskRuleItemField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddRiskRuleItemPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddRiskRuleItem = ::Allocate<RspAddRiskRuleItemField>();
		memcpy(RspAddRiskRuleItem, buff + offset, sizeof(RspAddRiskRuleItemField));
		offset += sizeof(RspAddRiskRuleItemField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddRiskRuleItemPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddRiskRuleItem:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d]",
			RspAddRiskRuleItem->AdminUserID, RspAddRiskRuleItem->RiskID, RspAddRiskRuleItem->RiskRuleID, RspAddRiskRuleItem->RiskRuleItemID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddRiskTradeScopePackage::XtpReqAddRiskTradeScopePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddRiskTradeScopePackage* XtpReqAddRiskTradeScopePackage::Allocate()
	{
		return ::Allocate<XtpReqAddRiskTradeScopePackage>();
	}
	void XtpReqAddRiskTradeScopePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddRiskTradeScope != nullptr)
		{
			::Free<ReqAddRiskTradeScopeField>(ReqAddRiskTradeScope);
			ReqAddRiskTradeScope = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddRiskTradeScopePackage>::GetInstance().Free(this);
	}
	void XtpReqAddRiskTradeScopePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddRiskTradeScopePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddRiskTradeScope, sizeof(ReqAddRiskTradeScopeField));
		offset += sizeof(ReqAddRiskTradeScopeField);
		return offset;
	}
	bool XtpReqAddRiskTradeScopePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddRiskTradeScope = ::Allocate<ReqAddRiskTradeScopeField>();
		memcpy(ReqAddRiskTradeScope, buff + offset, sizeof(ReqAddRiskTradeScopeField));
		offset += sizeof(ReqAddRiskTradeScopeField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddRiskTradeScopePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddRiskTradeScope:AdminUserID:[%s], RiskID:[%d], TradeScopeType:[%d], InstrumentGroupID:[%d], FormatRiskMessage:[%s]",
			ReqAddRiskTradeScope->AdminUserID, ReqAddRiskTradeScope->RiskID, (int)ReqAddRiskTradeScope->TradeScopeType, ReqAddRiskTradeScope->InstrumentGroupID, ReqAddRiskTradeScope->FormatRiskMessage);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddRiskTradeScopePackage::XtpRspAddRiskTradeScopePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddRiskTradeScopePackage* XtpRspAddRiskTradeScopePackage::Allocate()
	{
		return ::Allocate<XtpRspAddRiskTradeScopePackage>();
	}
	void XtpRspAddRiskTradeScopePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddRiskTradeScope != nullptr)
		{
			::Free<RspAddRiskTradeScopeField>(RspAddRiskTradeScope);
			RspAddRiskTradeScope = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddRiskTradeScopePackage>::GetInstance().Free(this);
	}
	void XtpRspAddRiskTradeScopePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddRiskTradeScopePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddRiskTradeScope, sizeof(RspAddRiskTradeScopeField));
		offset += sizeof(RspAddRiskTradeScopeField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddRiskTradeScopePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddRiskTradeScope = ::Allocate<RspAddRiskTradeScopeField>();
		memcpy(RspAddRiskTradeScope, buff + offset, sizeof(RspAddRiskTradeScopeField));
		offset += sizeof(RspAddRiskTradeScopeField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddRiskTradeScopePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddRiskTradeScope:AdminUserID:[%s], RiskID:[%d]",
			RspAddRiskTradeScope->AdminUserID, RspAddRiskTradeScope->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAddAccountRiskPackage::XtpReqAddAccountRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAddAccountRiskPackage* XtpReqAddAccountRiskPackage::Allocate()
	{
		return ::Allocate<XtpReqAddAccountRiskPackage>();
	}
	void XtpReqAddAccountRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAddAccountRisk != nullptr)
		{
			::Free<ReqAddAccountRiskField>(ReqAddAccountRisk);
			ReqAddAccountRisk = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAddAccountRiskPackage>::GetInstance().Free(this);
	}
	void XtpReqAddAccountRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAddAccountRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAddAccountRisk, sizeof(ReqAddAccountRiskField));
		offset += sizeof(ReqAddAccountRiskField);
		return offset;
	}
	bool XtpReqAddAccountRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAddAccountRisk = ::Allocate<ReqAddAccountRiskField>();
		memcpy(ReqAddAccountRisk, buff + offset, sizeof(ReqAddAccountRiskField));
		offset += sizeof(ReqAddAccountRiskField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAddAccountRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAddAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]",
			ReqAddAccountRisk->AdminUserID, ReqAddAccountRisk->AccountID, ReqAddAccountRisk->RiskID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAddAccountRiskPackage::XtpRspAddAccountRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAddAccountRiskPackage* XtpRspAddAccountRiskPackage::Allocate()
	{
		return ::Allocate<XtpRspAddAccountRiskPackage>();
	}
	void XtpRspAddAccountRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAddAccountRisk != nullptr)
		{
			::Free<RspAddAccountRiskField>(RspAddAccountRisk);
			RspAddAccountRisk = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAddAccountRiskPackage>::GetInstance().Free(this);
	}
	void XtpRspAddAccountRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAddAccountRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAddAccountRisk, sizeof(RspAddAccountRiskField));
		offset += sizeof(RspAddAccountRiskField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAddAccountRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAddAccountRisk = ::Allocate<RspAddAccountRiskField>();
		memcpy(RspAddAccountRisk, buff + offset, sizeof(RspAddAccountRiskField));
		offset += sizeof(RspAddAccountRiskField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAddAccountRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAddAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]",
			RspAddAccountRisk->AdminUserID, RspAddAccountRisk->AccountID, RspAddAccountRisk->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqRemoveAccountRiskPackage::XtpReqRemoveAccountRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqRemoveAccountRiskPackage* XtpReqRemoveAccountRiskPackage::Allocate()
	{
		return ::Allocate<XtpReqRemoveAccountRiskPackage>();
	}
	void XtpReqRemoveAccountRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqRemoveAccountRisk != nullptr)
		{
			::Free<ReqRemoveAccountRiskField>(ReqRemoveAccountRisk);
			ReqRemoveAccountRisk = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqRemoveAccountRiskPackage>::GetInstance().Free(this);
	}
	void XtpReqRemoveAccountRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqRemoveAccountRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqRemoveAccountRisk, sizeof(ReqRemoveAccountRiskField));
		offset += sizeof(ReqRemoveAccountRiskField);
		return offset;
	}
	bool XtpReqRemoveAccountRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqRemoveAccountRisk = ::Allocate<ReqRemoveAccountRiskField>();
		memcpy(ReqRemoveAccountRisk, buff + offset, sizeof(ReqRemoveAccountRiskField));
		offset += sizeof(ReqRemoveAccountRiskField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqRemoveAccountRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqRemoveAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]",
			ReqRemoveAccountRisk->AdminUserID, ReqRemoveAccountRisk->AccountID, ReqRemoveAccountRisk->RiskID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspRemoveAccountRiskPackage::XtpRspRemoveAccountRiskPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspRemoveAccountRiskPackage* XtpRspRemoveAccountRiskPackage::Allocate()
	{
		return ::Allocate<XtpRspRemoveAccountRiskPackage>();
	}
	void XtpRspRemoveAccountRiskPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspRemoveAccountRisk != nullptr)
		{
			::Free<RspRemoveAccountRiskField>(RspRemoveAccountRisk);
			RspRemoveAccountRisk = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspRemoveAccountRiskPackage>::GetInstance().Free(this);
	}
	void XtpRspRemoveAccountRiskPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspRemoveAccountRiskPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspRemoveAccountRisk, sizeof(RspRemoveAccountRiskField));
		offset += sizeof(RspRemoveAccountRiskField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspRemoveAccountRiskPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspRemoveAccountRisk = ::Allocate<RspRemoveAccountRiskField>();
		memcpy(RspRemoveAccountRisk, buff + offset, sizeof(RspRemoveAccountRiskField));
		offset += sizeof(RspRemoveAccountRiskField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspRemoveAccountRiskPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspRemoveAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]",
			RspRemoveAccountRisk->AdminUserID, RspRemoveAccountRisk->AccountID, RspRemoveAccountRisk->RiskID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqMoneyTransferPackage::XtpReqMoneyTransferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqMoneyTransferPackage* XtpReqMoneyTransferPackage::Allocate()
	{
		return ::Allocate<XtpReqMoneyTransferPackage>();
	}
	void XtpReqMoneyTransferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqMoneyTransfer != nullptr)
		{
			::Free<ReqMoneyTransferField>(ReqMoneyTransfer);
			ReqMoneyTransfer = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqMoneyTransferPackage>::GetInstance().Free(this);
	}
	void XtpReqMoneyTransferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqMoneyTransferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqMoneyTransfer, sizeof(ReqMoneyTransferField));
		offset += sizeof(ReqMoneyTransferField);
		return offset;
	}
	bool XtpReqMoneyTransferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqMoneyTransfer = ::Allocate<ReqMoneyTransferField>();
		memcpy(ReqMoneyTransfer, buff + offset, sizeof(ReqMoneyTransferField));
		offset += sizeof(ReqMoneyTransferField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqMoneyTransferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqMoneyTransfer:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]",
			ReqMoneyTransfer->AdminUserID, ReqMoneyTransfer->TradingDay, ReqMoneyTransfer->AccountID, ReqMoneyTransfer->MoneyTransferID, (int)ReqMoneyTransfer->AccountType, (int)ReqMoneyTransfer->TransferDirection, ReqMoneyTransfer->TransferAmount, ReqMoneyTransfer->InfoMessage, ReqMoneyTransfer->UserID, ReqMoneyTransfer->TransferDate, ReqMoneyTransfer->TransferTime);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspMoneyTransferPackage::XtpRspMoneyTransferPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspMoneyTransferPackage* XtpRspMoneyTransferPackage::Allocate()
	{
		return ::Allocate<XtpRspMoneyTransferPackage>();
	}
	void XtpRspMoneyTransferPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspMoneyTransfer != nullptr)
		{
			::Free<RspMoneyTransferField>(RspMoneyTransfer);
			RspMoneyTransfer = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspMoneyTransferPackage>::GetInstance().Free(this);
	}
	void XtpRspMoneyTransferPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspMoneyTransferPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspMoneyTransfer, sizeof(RspMoneyTransferField));
		offset += sizeof(RspMoneyTransferField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspMoneyTransferPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspMoneyTransfer = ::Allocate<RspMoneyTransferField>();
		memcpy(RspMoneyTransfer, buff + offset, sizeof(RspMoneyTransferField));
		offset += sizeof(RspMoneyTransferField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspMoneyTransferPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspMoneyTransfer:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d]",
			RspMoneyTransfer->AdminUserID, RspMoneyTransfer->TradingDay, RspMoneyTransfer->AccountID, RspMoneyTransfer->MoneyTransferID);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqAuditOrderPackage::XtpReqAuditOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqAuditOrderPackage* XtpReqAuditOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqAuditOrderPackage>();
	}
	void XtpReqAuditOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqAuditOrder != nullptr)
		{
			::Free<ReqAuditOrderField>(ReqAuditOrder);
			ReqAuditOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqAuditOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqAuditOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqAuditOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqAuditOrder, sizeof(ReqAuditOrderField));
		offset += sizeof(ReqAuditOrderField);
		return offset;
	}
	bool XtpReqAuditOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqAuditOrder = ::Allocate<ReqAuditOrderField>();
		memcpy(ReqAuditOrder, buff + offset, sizeof(ReqAuditOrderField));
		offset += sizeof(ReqAuditOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqAuditOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqAuditOrder:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]",
			ReqAuditOrder->AdminUserID, ReqAuditOrder->TradingDay, ReqAuditOrder->AccountID, ReqAuditOrder->ExchangeID, ReqAuditOrder->InstrumentID, ReqAuditOrder->OrderID, (int)ReqAuditOrder->AuditStatus);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspAuditOrderPackage::XtpRspAuditOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspAuditOrderPackage* XtpRspAuditOrderPackage::Allocate()
	{
		return ::Allocate<XtpRspAuditOrderPackage>();
	}
	void XtpRspAuditOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspAuditOrder != nullptr)
		{
			::Free<RspAuditOrderField>(RspAuditOrder);
			RspAuditOrder = nullptr;
		}
		if (RspInfo != nullptr)
		{
			::Free<RspInfoField>(RspInfo);
			RspInfo = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspAuditOrderPackage>::GetInstance().Free(this);
	}
	void XtpRspAuditOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspAuditOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspAuditOrder, sizeof(RspAuditOrderField));
		offset += sizeof(RspAuditOrderField);
		memcpy(buff + offset, RspInfo, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		return offset;
	}
	bool XtpRspAuditOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspAuditOrder = ::Allocate<RspAuditOrderField>();
		memcpy(RspAuditOrder, buff + offset, sizeof(RspAuditOrderField));
		offset += sizeof(RspAuditOrderField);
		RspInfo = ::Allocate<RspInfoField>();
		memcpy(RspInfo, buff + offset, sizeof(RspInfoField));
		offset += sizeof(RspInfoField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspAuditOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspAuditOrder:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]",
			RspAuditOrder->AdminUserID, RspAuditOrder->TradingDay, RspAuditOrder->AccountID, RspAuditOrder->ExchangeID, RspAuditOrder->InstrumentID, RspAuditOrder->OrderID, (int)RspAuditOrder->AuditStatus);
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspInfo:ErrorID:[%d], ErrorMsg:[%s]",
			RspInfo->ErrorID, RspInfo->ErrorMsg);
		return t_XtpDataStringBuffer;
	}
 
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
			::Free<ReqOfferLoginField>(ReqOfferLogin);
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
		memcpy(buff + offset, ReqOfferLogin, sizeof(ReqOfferLoginField));
		offset += sizeof(ReqOfferLoginField);
		return offset;
	}
	bool XtpReqOfferLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqOfferLogin = ::Allocate<ReqOfferLoginField>();
		memcpy(ReqOfferLogin, buff + offset, sizeof(ReqOfferLoginField));
		offset += sizeof(ReqOfferLoginField);
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
			::Free<RspOfferLoginField>(RspOfferLogin);
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
		memcpy(buff + offset, RspOfferLogin, sizeof(RspOfferLoginField));
		offset += sizeof(RspOfferLoginField);
		return offset;
	}
	bool XtpRspOfferLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspOfferLogin = ::Allocate<RspOfferLoginField>();
		memcpy(RspOfferLogin, buff + offset, sizeof(RspOfferLoginField));
		offset += sizeof(RspOfferLoginField);
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
			::Free<ReqPrimaryAccountLoginField>(ReqPrimaryAccountLogin);
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
		memcpy(buff + offset, ReqPrimaryAccountLogin, sizeof(ReqPrimaryAccountLoginField));
		offset += sizeof(ReqPrimaryAccountLoginField);
		return offset;
	}
	bool XtpReqPrimaryAccountLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountLogin = ::Allocate<ReqPrimaryAccountLoginField>();
		memcpy(ReqPrimaryAccountLogin, buff + offset, sizeof(ReqPrimaryAccountLoginField));
		offset += sizeof(ReqPrimaryAccountLoginField);
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
			::Free<RspPrimaryAccountLoginField>(RspPrimaryAccountLogin);
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
		memcpy(buff + offset, RspPrimaryAccountLogin, sizeof(RspPrimaryAccountLoginField));
		offset += sizeof(RspPrimaryAccountLoginField);
		return offset;
	}
	bool XtpRspPrimaryAccountLoginPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspPrimaryAccountLogin = ::Allocate<RspPrimaryAccountLoginField>();
		memcpy(RspPrimaryAccountLogin, buff + offset, sizeof(RspPrimaryAccountLoginField));
		offset += sizeof(RspPrimaryAccountLoginField);
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
			::Free<ReqPrimaryAccountLogoutField>(ReqPrimaryAccountLogout);
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
		memcpy(buff + offset, ReqPrimaryAccountLogout, sizeof(ReqPrimaryAccountLogoutField));
		offset += sizeof(ReqPrimaryAccountLogoutField);
		return offset;
	}
	bool XtpReqPrimaryAccountLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountLogout = ::Allocate<ReqPrimaryAccountLogoutField>();
		memcpy(ReqPrimaryAccountLogout, buff + offset, sizeof(ReqPrimaryAccountLogoutField));
		offset += sizeof(ReqPrimaryAccountLogoutField);
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
			::Free<RtnPrimaryAccountLogoutField>(RtnPrimaryAccountLogout);
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
		memcpy(buff + offset, RtnPrimaryAccountLogout, sizeof(RtnPrimaryAccountLogoutField));
		offset += sizeof(RtnPrimaryAccountLogoutField);
		return offset;
	}
	bool XtpRtnPrimaryAccountLogoutPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RtnPrimaryAccountLogout = ::Allocate<RtnPrimaryAccountLogoutField>();
		memcpy(RtnPrimaryAccountLogout, buff + offset, sizeof(RtnPrimaryAccountLogoutField));
		offset += sizeof(RtnPrimaryAccountLogoutField);
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
			::Free<ReqPrimaryAccountInitField>(ReqPrimaryAccountInit);
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
		memcpy(buff + offset, ReqPrimaryAccountInit, sizeof(ReqPrimaryAccountInitField));
		offset += sizeof(ReqPrimaryAccountInitField);
		return offset;
	}
	bool XtpReqPrimaryAccountInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountInit = ::Allocate<ReqPrimaryAccountInitField>();
		memcpy(ReqPrimaryAccountInit, buff + offset, sizeof(ReqPrimaryAccountInitField));
		offset += sizeof(ReqPrimaryAccountInitField);
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
			::Free<RspPrimaryAccountInitField>(RspPrimaryAccountInit);
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
		memcpy(buff + offset, RspPrimaryAccountInit, sizeof(RspPrimaryAccountInitField));
		offset += sizeof(RspPrimaryAccountInitField);
		return offset;
	}
	bool XtpRspPrimaryAccountInitPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspPrimaryAccountInit = ::Allocate<RspPrimaryAccountInitField>();
		memcpy(RspPrimaryAccountInit, buff + offset, sizeof(RspPrimaryAccountInitField));
		offset += sizeof(RspPrimaryAccountInitField);
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
			::Free<ReqPrimaryAccountQueryField>(ReqPrimaryAccountQuery);
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
		memcpy(buff + offset, ReqPrimaryAccountQuery, sizeof(ReqPrimaryAccountQueryField));
		offset += sizeof(ReqPrimaryAccountQueryField);
		return offset;
	}
	bool XtpReqPrimaryAccountQueryPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqPrimaryAccountQuery = ::Allocate<ReqPrimaryAccountQueryField>();
		memcpy(ReqPrimaryAccountQuery, buff + offset, sizeof(ReqPrimaryAccountQueryField));
		offset += sizeof(ReqPrimaryAccountQueryField);
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
			::Free<RspPrimaryAccountQueryField>(RspPrimaryAccountQuery);
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
		memcpy(buff + offset, RspPrimaryAccountQuery, sizeof(RspPrimaryAccountQueryField));
		offset += sizeof(RspPrimaryAccountQueryField);
		return offset;
	}
	bool XtpRspPrimaryAccountQueryPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspPrimaryAccountQuery = ::Allocate<RspPrimaryAccountQueryField>();
		memcpy(RspPrimaryAccountQuery, buff + offset, sizeof(RspPrimaryAccountQueryField));
		offset += sizeof(RspPrimaryAccountQueryField);
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
 
	XtpReqQryOfferOptionInstrumentPackage::XtpReqQryOfferOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqQryOfferOptionInstrumentPackage* XtpReqQryOfferOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpReqQryOfferOptionInstrumentPackage>();
	}
	void XtpReqQryOfferOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqQryOfferOptionInstrument != nullptr)
		{
			::Free<ReqQryOfferOptionInstrumentField>(ReqQryOfferOptionInstrument);
			ReqQryOfferOptionInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqQryOfferOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpReqQryOfferOptionInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqQryOfferOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqQryOfferOptionInstrument, sizeof(ReqQryOfferOptionInstrumentField));
		offset += sizeof(ReqQryOfferOptionInstrumentField);
		return offset;
	}
	bool XtpReqQryOfferOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqQryOfferOptionInstrument = ::Allocate<ReqQryOfferOptionInstrumentField>();
		memcpy(ReqQryOfferOptionInstrument, buff + offset, sizeof(ReqQryOfferOptionInstrumentField));
		offset += sizeof(ReqQryOfferOptionInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqQryOfferOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqQryOfferOptionInstrument:PrimaryAccountID:[%s]",
			ReqQryOfferOptionInstrument->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRspQryOfferOptionInstrumentPackage::XtpRspQryOfferOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRspQryOfferOptionInstrumentPackage* XtpRspQryOfferOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRspQryOfferOptionInstrumentPackage>();
	}
	void XtpRspQryOfferOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (RspQryOfferOptionInstrument != nullptr)
		{
			::Free<RspQryOfferOptionInstrumentField>(RspQryOfferOptionInstrument);
			RspQryOfferOptionInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpRspQryOfferOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRspQryOfferOptionInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRspQryOfferOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, RspQryOfferOptionInstrument, sizeof(RspQryOfferOptionInstrumentField));
		offset += sizeof(RspQryOfferOptionInstrumentField);
		return offset;
	}
	bool XtpRspQryOfferOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		RspQryOfferOptionInstrument = ::Allocate<RspQryOfferOptionInstrumentField>();
		memcpy(RspQryOfferOptionInstrument, buff + offset, sizeof(RspQryOfferOptionInstrumentField));
		offset += sizeof(RspQryOfferOptionInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRspQryOfferOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "RspQryOfferOptionInstrument:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			RspQryOfferOptionInstrument->ErrorID, RspQryOfferOptionInstrument->ErrorMsg, RspQryOfferOptionInstrument->PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnOfferOptionInstrumentPackage::XtpRtnOfferOptionInstrumentPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOfferOptionInstrumentPackage* XtpRtnOfferOptionInstrumentPackage::Allocate()
	{
		return ::Allocate<XtpRtnOfferOptionInstrumentPackage>();
	}
	void XtpRtnOfferOptionInstrumentPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (OfferOptionInstrument != nullptr)
		{
			::Free<OfferOptionInstrumentField>(OfferOptionInstrument);
			OfferOptionInstrument = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOfferOptionInstrumentPackage>::GetInstance().Free(this);
	}
	void XtpRtnOfferOptionInstrumentPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOfferOptionInstrumentPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, OfferOptionInstrument, sizeof(OfferOptionInstrumentField));
		offset += sizeof(OfferOptionInstrumentField);
		return offset;
	}
	bool XtpRtnOfferOptionInstrumentPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		OfferOptionInstrument = ::Allocate<OfferOptionInstrumentField>();
		memcpy(OfferOptionInstrument, buff + offset, sizeof(OfferOptionInstrumentField));
		offset += sizeof(OfferOptionInstrumentField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOfferOptionInstrumentPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "OfferOptionInstrument:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]",
			OfferOptionInstrument->TradingDay, OfferOptionInstrument->ExchangeID, OfferOptionInstrument->InstrumentID, OfferOptionInstrument->ExchangeInstID, OfferOptionInstrument->InstrumentName, OfferOptionInstrument->VolumeMultiple, (int)OfferOptionInstrument->OptionType, OfferOptionInstrument->UnderlyingInstrumentID, OfferOptionInstrument->ExecutePrice, OfferOptionInstrument->UnitMargin, OfferOptionInstrument->PriceTick, OfferOptionInstrument->MaxLimitOrderVolume, OfferOptionInstrument->MaxMarketOrderVolume, OfferOptionInstrument->ExpiringDate);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqOfferOrderPackage::XtpReqOfferOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqOfferOrderPackage* XtpReqOfferOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqOfferOrderPackage>();
	}
	void XtpReqOfferOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqOfferOrder != nullptr)
		{
			::Free<ReqOfferOrderField>(ReqOfferOrder);
			ReqOfferOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqOfferOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqOfferOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqOfferOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqOfferOrder, sizeof(ReqOfferOrderField));
		offset += sizeof(ReqOfferOrderField);
		return offset;
	}
	bool XtpReqOfferOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqOfferOrder = ::Allocate<ReqOfferOrderField>();
		memcpy(ReqOfferOrder, buff + offset, sizeof(ReqOfferOrderField));
		offset += sizeof(ReqOfferOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqOfferOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqOfferOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d]",
			ReqOfferOrder->TradingDay, ReqOfferOrder->PrimaryAccountID, ReqOfferOrder->ExchangeID, ReqOfferOrder->InstrumentID, (int)ReqOfferOrder->SecurityType, ReqOfferOrder->OrderID, (int)ReqOfferOrder->Direction, (int)ReqOfferOrder->OffsetFlag, (int)ReqOfferOrder->OrderPriceType, ReqOfferOrder->Price, ReqOfferOrder->Volume);
		return t_XtpDataStringBuffer;
	}
 
	XtpReqOfferCancelOrderPackage::XtpReqOfferCancelOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpReqOfferCancelOrderPackage* XtpReqOfferCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpReqOfferCancelOrderPackage>();
	}
	void XtpReqOfferCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (ReqOfferCancelOrder != nullptr)
		{
			::Free<ReqOfferCancelOrderField>(ReqOfferCancelOrder);
			ReqOfferCancelOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpReqOfferCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpReqOfferCancelOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpReqOfferCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, ReqOfferCancelOrder, sizeof(ReqOfferCancelOrderField));
		offset += sizeof(ReqOfferCancelOrderField);
		return offset;
	}
	bool XtpReqOfferCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		ReqOfferCancelOrder = ::Allocate<ReqOfferCancelOrderField>();
		memcpy(ReqOfferCancelOrder, buff + offset, sizeof(ReqOfferCancelOrderField));
		offset += sizeof(ReqOfferCancelOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpReqOfferCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "ReqOfferCancelOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			ReqOfferCancelOrder->TradingDay, ReqOfferCancelOrder->PrimaryAccountID, ReqOfferCancelOrder->ExchangeID, ReqOfferCancelOrder->InstrumentID, (int)ReqOfferCancelOrder->SecurityType, (int)ReqOfferCancelOrder->Direction, ReqOfferCancelOrder->CancelOrderID, ReqOfferCancelOrder->OrderID, ReqOfferCancelOrder->OrderSysID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnOfferOrderPackage::XtpRtnOfferOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOfferOrderPackage* XtpRtnOfferOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnOfferOrderPackage>();
	}
	void XtpRtnOfferOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (OfferOrder != nullptr)
		{
			::Free<OfferOrderField>(OfferOrder);
			OfferOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOfferOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnOfferOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOfferOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, OfferOrder, sizeof(OfferOrderField));
		offset += sizeof(OfferOrderField);
		return offset;
	}
	bool XtpRtnOfferOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		OfferOrder = ::Allocate<OfferOrderField>();
		memcpy(OfferOrder, buff + offset, sizeof(OfferOrderField));
		offset += sizeof(OfferOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOfferOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "OfferOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], IsNewOrder:[%d]",
			OfferOrder->TradingDay, OfferOrder->PrimaryAccountID, OfferOrder->ExchangeID, OfferOrder->InstrumentID, OfferOrder->OrderID, OfferOrder->OrderSysID, (int)OfferOrder->Direction, (int)OfferOrder->OffsetFlag, (int)OfferOrder->OrderPriceType, OfferOrder->Price, OfferOrder->Volume, OfferOrder->VolumeTotal, OfferOrder->VolumeTraded, (int)OfferOrder->OrderStatus, OfferOrder->StatusMsg, OfferOrder->OrderDate, OfferOrder->OrderTime, OfferOrder->CancelDate, OfferOrder->CancelTime, OfferOrder->IsNewOrder);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnOfferTradePackage::XtpRtnOfferTradePackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOfferTradePackage* XtpRtnOfferTradePackage::Allocate()
	{
		return ::Allocate<XtpRtnOfferTradePackage>();
	}
	void XtpRtnOfferTradePackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (OfferTrade != nullptr)
		{
			::Free<OfferTradeField>(OfferTrade);
			OfferTrade = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOfferTradePackage>::GetInstance().Free(this);
	}
	void XtpRtnOfferTradePackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOfferTradePackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, OfferTrade, sizeof(OfferTradeField));
		offset += sizeof(OfferTradeField);
		return offset;
	}
	bool XtpRtnOfferTradePackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		OfferTrade = ::Allocate<OfferTradeField>();
		memcpy(OfferTrade, buff + offset, sizeof(OfferTradeField));
		offset += sizeof(OfferTradeField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOfferTradePackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "OfferTrade:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], TradeDate:[%s], TradeTime:[%s]",
			OfferTrade->TradingDay, OfferTrade->PrimaryAccountID, OfferTrade->ExchangeID, OfferTrade->InstrumentID, OfferTrade->OrderID, OfferTrade->OrderSysID, OfferTrade->TradeID, (int)OfferTrade->Direction, (int)OfferTrade->OffsetFlag, OfferTrade->Price, OfferTrade->Volume, OfferTrade->TradeDate, OfferTrade->TradeTime);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnOfferErrorCancelOrderPackage::XtpRtnOfferErrorCancelOrderPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOfferErrorCancelOrderPackage* XtpRtnOfferErrorCancelOrderPackage::Allocate()
	{
		return ::Allocate<XtpRtnOfferErrorCancelOrderPackage>();
	}
	void XtpRtnOfferErrorCancelOrderPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (OfferErrorCancelOrder != nullptr)
		{
			::Free<OfferErrorCancelOrderField>(OfferErrorCancelOrder);
			OfferErrorCancelOrder = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOfferErrorCancelOrderPackage>::GetInstance().Free(this);
	}
	void XtpRtnOfferErrorCancelOrderPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOfferErrorCancelOrderPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, OfferErrorCancelOrder, sizeof(OfferErrorCancelOrderField));
		offset += sizeof(OfferErrorCancelOrderField);
		return offset;
	}
	bool XtpRtnOfferErrorCancelOrderPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		OfferErrorCancelOrder = ::Allocate<OfferErrorCancelOrderField>();
		memcpy(OfferErrorCancelOrder, buff + offset, sizeof(OfferErrorCancelOrderField));
		offset += sizeof(OfferErrorCancelOrderField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOfferErrorCancelOrderPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "OfferErrorCancelOrder:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			OfferErrorCancelOrder->ErrorID, OfferErrorCancelOrder->ErrorMsg, OfferErrorCancelOrder->TradingDay, OfferErrorCancelOrder->PrimaryAccountID, OfferErrorCancelOrder->ExchangeID, OfferErrorCancelOrder->InstrumentID, (int)OfferErrorCancelOrder->Direction, OfferErrorCancelOrder->CancelOrderID, OfferErrorCancelOrder->OrderID, OfferErrorCancelOrder->OrderSysID);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnOfferCapitalPackage::XtpRtnOfferCapitalPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOfferCapitalPackage* XtpRtnOfferCapitalPackage::Allocate()
	{
		return ::Allocate<XtpRtnOfferCapitalPackage>();
	}
	void XtpRtnOfferCapitalPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (OfferCapital != nullptr)
		{
			::Free<OfferCapitalField>(OfferCapital);
			OfferCapital = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOfferCapitalPackage>::GetInstance().Free(this);
	}
	void XtpRtnOfferCapitalPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOfferCapitalPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, OfferCapital, sizeof(OfferCapitalField));
		offset += sizeof(OfferCapitalField);
		return offset;
	}
	bool XtpRtnOfferCapitalPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		OfferCapital = ::Allocate<OfferCapitalField>();
		memcpy(OfferCapital, buff + offset, sizeof(OfferCapitalField));
		offset += sizeof(OfferCapitalField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOfferCapitalPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "OfferCapital:TradingDay:[%s], PrimaryAccountID:[%s], PreCashAsset:[%f]",
			OfferCapital->TradingDay, OfferCapital->PrimaryAccountID, OfferCapital->PreCashAsset);
		return t_XtpDataStringBuffer;
	}
 
	XtpRtnOfferPositionPackage::XtpRtnOfferPositionPackage()
	{
		Head.PackageID = PackageID;
	}
	XtpRtnOfferPositionPackage* XtpRtnOfferPositionPackage::Allocate()
	{
		return ::Allocate<XtpRtnOfferPositionPackage>();
	}
	void XtpRtnOfferPositionPackage::Free()
	{
		SessionID = 0;
		memset(IPAddress, 0, sizeof(IPAddressType));
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
		Head.PackageID = PackageID;
		if (OfferPosition != nullptr)
		{
			::Free<OfferPositionField>(OfferPosition);
			OfferPosition = nullptr;
		}
		MemCacheTemplateSingleton<XtpRtnOfferPositionPackage>::GetInstance().Free(this);
	}
	void XtpRtnOfferPositionPackage::Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum)
	{
		SessionID = sessionID;
		Head.MessageChain = messageChain;
		Head.MsgSeqNum = msgSeqNum;
	}
	int XtpRtnOfferPositionPackage::ToProtocolStream(char* buff, int size) const
	{
		int offset = 0;
		memcpy(buff + offset, OfferPosition, sizeof(OfferPositionField));
		offset += sizeof(OfferPositionField);
		return offset;
	}
	bool XtpRtnOfferPositionPackage::FromProtocolStream(char* buff, int startIndex, int endIndex)
	{
		int offset = startIndex;
		OfferPosition = ::Allocate<OfferPositionField>();
		memcpy(OfferPosition, buff + offset, sizeof(OfferPositionField));
		offset += sizeof(OfferPositionField);
		if (offset != endIndex)
		{
			return false;
		}
		return true;
	}
	const char* XtpRtnOfferPositionPackage::GetDebugString() const
	{
		int offset = 0;
		offset += sprintf(t_XtpDataStringBuffer + offset, "OfferPosition:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TotalCostPrice:[%f], Margin:[%f], MarketValue:[%f]",
			OfferPosition->TradingDay, OfferPosition->PrimaryAccountID, OfferPosition->ExchangeID, OfferPosition->InstrumentID, (int)OfferPosition->PosiDirection, OfferPosition->TotalPosition, OfferPosition->PositionFrozen, OfferPosition->TotalCostPrice, OfferPosition->Margin, OfferPosition->MarketValue);
		return t_XtpDataStringBuffer;
	}
}
