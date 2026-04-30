#pragma once
#include "Fields.h"
#include "Package/Package.h"


class NotifyComponentConnectStatusPackage : public Package
{
public:
	static NotifyComponentConnectStatusPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x0001;
	NotifyComponentConnectStatusField* NotifyComponentConnectStatus = nullptr;
};
class ReqAccountLoginPackage : public Package
{
public:
	static ReqAccountLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1001;
	ReqAccountLoginField* ReqAccountLogin = nullptr;
};
class RspAccountLoginPackage : public Package
{
public:
	static RspAccountLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1002;
	RspAccountLoginField* RspAccountLogin = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAccountLogoutPackage : public Package
{
public:
	static ReqAccountLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1003;
	ReqAccountLogoutField* ReqAccountLogout = nullptr;
};
class RspAccountLogoutPackage : public Package
{
public:
	static RspAccountLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1004;
	RspAccountLogoutField* RspAccountLogout = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryAccountPackage : public Package
{
public:
	static ReqQryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1005;
	ReqQryAccountField* ReqQryAccount = nullptr;
};
class RspQryAccountPackage : public Package
{
public:
	static RspQryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1006;
	AccountField* Account = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryHolderAccountPackage : public Package
{
public:
	static ReqQryHolderAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1007;
	ReqQryHolderAccountField* ReqQryHolderAccount = nullptr;
};
class RspQryHolderAccountPackage : public Package
{
public:
	static RspQryHolderAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1008;
	HolderAccountField* HolderAccount = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryCapitalPackage : public Package
{
public:
	static ReqQryCapitalPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1009;
	ReqQryCapitalField* ReqQryCapital = nullptr;
};
class RspQryCapitalPackage : public Package
{
public:
	static RspQryCapitalPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x100A;
	CapitalField* Capital = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryPositionPackage : public Package
{
public:
	static ReqQryPositionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x100B;
	ReqQryPositionField* ReqQryPosition = nullptr;
};
class RspQryPositionPackage : public Package
{
public:
	static RspQryPositionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x100C;
	PositionField* Position = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryOrderPackage : public Package
{
public:
	static ReqQryOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x100D;
	ReqQryOrderField* ReqQryOrder = nullptr;
};
class RspQryOrderPackage : public Package
{
public:
	static RspQryOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x100E;
	OrderField* Order = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryTradePackage : public Package
{
public:
	static ReqQryTradePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x100F;
	ReqQryTradeField* ReqQryTrade = nullptr;
};
class RspQryTradePackage : public Package
{
public:
	static RspQryTradePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1010;
	TradeField* Trade = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryInstrumentPackage : public Package
{
public:
	static ReqQryInstrumentPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1011;
	ReqQryInstrumentField* ReqQryInstrument = nullptr;
};
class RspQryInstrumentPackage : public Package
{
public:
	static RspQryInstrumentPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1012;
	InstrumentField* Instrument = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryOptionInstrumentPackage : public Package
{
public:
	static ReqQryOptionInstrumentPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1013;
	ReqQryOptionInstrumentField* ReqQryOptionInstrument = nullptr;
};
class RspQryOptionInstrumentPackage : public Package
{
public:
	static RspQryOptionInstrumentPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1014;
	OptionInstrumentField* OptionInstrument = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryCommissionRatePackage : public Package
{
public:
	static ReqQryCommissionRatePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1015;
	ReqQryCommissionRateField* ReqQryCommissionRate = nullptr;
};
class RspQryCommissionRatePackage : public Package
{
public:
	static RspQryCommissionRatePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1016;
	CommissionRateField* CommissionRate = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryMoneyTransferPackage : public Package
{
public:
	static ReqQryMoneyTransferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1017;
	ReqQryMoneyTransferField* ReqQryMoneyTransfer = nullptr;
};
class RspQryMoneyTransferPackage : public Package
{
public:
	static RspQryMoneyTransferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1018;
	MoneyTransferField* MoneyTransfer = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqInsertOrderPackage : public Package
{
public:
	static ReqInsertOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1019;
	ReqInsertOrderField* ReqInsertOrder = nullptr;
};
class RspInsertOrderPackage : public Package
{
public:
	static RspInsertOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x101A;
	OrderField* Order = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqCancelOrderPackage : public Package
{
public:
	static ReqCancelOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x101B;
	ReqCancelOrderField* ReqCancelOrder = nullptr;
};
class RspCancelOrderPackage : public Package
{
public:
	static RspCancelOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x101C;
	CancelOrderField* CancelOrder = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class RtnOrderPackage : public Package
{
public:
	static RtnOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x101D;
	OrderField* Order = nullptr;
};
class RtnTradePackage : public Package
{
public:
	static RtnTradePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x101E;
	TradeField* Trade = nullptr;
};
class RtnMoneyTransferPackage : public Package
{
public:
	static RtnMoneyTransferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x101F;
	MoneyTransferField* MoneyTransfer = nullptr;
};
class RtnAccountLogoutPackage : public Package
{
public:
	static RtnAccountLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x1020;
	AccountLogoutField* AccountLogout = nullptr;
};
class ReqRiskUserLoginPackage : public Package
{
public:
	static ReqRiskUserLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2001;
	ReqRiskUserLoginField* ReqRiskUserLogin = nullptr;
};
class RspRiskUserLoginPackage : public Package
{
public:
	static RspRiskUserLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2002;
	RspRiskUserLoginField* RspRiskUserLogin = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRiskUserLogoutPackage : public Package
{
public:
	static ReqRiskUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2003;
	ReqRiskUserLogoutField* ReqRiskUserLogout = nullptr;
};
class RspRiskUserLogoutPackage : public Package
{
public:
	static RspRiskUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2004;
	RspRiskUserLogoutField* RspRiskUserLogout = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class RtnRiskUserLogoutPackage : public Package
{
public:
	static RtnRiskUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2005;
	RiskUserLogoutField* RiskUserLogout = nullptr;
};
class RtnAccountPackage : public Package
{
public:
	static RtnAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2006;
	AccountField* Account = nullptr;
};
class RtnAccountDeletePackage : public Package
{
public:
	static RtnAccountDeletePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2007;
	AccountDeleteField* AccountDelete = nullptr;
};
class RtnPositionPackage : public Package
{
public:
	static RtnPositionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2008;
	PositionField* Position = nullptr;
};
class RtnAccountRiskPackage : public Package
{
public:
	static RtnAccountRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2009;
	AccountRiskField* AccountRisk = nullptr;
};
class RtnAccountRiskDeletePackage : public Package
{
public:
	static RtnAccountRiskDeletePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x200A;
	AccountRiskDeleteField* AccountRiskDelete = nullptr;
};
class RtnAccountRiskNotifyPackage : public Package
{
public:
	static RtnAccountRiskNotifyPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x200B;
	AccountRiskNotifyField* AccountRiskNotify = nullptr;
};
class ReqQryRiskGroupAccountPackage : public Package
{
public:
	static ReqQryRiskGroupAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x200C;
	ReqQryRiskGroupAccountField* ReqQryRiskGroupAccount = nullptr;
};
class RspQryRiskGroupAccountPackage : public Package
{
public:
	static RspQryRiskGroupAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x200D;
	AccountField* Account = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryRiskGroupCapitalPackage : public Package
{
public:
	static ReqQryRiskGroupCapitalPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x200E;
	ReqQryRiskGroupCapitalField* ReqQryRiskGroupCapital = nullptr;
};
class RspQryRiskGroupCapitalPackage : public Package
{
public:
	static RspQryRiskGroupCapitalPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x200F;
	CapitalField* Capital = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryRiskGroupPositionPackage : public Package
{
public:
	static ReqQryRiskGroupPositionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2010;
	ReqQryRiskGroupPositionField* ReqQryRiskGroupPosition = nullptr;
};
class RspQryRiskGroupPositionPackage : public Package
{
public:
	static RspQryRiskGroupPositionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2011;
	PositionField* Position = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryRiskGroupOrderPackage : public Package
{
public:
	static ReqQryRiskGroupOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2012;
	ReqQryRiskGroupOrderField* ReqQryRiskGroupOrder = nullptr;
};
class RspQryRiskGroupOrderPackage : public Package
{
public:
	static RspQryRiskGroupOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2013;
	OrderField* Order = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryRiskGroupTradePackage : public Package
{
public:
	static ReqQryRiskGroupTradePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2014;
	ReqQryRiskGroupTradeField* ReqQryRiskGroupTrade = nullptr;
};
class RspQryRiskGroupTradePackage : public Package
{
public:
	static RspQryRiskGroupTradePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2015;
	TradeField* Trade = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryRiskGroupAccountRiskPackage : public Package
{
public:
	static ReqQryRiskGroupAccountRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2016;
	ReqQryRiskGroupAccountRiskField* ReqQryRiskGroupAccountRisk = nullptr;
};
class RspQryRiskGroupAccountRiskPackage : public Package
{
public:
	static RspQryRiskGroupAccountRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2017;
	AccountRiskField* AccountRisk = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqQryRiskGroupAccountRiskNotifyPackage : public Package
{
public:
	static ReqQryRiskGroupAccountRiskNotifyPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2018;
	ReqQryRiskGroupAccountRiskNotifyField* ReqQryRiskGroupAccountRiskNotify = nullptr;
};
class RspQryRiskGroupAccountRiskNotifyPackage : public Package
{
public:
	static RspQryRiskGroupAccountRiskNotifyPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x2019;
	AccountRiskNotifyField* AccountRiskNotify = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRiskInsertOrderPackage : public Package
{
public:
	static ReqRiskInsertOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x201A;
	ReqRiskInsertOrderField* ReqRiskInsertOrder = nullptr;
};
class RspRiskInsertOrderPackage : public Package
{
public:
	static RspRiskInsertOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x201B;
	OrderField* Order = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRiskCancelOrderPackage : public Package
{
public:
	static ReqRiskCancelOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x201C;
	ReqRiskCancelOrderField* ReqRiskCancelOrder = nullptr;
};
class RspRiskCancelOrderPackage : public Package
{
public:
	static RspRiskCancelOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x201D;
	CancelOrderField* CancelOrder = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqMdUserLoginPackage : public Package
{
public:
	static ReqMdUserLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3001;
	ReqMdUserLoginField* ReqMdUserLogin = nullptr;
};
class RspMdUserLoginPackage : public Package
{
public:
	static RspMdUserLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3002;
	RspMdUserLoginField* RspMdUserLogin = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqMdUserLogoutPackage : public Package
{
public:
	static ReqMdUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3003;
	ReqMdUserLogoutField* ReqMdUserLogout = nullptr;
};
class RspMdUserLogoutPackage : public Package
{
public:
	static RspMdUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3004;
	RspMdUserLogoutField* RspMdUserLogout = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqMdInitPackage : public Package
{
public:
	static ReqMdInitPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3005;
	ReqMdInitField* ReqMdInit = nullptr;
};
class RspMdInitPackage : public Package
{
public:
	static RspMdInitPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3006;
	RspMdInitField* RspMdInit = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqSubscribeMdPackage : public Package
{
public:
	static ReqSubscribeMdPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3007;
	ReqSubscribeMdField* ReqSubscribeMd = nullptr;
};
class RspSubscribeMdPackage : public Package
{
public:
	static RspSubscribeMdPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3008;
	RspSubscribeMdField* RspSubscribeMd = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class RtnShortMdPackage : public Package
{
public:
	static RtnShortMdPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x3009;
	ShortMdField* ShortMd = nullptr;
};
class RtnExchangeStatusPackage : public Package
{
public:
	static RtnExchangeStatusPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x300A;
	RtnExchangeStatusField* RtnExchangeStatus = nullptr;
};
class RtnMdInitCompletedPackage : public Package
{
public:
	static RtnMdInitCompletedPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x300B;
	MdInitCompletedField* MdInitCompleted = nullptr;
};
class ReqAdminUserLoginPackage : public Package
{
public:
	static ReqAdminUserLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4001;
	ReqAdminUserLoginField* ReqAdminUserLogin = nullptr;
};
class RspAdminUserLoginPackage : public Package
{
public:
	static RspAdminUserLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4002;
	RspAdminUserLoginField* RspAdminUserLogin = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAdminUserLogoutPackage : public Package
{
public:
	static ReqAdminUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4003;
	ReqAdminUserLogoutField* ReqAdminUserLogout = nullptr;
};
class RspAdminUserLogoutPackage : public Package
{
public:
	static RspAdminUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4004;
	RspAdminUserLogoutField* RspAdminUserLogout = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class RtnAdminUserLogoutPackage : public Package
{
public:
	static RtnAdminUserLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4005;
	AdminUserLogoutField* AdminUserLogout = nullptr;
};
class ReqAddRiskUserPackage : public Package
{
public:
	static ReqAddRiskUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4006;
	ReqAddRiskUserField* ReqAddRiskUser = nullptr;
};
class RspAddRiskUserPackage : public Package
{
public:
	static RspAddRiskUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4007;
	RspAddRiskUserField* RspAddRiskUser = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateRiskUserPackage : public Package
{
public:
	static ReqUpdateRiskUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4008;
	ReqUpdateRiskUserField* ReqUpdateRiskUser = nullptr;
};
class RspUpdateRiskUserPackage : public Package
{
public:
	static RspUpdateRiskUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4009;
	RspUpdateRiskUserField* RspUpdateRiskUser = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveRiskUserPackage : public Package
{
public:
	static ReqRemoveRiskUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x400A;
	ReqRemoveRiskUserField* ReqRemoveRiskUser = nullptr;
};
class RspRemoveRiskUserPackage : public Package
{
public:
	static RspRemoveRiskUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x400B;
	RspRemoveRiskUserField* RspRemoveRiskUser = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddAdminUserPackage : public Package
{
public:
	static ReqAddAdminUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x400C;
	ReqAddAdminUserField* ReqAddAdminUser = nullptr;
};
class RspAddAdminUserPackage : public Package
{
public:
	static RspAddAdminUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x400D;
	RspAddAdminUserField* RspAddAdminUser = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateAdminUserPackage : public Package
{
public:
	static ReqUpdateAdminUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x400E;
	ReqUpdateAdminUserField* ReqUpdateAdminUser = nullptr;
};
class RspUpdateAdminUserPackage : public Package
{
public:
	static RspUpdateAdminUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x400F;
	RspUpdateAdminUserField* RspUpdateAdminUser = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveAdminUserPackage : public Package
{
public:
	static ReqRemoveAdminUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4010;
	ReqRemoveAdminUserField* ReqRemoveAdminUser = nullptr;
};
class RspRemoveAdminUserPackage : public Package
{
public:
	static RspRemoveAdminUserPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4011;
	RspRemoveAdminUserField* RspRemoveAdminUser = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddPrimaryAccountPackage : public Package
{
public:
	static ReqAddPrimaryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4012;
	ReqAddPrimaryAccountField* ReqAddPrimaryAccount = nullptr;
};
class RspAddPrimaryAccountPackage : public Package
{
public:
	static RspAddPrimaryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4013;
	RspAddPrimaryAccountField* RspAddPrimaryAccount = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdatePrimaryAccountPackage : public Package
{
public:
	static ReqUpdatePrimaryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4014;
	ReqUpdatePrimaryAccountField* ReqUpdatePrimaryAccount = nullptr;
};
class RspUpdatePrimaryAccountPackage : public Package
{
public:
	static RspUpdatePrimaryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4015;
	RspUpdatePrimaryAccountField* RspUpdatePrimaryAccount = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemovePrimaryAccountPackage : public Package
{
public:
	static ReqRemovePrimaryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4016;
	ReqRemovePrimaryAccountField* ReqRemovePrimaryAccount = nullptr;
};
class RspRemovePrimaryAccountPackage : public Package
{
public:
	static RspRemovePrimaryAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4017;
	RspRemovePrimaryAccountField* RspRemovePrimaryAccount = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddAccountPackage : public Package
{
public:
	static ReqAddAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4018;
	ReqAddAccountField* ReqAddAccount = nullptr;
};
class RspAddAccountPackage : public Package
{
public:
	static RspAddAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4019;
	RspAddAccountField* RspAddAccount = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateAccountPackage : public Package
{
public:
	static ReqUpdateAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x401A;
	ReqUpdateAccountField* ReqUpdateAccount = nullptr;
};
class RspUpdateAccountPackage : public Package
{
public:
	static RspUpdateAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x401B;
	RspUpdateAccountField* RspUpdateAccount = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveAccountPackage : public Package
{
public:
	static ReqRemoveAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x401C;
	ReqRemoveAccountField* ReqRemoveAccount = nullptr;
};
class RspRemoveAccountPackage : public Package
{
public:
	static RspRemoveAccountPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x401D;
	RspRemoveAccountField* RspRemoveAccount = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddBaseCommissionPackage : public Package
{
public:
	static ReqAddBaseCommissionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x401E;
	ReqAddBaseCommissionField* ReqAddBaseCommission = nullptr;
};
class RspAddBaseCommissionPackage : public Package
{
public:
	static RspAddBaseCommissionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x401F;
	RspAddBaseCommissionField* RspAddBaseCommission = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateBaseCommissionPackage : public Package
{
public:
	static ReqUpdateBaseCommissionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4020;
	ReqUpdateBaseCommissionField* ReqUpdateBaseCommission = nullptr;
};
class RspUpdateBaseCommissionPackage : public Package
{
public:
	static RspUpdateBaseCommissionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4021;
	RspUpdateBaseCommissionField* RspUpdateBaseCommission = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveBaseCommissionPackage : public Package
{
public:
	static ReqRemoveBaseCommissionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4022;
	ReqRemoveBaseCommissionField* ReqRemoveBaseCommission = nullptr;
};
class RspRemoveBaseCommissionPackage : public Package
{
public:
	static RspRemoveBaseCommissionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4023;
	RspInfoField* RspInfo = nullptr;
	RspRemoveBaseCommissionField* RspRemoveBaseCommission = nullptr;
};
class ReqAddCommissionGroupPackage : public Package
{
public:
	static ReqAddCommissionGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4024;
	ReqAddCommissionGroupField* ReqAddCommissionGroup = nullptr;
};
class RspAddCommissionGroupPackage : public Package
{
public:
	static RspAddCommissionGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4025;
	RspAddCommissionGroupField* RspAddCommissionGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateCommissionGroupPackage : public Package
{
public:
	static ReqUpdateCommissionGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4026;
	ReqUpdateCommissionGroupField* ReqUpdateCommissionGroup = nullptr;
};
class RspUpdateCommissionGroupPackage : public Package
{
public:
	static RspUpdateCommissionGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4027;
	RspUpdateCommissionGroupField* RspUpdateCommissionGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveCommissionGroupPackage : public Package
{
public:
	static ReqRemoveCommissionGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4028;
	ReqRemoveCommissionGroupField* ReqRemoveCommissionGroup = nullptr;
};
class RspRemoveCommissionGroupPackage : public Package
{
public:
	static RspRemoveCommissionGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4029;
	RspRemoveCommissionGroupField* RspRemoveCommissionGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddOptionMarginParamPackage : public Package
{
public:
	static ReqAddOptionMarginParamPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x402A;
	ReqAddOptionMarginParamField* ReqAddOptionMarginParam = nullptr;
};
class RspAddOptionMarginParamPackage : public Package
{
public:
	static RspAddOptionMarginParamPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x402B;
	RspAddOptionMarginParamField* RspAddOptionMarginParam = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateOptionMarginParamPackage : public Package
{
public:
	static ReqUpdateOptionMarginParamPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x402C;
	ReqUpdateOptionMarginParamField* ReqUpdateOptionMarginParam = nullptr;
};
class RspUpdateOptionMarginParamPackage : public Package
{
public:
	static RspUpdateOptionMarginParamPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x402D;
	RspUpdateOptionMarginParamField* RspUpdateOptionMarginParam = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveOptionMarginParamPackage : public Package
{
public:
	static ReqRemoveOptionMarginParamPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x402E;
	ReqRemoveOptionMarginParamField* ReqRemoveOptionMarginParam = nullptr;
};
class RspRemoveOptionMarginParamPackage : public Package
{
public:
	static RspRemoveOptionMarginParamPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x402F;
	RspRemoveOptionMarginParamField* RspRemoveOptionMarginParam = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddTradeOfferPackage : public Package
{
public:
	static ReqAddTradeOfferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4030;
	ReqAddTradeOfferField* ReqAddTradeOffer = nullptr;
};
class RspAddTradeOfferPackage : public Package
{
public:
	static RspAddTradeOfferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4031;
	RspAddTradeOfferField* RspAddTradeOffer = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateTradeOfferPackage : public Package
{
public:
	static ReqUpdateTradeOfferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4032;
	ReqUpdateTradeOfferField* ReqUpdateTradeOffer = nullptr;
};
class RspUpdateTradeOfferPackage : public Package
{
public:
	static RspUpdateTradeOfferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4033;
	RspUpdateTradeOfferField* RspUpdateTradeOffer = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveTradeOfferPackage : public Package
{
public:
	static ReqRemoveTradeOfferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4034;
	ReqRemoveTradeOfferField* ReqRemoveTradeOffer = nullptr;
};
class RspRemoveTradeOfferPackage : public Package
{
public:
	static RspRemoveTradeOfferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4035;
	RspRemoveTradeOfferField* RspRemoveTradeOffer = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddTradeGroupPackage : public Package
{
public:
	static ReqAddTradeGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4036;
	ReqAddTradeGroupField* ReqAddTradeGroup = nullptr;
};
class RspAddTradeGroupPackage : public Package
{
public:
	static RspAddTradeGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4037;
	RspAddTradeGroupField* RspAddTradeGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateTradeGroupPackage : public Package
{
public:
	static ReqUpdateTradeGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4038;
	ReqUpdateTradeGroupField* ReqUpdateTradeGroup = nullptr;
};
class RspUpdateTradeGroupPackage : public Package
{
public:
	static RspUpdateTradeGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4039;
	RspUpdateTradeGroupField* RspUpdateTradeGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveTradeGroupPackage : public Package
{
public:
	static ReqRemoveTradeGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x403A;
	ReqRemoveTradeGroupField* ReqRemoveTradeGroup = nullptr;
};
class RspRemoveTradeGroupPackage : public Package
{
public:
	static RspRemoveTradeGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x403B;
	RspRemoveTradeGroupField* RspRemoveTradeGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddTradeGroupItemPackage : public Package
{
public:
	static ReqAddTradeGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x403C;
	ReqAddTradeGroupItemField* ReqAddTradeGroupItem = nullptr;
};
class RspAddTradeGroupItemPackage : public Package
{
public:
	static RspAddTradeGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x403D;
	RspAddTradeGroupItemField* RspAddTradeGroupItem = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateTradeGroupItemPackage : public Package
{
public:
	static ReqUpdateTradeGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x403E;
	ReqUpdateTradeGroupItemField* ReqUpdateTradeGroupItem = nullptr;
};
class RspUpdateTradeGroupItemPackage : public Package
{
public:
	static RspUpdateTradeGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x403F;
	RspUpdateTradeGroupItemField* RspUpdateTradeGroupItem = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveTradeGroupItemPackage : public Package
{
public:
	static ReqRemoveTradeGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4040;
	ReqRemoveTradeGroupItemField* ReqRemoveTradeGroupItem = nullptr;
};
class RspRemoveTradeGroupItemPackage : public Package
{
public:
	static RspRemoveTradeGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4041;
	RspRemoveTradeGroupItemField* RspRemoveTradeGroupItem = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddRiskGroupPackage : public Package
{
public:
	static ReqAddRiskGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4042;
	ReqAddRiskGroupField* ReqAddRiskGroup = nullptr;
};
class RspAddRiskGroupPackage : public Package
{
public:
	static RspAddRiskGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4043;
	RspAddRiskGroupField* RspAddRiskGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateRiskGroupPackage : public Package
{
public:
	static ReqUpdateRiskGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4044;
	ReqUpdateRiskGroupField* ReqUpdateRiskGroup = nullptr;
};
class RspUpdateRiskGroupPackage : public Package
{
public:
	static RspUpdateRiskGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4045;
	RspUpdateRiskGroupField* RspUpdateRiskGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveRiskGroupPackage : public Package
{
public:
	static ReqRemoveRiskGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4046;
	ReqRemoveRiskGroupField* ReqRemoveRiskGroup = nullptr;
};
class RspRemoveRiskGroupPackage : public Package
{
public:
	static RspRemoveRiskGroupPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4047;
	RspRemoveRiskGroupField* RspRemoveRiskGroup = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddRiskGroupItemPackage : public Package
{
public:
	static ReqAddRiskGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4048;
	ReqAddRiskGroupItemField* ReqAddRiskGroupItem = nullptr;
};
class RspAddRiskGroupItemPackage : public Package
{
public:
	static RspAddRiskGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4049;
	RspAddRiskGroupItemField* RspAddRiskGroupItem = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqUpdateRiskGroupItemPackage : public Package
{
public:
	static ReqUpdateRiskGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x404A;
	ReqUpdateRiskGroupItemField* ReqUpdateRiskGroupItem = nullptr;
};
class RspUpdateRiskGroupItemPackage : public Package
{
public:
	static RspUpdateRiskGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x404B;
	RspUpdateRiskGroupItemField* RspUpdateRiskGroupItem = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveRiskGroupItemPackage : public Package
{
public:
	static ReqRemoveRiskGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x404C;
	ReqRemoveRiskGroupItemField* ReqRemoveRiskGroupItem = nullptr;
};
class RspRemoveRiskGroupItemPackage : public Package
{
public:
	static RspRemoveRiskGroupItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x404D;
	RspRemoveRiskGroupItemField* RspRemoveRiskGroupItem = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddOrUpdateRiskPackage : public Package
{
public:
	static ReqAddOrUpdateRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x404E;
	ReqAddOrUpdateRiskField* ReqAddOrUpdateRisk = nullptr;
};
class RspAddOrUpdateRiskPackage : public Package
{
public:
	static RspAddOrUpdateRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x404F;
	RspAddOrUpdateRiskField* RspAddOrUpdateRisk = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveRiskPackage : public Package
{
public:
	static ReqRemoveRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4050;
	ReqRemoveRiskField* ReqRemoveRisk = nullptr;
};
class RspRemoveRiskPackage : public Package
{
public:
	static RspRemoveRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4051;
	RspRemoveRiskField* RspRemoveRisk = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddRiskRulePackage : public Package
{
public:
	static ReqAddRiskRulePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4052;
	ReqAddRiskRuleField* ReqAddRiskRule = nullptr;
};
class RspAddRiskRulePackage : public Package
{
public:
	static RspAddRiskRulePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4053;
	RspAddRiskRuleField* RspAddRiskRule = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddRiskRuleItemPackage : public Package
{
public:
	static ReqAddRiskRuleItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4054;
	ReqAddRiskRuleItemField* ReqAddRiskRuleItem = nullptr;
};
class RspAddRiskRuleItemPackage : public Package
{
public:
	static RspAddRiskRuleItemPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4055;
	RspAddRiskRuleItemField* RspAddRiskRuleItem = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddRiskTradeScopePackage : public Package
{
public:
	static ReqAddRiskTradeScopePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4056;
	ReqAddRiskTradeScopeField* ReqAddRiskTradeScope = nullptr;
};
class RspAddRiskTradeScopePackage : public Package
{
public:
	static RspAddRiskTradeScopePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4057;
	RspAddRiskTradeScopeField* RspAddRiskTradeScope = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAddAccountRiskPackage : public Package
{
public:
	static ReqAddAccountRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4058;
	ReqAddAccountRiskField* ReqAddAccountRisk = nullptr;
};
class RspAddAccountRiskPackage : public Package
{
public:
	static RspAddAccountRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x4059;
	RspAddAccountRiskField* RspAddAccountRisk = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqRemoveAccountRiskPackage : public Package
{
public:
	static ReqRemoveAccountRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x405A;
	ReqRemoveAccountRiskField* ReqRemoveAccountRisk = nullptr;
};
class RspRemoveAccountRiskPackage : public Package
{
public:
	static RspRemoveAccountRiskPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x405B;
	RspRemoveAccountRiskField* RspRemoveAccountRisk = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqMoneyTransferPackage : public Package
{
public:
	static ReqMoneyTransferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x405C;
	ReqMoneyTransferField* ReqMoneyTransfer = nullptr;
};
class RspMoneyTransferPackage : public Package
{
public:
	static RspMoneyTransferPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x405D;
	RspMoneyTransferField* RspMoneyTransfer = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqAuditOrderPackage : public Package
{
public:
	static ReqAuditOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x405E;
	ReqAuditOrderField* ReqAuditOrder = nullptr;
};
class RspAuditOrderPackage : public Package
{
public:
	static RspAuditOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x405F;
	RspAuditOrderField* RspAuditOrder = nullptr;
	RspInfoField* RspInfo = nullptr;
};
class ReqOfferLoginPackage : public Package
{
public:
	static ReqOfferLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5001;
	ReqOfferLoginField* ReqOfferLogin = nullptr;
};
class RspOfferLoginPackage : public Package
{
public:
	static RspOfferLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5002;
	RspOfferLoginField* RspOfferLogin = nullptr;
};
class ReqPrimaryAccountLoginPackage : public Package
{
public:
	static ReqPrimaryAccountLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5003;
	ReqPrimaryAccountLoginField* ReqPrimaryAccountLogin = nullptr;
};
class RspPrimaryAccountLoginPackage : public Package
{
public:
	static RspPrimaryAccountLoginPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5004;
	RspPrimaryAccountLoginField* RspPrimaryAccountLogin = nullptr;
};
class ReqPrimaryAccountLogoutPackage : public Package
{
public:
	static ReqPrimaryAccountLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5005;
	ReqPrimaryAccountLogoutField* ReqPrimaryAccountLogout = nullptr;
};
class RtnPrimaryAccountLogoutPackage : public Package
{
public:
	static RtnPrimaryAccountLogoutPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5006;
	RtnPrimaryAccountLogoutField* RtnPrimaryAccountLogout = nullptr;
};
class ReqPrimaryAccountInitPackage : public Package
{
public:
	static ReqPrimaryAccountInitPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5007;
	ReqPrimaryAccountInitField* ReqPrimaryAccountInit = nullptr;
};
class RspPrimaryAccountInitPackage : public Package
{
public:
	static RspPrimaryAccountInitPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5008;
	RspPrimaryAccountInitField* RspPrimaryAccountInit = nullptr;
};
class ReqPrimaryAccountQueryPackage : public Package
{
public:
	static ReqPrimaryAccountQueryPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5009;
	ReqPrimaryAccountQueryField* ReqPrimaryAccountQuery = nullptr;
};
class RspPrimaryAccountQueryPackage : public Package
{
public:
	static RspPrimaryAccountQueryPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x500A;
	RspPrimaryAccountQueryField* RspPrimaryAccountQuery = nullptr;
};
class ReqQryOfferOptionInstrumentPackage : public Package
{
public:
	static ReqQryOfferOptionInstrumentPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x500B;
	ReqQryOfferOptionInstrumentField* ReqQryOfferOptionInstrument = nullptr;
};
class RspQryOfferOptionInstrumentPackage : public Package
{
public:
	static RspQryOfferOptionInstrumentPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x500C;
	RspQryOfferOptionInstrumentField* RspQryOfferOptionInstrument = nullptr;
};
class RtnOfferOptionInstrumentPackage : public Package
{
public:
	static RtnOfferOptionInstrumentPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x500D;
	OfferOptionInstrumentField* OfferOptionInstrument = nullptr;
};
class ReqOfferOrderPackage : public Package
{
public:
	static ReqOfferOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x500E;
	ReqOfferOrderField* ReqOfferOrder = nullptr;
};
class ReqOfferCancelOrderPackage : public Package
{
public:
	static ReqOfferCancelOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x500F;
	ReqOfferCancelOrderField* ReqOfferCancelOrder = nullptr;
};
class RtnOfferOrderPackage : public Package
{
public:
	static RtnOfferOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5010;
	OfferOrderField* OfferOrder = nullptr;
};
class RtnOfferTradePackage : public Package
{
public:
	static RtnOfferTradePackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5011;
	OfferTradeField* OfferTrade = nullptr;
};
class RtnOfferErrorCancelOrderPackage : public Package
{
public:
	static RtnOfferErrorCancelOrderPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5012;
	OfferErrorCancelOrderField* OfferErrorCancelOrder = nullptr;
};
class RtnOfferCapitalPackage : public Package
{
public:
	static RtnOfferCapitalPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5013;
	OfferCapitalField* OfferCapital = nullptr;
};
class RtnOfferPositionPackage : public Package
{
public:
	static RtnOfferPositionPackage* Allocate();
	virtual void Free() override;
	virtual void Prepare(SessionIDType sessionID, int messageChain, int msgSeqNum) override;
	virtual int ToStepStream(char* buff, int size) const override;
	virtual bool FromStepStream(char* buff, int startIndex, int endIndex) override;
	virtual int ToXtpStream(char* buff, int size) const override;
	virtual bool FromXtpStream(char* buff, int startIndex, int endIndex) override;
	virtual const char* GetDebugString() const override;
public:
	static constexpr UShortType PackageID = 0x5014;
	OfferPositionField* OfferPosition = nullptr;
};
