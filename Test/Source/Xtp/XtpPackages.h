#pragma once
#include "XtpStructs.h"
#include "XtpPackageBase.h"

namespace xtp
{
	class XtpSessionClosePackage : public XtpPackageBase
	{
	public:
		XtpSessionClosePackage();
		static XtpSessionClosePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1001;
		XtpSessionClose Field;
	};

	class XtpReqOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqOfferLoginPackage();
		static XtpReqOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1002;
		XtpReqOfferLogin Field;
	};

	class XtpRspOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspOfferLoginPackage();
		static XtpRspOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1003;
		XtpRspOfferLogin Field;
	};

	class XtpReqPrimaryAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountLoginPackage();
		static XtpReqPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1004;
		XtpReqPrimaryAccountLogin Field;
	};

	class XtpRspPrimaryAccountLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountLoginPackage();
		static XtpRspPrimaryAccountLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1005;
		XtpRspPrimaryAccountLogin Field;
	};

	class XtpReqPrimaryAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountLogoutPackage();
		static XtpReqPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1006;
		XtpReqPrimaryAccountLogout Field;
	};

	class XtpRtnPrimaryAccountLogoutPackage : public XtpPackageBase
	{
	public:
		XtpRtnPrimaryAccountLogoutPackage();
		static XtpRtnPrimaryAccountLogoutPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1007;
		XtpRtnPrimaryAccountLogout Field;
	};

	class XtpReqPrimaryAccountInitPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountInitPackage();
		static XtpReqPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1008;
		XtpReqPrimaryAccountInit Field;
	};

	class XtpRspPrimaryAccountInitPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountInitPackage();
		static XtpRspPrimaryAccountInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x1009;
		XtpRspPrimaryAccountInit Field;
	};

	class XtpReqPrimaryAccountQueryPackage : public XtpPackageBase
	{
	public:
		XtpReqPrimaryAccountQueryPackage();
		static XtpReqPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100A;
		XtpReqPrimaryAccountQuery Field;
	};

	class XtpRspPrimaryAccountQueryPackage : public XtpPackageBase
	{
	public:
		XtpRspPrimaryAccountQueryPackage();
		static XtpRspPrimaryAccountQueryPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100B;
		XtpRspPrimaryAccountQuery Field;
	};

	class XtpReqQryOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpReqQryOptionInstrumentPackage();
		static XtpReqQryOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100C;
		XtpReqQryOptionInstrument Field;
	};

	class XtpRspQryOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRspQryOptionInstrumentPackage();
		static XtpRspQryOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100D;
		XtpRspQryOptionInstrument Field;
	};

	class XtpRtnOptionInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRtnOptionInstrumentPackage();
		static XtpRtnOptionInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x100E;
		XtpRtnOptionInstrument Field;
	};

	class XtpReqInsertOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqInsertOrderPackage();
		static XtpReqInsertOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2001;
		XtpReqInsertOrder Field;
	};

	class XtpReqCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpReqCancelOrderPackage();
		static XtpReqCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2002;
		XtpReqCancelOrder Field;
	};

	class XtpRtnOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnOrderPackage();
		static XtpRtnOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2003;
		XtpRtnOrder Field;
	};

	class XtpRtnTradePackage : public XtpPackageBase
	{
	public:
		XtpRtnTradePackage();
		static XtpRtnTradePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2004;
		XtpRtnTrade Field;
	};

	class XtpRtnErrorCancelOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnErrorCancelOrderPackage();
		static XtpRtnErrorCancelOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2005;
		XtpRtnErrorCancelOrder Field;
	};

	class XtpRtnCapitalPackage : public XtpPackageBase
	{
	public:
		XtpRtnCapitalPackage();
		static XtpRtnCapitalPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2006;
		XtpRtnCapital Field;
	};

	class XtpRtnPositionPackage : public XtpPackageBase
	{
	public:
		XtpRtnPositionPackage();
		static XtpRtnPositionPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x2007;
		XtpRtnPosition Field;
	};

	class XtpReqMDOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpReqMDOfferLoginPackage();
		static XtpReqMDOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3001;
		XtpReqMDOfferLogin Field;
	};

	class XtpRspMDOfferLoginPackage : public XtpPackageBase
	{
	public:
		XtpRspMDOfferLoginPackage();
		static XtpRspMDOfferLoginPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3002;
		XtpRspMDOfferLogin Field;
	};

	class XtpReqMDInitPackage : public XtpPackageBase
	{
	public:
		XtpReqMDInitPackage();
		static XtpReqMDInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3003;
		XtpReqMDInit Field;
	};

	class XtpRspMDInitPackage : public XtpPackageBase
	{
	public:
		XtpRspMDInitPackage();
		static XtpRspMDInitPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3004;
		XtpRspMDInit Field;
	};

	class XtpReqSubscribeMDPackage : public XtpPackageBase
	{
	public:
		XtpReqSubscribeMDPackage();
		static XtpReqSubscribeMDPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3005;
		XtpReqSubscribeMD Field;
	};

	class XtpRspSubscribeMDPackage : public XtpPackageBase
	{
	public:
		XtpRspSubscribeMDPackage();
		static XtpRspSubscribeMDPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3006;
		XtpRspSubscribeMD Field;
	};

	class XtpRtnShortMDPackage : public XtpPackageBase
	{
	public:
		XtpRtnShortMDPackage();
		static XtpRtnShortMDPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3101;
		XtpRtnShortMD Field;
	};

	class XtpRtnExchangeStatusPackage : public XtpPackageBase
	{
	public:
		XtpRtnExchangeStatusPackage();
		static XtpRtnExchangeStatusPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3102;
		XtpRtnExchangeStatus Field;
	};

	class XtpRtnInstrumentPackage : public XtpPackageBase
	{
	public:
		XtpRtnInstrumentPackage();
		static XtpRtnInstrumentPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3103;
		XtpRtnInstrument Field;
	};

	class XtpRtnMDInitCompletedPackage : public XtpPackageBase
	{
	public:
		XtpRtnMDInitCompletedPackage();
		static XtpRtnMDInitCompletedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x3104;
		XtpRtnMDInitCompleted Field;
	};

	class XtpNotifyMdClientConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyMdClientConnectedPackage();
		static XtpNotifyMdClientConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4001;
		XtpNotifyMdClientConnected Field;
	};

	class XtpNotifyMdClientDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyMdClientDisConnectedPackage();
		static XtpNotifyMdClientDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4002;
		XtpNotifyMdClientDisConnected Field;
	};

	class XtpNotifyRiskCheckClientConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskCheckClientConnectedPackage();
		static XtpNotifyRiskCheckClientConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4003;
		XtpNotifyRiskCheckClientConnected Field;
	};

	class XtpNotifyRiskCheckClientDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskCheckClientDisConnectedPackage();
		static XtpNotifyRiskCheckClientDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4004;
		XtpNotifyRiskCheckClientDisConnected Field;
	};

	class XtpNotifyTradeFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyTradeFrontConnectedPackage();
		static XtpNotifyTradeFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4005;
		XtpNotifyTradeFrontConnected Field;
	};

	class XtpNotifyTradeFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyTradeFrontDisConnectedPackage();
		static XtpNotifyTradeFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4006;
		XtpNotifyTradeFrontDisConnected Field;
	};

	class XtpNotifyRiskFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskFrontConnectedPackage();
		static XtpNotifyRiskFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4007;
		XtpNotifyRiskFrontConnected Field;
	};

	class XtpNotifyRiskFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyRiskFrontDisConnectedPackage();
		static XtpNotifyRiskFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4008;
		XtpNotifyRiskFrontDisConnected Field;
	};

	class XtpNotifyAdminFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyAdminFrontConnectedPackage();
		static XtpNotifyAdminFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x4009;
		XtpNotifyAdminFrontConnected Field;
	};

	class XtpNotifyAdminFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyAdminFrontDisConnectedPackage();
		static XtpNotifyAdminFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400A;
		XtpNotifyAdminFrontDisConnected Field;
	};

	class XtpNotifyOfferFrontConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyOfferFrontConnectedPackage();
		static XtpNotifyOfferFrontConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400B;
		XtpNotifyOfferFrontConnected Field;
	};

	class XtpNotifyOfferFrontDisConnectedPackage : public XtpPackageBase
	{
	public:
		XtpNotifyOfferFrontDisConnectedPackage();
		static XtpNotifyOfferFrontDisConnectedPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400C;
		XtpNotifyOfferFrontDisConnected Field;
	};

	class XtpNotifyInitCompletePackage : public XtpPackageBase
	{
	public:
		XtpNotifyInitCompletePackage();
		static XtpNotifyInitCompletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400D;
		XtpNotifyInitComplete Field;
	};

	class XtpRspNotifyInitCompletePackage : public XtpPackageBase
	{
	public:
		XtpRspNotifyInitCompletePackage();
		static XtpRspNotifyInitCompletePackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x400E;
		XtpRspNotifyInitComplete Field;
	};

	class XtpRtnRiskCheckOrderPackage : public XtpPackageBase
	{
	public:
		XtpRtnRiskCheckOrderPackage();
		static XtpRtnRiskCheckOrderPackage* Allocate();
		virtual void Free() override;
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x5001;
		XtpRtnRiskCheckOrder Field;
	};

}
