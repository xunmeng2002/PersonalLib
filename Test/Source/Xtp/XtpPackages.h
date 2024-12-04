#pragma once
#include "XtpStructs.h"
#include "XtpPackageBase.h"

namespace xtp
{
	class XtpReqOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqOfferLoginPackage();
		static XtpReqOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0002;
		XtpReqOfferLoginField* ReqOfferLogin;
	};

	class XtpRspOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspOfferLoginPackage();
		static XtpRspOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0003;
		XtpRspOfferLoginField* RspOfferLogin;
	};

	class XtpReqPrimaryAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountLoginPackage();
		static XtpReqPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0004;
		XtpReqPrimaryAccountLoginField* ReqPrimaryAccountLogin;
	};

	class XtpRspPrimaryAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountLoginPackage();
		static XtpRspPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0005;
		XtpRspPrimaryAccountLoginField* RspPrimaryAccountLogin;
	};

	class XtpReqPrimaryAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountLogoutPackage();
		static XtpReqPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0006;
		XtpReqPrimaryAccountLogoutField* ReqPrimaryAccountLogout;
	};

	class XtpRtnPrimaryAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRtnPrimaryAccountLogoutPackage();
		static XtpRtnPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0007;
		XtpRtnPrimaryAccountLogoutField* RtnPrimaryAccountLogout;
	};

	class XtpReqPrimaryAccountInitPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountInitPackage();
		static XtpReqPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0008;
		XtpReqPrimaryAccountInitField* ReqPrimaryAccountInit;
	};

	class XtpRspPrimaryAccountInitPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountInitPackage();
		static XtpRspPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0009;
		XtpRspPrimaryAccountInitField* RspPrimaryAccountInit;
	};

	class XtpReqPrimaryAccountQueryPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountQueryPackage();
		static XtpReqPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x000A;
		XtpReqPrimaryAccountQueryField* ReqPrimaryAccountQuery;
	};

	class XtpRspPrimaryAccountQueryPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountQueryPackage();
		static XtpRspPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x000B;
		XtpRspPrimaryAccountQueryField* RspPrimaryAccountQuery;
	};

	class XtpReqQryOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpReqQryOptionInstrumentPackage();
		static XtpReqQryOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x000C;
		XtpReqQryOptionInstrumentField* ReqQryOptionInstrument;
	};

	class XtpRspQryOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRspQryOptionInstrumentPackage();
		static XtpRspQryOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x000D;
		XtpRspQryOptionInstrumentField* RspQryOptionInstrument;
	};

	class XtpRtnOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRtnOptionInstrumentPackage();
		static XtpRtnOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x000E;
		XtpRtnOptionInstrumentField* RtnOptionInstrument;
	};

	class XtpReqInsertOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqInsertOrderPackage();
		static XtpReqInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1001;
		XtpReqInsertOrderField* ReqInsertOrder;
	};

	class XtpReqCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqCancelOrderPackage();
		static XtpReqCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1002;
		XtpReqCancelOrderField* ReqCancelOrder;
	};

	class XtpRtnOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnOrderPackage();
		static XtpRtnOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1003;
		XtpRtnOrderField* RtnOrder;
	};

	class XtpRtnTradePackage : public XtpPackageBase
	{
	public:
		XtpRtnTradePackage();
		static XtpRtnTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1004;
		XtpRtnTradeField* RtnTrade;
	};

	class XtpRtnErrorCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnErrorCancelOrderPackage();
		static XtpRtnErrorCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1005;
		XtpRtnErrorCancelOrderField* RtnErrorCancelOrder;
	};

	class XtpRtnCapitalPackage : public XtpPackageBase
	{
	public:
		XtpRtnCapitalPackage();
		static XtpRtnCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1006;
		XtpRtnCapitalField* RtnCapital;
	};

	class XtpRtnPositionPackage : public XtpPackageBase
	{
	public:
		XtpRtnPositionPackage();
		static XtpRtnPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1007;
		XtpRtnPositionField* RtnPosition;
	};

	class XtpReqMDOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqMDOfferLoginPackage();
		static XtpReqMDOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2001;
		XtpReqMDOfferLoginField* ReqMDOfferLogin;
	};

	class XtpRspMDOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspMDOfferLoginPackage();
		static XtpRspMDOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2002;
		XtpRspMDOfferLoginField* RspMDOfferLogin;
	};

	class XtpReqMDInitPackage : public XtpPackageBase
	{
	public:
		XtpReqMDInitPackage();
		static XtpReqMDInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2003;
		XtpReqMDInitField* ReqMDInit;
	};

	class XtpRspMDInitPackage : public XtpPackageBase
	{
	public:
		XtpRspMDInitPackage();
		static XtpRspMDInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2004;
		XtpRspMDInitField* RspMDInit;
	};

	class XtpReqSubscribeMDPackage : public XtpPackageBase
	{
	public:
		XtpReqSubscribeMDPackage();
		static XtpReqSubscribeMDPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2005;
		XtpReqSubscribeMDField* ReqSubscribeMD;
	};

	class XtpRspSubscribeMDPackage : public XtpPackageBase
	{
	public:
		XtpRspSubscribeMDPackage();
		static XtpRspSubscribeMDPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2006;
		XtpRspSubscribeMDField* RspSubscribeMD;
	};

	class XtpRtnShortMDPackage : public XtpPackageBase
	{
	public:
		XtpRtnShortMDPackage();
		static XtpRtnShortMDPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3001;
		XtpRtnShortMDField* RtnShortMD;
	};

	class XtpRtnExchangeStatusPackage : public XtpPackageBase
	{
	public:
		XtpRtnExchangeStatusPackage();
		static XtpRtnExchangeStatusPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3002;
		XtpRtnExchangeStatusField* RtnExchangeStatus;
	};

	class XtpRtnInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRtnInstrumentPackage();
		static XtpRtnInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3003;
		XtpRtnInstrumentField* RtnInstrument;
	};

	class XtpRtnMDInitCompletedPackage : public XtpPackageBase
	{
	public:
		XtpRtnMDInitCompletedPackage();
		static XtpRtnMDInitCompletedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3004;
		XtpRtnMDInitCompletedField* RtnMDInitCompleted;
	};

	class XtpNotifyMdClientConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyMdClientConnectedPackage();
		static XtpNotifyMdClientConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4001;
		XtpNotifyMdClientConnectedField* NotifyMdClientConnected;
	};

	class XtpNotifyMdClientDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyMdClientDisConnectedPackage();
		static XtpNotifyMdClientDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4002;
		XtpNotifyMdClientDisConnectedField* NotifyMdClientDisConnected;
	};

	class XtpNotifyRiskCheckClientConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskCheckClientConnectedPackage();
		static XtpNotifyRiskCheckClientConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4003;
		XtpNotifyRiskCheckClientConnectedField* NotifyRiskCheckClientConnected;
	};

	class XtpNotifyRiskCheckClientDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskCheckClientDisConnectedPackage();
		static XtpNotifyRiskCheckClientDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4004;
		XtpNotifyRiskCheckClientDisConnectedField* NotifyRiskCheckClientDisConnected;
	};

	class XtpNotifyTradeFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyTradeFrontConnectedPackage();
		static XtpNotifyTradeFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4005;
		XtpNotifyTradeFrontConnectedField* NotifyTradeFrontConnected;
	};

	class XtpNotifyTradeFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyTradeFrontDisConnectedPackage();
		static XtpNotifyTradeFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4006;
		XtpNotifyTradeFrontDisConnectedField* NotifyTradeFrontDisConnected;
	};

	class XtpNotifyRiskFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskFrontConnectedPackage();
		static XtpNotifyRiskFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4007;
		XtpNotifyRiskFrontConnectedField* NotifyRiskFrontConnected;
	};

	class XtpNotifyRiskFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskFrontDisConnectedPackage();
		static XtpNotifyRiskFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4008;
		XtpNotifyRiskFrontDisConnectedField* NotifyRiskFrontDisConnected;
	};

	class XtpNotifyAdminFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyAdminFrontConnectedPackage();
		static XtpNotifyAdminFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4009;
		XtpNotifyAdminFrontConnectedField* NotifyAdminFrontConnected;
	};

	class XtpNotifyAdminFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyAdminFrontDisConnectedPackage();
		static XtpNotifyAdminFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400A;
		XtpNotifyAdminFrontDisConnectedField* NotifyAdminFrontDisConnected;
	};

	class XtpNotifyOfferFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyOfferFrontConnectedPackage();
		static XtpNotifyOfferFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400B;
		XtpNotifyOfferFrontConnectedField* NotifyOfferFrontConnected;
	};

	class XtpNotifyOfferFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyOfferFrontDisConnectedPackage();
		static XtpNotifyOfferFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400C;
		XtpNotifyOfferFrontDisConnectedField* NotifyOfferFrontDisConnected;
	};

	class XtpNotifyInitCompletePackage : public XtpPackageBase
	{
	public:
		XtpNotifyInitCompletePackage();
		static XtpNotifyInitCompletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400D;
		XtpNotifyInitCompleteField* NotifyInitComplete;
	};

	class XtpRspNotifyInitCompletePackage : public XtpPackageBase
	{
	public:
		XtpRspNotifyInitCompletePackage();
		static XtpRspNotifyInitCompletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400E;
		XtpRspNotifyInitCompleteField* RspNotifyInitComplete;
	};

	class XtpRtnRiskCheckOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnRiskCheckOrderPackage();
		static XtpRtnRiskCheckOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5001;
		XtpRtnRiskCheckOrderField* RtnRiskCheckOrder;
	};

}
