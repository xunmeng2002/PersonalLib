#pragma once
#include "Types.h"
#include "Fields.h"
#include "StepPackageBase.h"
#include <vector>

namespace step
{
	class StepNotifyComponentConnectStatusPackage : public StepPackageBase
	{
	public:
		StepNotifyComponentConnectStatusPackage();
		static StepNotifyComponentConnectStatusPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0001;
		NotifyComponentConnectStatusField* NotifyComponentConnectStatus = nullptr;
	};
	class StepReqAccountLoginPackage : public StepPackageBase
	{
	public:
		StepReqAccountLoginPackage();
		static StepReqAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1001;
		ReqAccountLoginField* ReqAccountLogin = nullptr;
	};
	class StepRspAccountLoginPackage : public StepPackageBase
	{
	public:
		StepRspAccountLoginPackage();
		static StepRspAccountLoginPackage* Allocate();
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
	class StepReqAccountLogoutPackage : public StepPackageBase
	{
	public:
		StepReqAccountLogoutPackage();
		static StepReqAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1003;
		ReqAccountLogoutField* ReqAccountLogout = nullptr;
	};
	class StepRspAccountLogoutPackage : public StepPackageBase
	{
	public:
		StepRspAccountLogoutPackage();
		static StepRspAccountLogoutPackage* Allocate();
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
	class StepReqQryAccountPackage : public StepPackageBase
	{
	public:
		StepReqQryAccountPackage();
		static StepReqQryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1005;
		ReqQryAccountField* ReqQryAccount = nullptr;
	};
	class StepRspQryAccountPackage : public StepPackageBase
	{
	public:
		StepRspQryAccountPackage();
		static StepRspQryAccountPackage* Allocate();
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
	class StepReqQryHolderAccountPackage : public StepPackageBase
	{
	public:
		StepReqQryHolderAccountPackage();
		static StepReqQryHolderAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1007;
		ReqQryHolderAccountField* ReqQryHolderAccount = nullptr;
	};
	class StepRspQryHolderAccountPackage : public StepPackageBase
	{
	public:
		StepRspQryHolderAccountPackage();
		static StepRspQryHolderAccountPackage* Allocate();
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
	class StepReqQryCapitalPackage : public StepPackageBase
	{
	public:
		StepReqQryCapitalPackage();
		static StepReqQryCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1009;
		ReqQryCapitalField* ReqQryCapital = nullptr;
	};
	class StepRspQryCapitalPackage : public StepPackageBase
	{
	public:
		StepRspQryCapitalPackage();
		static StepRspQryCapitalPackage* Allocate();
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
	class StepReqQryPositionPackage : public StepPackageBase
	{
	public:
		StepReqQryPositionPackage();
		static StepReqQryPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100B;
		ReqQryPositionField* ReqQryPosition = nullptr;
	};
	class StepRspQryPositionPackage : public StepPackageBase
	{
	public:
		StepRspQryPositionPackage();
		static StepRspQryPositionPackage* Allocate();
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
	class StepReqQryOrderPackage : public StepPackageBase
	{
	public:
		StepReqQryOrderPackage();
		static StepReqQryOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100D;
		ReqQryOrderField* ReqQryOrder = nullptr;
	};
	class StepRspQryOrderPackage : public StepPackageBase
	{
	public:
		StepRspQryOrderPackage();
		static StepRspQryOrderPackage* Allocate();
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
	class StepReqQryTradePackage : public StepPackageBase
	{
	public:
		StepReqQryTradePackage();
		static StepReqQryTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100F;
		ReqQryTradeField* ReqQryTrade = nullptr;
	};
	class StepRspQryTradePackage : public StepPackageBase
	{
	public:
		StepRspQryTradePackage();
		static StepRspQryTradePackage* Allocate();
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
	class StepReqQryInstrumentPackage : public StepPackageBase
	{
	public:
		StepReqQryInstrumentPackage();
		static StepReqQryInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1011;
		ReqQryInstrumentField* ReqQryInstrument = nullptr;
	};
	class StepRspQryInstrumentPackage : public StepPackageBase
	{
	public:
		StepRspQryInstrumentPackage();
		static StepRspQryInstrumentPackage* Allocate();
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
	class StepReqQryOptionInstrumentPackage : public StepPackageBase
	{
	public:
		StepReqQryOptionInstrumentPackage();
		static StepReqQryOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1013;
		ReqQryOptionInstrumentField* ReqQryOptionInstrument = nullptr;
	};
	class StepRspQryOptionInstrumentPackage : public StepPackageBase
	{
	public:
		StepRspQryOptionInstrumentPackage();
		static StepRspQryOptionInstrumentPackage* Allocate();
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
	class StepReqQryCommissionRatePackage : public StepPackageBase
	{
	public:
		StepReqQryCommissionRatePackage();
		static StepReqQryCommissionRatePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1015;
		ReqQryCommissionRateField* ReqQryCommissionRate = nullptr;
	};
	class StepRspQryCommissionRatePackage : public StepPackageBase
	{
	public:
		StepRspQryCommissionRatePackage();
		static StepRspQryCommissionRatePackage* Allocate();
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
	class StepReqQryMoneyTransferPackage : public StepPackageBase
	{
	public:
		StepReqQryMoneyTransferPackage();
		static StepReqQryMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1017;
		ReqQryMoneyTransferField* ReqQryMoneyTransfer = nullptr;
	};
	class StepRspQryMoneyTransferPackage : public StepPackageBase
	{
	public:
		StepRspQryMoneyTransferPackage();
		static StepRspQryMoneyTransferPackage* Allocate();
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
	class StepReqInsertOrderPackage : public StepPackageBase
	{
	public:
		StepReqInsertOrderPackage();
		static StepReqInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1019;
		ReqInsertOrderField* ReqInsertOrder = nullptr;
	};
	class StepRspInsertOrderPackage : public StepPackageBase
	{
	public:
		StepRspInsertOrderPackage();
		static StepRspInsertOrderPackage* Allocate();
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
	class StepReqCancelOrderPackage : public StepPackageBase
	{
	public:
		StepReqCancelOrderPackage();
		static StepReqCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101B;
		ReqCancelOrderField* ReqCancelOrder = nullptr;
	};
	class StepRspCancelOrderPackage : public StepPackageBase
	{
	public:
		StepRspCancelOrderPackage();
		static StepRspCancelOrderPackage* Allocate();
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
	class StepRtnOrderPackage : public StepPackageBase
	{
	public:
		StepRtnOrderPackage();
		static StepRtnOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101D;
		OrderField* Order = nullptr;
	};
	class StepRtnTradePackage : public StepPackageBase
	{
	public:
		StepRtnTradePackage();
		static StepRtnTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101E;
		TradeField* Trade = nullptr;
	};
	class StepRtnMoneyTransferPackage : public StepPackageBase
	{
	public:
		StepRtnMoneyTransferPackage();
		static StepRtnMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x101F;
		MoneyTransferField* MoneyTransfer = nullptr;
	};
	class StepRtnAccountLogoutPackage : public StepPackageBase
	{
	public:
		StepRtnAccountLogoutPackage();
		static StepRtnAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1020;
		AccountLogoutField* AccountLogout = nullptr;
	};
	class StepReqRiskUserLoginPackage : public StepPackageBase
	{
	public:
		StepReqRiskUserLoginPackage();
		static StepReqRiskUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2001;
		ReqRiskUserLoginField* ReqRiskUserLogin = nullptr;
	};
	class StepRspRiskUserLoginPackage : public StepPackageBase
	{
	public:
		StepRspRiskUserLoginPackage();
		static StepRspRiskUserLoginPackage* Allocate();
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
	class StepReqRiskUserLogoutPackage : public StepPackageBase
	{
	public:
		StepReqRiskUserLogoutPackage();
		static StepReqRiskUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2003;
		ReqRiskUserLogoutField* ReqRiskUserLogout = nullptr;
	};
	class StepRspRiskUserLogoutPackage : public StepPackageBase
	{
	public:
		StepRspRiskUserLogoutPackage();
		static StepRspRiskUserLogoutPackage* Allocate();
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
	class StepRtnRiskUserLogoutPackage : public StepPackageBase
	{
	public:
		StepRtnRiskUserLogoutPackage();
		static StepRtnRiskUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2005;
		RiskUserLogoutField* RiskUserLogout = nullptr;
	};
	class StepRtnAccountPackage : public StepPackageBase
	{
	public:
		StepRtnAccountPackage();
		static StepRtnAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2006;
		AccountField* Account = nullptr;
	};
	class StepRtnAccountDeletePackage : public StepPackageBase
	{
	public:
		StepRtnAccountDeletePackage();
		static StepRtnAccountDeletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2007;
		AccountDeleteField* AccountDelete = nullptr;
	};
	class StepRtnPositionPackage : public StepPackageBase
	{
	public:
		StepRtnPositionPackage();
		static StepRtnPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2008;
		PositionField* Position = nullptr;
	};
	class StepRtnAccountRiskPackage : public StepPackageBase
	{
	public:
		StepRtnAccountRiskPackage();
		static StepRtnAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2009;
		AccountRiskField* AccountRisk = nullptr;
	};
	class StepRtnAccountRiskDeletePackage : public StepPackageBase
	{
	public:
		StepRtnAccountRiskDeletePackage();
		static StepRtnAccountRiskDeletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200A;
		AccountRiskDeleteField* AccountRiskDelete = nullptr;
	};
	class StepRtnAccountRiskNotifyPackage : public StepPackageBase
	{
	public:
		StepRtnAccountRiskNotifyPackage();
		static StepRtnAccountRiskNotifyPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200B;
		AccountRiskNotifyField* AccountRiskNotify = nullptr;
	};
	class StepReqQryRiskGroupAccountPackage : public StepPackageBase
	{
	public:
		StepReqQryRiskGroupAccountPackage();
		static StepReqQryRiskGroupAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200C;
		ReqQryRiskGroupAccountField* ReqQryRiskGroupAccount = nullptr;
	};
	class StepRspQryRiskGroupAccountPackage : public StepPackageBase
	{
	public:
		StepRspQryRiskGroupAccountPackage();
		static StepRspQryRiskGroupAccountPackage* Allocate();
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
	class StepReqQryRiskGroupCapitalPackage : public StepPackageBase
	{
	public:
		StepReqQryRiskGroupCapitalPackage();
		static StepReqQryRiskGroupCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x200E;
		ReqQryRiskGroupCapitalField* ReqQryRiskGroupCapital = nullptr;
	};
	class StepRspQryRiskGroupCapitalPackage : public StepPackageBase
	{
	public:
		StepRspQryRiskGroupCapitalPackage();
		static StepRspQryRiskGroupCapitalPackage* Allocate();
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
	class StepReqQryRiskGroupPositionPackage : public StepPackageBase
	{
	public:
		StepReqQryRiskGroupPositionPackage();
		static StepReqQryRiskGroupPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2010;
		ReqQryRiskGroupPositionField* ReqQryRiskGroupPosition = nullptr;
	};
	class StepRspQryRiskGroupPositionPackage : public StepPackageBase
	{
	public:
		StepRspQryRiskGroupPositionPackage();
		static StepRspQryRiskGroupPositionPackage* Allocate();
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
	class StepReqQryRiskGroupOrderPackage : public StepPackageBase
	{
	public:
		StepReqQryRiskGroupOrderPackage();
		static StepReqQryRiskGroupOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2012;
		ReqQryRiskGroupOrderField* ReqQryRiskGroupOrder = nullptr;
	};
	class StepRspQryRiskGroupOrderPackage : public StepPackageBase
	{
	public:
		StepRspQryRiskGroupOrderPackage();
		static StepRspQryRiskGroupOrderPackage* Allocate();
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
	class StepReqQryRiskGroupTradePackage : public StepPackageBase
	{
	public:
		StepReqQryRiskGroupTradePackage();
		static StepReqQryRiskGroupTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2014;
		ReqQryRiskGroupTradeField* ReqQryRiskGroupTrade = nullptr;
	};
	class StepRspQryRiskGroupTradePackage : public StepPackageBase
	{
	public:
		StepRspQryRiskGroupTradePackage();
		static StepRspQryRiskGroupTradePackage* Allocate();
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
	class StepReqQryRiskGroupAccountRiskPackage : public StepPackageBase
	{
	public:
		StepReqQryRiskGroupAccountRiskPackage();
		static StepReqQryRiskGroupAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2016;
		ReqQryRiskGroupAccountRiskField* ReqQryRiskGroupAccountRisk = nullptr;
	};
	class StepRspQryRiskGroupAccountRiskPackage : public StepPackageBase
	{
	public:
		StepRspQryRiskGroupAccountRiskPackage();
		static StepRspQryRiskGroupAccountRiskPackage* Allocate();
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
	class StepReqQryRiskGroupAccountRiskNotifyPackage : public StepPackageBase
	{
	public:
		StepReqQryRiskGroupAccountRiskNotifyPackage();
		static StepReqQryRiskGroupAccountRiskNotifyPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2018;
		ReqQryRiskGroupAccountRiskNotifyField* ReqQryRiskGroupAccountRiskNotify = nullptr;
	};
	class StepRspQryRiskGroupAccountRiskNotifyPackage : public StepPackageBase
	{
	public:
		StepRspQryRiskGroupAccountRiskNotifyPackage();
		static StepRspQryRiskGroupAccountRiskNotifyPackage* Allocate();
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
	class StepReqRiskInsertOrderPackage : public StepPackageBase
	{
	public:
		StepReqRiskInsertOrderPackage();
		static StepReqRiskInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x201A;
		ReqRiskInsertOrderField* ReqRiskInsertOrder = nullptr;
	};
	class StepRspRiskInsertOrderPackage : public StepPackageBase
	{
	public:
		StepRspRiskInsertOrderPackage();
		static StepRspRiskInsertOrderPackage* Allocate();
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
	class StepReqRiskCancelOrderPackage : public StepPackageBase
	{
	public:
		StepReqRiskCancelOrderPackage();
		static StepReqRiskCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x201C;
		ReqRiskCancelOrderField* ReqRiskCancelOrder = nullptr;
	};
	class StepRspRiskCancelOrderPackage : public StepPackageBase
	{
	public:
		StepRspRiskCancelOrderPackage();
		static StepRspRiskCancelOrderPackage* Allocate();
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
	class StepReqMdUserLoginPackage : public StepPackageBase
	{
	public:
		StepReqMdUserLoginPackage();
		static StepReqMdUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3001;
		ReqMdUserLoginField* ReqMdUserLogin = nullptr;
	};
	class StepRspMdUserLoginPackage : public StepPackageBase
	{
	public:
		StepRspMdUserLoginPackage();
		static StepRspMdUserLoginPackage* Allocate();
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
	class StepReqMdUserLogoutPackage : public StepPackageBase
	{
	public:
		StepReqMdUserLogoutPackage();
		static StepReqMdUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3003;
		ReqMdUserLogoutField* ReqMdUserLogout = nullptr;
	};
	class StepRspMdUserLogoutPackage : public StepPackageBase
	{
	public:
		StepRspMdUserLogoutPackage();
		static StepRspMdUserLogoutPackage* Allocate();
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
	class StepReqMdInitPackage : public StepPackageBase
	{
	public:
		StepReqMdInitPackage();
		static StepReqMdInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3005;
		ReqMdInitField* ReqMdInit = nullptr;
	};
	class StepRspMdInitPackage : public StepPackageBase
	{
	public:
		StepRspMdInitPackage();
		static StepRspMdInitPackage* Allocate();
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
	class StepReqSubscribeMdPackage : public StepPackageBase
	{
	public:
		StepReqSubscribeMdPackage();
		static StepReqSubscribeMdPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3007;
		ReqSubscribeMdField* ReqSubscribeMd = nullptr;
	};
	class StepRspSubscribeMdPackage : public StepPackageBase
	{
	public:
		StepRspSubscribeMdPackage();
		static StepRspSubscribeMdPackage* Allocate();
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
	class StepRtnShortMdPackage : public StepPackageBase
	{
	public:
		StepRtnShortMdPackage();
		static StepRtnShortMdPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3009;
		ShortMdField* ShortMd = nullptr;
	};
	class StepRtnExchangeStatusPackage : public StepPackageBase
	{
	public:
		StepRtnExchangeStatusPackage();
		static StepRtnExchangeStatusPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x300A;
		RtnExchangeStatusField* RtnExchangeStatus = nullptr;
	};
	class StepRtnMdInitCompletedPackage : public StepPackageBase
	{
	public:
		StepRtnMdInitCompletedPackage();
		static StepRtnMdInitCompletedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x300B;
		MdInitCompletedField* MdInitCompleted = nullptr;
	};
	class StepReqAdminUserLoginPackage : public StepPackageBase
	{
	public:
		StepReqAdminUserLoginPackage();
		static StepReqAdminUserLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4001;
		ReqAdminUserLoginField* ReqAdminUserLogin = nullptr;
	};
	class StepRspAdminUserLoginPackage : public StepPackageBase
	{
	public:
		StepRspAdminUserLoginPackage();
		static StepRspAdminUserLoginPackage* Allocate();
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
	class StepReqAdminUserLogoutPackage : public StepPackageBase
	{
	public:
		StepReqAdminUserLogoutPackage();
		static StepReqAdminUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4003;
		ReqAdminUserLogoutField* ReqAdminUserLogout = nullptr;
	};
	class StepRspAdminUserLogoutPackage : public StepPackageBase
	{
	public:
		StepRspAdminUserLogoutPackage();
		static StepRspAdminUserLogoutPackage* Allocate();
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
	class StepRtnAdminUserLogoutPackage : public StepPackageBase
	{
	public:
		StepRtnAdminUserLogoutPackage();
		static StepRtnAdminUserLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4005;
		AdminUserLogoutField* AdminUserLogout = nullptr;
	};
	class StepReqAddRiskUserPackage : public StepPackageBase
	{
	public:
		StepReqAddRiskUserPackage();
		static StepReqAddRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4006;
		ReqAddRiskUserField* ReqAddRiskUser = nullptr;
	};
	class StepRspAddRiskUserPackage : public StepPackageBase
	{
	public:
		StepRspAddRiskUserPackage();
		static StepRspAddRiskUserPackage* Allocate();
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
	class StepReqUpdateRiskUserPackage : public StepPackageBase
	{
	public:
		StepReqUpdateRiskUserPackage();
		static StepReqUpdateRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4008;
		ReqUpdateRiskUserField* ReqUpdateRiskUser = nullptr;
	};
	class StepRspUpdateRiskUserPackage : public StepPackageBase
	{
	public:
		StepRspUpdateRiskUserPackage();
		static StepRspUpdateRiskUserPackage* Allocate();
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
	class StepReqRemoveRiskUserPackage : public StepPackageBase
	{
	public:
		StepReqRemoveRiskUserPackage();
		static StepReqRemoveRiskUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400A;
		ReqRemoveRiskUserField* ReqRemoveRiskUser = nullptr;
	};
	class StepRspRemoveRiskUserPackage : public StepPackageBase
	{
	public:
		StepRspRemoveRiskUserPackage();
		static StepRspRemoveRiskUserPackage* Allocate();
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
	class StepReqAddAdminUserPackage : public StepPackageBase
	{
	public:
		StepReqAddAdminUserPackage();
		static StepReqAddAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400C;
		ReqAddAdminUserField* ReqAddAdminUser = nullptr;
	};
	class StepRspAddAdminUserPackage : public StepPackageBase
	{
	public:
		StepRspAddAdminUserPackage();
		static StepRspAddAdminUserPackage* Allocate();
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
	class StepReqUpdateAdminUserPackage : public StepPackageBase
	{
	public:
		StepReqUpdateAdminUserPackage();
		static StepReqUpdateAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400E;
		ReqUpdateAdminUserField* ReqUpdateAdminUser = nullptr;
	};
	class StepRspUpdateAdminUserPackage : public StepPackageBase
	{
	public:
		StepRspUpdateAdminUserPackage();
		static StepRspUpdateAdminUserPackage* Allocate();
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
	class StepReqRemoveAdminUserPackage : public StepPackageBase
	{
	public:
		StepReqRemoveAdminUserPackage();
		static StepReqRemoveAdminUserPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4010;
		ReqRemoveAdminUserField* ReqRemoveAdminUser = nullptr;
	};
	class StepRspRemoveAdminUserPackage : public StepPackageBase
	{
	public:
		StepRspRemoveAdminUserPackage();
		static StepRspRemoveAdminUserPackage* Allocate();
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
	class StepReqAddPrimaryAccountPackage : public StepPackageBase
	{
	public:
		StepReqAddPrimaryAccountPackage();
		static StepReqAddPrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4012;
		ReqAddPrimaryAccountField* ReqAddPrimaryAccount = nullptr;
	};
	class StepRspAddPrimaryAccountPackage : public StepPackageBase
	{
	public:
		StepRspAddPrimaryAccountPackage();
		static StepRspAddPrimaryAccountPackage* Allocate();
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
	class StepReqUpdatePrimaryAccountPackage : public StepPackageBase
	{
	public:
		StepReqUpdatePrimaryAccountPackage();
		static StepReqUpdatePrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4014;
		ReqUpdatePrimaryAccountField* ReqUpdatePrimaryAccount = nullptr;
	};
	class StepRspUpdatePrimaryAccountPackage : public StepPackageBase
	{
	public:
		StepRspUpdatePrimaryAccountPackage();
		static StepRspUpdatePrimaryAccountPackage* Allocate();
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
	class StepReqRemovePrimaryAccountPackage : public StepPackageBase
	{
	public:
		StepReqRemovePrimaryAccountPackage();
		static StepReqRemovePrimaryAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4016;
		ReqRemovePrimaryAccountField* ReqRemovePrimaryAccount = nullptr;
	};
	class StepRspRemovePrimaryAccountPackage : public StepPackageBase
	{
	public:
		StepRspRemovePrimaryAccountPackage();
		static StepRspRemovePrimaryAccountPackage* Allocate();
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
	class StepReqAddAccountPackage : public StepPackageBase
	{
	public:
		StepReqAddAccountPackage();
		static StepReqAddAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4018;
		ReqAddAccountField* ReqAddAccount = nullptr;
	};
	class StepRspAddAccountPackage : public StepPackageBase
	{
	public:
		StepRspAddAccountPackage();
		static StepRspAddAccountPackage* Allocate();
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
	class StepReqUpdateAccountPackage : public StepPackageBase
	{
	public:
		StepReqUpdateAccountPackage();
		static StepReqUpdateAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401A;
		ReqUpdateAccountField* ReqUpdateAccount = nullptr;
	};
	class StepRspUpdateAccountPackage : public StepPackageBase
	{
	public:
		StepRspUpdateAccountPackage();
		static StepRspUpdateAccountPackage* Allocate();
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
	class StepReqRemoveAccountPackage : public StepPackageBase
	{
	public:
		StepReqRemoveAccountPackage();
		static StepReqRemoveAccountPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401C;
		ReqRemoveAccountField* ReqRemoveAccount = nullptr;
	};
	class StepRspRemoveAccountPackage : public StepPackageBase
	{
	public:
		StepRspRemoveAccountPackage();
		static StepRspRemoveAccountPackage* Allocate();
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
	class StepReqAddBaseCommissionPackage : public StepPackageBase
	{
	public:
		StepReqAddBaseCommissionPackage();
		static StepReqAddBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x401E;
		ReqAddBaseCommissionField* ReqAddBaseCommission = nullptr;
	};
	class StepRspAddBaseCommissionPackage : public StepPackageBase
	{
	public:
		StepRspAddBaseCommissionPackage();
		static StepRspAddBaseCommissionPackage* Allocate();
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
	class StepReqUpdateBaseCommissionPackage : public StepPackageBase
	{
	public:
		StepReqUpdateBaseCommissionPackage();
		static StepReqUpdateBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4020;
		ReqUpdateBaseCommissionField* ReqUpdateBaseCommission = nullptr;
	};
	class StepRspUpdateBaseCommissionPackage : public StepPackageBase
	{
	public:
		StepRspUpdateBaseCommissionPackage();
		static StepRspUpdateBaseCommissionPackage* Allocate();
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
	class StepReqRemoveBaseCommissionPackage : public StepPackageBase
	{
	public:
		StepReqRemoveBaseCommissionPackage();
		static StepReqRemoveBaseCommissionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4022;
		ReqRemoveBaseCommissionField* ReqRemoveBaseCommission = nullptr;
	};
	class StepRspRemoveBaseCommissionPackage : public StepPackageBase
	{
	public:
		StepRspRemoveBaseCommissionPackage();
		static StepRspRemoveBaseCommissionPackage* Allocate();
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
	class StepReqAddCommissionGroupPackage : public StepPackageBase
	{
	public:
		StepReqAddCommissionGroupPackage();
		static StepReqAddCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4024;
		ReqAddCommissionGroupField* ReqAddCommissionGroup = nullptr;
	};
	class StepRspAddCommissionGroupPackage : public StepPackageBase
	{
	public:
		StepRspAddCommissionGroupPackage();
		static StepRspAddCommissionGroupPackage* Allocate();
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
	class StepReqUpdateCommissionGroupPackage : public StepPackageBase
	{
	public:
		StepReqUpdateCommissionGroupPackage();
		static StepReqUpdateCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4026;
		ReqUpdateCommissionGroupField* ReqUpdateCommissionGroup = nullptr;
	};
	class StepRspUpdateCommissionGroupPackage : public StepPackageBase
	{
	public:
		StepRspUpdateCommissionGroupPackage();
		static StepRspUpdateCommissionGroupPackage* Allocate();
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
	class StepReqRemoveCommissionGroupPackage : public StepPackageBase
	{
	public:
		StepReqRemoveCommissionGroupPackage();
		static StepReqRemoveCommissionGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4028;
		ReqRemoveCommissionGroupField* ReqRemoveCommissionGroup = nullptr;
	};
	class StepRspRemoveCommissionGroupPackage : public StepPackageBase
	{
	public:
		StepRspRemoveCommissionGroupPackage();
		static StepRspRemoveCommissionGroupPackage* Allocate();
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
	class StepReqAddOptionMarginParamPackage : public StepPackageBase
	{
	public:
		StepReqAddOptionMarginParamPackage();
		static StepReqAddOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402A;
		ReqAddOptionMarginParamField* ReqAddOptionMarginParam = nullptr;
	};
	class StepRspAddOptionMarginParamPackage : public StepPackageBase
	{
	public:
		StepRspAddOptionMarginParamPackage();
		static StepRspAddOptionMarginParamPackage* Allocate();
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
	class StepReqUpdateOptionMarginParamPackage : public StepPackageBase
	{
	public:
		StepReqUpdateOptionMarginParamPackage();
		static StepReqUpdateOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402C;
		ReqUpdateOptionMarginParamField* ReqUpdateOptionMarginParam = nullptr;
	};
	class StepRspUpdateOptionMarginParamPackage : public StepPackageBase
	{
	public:
		StepRspUpdateOptionMarginParamPackage();
		static StepRspUpdateOptionMarginParamPackage* Allocate();
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
	class StepReqRemoveOptionMarginParamPackage : public StepPackageBase
	{
	public:
		StepReqRemoveOptionMarginParamPackage();
		static StepReqRemoveOptionMarginParamPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x402E;
		ReqRemoveOptionMarginParamField* ReqRemoveOptionMarginParam = nullptr;
	};
	class StepRspRemoveOptionMarginParamPackage : public StepPackageBase
	{
	public:
		StepRspRemoveOptionMarginParamPackage();
		static StepRspRemoveOptionMarginParamPackage* Allocate();
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
	class StepReqAddTradeOfferPackage : public StepPackageBase
	{
	public:
		StepReqAddTradeOfferPackage();
		static StepReqAddTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4030;
		ReqAddTradeOfferField* ReqAddTradeOffer = nullptr;
	};
	class StepRspAddTradeOfferPackage : public StepPackageBase
	{
	public:
		StepRspAddTradeOfferPackage();
		static StepRspAddTradeOfferPackage* Allocate();
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
	class StepReqUpdateTradeOfferPackage : public StepPackageBase
	{
	public:
		StepReqUpdateTradeOfferPackage();
		static StepReqUpdateTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4032;
		ReqUpdateTradeOfferField* ReqUpdateTradeOffer = nullptr;
	};
	class StepRspUpdateTradeOfferPackage : public StepPackageBase
	{
	public:
		StepRspUpdateTradeOfferPackage();
		static StepRspUpdateTradeOfferPackage* Allocate();
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
	class StepReqRemoveTradeOfferPackage : public StepPackageBase
	{
	public:
		StepReqRemoveTradeOfferPackage();
		static StepReqRemoveTradeOfferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4034;
		ReqRemoveTradeOfferField* ReqRemoveTradeOffer = nullptr;
	};
	class StepRspRemoveTradeOfferPackage : public StepPackageBase
	{
	public:
		StepRspRemoveTradeOfferPackage();
		static StepRspRemoveTradeOfferPackage* Allocate();
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
	class StepReqAddTradeGroupPackage : public StepPackageBase
	{
	public:
		StepReqAddTradeGroupPackage();
		static StepReqAddTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4036;
		ReqAddTradeGroupField* ReqAddTradeGroup = nullptr;
	};
	class StepRspAddTradeGroupPackage : public StepPackageBase
	{
	public:
		StepRspAddTradeGroupPackage();
		static StepRspAddTradeGroupPackage* Allocate();
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
	class StepReqUpdateTradeGroupPackage : public StepPackageBase
	{
	public:
		StepReqUpdateTradeGroupPackage();
		static StepReqUpdateTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4038;
		ReqUpdateTradeGroupField* ReqUpdateTradeGroup = nullptr;
	};
	class StepRspUpdateTradeGroupPackage : public StepPackageBase
	{
	public:
		StepRspUpdateTradeGroupPackage();
		static StepRspUpdateTradeGroupPackage* Allocate();
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
	class StepReqRemoveTradeGroupPackage : public StepPackageBase
	{
	public:
		StepReqRemoveTradeGroupPackage();
		static StepReqRemoveTradeGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403A;
		ReqRemoveTradeGroupField* ReqRemoveTradeGroup = nullptr;
	};
	class StepRspRemoveTradeGroupPackage : public StepPackageBase
	{
	public:
		StepRspRemoveTradeGroupPackage();
		static StepRspRemoveTradeGroupPackage* Allocate();
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
	class StepReqAddTradeGroupItemPackage : public StepPackageBase
	{
	public:
		StepReqAddTradeGroupItemPackage();
		static StepReqAddTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403C;
		ReqAddTradeGroupItemField* ReqAddTradeGroupItem = nullptr;
	};
	class StepRspAddTradeGroupItemPackage : public StepPackageBase
	{
	public:
		StepRspAddTradeGroupItemPackage();
		static StepRspAddTradeGroupItemPackage* Allocate();
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
	class StepReqUpdateTradeGroupItemPackage : public StepPackageBase
	{
	public:
		StepReqUpdateTradeGroupItemPackage();
		static StepReqUpdateTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x403E;
		ReqUpdateTradeGroupItemField* ReqUpdateTradeGroupItem = nullptr;
	};
	class StepRspUpdateTradeGroupItemPackage : public StepPackageBase
	{
	public:
		StepRspUpdateTradeGroupItemPackage();
		static StepRspUpdateTradeGroupItemPackage* Allocate();
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
	class StepReqRemoveTradeGroupItemPackage : public StepPackageBase
	{
	public:
		StepReqRemoveTradeGroupItemPackage();
		static StepReqRemoveTradeGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4040;
		ReqRemoveTradeGroupItemField* ReqRemoveTradeGroupItem = nullptr;
	};
	class StepRspRemoveTradeGroupItemPackage : public StepPackageBase
	{
	public:
		StepRspRemoveTradeGroupItemPackage();
		static StepRspRemoveTradeGroupItemPackage* Allocate();
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
	class StepReqAddRiskGroupPackage : public StepPackageBase
	{
	public:
		StepReqAddRiskGroupPackage();
		static StepReqAddRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4042;
		ReqAddRiskGroupField* ReqAddRiskGroup = nullptr;
	};
	class StepRspAddRiskGroupPackage : public StepPackageBase
	{
	public:
		StepRspAddRiskGroupPackage();
		static StepRspAddRiskGroupPackage* Allocate();
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
	class StepReqUpdateRiskGroupPackage : public StepPackageBase
	{
	public:
		StepReqUpdateRiskGroupPackage();
		static StepReqUpdateRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4044;
		ReqUpdateRiskGroupField* ReqUpdateRiskGroup = nullptr;
	};
	class StepRspUpdateRiskGroupPackage : public StepPackageBase
	{
	public:
		StepRspUpdateRiskGroupPackage();
		static StepRspUpdateRiskGroupPackage* Allocate();
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
	class StepReqRemoveRiskGroupPackage : public StepPackageBase
	{
	public:
		StepReqRemoveRiskGroupPackage();
		static StepReqRemoveRiskGroupPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4046;
		ReqRemoveRiskGroupField* ReqRemoveRiskGroup = nullptr;
	};
	class StepRspRemoveRiskGroupPackage : public StepPackageBase
	{
	public:
		StepRspRemoveRiskGroupPackage();
		static StepRspRemoveRiskGroupPackage* Allocate();
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
	class StepReqAddRiskGroupItemPackage : public StepPackageBase
	{
	public:
		StepReqAddRiskGroupItemPackage();
		static StepReqAddRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4048;
		ReqAddRiskGroupItemField* ReqAddRiskGroupItem = nullptr;
	};
	class StepRspAddRiskGroupItemPackage : public StepPackageBase
	{
	public:
		StepRspAddRiskGroupItemPackage();
		static StepRspAddRiskGroupItemPackage* Allocate();
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
	class StepReqUpdateRiskGroupItemPackage : public StepPackageBase
	{
	public:
		StepReqUpdateRiskGroupItemPackage();
		static StepReqUpdateRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404A;
		ReqUpdateRiskGroupItemField* ReqUpdateRiskGroupItem = nullptr;
	};
	class StepRspUpdateRiskGroupItemPackage : public StepPackageBase
	{
	public:
		StepRspUpdateRiskGroupItemPackage();
		static StepRspUpdateRiskGroupItemPackage* Allocate();
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
	class StepReqRemoveRiskGroupItemPackage : public StepPackageBase
	{
	public:
		StepReqRemoveRiskGroupItemPackage();
		static StepReqRemoveRiskGroupItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404C;
		ReqRemoveRiskGroupItemField* ReqRemoveRiskGroupItem = nullptr;
	};
	class StepRspRemoveRiskGroupItemPackage : public StepPackageBase
	{
	public:
		StepRspRemoveRiskGroupItemPackage();
		static StepRspRemoveRiskGroupItemPackage* Allocate();
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
	class StepReqAddOrUpdateRiskPackage : public StepPackageBase
	{
	public:
		StepReqAddOrUpdateRiskPackage();
		static StepReqAddOrUpdateRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x404E;
		ReqAddOrUpdateRiskField* ReqAddOrUpdateRisk = nullptr;
	};
	class StepRspAddOrUpdateRiskPackage : public StepPackageBase
	{
	public:
		StepRspAddOrUpdateRiskPackage();
		static StepRspAddOrUpdateRiskPackage* Allocate();
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
	class StepReqRemoveRiskPackage : public StepPackageBase
	{
	public:
		StepReqRemoveRiskPackage();
		static StepReqRemoveRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4050;
		ReqRemoveRiskField* ReqRemoveRisk = nullptr;
	};
	class StepRspRemoveRiskPackage : public StepPackageBase
	{
	public:
		StepRspRemoveRiskPackage();
		static StepRspRemoveRiskPackage* Allocate();
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
	class StepReqAddRiskRulePackage : public StepPackageBase
	{
	public:
		StepReqAddRiskRulePackage();
		static StepReqAddRiskRulePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4052;
		ReqAddRiskRuleField* ReqAddRiskRule = nullptr;
	};
	class StepRspAddRiskRulePackage : public StepPackageBase
	{
	public:
		StepRspAddRiskRulePackage();
		static StepRspAddRiskRulePackage* Allocate();
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
	class StepReqAddRiskRuleItemPackage : public StepPackageBase
	{
	public:
		StepReqAddRiskRuleItemPackage();
		static StepReqAddRiskRuleItemPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4054;
		ReqAddRiskRuleItemField* ReqAddRiskRuleItem = nullptr;
	};
	class StepRspAddRiskRuleItemPackage : public StepPackageBase
	{
	public:
		StepRspAddRiskRuleItemPackage();
		static StepRspAddRiskRuleItemPackage* Allocate();
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
	class StepReqAddRiskTradeScopePackage : public StepPackageBase
	{
	public:
		StepReqAddRiskTradeScopePackage();
		static StepReqAddRiskTradeScopePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4056;
		ReqAddRiskTradeScopeField* ReqAddRiskTradeScope = nullptr;
	};
	class StepRspAddRiskTradeScopePackage : public StepPackageBase
	{
	public:
		StepRspAddRiskTradeScopePackage();
		static StepRspAddRiskTradeScopePackage* Allocate();
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
	class StepReqAddAccountRiskPackage : public StepPackageBase
	{
	public:
		StepReqAddAccountRiskPackage();
		static StepReqAddAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4058;
		ReqAddAccountRiskField* ReqAddAccountRisk = nullptr;
	};
	class StepRspAddAccountRiskPackage : public StepPackageBase
	{
	public:
		StepRspAddAccountRiskPackage();
		static StepRspAddAccountRiskPackage* Allocate();
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
	class StepReqRemoveAccountRiskPackage : public StepPackageBase
	{
	public:
		StepReqRemoveAccountRiskPackage();
		static StepReqRemoveAccountRiskPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405A;
		ReqRemoveAccountRiskField* ReqRemoveAccountRisk = nullptr;
	};
	class StepRspRemoveAccountRiskPackage : public StepPackageBase
	{
	public:
		StepRspRemoveAccountRiskPackage();
		static StepRspRemoveAccountRiskPackage* Allocate();
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
	class StepReqMoneyTransferPackage : public StepPackageBase
	{
	public:
		StepReqMoneyTransferPackage();
		static StepReqMoneyTransferPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405C;
		ReqMoneyTransferField* ReqMoneyTransfer = nullptr;
	};
	class StepRspMoneyTransferPackage : public StepPackageBase
	{
	public:
		StepRspMoneyTransferPackage();
		static StepRspMoneyTransferPackage* Allocate();
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
	class StepReqAuditOrderPackage : public StepPackageBase
	{
	public:
		StepReqAuditOrderPackage();
		static StepReqAuditOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x405E;
		ReqAuditOrderField* ReqAuditOrder = nullptr;
	};
	class StepRspAuditOrderPackage : public StepPackageBase
	{
	public:
		StepRspAuditOrderPackage();
		static StepRspAuditOrderPackage* Allocate();
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
	class StepReqOfferLoginPackage : public StepPackageBase
	{
	public:
		StepReqOfferLoginPackage();
		static StepReqOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5001;
		ReqOfferLoginField* ReqOfferLogin = nullptr;
	};
	class StepRspOfferLoginPackage : public StepPackageBase
	{
	public:
		StepRspOfferLoginPackage();
		static StepRspOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5002;
		RspOfferLoginField* RspOfferLogin = nullptr;
	};
	class StepReqPrimaryAccountLoginPackage : public StepPackageBase
	{
	public:
		StepReqPrimaryAccountLoginPackage();
		static StepReqPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5003;
		ReqPrimaryAccountLoginField* ReqPrimaryAccountLogin = nullptr;
	};
	class StepRspPrimaryAccountLoginPackage : public StepPackageBase
	{
	public:
		StepRspPrimaryAccountLoginPackage();
		static StepRspPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5004;
		RspPrimaryAccountLoginField* RspPrimaryAccountLogin = nullptr;
	};
	class StepReqPrimaryAccountLogoutPackage : public StepPackageBase
	{
	public:
		StepReqPrimaryAccountLogoutPackage();
		static StepReqPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5005;
		ReqPrimaryAccountLogoutField* ReqPrimaryAccountLogout = nullptr;
	};
	class StepRtnPrimaryAccountLogoutPackage : public StepPackageBase
	{
	public:
		StepRtnPrimaryAccountLogoutPackage();
		static StepRtnPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5006;
		RtnPrimaryAccountLogoutField* RtnPrimaryAccountLogout = nullptr;
	};
	class StepReqPrimaryAccountInitPackage : public StepPackageBase
	{
	public:
		StepReqPrimaryAccountInitPackage();
		static StepReqPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5007;
		ReqPrimaryAccountInitField* ReqPrimaryAccountInit = nullptr;
	};
	class StepRspPrimaryAccountInitPackage : public StepPackageBase
	{
	public:
		StepRspPrimaryAccountInitPackage();
		static StepRspPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5008;
		RspPrimaryAccountInitField* RspPrimaryAccountInit = nullptr;
	};
	class StepReqPrimaryAccountQueryPackage : public StepPackageBase
	{
	public:
		StepReqPrimaryAccountQueryPackage();
		static StepReqPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5009;
		ReqPrimaryAccountQueryField* ReqPrimaryAccountQuery = nullptr;
	};
	class StepRspPrimaryAccountQueryPackage : public StepPackageBase
	{
	public:
		StepRspPrimaryAccountQueryPackage();
		static StepRspPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500A;
		RspPrimaryAccountQueryField* RspPrimaryAccountQuery = nullptr;
	};
	class StepReqQryOfferOptionInstrumentPackage : public StepPackageBase
	{
	public:
		StepReqQryOfferOptionInstrumentPackage();
		static StepReqQryOfferOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500B;
		ReqQryOfferOptionInstrumentField* ReqQryOfferOptionInstrument = nullptr;
	};
	class StepRspQryOfferOptionInstrumentPackage : public StepPackageBase
	{
	public:
		StepRspQryOfferOptionInstrumentPackage();
		static StepRspQryOfferOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500C;
		RspQryOfferOptionInstrumentField* RspQryOfferOptionInstrument = nullptr;
	};
	class StepRtnOfferOptionInstrumentPackage : public StepPackageBase
	{
	public:
		StepRtnOfferOptionInstrumentPackage();
		static StepRtnOfferOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500D;
		OfferOptionInstrumentField* OfferOptionInstrument = nullptr;
	};
	class StepReqOfferOrderPackage : public StepPackageBase
	{
	public:
		StepReqOfferOrderPackage();
		static StepReqOfferOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500E;
		ReqOfferOrderField* ReqOfferOrder = nullptr;
	};
	class StepReqOfferCancelOrderPackage : public StepPackageBase
	{
	public:
		StepReqOfferCancelOrderPackage();
		static StepReqOfferCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x500F;
		ReqOfferCancelOrderField* ReqOfferCancelOrder = nullptr;
	};
	class StepRtnOfferOrderPackage : public StepPackageBase
	{
	public:
		StepRtnOfferOrderPackage();
		static StepRtnOfferOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5010;
		OfferOrderField* OfferOrder = nullptr;
	};
	class StepRtnOfferTradePackage : public StepPackageBase
	{
	public:
		StepRtnOfferTradePackage();
		static StepRtnOfferTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5011;
		OfferTradeField* OfferTrade = nullptr;
	};
	class StepRtnOfferErrorCancelOrderPackage : public StepPackageBase
	{
	public:
		StepRtnOfferErrorCancelOrderPackage();
		static StepRtnOfferErrorCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5012;
		OfferErrorCancelOrderField* OfferErrorCancelOrder = nullptr;
	};
	class StepRtnOfferCapitalPackage : public StepPackageBase
	{
	public:
		StepRtnOfferCapitalPackage();
		static StepRtnOfferCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5013;
		OfferCapitalField* OfferCapital = nullptr;
	};
	class StepRtnOfferPositionPackage : public StepPackageBase
	{
	public:
		StepRtnOfferPositionPackage();
		static StepRtnOfferPositionPackage* Allocate();
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