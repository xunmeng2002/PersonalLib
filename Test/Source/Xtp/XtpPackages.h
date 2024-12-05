#pragma once
#include "Fields.h"
#include "XtpPackageBase.h"

namespace xtp
{
	class XtpNotifyComponentConnectStatusPackage : public XtpPackageBase
	{
	public:
		XtpNotifyComponentConnectStatusPackage();
		static XtpNotifyComponentConnectStatusPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0001;
		NotifyComponentConnectStatusField* NotifyComponentConnectStatus = nullptr;
	};

	class XtpReqAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqAccountLoginPackage();
		static XtpReqAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1001;
		ReqAccountLoginField* ReqAccountLogin = nullptr;
	};

	class XtpRspAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspAccountLoginPackage();
		static XtpRspAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1002;
		RspAccountLoginField* RspAccountLogin = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpReqAccountLogoutPackage();
		static XtpReqAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1003;
		ReqAccountLogoutField* ReqAccountLogout = nullptr;
	};

	class XtpRspAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRspAccountLogoutPackage();
		static XtpRspAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1004;
		RspAccountLogoutField* RspAccountLogout = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqQryAccountPackage();
		static XtpReqQryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1005;
		ReqQryAccountField* ReqQryAccount = nullptr;
	};

	class XtpRspQryAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspQryAccountPackage();
		static XtpRspQryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1006;
		AccountField* Account = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryHolderAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqQryHolderAccountPackage();
		static XtpReqQryHolderAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1007;
		ReqQryHolderAccountField* ReqQryHolderAccount = nullptr;
	};

	class XtpRspQryHolderAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspQryHolderAccountPackage();
		static XtpRspQryHolderAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1008;
		HolderAccountField* HolderAccount = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryCapitalPackage : public XtpPackageBase
	{
	public:
		XtpReqQryCapitalPackage();
		static XtpReqQryCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1009;
		ReqQryCapitalField* ReqQryCapital = nullptr;
	};

	class XtpRspQryCapitalPackage : public XtpPackageBase
	{
	public:
		XtpRspQryCapitalPackage();
		static XtpRspQryCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100A;
		CapitalField* Capital = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryPositionPackage : public XtpPackageBase
	{
	public:
		XtpReqQryPositionPackage();
		static XtpReqQryPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100B;
		ReqQryPositionField* ReqQryPosition = nullptr;
	};

	class XtpRspQryPositionPackage : public XtpPackageBase
	{
	public:
		XtpRspQryPositionPackage();
		static XtpRspQryPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100C;
		PositionField* Position = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqQryOrderPackage();
		static XtpReqQryOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100D;
		ReqQryOrderField* ReqQryOrder = nullptr;
	};

	class XtpRspQryOrderPackage : public XtpPackageBase
	{
	public:
		XtpRspQryOrderPackage();
		static XtpRspQryOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100E;
		OrderField* Order = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryTradePackage : public XtpPackageBase
	{
	public:
		XtpReqQryTradePackage();
		static XtpReqQryTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100F;
		ReqQryTradeField* ReqQryTrade = nullptr;
	};

	class XtpRspQryTradePackage : public XtpPackageBase
	{
	public:
		XtpRspQryTradePackage();
		static XtpRspQryTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1010;
		TradeField* Trade = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpReqQryInstrumentPackage();
		static XtpReqQryInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1011;
		ReqQryInstrumentField* ReqQryInstrument = nullptr;
	};

	class XtpRspQryInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRspQryInstrumentPackage();
		static XtpRspQryInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1012;
		InstrumentField* Instrument = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpReqQryOptionInstrumentPackage();
		static XtpReqQryOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1013;
		ReqQryOptionInstrumentField* ReqQryOptionInstrument = nullptr;
	};

	class XtpRspQryOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRspQryOptionInstrumentPackage();
		static XtpRspQryOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1014;
		OptionInstrumentField* OptionInstrument = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryCommissionRatePackage : public XtpPackageBase
	{
	public:
		XtpReqQryCommissionRatePackage();
		static XtpReqQryCommissionRatePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1015;
		ReqQryCommissionRateField* ReqQryCommissionRate = nullptr;
	};

	class XtpRspQryCommissionRatePackage : public XtpPackageBase
	{
	public:
		XtpRspQryCommissionRatePackage();
		static XtpRspQryCommissionRatePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1016;
		CommissionRateField* CommissionRate = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryMoneyTransferPackage : public XtpPackageBase
	{
	public:
		XtpReqQryMoneyTransferPackage();
		static XtpReqQryMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1017;
		ReqQryMoneyTransferField* ReqQryMoneyTransfer = nullptr;
	};

	class XtpRspQryMoneyTransferPackage : public XtpPackageBase
	{
	public:
		XtpRspQryMoneyTransferPackage();
		static XtpRspQryMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1018;
		MoneyTransferField* MoneyTransfer = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqInsertOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqInsertOrderPackage();
		static XtpReqInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1019;
		ReqInsertOrderField* ReqInsertOrder = nullptr;
	};

	class XtpRspInsertOrderPackage : public XtpPackageBase
	{
	public:
		XtpRspInsertOrderPackage();
		static XtpRspInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101A;
		OrderField* Order = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqCancelOrderPackage();
		static XtpReqCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101B;
		ReqCancelOrderField* ReqCancelOrder = nullptr;
	};

	class XtpRspCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpRspCancelOrderPackage();
		static XtpRspCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101C;
		CancelOrderField* CancelOrder = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpRtnOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnOrderPackage();
		static XtpRtnOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101D;
		OrderField* Order = nullptr;
	};

	class XtpRtnTradePackage : public XtpPackageBase
	{
	public:
		XtpRtnTradePackage();
		static XtpRtnTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101E;
		TradeField* Trade = nullptr;
	};

	class XtpRtnMoneyTransferPackage : public XtpPackageBase
	{
	public:
		XtpRtnMoneyTransferPackage();
		static XtpRtnMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101F;
		MoneyTransferField* MoneyTransfer = nullptr;
	};

	class XtpRtnAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRtnAccountLogoutPackage();
		static XtpRtnAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1020;
		AccountLogoutField* AccountLogout = nullptr;
	};

	class XtpReqRiskUserLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqRiskUserLoginPackage();
		static XtpReqRiskUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2001;
		ReqRiskUserLoginField* ReqRiskUserLogin = nullptr;
	};

	class XtpRspRiskUserLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspRiskUserLoginPackage();
		static XtpRspRiskUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2002;
		RspRiskUserLoginField* RspRiskUserLogin = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRiskUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpReqRiskUserLogoutPackage();
		static XtpReqRiskUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2003;
		ReqRiskUserLogoutField* ReqRiskUserLogout = nullptr;
	};

	class XtpRspRiskUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRspRiskUserLogoutPackage();
		static XtpRspRiskUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2004;
		RspRiskUserLogoutField* RspRiskUserLogout = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpRtnRiskUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRtnRiskUserLogoutPackage();
		static XtpRtnRiskUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2005;
		RiskUserLogoutField* RiskUserLogout = nullptr;
	};

	class XtpRtnAccountPackage : public XtpPackageBase
	{
	public:
		XtpRtnAccountPackage();
		static XtpRtnAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2006;
		AccountField* Account = nullptr;
	};

	class XtpRtnAccountDeletePackage : public XtpPackageBase
	{
	public:
		XtpRtnAccountDeletePackage();
		static XtpRtnAccountDeletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2007;
		AccountDeleteField* AccountDelete = nullptr;
	};

	class XtpRtnPositionPackage : public XtpPackageBase
	{
	public:
		XtpRtnPositionPackage();
		static XtpRtnPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2008;
		PositionField* Position = nullptr;
	};

	class XtpRtnAccountRiskPackage : public XtpPackageBase
	{
	public:
		XtpRtnAccountRiskPackage();
		static XtpRtnAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2009;
		AccountRiskField* AccountRisk = nullptr;
	};

	class XtpRtnAccountRiskDeletePackage : public XtpPackageBase
	{
	public:
		XtpRtnAccountRiskDeletePackage();
		static XtpRtnAccountRiskDeletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200A;
		AccountRiskDeleteField* AccountRiskDelete = nullptr;
	};

	class XtpRtnAccountRiskNotifyPackage : public XtpPackageBase
	{
	public:
		XtpRtnAccountRiskNotifyPackage();
		static XtpRtnAccountRiskNotifyPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200B;
		AccountRiskNotifyField* AccountRiskNotify = nullptr;
	};

	class XtpReqQryRiskGroupAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqQryRiskGroupAccountPackage();
		static XtpReqQryRiskGroupAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200C;
		ReqQryRiskGroupAccountField* ReqQryRiskGroupAccount = nullptr;
	};

	class XtpRspQryRiskGroupAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspQryRiskGroupAccountPackage();
		static XtpRspQryRiskGroupAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200D;
		AccountField* Account = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryRiskGroupCapitalPackage : public XtpPackageBase
	{
	public:
		XtpReqQryRiskGroupCapitalPackage();
		static XtpReqQryRiskGroupCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200E;
		ReqQryRiskGroupCapitalField* ReqQryRiskGroupCapital = nullptr;
	};

	class XtpRspQryRiskGroupCapitalPackage : public XtpPackageBase
	{
	public:
		XtpRspQryRiskGroupCapitalPackage();
		static XtpRspQryRiskGroupCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200F;
		CapitalField* Capital = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryRiskGroupPositionPackage : public XtpPackageBase
	{
	public:
		XtpReqQryRiskGroupPositionPackage();
		static XtpReqQryRiskGroupPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2010;
		ReqQryRiskGroupPositionField* ReqQryRiskGroupPosition = nullptr;
	};

	class XtpRspQryRiskGroupPositionPackage : public XtpPackageBase
	{
	public:
		XtpRspQryRiskGroupPositionPackage();
		static XtpRspQryRiskGroupPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2011;
		PositionField* Position = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryRiskGroupOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqQryRiskGroupOrderPackage();
		static XtpReqQryRiskGroupOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2012;
		ReqQryRiskGroupOrderField* ReqQryRiskGroupOrder = nullptr;
	};

	class XtpRspQryRiskGroupOrderPackage : public XtpPackageBase
	{
	public:
		XtpRspQryRiskGroupOrderPackage();
		static XtpRspQryRiskGroupOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2013;
		OrderField* Order = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryRiskGroupTradePackage : public XtpPackageBase
	{
	public:
		XtpReqQryRiskGroupTradePackage();
		static XtpReqQryRiskGroupTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2014;
		ReqQryRiskGroupTradeField* ReqQryRiskGroupTrade = nullptr;
	};

	class XtpRspQryRiskGroupTradePackage : public XtpPackageBase
	{
	public:
		XtpRspQryRiskGroupTradePackage();
		static XtpRspQryRiskGroupTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2015;
		TradeField* Trade = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryRiskGroupAccountRiskPackage : public XtpPackageBase
	{
	public:
		XtpReqQryRiskGroupAccountRiskPackage();
		static XtpReqQryRiskGroupAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2016;
		ReqQryRiskGroupAccountRiskField* ReqQryRiskGroupAccountRisk = nullptr;
	};

	class XtpRspQryRiskGroupAccountRiskPackage : public XtpPackageBase
	{
	public:
		XtpRspQryRiskGroupAccountRiskPackage();
		static XtpRspQryRiskGroupAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2017;
		AccountRiskField* AccountRisk = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqQryRiskGroupAccountRiskNotifyPackage : public XtpPackageBase
	{
	public:
		XtpReqQryRiskGroupAccountRiskNotifyPackage();
		static XtpReqQryRiskGroupAccountRiskNotifyPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2018;
		ReqQryRiskGroupAccountRiskNotifyField* ReqQryRiskGroupAccountRiskNotify = nullptr;
	};

	class XtpRspQryRiskGroupAccountRiskNotifyPackage : public XtpPackageBase
	{
	public:
		XtpRspQryRiskGroupAccountRiskNotifyPackage();
		static XtpRspQryRiskGroupAccountRiskNotifyPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2019;
		AccountRiskNotifyField* AccountRiskNotify = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRiskInsertOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqRiskInsertOrderPackage();
		static XtpReqRiskInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x201A;
		ReqRiskInsertOrderField* ReqRiskInsertOrder = nullptr;
	};

	class XtpRspRiskInsertOrderPackage : public XtpPackageBase
	{
	public:
		XtpRspRiskInsertOrderPackage();
		static XtpRspRiskInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x201B;
		OrderField* Order = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRiskCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqRiskCancelOrderPackage();
		static XtpReqRiskCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x201C;
		ReqRiskCancelOrderField* ReqRiskCancelOrder = nullptr;
	};

	class XtpRspRiskCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpRspRiskCancelOrderPackage();
		static XtpRspRiskCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x201D;
		CancelOrderField* CancelOrder = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqMdUserLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqMdUserLoginPackage();
		static XtpReqMdUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3001;
		ReqMdUserLoginField* ReqMdUserLogin = nullptr;
	};

	class XtpRspMdUserLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspMdUserLoginPackage();
		static XtpRspMdUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3002;
		RspMdUserLoginField* RspMdUserLogin = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqMdUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpReqMdUserLogoutPackage();
		static XtpReqMdUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3003;
		ReqMdUserLogoutField* ReqMdUserLogout = nullptr;
	};

	class XtpRspMdUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRspMdUserLogoutPackage();
		static XtpRspMdUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3004;
		RspMdUserLogoutField* RspMdUserLogout = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqMdInitPackage : public XtpPackageBase
	{
	public:
		XtpReqMdInitPackage();
		static XtpReqMdInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3005;
		ReqMdInitField* ReqMdInit = nullptr;
	};

	class XtpRspMdInitPackage : public XtpPackageBase
	{
	public:
		XtpRspMdInitPackage();
		static XtpRspMdInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3006;
		RspMdInitField* RspMdInit = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqSubscribeMdPackage : public XtpPackageBase
	{
	public:
		XtpReqSubscribeMdPackage();
		static XtpReqSubscribeMdPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3007;
		ReqSubscribeMdField* ReqSubscribeMd = nullptr;
	};

	class XtpRspSubscribeMdPackage : public XtpPackageBase
	{
	public:
		XtpRspSubscribeMdPackage();
		static XtpRspSubscribeMdPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3008;
		RspSubscribeMdField* RspSubscribeMd = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpRtnShortMdPackage : public XtpPackageBase
	{
	public:
		XtpRtnShortMdPackage();
		static XtpRtnShortMdPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3009;
		ShortMdField* ShortMd = nullptr;
	};

	class XtpRtnExchangeStatusPackage : public XtpPackageBase
	{
	public:
		XtpRtnExchangeStatusPackage();
		static XtpRtnExchangeStatusPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x300A;
		RtnExchangeStatusField* RtnExchangeStatus = nullptr;
	};

	class XtpRtnMdInitCompletedPackage : public XtpPackageBase
	{
	public:
		XtpRtnMdInitCompletedPackage();
		static XtpRtnMdInitCompletedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x300B;
		MdInitCompletedField* MdInitCompleted = nullptr;
	};

	class XtpReqAdminUserLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqAdminUserLoginPackage();
		static XtpReqAdminUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4001;
		ReqAdminUserLoginField* ReqAdminUserLogin = nullptr;
	};

	class XtpRspAdminUserLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspAdminUserLoginPackage();
		static XtpRspAdminUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4002;
		RspAdminUserLoginField* RspAdminUserLogin = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAdminUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpReqAdminUserLogoutPackage();
		static XtpReqAdminUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4003;
		ReqAdminUserLogoutField* ReqAdminUserLogout = nullptr;
	};

	class XtpRspAdminUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRspAdminUserLogoutPackage();
		static XtpRspAdminUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4004;
		RspAdminUserLogoutField* RspAdminUserLogout = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpRtnAdminUserLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRtnAdminUserLogoutPackage();
		static XtpRtnAdminUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4005;
		AdminUserLogoutField* AdminUserLogout = nullptr;
	};

	class XtpReqAddRiskUserPackage : public XtpPackageBase
	{
	public:
		XtpReqAddRiskUserPackage();
		static XtpReqAddRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4006;
		ReqAddRiskUserField* ReqAddRiskUser = nullptr;
	};

	class XtpRspAddRiskUserPackage : public XtpPackageBase
	{
	public:
		XtpRspAddRiskUserPackage();
		static XtpRspAddRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4007;
		RspAddRiskUserField* RspAddRiskUser = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateRiskUserPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateRiskUserPackage();
		static XtpReqUpdateRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4008;
		ReqUpdateRiskUserField* ReqUpdateRiskUser = nullptr;
	};

	class XtpRspUpdateRiskUserPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateRiskUserPackage();
		static XtpRspUpdateRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4009;
		RspUpdateRiskUserField* RspUpdateRiskUser = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveRiskUserPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveRiskUserPackage();
		static XtpReqRemoveRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400A;
		ReqRemoveRiskUserField* ReqRemoveRiskUser = nullptr;
	};

	class XtpRspRemoveRiskUserPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveRiskUserPackage();
		static XtpRspRemoveRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400B;
		RspRemoveRiskUserField* RspRemoveRiskUser = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddAdminUserPackage : public XtpPackageBase
	{
	public:
		XtpReqAddAdminUserPackage();
		static XtpReqAddAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400C;
		ReqAddAdminUserField* ReqAddAdminUser = nullptr;
	};

	class XtpRspAddAdminUserPackage : public XtpPackageBase
	{
	public:
		XtpRspAddAdminUserPackage();
		static XtpRspAddAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400D;
		RspAddAdminUserField* RspAddAdminUser = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateAdminUserPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateAdminUserPackage();
		static XtpReqUpdateAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400E;
		ReqUpdateAdminUserField* ReqUpdateAdminUser = nullptr;
	};

	class XtpRspUpdateAdminUserPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateAdminUserPackage();
		static XtpRspUpdateAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400F;
		RspUpdateAdminUserField* RspUpdateAdminUser = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveAdminUserPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveAdminUserPackage();
		static XtpReqRemoveAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4010;
		ReqRemoveAdminUserField* ReqRemoveAdminUser = nullptr;
	};

	class XtpRspRemoveAdminUserPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveAdminUserPackage();
		static XtpRspRemoveAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4011;
		RspRemoveAdminUserField* RspRemoveAdminUser = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddPrimaryAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqAddPrimaryAccountPackage();
		static XtpReqAddPrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4012;
		ReqAddPrimaryAccountField* ReqAddPrimaryAccount = nullptr;
	};

	class XtpRspAddPrimaryAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspAddPrimaryAccountPackage();
		static XtpRspAddPrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4013;
		RspAddPrimaryAccountField* RspAddPrimaryAccount = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdatePrimaryAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdatePrimaryAccountPackage();
		static XtpReqUpdatePrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4014;
		ReqUpdatePrimaryAccountField* ReqUpdatePrimaryAccount = nullptr;
	};

	class XtpRspUpdatePrimaryAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdatePrimaryAccountPackage();
		static XtpRspUpdatePrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4015;
		RspUpdatePrimaryAccountField* RspUpdatePrimaryAccount = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemovePrimaryAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqRemovePrimaryAccountPackage();
		static XtpReqRemovePrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4016;
		ReqRemovePrimaryAccountField* ReqRemovePrimaryAccount = nullptr;
	};

	class XtpRspRemovePrimaryAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspRemovePrimaryAccountPackage();
		static XtpRspRemovePrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4017;
		RspRemovePrimaryAccountField* RspRemovePrimaryAccount = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqAddAccountPackage();
		static XtpReqAddAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4018;
		ReqAddAccountField* ReqAddAccount = nullptr;
	};

	class XtpRspAddAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspAddAccountPackage();
		static XtpRspAddAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4019;
		RspAddAccountField* RspAddAccount = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateAccountPackage();
		static XtpReqUpdateAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401A;
		ReqUpdateAccountField* ReqUpdateAccount = nullptr;
	};

	class XtpRspUpdateAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateAccountPackage();
		static XtpRspUpdateAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401B;
		RspUpdateAccountField* RspUpdateAccount = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveAccountPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveAccountPackage();
		static XtpReqRemoveAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401C;
		ReqRemoveAccountField* ReqRemoveAccount = nullptr;
	};

	class XtpRspRemoveAccountPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveAccountPackage();
		static XtpRspRemoveAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401D;
		RspRemoveAccountField* RspRemoveAccount = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddBaseCommissionPackage : public XtpPackageBase
	{
	public:
		XtpReqAddBaseCommissionPackage();
		static XtpReqAddBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401E;
		ReqAddBaseCommissionField* ReqAddBaseCommission = nullptr;
	};

	class XtpRspAddBaseCommissionPackage : public XtpPackageBase
	{
	public:
		XtpRspAddBaseCommissionPackage();
		static XtpRspAddBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401F;
		RspAddBaseCommissionField* RspAddBaseCommission = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateBaseCommissionPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateBaseCommissionPackage();
		static XtpReqUpdateBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4020;
		ReqUpdateBaseCommissionField* ReqUpdateBaseCommission = nullptr;
	};

	class XtpRspUpdateBaseCommissionPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateBaseCommissionPackage();
		static XtpRspUpdateBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4021;
		RspUpdateBaseCommissionField* RspUpdateBaseCommission = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveBaseCommissionPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveBaseCommissionPackage();
		static XtpReqRemoveBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4022;
		ReqRemoveBaseCommissionField* ReqRemoveBaseCommission = nullptr;
	};

	class XtpRspRemoveBaseCommissionPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveBaseCommissionPackage();
		static XtpRspRemoveBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4023;
		RspInfoField* RspInfo = nullptr;
		RspRemoveBaseCommissionField* RspRemoveBaseCommission = nullptr;
	};

	class XtpReqAddCommissionGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqAddCommissionGroupPackage();
		static XtpReqAddCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4024;
		ReqAddCommissionGroupField* ReqAddCommissionGroup = nullptr;
	};

	class XtpRspAddCommissionGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspAddCommissionGroupPackage();
		static XtpRspAddCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4025;
		RspAddCommissionGroupField* RspAddCommissionGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateCommissionGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateCommissionGroupPackage();
		static XtpReqUpdateCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4026;
		ReqUpdateCommissionGroupField* ReqUpdateCommissionGroup = nullptr;
	};

	class XtpRspUpdateCommissionGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateCommissionGroupPackage();
		static XtpRspUpdateCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4027;
		RspUpdateCommissionGroupField* RspUpdateCommissionGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveCommissionGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveCommissionGroupPackage();
		static XtpReqRemoveCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4028;
		ReqRemoveCommissionGroupField* ReqRemoveCommissionGroup = nullptr;
	};

	class XtpRspRemoveCommissionGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveCommissionGroupPackage();
		static XtpRspRemoveCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4029;
		RspRemoveCommissionGroupField* RspRemoveCommissionGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddOptionMarginParamPackage : public XtpPackageBase
	{
	public:
		XtpReqAddOptionMarginParamPackage();
		static XtpReqAddOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402A;
		ReqAddOptionMarginParamField* ReqAddOptionMarginParam = nullptr;
	};

	class XtpRspAddOptionMarginParamPackage : public XtpPackageBase
	{
	public:
		XtpRspAddOptionMarginParamPackage();
		static XtpRspAddOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402B;
		RspAddOptionMarginParamField* RspAddOptionMarginParam = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateOptionMarginParamPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateOptionMarginParamPackage();
		static XtpReqUpdateOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402C;
		ReqUpdateOptionMarginParamField* ReqUpdateOptionMarginParam = nullptr;
	};

	class XtpRspUpdateOptionMarginParamPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateOptionMarginParamPackage();
		static XtpRspUpdateOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402D;
		RspUpdateOptionMarginParamField* RspUpdateOptionMarginParam = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveOptionMarginParamPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveOptionMarginParamPackage();
		static XtpReqRemoveOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402E;
		ReqRemoveOptionMarginParamField* ReqRemoveOptionMarginParam = nullptr;
	};

	class XtpRspRemoveOptionMarginParamPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveOptionMarginParamPackage();
		static XtpRspRemoveOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402F;
		RspRemoveOptionMarginParamField* RspRemoveOptionMarginParam = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddTradeOfferPackage : public XtpPackageBase
	{
	public:
		XtpReqAddTradeOfferPackage();
		static XtpReqAddTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4030;
		ReqAddTradeOfferField* ReqAddTradeOffer = nullptr;
	};

	class XtpRspAddTradeOfferPackage : public XtpPackageBase
	{
	public:
		XtpRspAddTradeOfferPackage();
		static XtpRspAddTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4031;
		RspAddTradeOfferField* RspAddTradeOffer = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateTradeOfferPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateTradeOfferPackage();
		static XtpReqUpdateTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4032;
		ReqUpdateTradeOfferField* ReqUpdateTradeOffer = nullptr;
	};

	class XtpRspUpdateTradeOfferPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateTradeOfferPackage();
		static XtpRspUpdateTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4033;
		RspUpdateTradeOfferField* RspUpdateTradeOffer = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveTradeOfferPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveTradeOfferPackage();
		static XtpReqRemoveTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4034;
		ReqRemoveTradeOfferField* ReqRemoveTradeOffer = nullptr;
	};

	class XtpRspRemoveTradeOfferPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveTradeOfferPackage();
		static XtpRspRemoveTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4035;
		RspRemoveTradeOfferField* RspRemoveTradeOffer = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddTradeGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqAddTradeGroupPackage();
		static XtpReqAddTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4036;
		ReqAddTradeGroupField* ReqAddTradeGroup = nullptr;
	};

	class XtpRspAddTradeGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspAddTradeGroupPackage();
		static XtpRspAddTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4037;
		RspAddTradeGroupField* RspAddTradeGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateTradeGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateTradeGroupPackage();
		static XtpReqUpdateTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4038;
		ReqUpdateTradeGroupField* ReqUpdateTradeGroup = nullptr;
	};

	class XtpRspUpdateTradeGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateTradeGroupPackage();
		static XtpRspUpdateTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4039;
		RspUpdateTradeGroupField* RspUpdateTradeGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveTradeGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveTradeGroupPackage();
		static XtpReqRemoveTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403A;
		ReqRemoveTradeGroupField* ReqRemoveTradeGroup = nullptr;
	};

	class XtpRspRemoveTradeGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveTradeGroupPackage();
		static XtpRspRemoveTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403B;
		RspRemoveTradeGroupField* RspRemoveTradeGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddTradeGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpReqAddTradeGroupItemPackage();
		static XtpReqAddTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403C;
		ReqAddTradeGroupItemField* ReqAddTradeGroupItem = nullptr;
	};

	class XtpRspAddTradeGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpRspAddTradeGroupItemPackage();
		static XtpRspAddTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403D;
		RspAddTradeGroupItemField* RspAddTradeGroupItem = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateTradeGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateTradeGroupItemPackage();
		static XtpReqUpdateTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403E;
		ReqUpdateTradeGroupItemField* ReqUpdateTradeGroupItem = nullptr;
	};

	class XtpRspUpdateTradeGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateTradeGroupItemPackage();
		static XtpRspUpdateTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403F;
		RspUpdateTradeGroupItemField* RspUpdateTradeGroupItem = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveTradeGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveTradeGroupItemPackage();
		static XtpReqRemoveTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4040;
		ReqRemoveTradeGroupItemField* ReqRemoveTradeGroupItem = nullptr;
	};

	class XtpRspRemoveTradeGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveTradeGroupItemPackage();
		static XtpRspRemoveTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4041;
		RspRemoveTradeGroupItemField* RspRemoveTradeGroupItem = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddRiskGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqAddRiskGroupPackage();
		static XtpReqAddRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4042;
		ReqAddRiskGroupField* ReqAddRiskGroup = nullptr;
	};

	class XtpRspAddRiskGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspAddRiskGroupPackage();
		static XtpRspAddRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4043;
		RspAddRiskGroupField* RspAddRiskGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateRiskGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateRiskGroupPackage();
		static XtpReqUpdateRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4044;
		ReqUpdateRiskGroupField* ReqUpdateRiskGroup = nullptr;
	};

	class XtpRspUpdateRiskGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateRiskGroupPackage();
		static XtpRspUpdateRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4045;
		RspUpdateRiskGroupField* RspUpdateRiskGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveRiskGroupPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveRiskGroupPackage();
		static XtpReqRemoveRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4046;
		ReqRemoveRiskGroupField* ReqRemoveRiskGroup = nullptr;
	};

	class XtpRspRemoveRiskGroupPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveRiskGroupPackage();
		static XtpRspRemoveRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4047;
		RspRemoveRiskGroupField* RspRemoveRiskGroup = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddRiskGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpReqAddRiskGroupItemPackage();
		static XtpReqAddRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4048;
		ReqAddRiskGroupItemField* ReqAddRiskGroupItem = nullptr;
	};

	class XtpRspAddRiskGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpRspAddRiskGroupItemPackage();
		static XtpRspAddRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4049;
		RspAddRiskGroupItemField* RspAddRiskGroupItem = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqUpdateRiskGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpReqUpdateRiskGroupItemPackage();
		static XtpReqUpdateRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404A;
		ReqUpdateRiskGroupItemField* ReqUpdateRiskGroupItem = nullptr;
	};

	class XtpRspUpdateRiskGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpRspUpdateRiskGroupItemPackage();
		static XtpRspUpdateRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404B;
		RspUpdateRiskGroupItemField* RspUpdateRiskGroupItem = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveRiskGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveRiskGroupItemPackage();
		static XtpReqRemoveRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404C;
		ReqRemoveRiskGroupItemField* ReqRemoveRiskGroupItem = nullptr;
	};

	class XtpRspRemoveRiskGroupItemPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveRiskGroupItemPackage();
		static XtpRspRemoveRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404D;
		RspRemoveRiskGroupItemField* RspRemoveRiskGroupItem = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddOrUpdateRiskPackage : public XtpPackageBase
	{
	public:
		XtpReqAddOrUpdateRiskPackage();
		static XtpReqAddOrUpdateRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404E;
		ReqAddOrUpdateRiskField* ReqAddOrUpdateRisk = nullptr;
	};

	class XtpRspAddOrUpdateRiskPackage : public XtpPackageBase
	{
	public:
		XtpRspAddOrUpdateRiskPackage();
		static XtpRspAddOrUpdateRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404F;
		RspAddOrUpdateRiskField* RspAddOrUpdateRisk = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveRiskPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveRiskPackage();
		static XtpReqRemoveRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4050;
		ReqRemoveRiskField* ReqRemoveRisk = nullptr;
	};

	class XtpRspRemoveRiskPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveRiskPackage();
		static XtpRspRemoveRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4051;
		RspRemoveRiskField* RspRemoveRisk = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddRiskRulePackage : public XtpPackageBase
	{
	public:
		XtpReqAddRiskRulePackage();
		static XtpReqAddRiskRulePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4052;
		ReqAddRiskRuleField* ReqAddRiskRule = nullptr;
	};

	class XtpRspAddRiskRulePackage : public XtpPackageBase
	{
	public:
		XtpRspAddRiskRulePackage();
		static XtpRspAddRiskRulePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4053;
		RspAddRiskRuleField* RspAddRiskRule = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddRiskRuleItemPackage : public XtpPackageBase
	{
	public:
		XtpReqAddRiskRuleItemPackage();
		static XtpReqAddRiskRuleItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4054;
		ReqAddRiskRuleItemField* ReqAddRiskRuleItem = nullptr;
	};

	class XtpRspAddRiskRuleItemPackage : public XtpPackageBase
	{
	public:
		XtpRspAddRiskRuleItemPackage();
		static XtpRspAddRiskRuleItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4055;
		RspAddRiskRuleItemField* RspAddRiskRuleItem = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddRiskTradeScopePackage : public XtpPackageBase
	{
	public:
		XtpReqAddRiskTradeScopePackage();
		static XtpReqAddRiskTradeScopePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4056;
		ReqAddRiskTradeScopeField* ReqAddRiskTradeScope = nullptr;
	};

	class XtpRspAddRiskTradeScopePackage : public XtpPackageBase
	{
	public:
		XtpRspAddRiskTradeScopePackage();
		static XtpRspAddRiskTradeScopePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4057;
		RspAddRiskTradeScopeField* RspAddRiskTradeScope = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAddAccountRiskPackage : public XtpPackageBase
	{
	public:
		XtpReqAddAccountRiskPackage();
		static XtpReqAddAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4058;
		ReqAddAccountRiskField* ReqAddAccountRisk = nullptr;
	};

	class XtpRspAddAccountRiskPackage : public XtpPackageBase
	{
	public:
		XtpRspAddAccountRiskPackage();
		static XtpRspAddAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4059;
		RspAddAccountRiskField* RspAddAccountRisk = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqRemoveAccountRiskPackage : public XtpPackageBase
	{
	public:
		XtpReqRemoveAccountRiskPackage();
		static XtpReqRemoveAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405A;
		ReqRemoveAccountRiskField* ReqRemoveAccountRisk = nullptr;
	};

	class XtpRspRemoveAccountRiskPackage : public XtpPackageBase
	{
	public:
		XtpRspRemoveAccountRiskPackage();
		static XtpRspRemoveAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405B;
		RspRemoveAccountRiskField* RspRemoveAccountRisk = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqMoneyTransferPackage : public XtpPackageBase
	{
	public:
		XtpReqMoneyTransferPackage();
		static XtpReqMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405C;
		ReqMoneyTransferField* ReqMoneyTransfer = nullptr;
	};

	class XtpRspMoneyTransferPackage : public XtpPackageBase
	{
	public:
		XtpRspMoneyTransferPackage();
		static XtpRspMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405D;
		RspMoneyTransferField* RspMoneyTransfer = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqAuditOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqAuditOrderPackage();
		static XtpReqAuditOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405E;
		ReqAuditOrderField* ReqAuditOrder = nullptr;
	};

	class XtpRspAuditOrderPackage : public XtpPackageBase
	{
	public:
		XtpRspAuditOrderPackage();
		static XtpRspAuditOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405F;
		RspAuditOrderField* RspAuditOrder = nullptr;
		RspInfoField* RspInfo = nullptr;
	};

	class XtpReqOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqOfferLoginPackage();
		static XtpReqOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5001;
		ReqOfferLoginField* ReqOfferLogin = nullptr;
	};

	class XtpRspOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspOfferLoginPackage();
		static XtpRspOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5002;
		RspOfferLoginField* RspOfferLogin = nullptr;
	};

	class XtpReqPrimaryAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountLoginPackage();
		static XtpReqPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5003;
		ReqPrimaryAccountLoginField* ReqPrimaryAccountLogin = nullptr;
	};

	class XtpRspPrimaryAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountLoginPackage();
		static XtpRspPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5004;
		RspPrimaryAccountLoginField* RspPrimaryAccountLogin = nullptr;
	};

	class XtpReqPrimaryAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountLogoutPackage();
		static XtpReqPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5005;
		ReqPrimaryAccountLogoutField* ReqPrimaryAccountLogout = nullptr;
	};

	class XtpRtnPrimaryAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRtnPrimaryAccountLogoutPackage();
		static XtpRtnPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5006;
		RtnPrimaryAccountLogoutField* RtnPrimaryAccountLogout = nullptr;
	};

	class XtpReqPrimaryAccountInitPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountInitPackage();
		static XtpReqPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5007;
		ReqPrimaryAccountInitField* ReqPrimaryAccountInit = nullptr;
	};

	class XtpRspPrimaryAccountInitPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountInitPackage();
		static XtpRspPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5008;
		RspPrimaryAccountInitField* RspPrimaryAccountInit = nullptr;
	};

	class XtpReqPrimaryAccountQueryPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountQueryPackage();
		static XtpReqPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5009;
		ReqPrimaryAccountQueryField* ReqPrimaryAccountQuery = nullptr;
	};

	class XtpRspPrimaryAccountQueryPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountQueryPackage();
		static XtpRspPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500A;
		RspPrimaryAccountQueryField* RspPrimaryAccountQuery = nullptr;
	};

	class XtpReqQryOfferOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpReqQryOfferOptionInstrumentPackage();
		static XtpReqQryOfferOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500B;
		ReqQryOfferOptionInstrumentField* ReqQryOfferOptionInstrument = nullptr;
	};

	class XtpRspQryOfferOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRspQryOfferOptionInstrumentPackage();
		static XtpRspQryOfferOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500C;
		RspQryOfferOptionInstrumentField* RspQryOfferOptionInstrument = nullptr;
	};

	class XtpRtnOfferOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRtnOfferOptionInstrumentPackage();
		static XtpRtnOfferOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500D;
		OfferOptionInstrumentField* OfferOptionInstrument = nullptr;
	};

	class XtpReqOfferOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqOfferOrderPackage();
		static XtpReqOfferOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500E;
		ReqOfferOrderField* ReqOfferOrder = nullptr;
	};

	class XtpReqOfferCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqOfferCancelOrderPackage();
		static XtpReqOfferCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500F;
		ReqOfferCancelOrderField* ReqOfferCancelOrder = nullptr;
	};

	class XtpRtnOfferOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnOfferOrderPackage();
		static XtpRtnOfferOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5010;
		OfferOrderField* OfferOrder = nullptr;
	};

	class XtpRtnOfferTradePackage : public XtpPackageBase
	{
	public:
		XtpRtnOfferTradePackage();
		static XtpRtnOfferTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5011;
		OfferTradeField* OfferTrade = nullptr;
	};

	class XtpRtnOfferErrorCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnOfferErrorCancelOrderPackage();
		static XtpRtnOfferErrorCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5012;
		OfferErrorCancelOrderField* OfferErrorCancelOrder = nullptr;
	};

	class XtpRtnOfferCapitalPackage : public XtpPackageBase
	{
	public:
		XtpRtnOfferCapitalPackage();
		static XtpRtnOfferCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5013;
		OfferCapitalField* OfferCapital = nullptr;
	};

	class XtpRtnOfferPositionPackage : public XtpPackageBase
	{
	public:
		XtpRtnOfferPositionPackage();
		static XtpRtnOfferPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5014;
		OfferPositionField* OfferPosition = nullptr;
	};

}
