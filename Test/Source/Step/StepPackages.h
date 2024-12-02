#pragma once
#include "Types.h"
#include "StepStructs.h"
#include "StepPackageBase.h"
#include <vector>

namespace step
{
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
		static constexpr UShortType PackageID = 0x0001;
		StepReqAccountLoginField* ReqAccountLogin = nullptr;
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
		static constexpr UShortType PackageID = 0x0002;
		StepRspAccountLoginField* RspAccountLogin = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x0003;
		StepReqAccountLogoutField* ReqAccountLogout = nullptr;
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
		static constexpr UShortType PackageID = 0x0004;
		StepRspAccountLogoutField* RspAccountLogout = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x0005;
		StepAccountLogoutField* AccountLogout = nullptr;
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
		static constexpr UShortType PackageID = 0x0006;
		StepReqRiskUserLoginField* ReqRiskUserLogin = nullptr;
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
		static constexpr UShortType PackageID = 0x0007;
		StepRspRiskUserLoginField* RspRiskUserLogin = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x0008;
		StepReqRiskUserLogoutField* ReqRiskUserLogout = nullptr;
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
		static constexpr UShortType PackageID = 0x0009;
		StepRspRiskUserLogoutField* RspRiskUserLogout = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x000A;
		StepRiskUserLogoutField* RiskUserLogout = nullptr;
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
		static constexpr UShortType PackageID = 0x000B;
		StepReqAdminUserLoginField* ReqAdminUserLogin = nullptr;
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
		static constexpr UShortType PackageID = 0x000C;
		StepRspAdminUserLoginField* RspAdminUserLogin = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x000D;
		StepReqAdminUserLogoutField* ReqAdminUserLogout = nullptr;
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
		static constexpr UShortType PackageID = 0x000E;
		StepRspAdminUserLogoutField* RspAdminUserLogout = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x000F;
		StepAdminUserLogoutField* AdminUserLogout = nullptr;
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
		static constexpr UShortType PackageID = 0x0010;
		StepReqMdUserLoginField* ReqMdUserLogin = nullptr;
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
		static constexpr UShortType PackageID = 0x0011;
		StepRspMdUserLoginField* RspMdUserLogin = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x0012;
		StepReqMdUserLogoutField* ReqMdUserLogout = nullptr;
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
		static constexpr UShortType PackageID = 0x0013;
		StepRspMdUserLogoutField* RspMdUserLogout = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x1001;
		StepReqQryAccountField* ReqQryAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x1002;
		StepAccountField* Account = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x1003;
		StepReqQryHolderAccountField* ReqQryHolderAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x1004;
		StepHolderAccountField* HolderAccount = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x1005;
		StepReqQryCapitalField* ReqQryCapital = nullptr;
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
		static constexpr UShortType PackageID = 0x1006;
		StepCapitalField* Capital = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x1007;
		StepReqQryPositionField* ReqQryPosition = nullptr;
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
		static constexpr UShortType PackageID = 0x1008;
		StepPositionField* Position = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x1009;
		StepPositionField* Position = nullptr;
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
		static constexpr UShortType PackageID = 0x100A;
		StepReqQryOrderField* ReqQryOrder = nullptr;
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
		static constexpr UShortType PackageID = 0x100B;
		StepOrderField* Order = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x100C;
		StepOrderField* Order = nullptr;
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
		static constexpr UShortType PackageID = 0x100D;
		StepReqQryTradeField* ReqQryTrade = nullptr;
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
		static constexpr UShortType PackageID = 0x100E;
		StepTradeField* Trade = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x100F;
		StepTradeField* Trade = nullptr;
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
		static constexpr UShortType PackageID = 0x1010;
		StepReqQryInstrumentField* ReqQryInstrument = nullptr;
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
		static constexpr UShortType PackageID = 0x1011;
		StepInstrumentField* Instrument = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x1012;
		StepReqQryOptionInstrumentField* ReqQryOptionInstrument = nullptr;
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
		static constexpr UShortType PackageID = 0x1013;
		StepOptionInstrumentField* OptionInstrument = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x1014;
		StepReqQryCommissionRateField* ReqQryCommissionRate = nullptr;
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
		static constexpr UShortType PackageID = 0x1015;
		StepCommissionRateField* CommissionRate = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x2001;
		StepReqInsertOrderField* ReqInsertOrder = nullptr;
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
		static constexpr UShortType PackageID = 0x2002;
		StepOrderField* Order = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x2003;
		StepReqCancelOrderField* ReqCancelOrder = nullptr;
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
		static constexpr UShortType PackageID = 0x2004;
		StepCancelOrderField* CancelOrder = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x2101;
		StepReqMdInitField* ReqMdInit = nullptr;
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
		static constexpr UShortType PackageID = 0x2102;
		StepRspMdInitField* RspMdInit = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x2103;
		StepReqSubscribeMdField* ReqSubscribeMd = nullptr;
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
		static constexpr UShortType PackageID = 0x2105;
		StepRspSubscribeMdField* RspSubscribeMd = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x3001;
		StepAccountField* Account = nullptr;
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
		static constexpr UShortType PackageID = 0x3002;
		StepAccountDeleteField* AccountDelete = nullptr;
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
		static constexpr UShortType PackageID = 0x3003;
		StepAccountRiskField* AccountRisk = nullptr;
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
		static constexpr UShortType PackageID = 0x3004;
		StepAccountRiskDeleteField* AccountRiskDelete = nullptr;
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
		static constexpr UShortType PackageID = 0x3005;
		StepAccountRiskNotifyField* AccountRiskNotify = nullptr;
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
		static constexpr UShortType PackageID = 0x3101;
		StepShortMdField* ShortMd = nullptr;
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
		static constexpr UShortType PackageID = 0x3102;
		StepRtnExchangeStatusField* RtnExchangeStatus = nullptr;
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
		static constexpr UShortType PackageID = 0x3103;
		StepMdInitCompletedField* MdInitCompleted = nullptr;
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
		static constexpr UShortType PackageID = 0x4001;
		StepReqQryRiskGroupAccountField* ReqQryRiskGroupAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x4002;
		StepAccountField* Account = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x4003;
		StepReqQryRiskGroupCapitalField* ReqQryRiskGroupCapital = nullptr;
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
		static constexpr UShortType PackageID = 0x4004;
		StepCapitalField* Capital = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x4005;
		StepReqQryRiskGroupPositionField* ReqQryRiskGroupPosition = nullptr;
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
		static constexpr UShortType PackageID = 0x4006;
		StepPositionField* Position = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x4007;
		StepReqQryRiskGroupOrderField* ReqQryRiskGroupOrder = nullptr;
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
		static constexpr UShortType PackageID = 0x4008;
		StepOrderField* Order = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x4009;
		StepReqQryRiskGroupTradeField* ReqQryRiskGroupTrade = nullptr;
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
		static constexpr UShortType PackageID = 0x400A;
		StepTradeField* Trade = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x400B;
		StepReqQryRiskGroupAccountRiskField* ReqQryRiskGroupAccountRisk = nullptr;
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
		static constexpr UShortType PackageID = 0x400C;
		StepAccountRiskField* AccountRisk = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x400D;
		StepReqQryRiskGroupAccountRiskNotifyField* ReqQryRiskGroupAccountRiskNotify = nullptr;
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
		static constexpr UShortType PackageID = 0x400E;
		StepAccountRiskNotifyField* AccountRiskNotify = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x400F;
		StepReqRiskInsertOrderField* ReqRiskInsertOrder = nullptr;
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
		static constexpr UShortType PackageID = 0x4010;
		StepOrderField* Order = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x4011;
		StepReqRiskCancelOrderField* ReqRiskCancelOrder = nullptr;
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
		static constexpr UShortType PackageID = 0x4012;
		StepCancelOrderField* CancelOrder = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x5001;
		StepReqAddRiskUserField* ReqAddRiskUser = nullptr;
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
		static constexpr UShortType PackageID = 0x5002;
		StepRspAddRiskUserField* RspAddRiskUser = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x5003;
		StepReqUpdateRiskUserField* ReqUpdateRiskUser = nullptr;
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
		static constexpr UShortType PackageID = 0x5004;
		StepRspUpdateRiskUserField* RspUpdateRiskUser = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x5005;
		StepReqRemoveRiskUserField* ReqRemoveRiskUser = nullptr;
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
		static constexpr UShortType PackageID = 0x5006;
		StepRspRemoveRiskUserField* RspRemoveRiskUser = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x5007;
		StepReqAddAdminUserField* ReqAddAdminUser = nullptr;
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
		static constexpr UShortType PackageID = 0x5008;
		StepRspAddAdminUserField* RspAddAdminUser = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x5009;
		StepReqUpdateAdminUserField* ReqUpdateAdminUser = nullptr;
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
		static constexpr UShortType PackageID = 0x500A;
		StepRspUpdateAdminUserField* RspUpdateAdminUser = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x500B;
		StepReqRemoveAdminUserField* ReqRemoveAdminUser = nullptr;
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
		static constexpr UShortType PackageID = 0x500C;
		StepRspRemoveAdminUserField* RspRemoveAdminUser = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x6001;
		StepReqAddPrimaryAccountField* ReqAddPrimaryAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x6002;
		StepRspAddPrimaryAccountField* RspAddPrimaryAccount = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x6003;
		StepReqUpdatePrimaryAccountField* ReqUpdatePrimaryAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x6004;
		StepRspUpdatePrimaryAccountField* RspUpdatePrimaryAccount = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x6005;
		StepReqRemovePrimaryAccountField* ReqRemovePrimaryAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x6006;
		StepRspRemovePrimaryAccountField* RspRemovePrimaryAccount = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x6007;
		StepReqAddAccountField* ReqAddAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x6008;
		StepRspAddAccountField* RspAddAccount = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x6009;
		StepReqUpdateAccountField* ReqUpdateAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x600A;
		StepRspUpdateAccountField* RspUpdateAccount = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x600B;
		StepReqRemoveAccountField* ReqRemoveAccount = nullptr;
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
		static constexpr UShortType PackageID = 0x600C;
		StepRspRemoveAccountField* RspRemoveAccount = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x7001;
		StepReqAddBaseCommissionField* ReqAddBaseCommission = nullptr;
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
		static constexpr UShortType PackageID = 0x7002;
		StepRspAddBaseCommissionField* RspAddBaseCommission = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x7003;
		StepReqUpdateBaseCommissionField* ReqUpdateBaseCommission = nullptr;
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
		static constexpr UShortType PackageID = 0x7004;
		StepRspUpdateBaseCommissionField* RspUpdateBaseCommission = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x7005;
		StepReqRemoveBaseCommissionField* ReqRemoveBaseCommission = nullptr;
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
		static constexpr UShortType PackageID = 0x7006;
		StepRspInfoField* RspInfo = nullptr;
		StepRspRemoveBaseCommissionField* RspRemoveBaseCommission = nullptr;
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
		static constexpr UShortType PackageID = 0x7007;
		StepReqAddCommissionGroupField* ReqAddCommissionGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x7008;
		StepRspAddCommissionGroupField* RspAddCommissionGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x7009;
		StepReqUpdateCommissionGroupField* ReqUpdateCommissionGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x700A;
		StepRspUpdateCommissionGroupField* RspUpdateCommissionGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x700B;
		StepReqRemoveCommissionGroupField* ReqRemoveCommissionGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x700C;
		StepRspRemoveCommissionGroupField* RspRemoveCommissionGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x700D;
		StepReqAddOptionMarginParamField* ReqAddOptionMarginParam = nullptr;
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
		static constexpr UShortType PackageID = 0x700E;
		StepRspAddOptionMarginParamField* RspAddOptionMarginParam = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x700F;
		StepReqUpdateOptionMarginParamField* ReqUpdateOptionMarginParam = nullptr;
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
		static constexpr UShortType PackageID = 0x7010;
		StepRspUpdateOptionMarginParamField* RspUpdateOptionMarginParam = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x7011;
		StepReqRemoveOptionMarginParamField* ReqRemoveOptionMarginParam = nullptr;
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
		static constexpr UShortType PackageID = 0x7012;
		StepRspRemoveOptionMarginParamField* RspRemoveOptionMarginParam = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x8001;
		StepReqAddTradeOfferField* ReqAddTradeOffer = nullptr;
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
		static constexpr UShortType PackageID = 0x8002;
		StepRspAddTradeOfferField* RspAddTradeOffer = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x8003;
		StepReqUpdateTradeOfferField* ReqUpdateTradeOffer = nullptr;
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
		static constexpr UShortType PackageID = 0x8004;
		StepRspUpdateTradeOfferField* RspUpdateTradeOffer = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x8005;
		StepReqRemoveTradeOfferField* ReqRemoveTradeOffer = nullptr;
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
		static constexpr UShortType PackageID = 0x8006;
		StepRspRemoveTradeOfferField* RspRemoveTradeOffer = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x8007;
		StepReqAddTradeGroupField* ReqAddTradeGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x8008;
		StepRspAddTradeGroupField* RspAddTradeGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x8009;
		StepReqUpdateTradeGroupField* ReqUpdateTradeGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x800A;
		StepRspUpdateTradeGroupField* RspUpdateTradeGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x800B;
		StepReqRemoveTradeGroupField* ReqRemoveTradeGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x800C;
		StepRspRemoveTradeGroupField* RspRemoveTradeGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x800D;
		StepReqAddTradeGroupItemField* ReqAddTradeGroupItem = nullptr;
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
		static constexpr UShortType PackageID = 0x800E;
		StepRspAddTradeGroupItemField* RspAddTradeGroupItem = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x800F;
		StepReqUpdateTradeGroupItemField* ReqUpdateTradeGroupItem = nullptr;
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
		static constexpr UShortType PackageID = 0x8010;
		StepRspUpdateTradeGroupItemField* RspUpdateTradeGroupItem = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x8011;
		StepReqRemoveTradeGroupItemField* ReqRemoveTradeGroupItem = nullptr;
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
		static constexpr UShortType PackageID = 0x8012;
		StepRspRemoveTradeGroupItemField* RspRemoveTradeGroupItem = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x9001;
		StepReqAddRiskGroupField* ReqAddRiskGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x9002;
		StepRspAddRiskGroupField* RspAddRiskGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x9003;
		StepReqUpdateRiskGroupField* ReqUpdateRiskGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x9004;
		StepRspUpdateRiskGroupField* RspUpdateRiskGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x9005;
		StepReqRemoveRiskGroupField* ReqRemoveRiskGroup = nullptr;
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
		static constexpr UShortType PackageID = 0x9006;
		StepRspRemoveRiskGroupField* RspRemoveRiskGroup = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x9007;
		StepReqAddRiskGroupItemField* ReqAddRiskGroupItem = nullptr;
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
		static constexpr UShortType PackageID = 0x9008;
		StepRspAddRiskGroupItemField* RspAddRiskGroupItem = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x9009;
		StepReqUpdateRiskGroupItemField* ReqUpdateRiskGroupItem = nullptr;
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
		static constexpr UShortType PackageID = 0x900A;
		StepRspUpdateRiskGroupItemField* RspUpdateRiskGroupItem = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0x900B;
		StepReqRemoveRiskGroupItemField* ReqRemoveRiskGroupItem = nullptr;
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
		static constexpr UShortType PackageID = 0x900C;
		StepRspRemoveRiskGroupItemField* RspRemoveRiskGroupItem = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xA001;
		StepReqAddOrUpdateRiskField* ReqAddOrUpdateRisk = nullptr;
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
		static constexpr UShortType PackageID = 0xA002;
		StepRspAddOrUpdateRiskField* RspAddOrUpdateRisk = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xA003;
		StepReqRemoveRiskField* ReqRemoveRisk = nullptr;
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
		static constexpr UShortType PackageID = 0xA004;
		StepRspRemoveRiskField* RspRemoveRisk = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xA005;
		StepReqAddRiskRuleField* ReqAddRiskRule = nullptr;
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
		static constexpr UShortType PackageID = 0xA006;
		StepRspAddRiskRuleField* RspAddRiskRule = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xA007;
		StepReqAddRiskRuleItemField* ReqAddRiskRuleItem = nullptr;
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
		static constexpr UShortType PackageID = 0xA008;
		StepRspAddRiskRuleItemField* RspAddRiskRuleItem = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xA009;
		StepReqAddRiskTradeScopeField* ReqAddRiskTradeScope = nullptr;
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
		static constexpr UShortType PackageID = 0xA00A;
		StepRspAddRiskTradeScopeField* RspAddRiskTradeScope = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xA00B;
		StepReqAddAccountRiskField* ReqAddAccountRisk = nullptr;
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
		static constexpr UShortType PackageID = 0xA00C;
		StepRspAddAccountRiskField* RspAddAccountRisk = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xA00D;
		StepReqRemoveAccountRiskField* ReqRemoveAccountRisk = nullptr;
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
		static constexpr UShortType PackageID = 0xA00E;
		StepRspRemoveAccountRiskField* RspRemoveAccountRisk = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xB001;
		StepReqMoneyTransferField* ReqMoneyTransfer = nullptr;
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
		static constexpr UShortType PackageID = 0xB002;
		StepRspMoneyTransferField* RspMoneyTransfer = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xB003;
		StepReqQryMoneyTransferField* ReqQryMoneyTransfer = nullptr;
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
		static constexpr UShortType PackageID = 0xB004;
		StepMoneyTransferField* MoneyTransfer = nullptr;
		StepRspInfoField* RspInfo = nullptr;
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
		static constexpr UShortType PackageID = 0xB005;
		StepMoneyTransferField* MoneyTransfer = nullptr;
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
		static constexpr UShortType PackageID = 0xB006;
		StepReqAuditOrderField* ReqAuditOrder = nullptr;
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
		static constexpr UShortType PackageID = 0xB007;
		StepRspAuditOrderField* RspAuditOrder = nullptr;
		StepRspInfoField* RspInfo = nullptr;
	};
}