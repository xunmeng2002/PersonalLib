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
		virtual void Prepare(SessionIDType sessionID) override;
		virtual int ToProtocolStream(char* buff, int size) const override;
		virtual bool FromProtocolStream(char* buff, int size) override;
		virtual const char* GetString() const override;
		virtual const char* GetDebugString() const override;
	public:
		static constexpr UShortType PackageID = 0x0002;
		XtpReqOfferLoginField Field;
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
		static constexpr UShortType PackageID = 0x0003;
		XtpRspOfferLoginField Field;
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
		static constexpr UShortType PackageID = 0x0004;
		XtpReqPrimaryAccountLoginField Field;
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
		static constexpr UShortType PackageID = 0x0005;
		XtpRspPrimaryAccountLoginField Field;
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
		static constexpr UShortType PackageID = 0x0006;
		XtpReqPrimaryAccountLogoutField Field;
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
		static constexpr UShortType PackageID = 0x0007;
		XtpRtnPrimaryAccountLogoutField Field;
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
		static constexpr UShortType PackageID = 0x0008;
		XtpReqPrimaryAccountInitField Field;
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
		static constexpr UShortType PackageID = 0x0009;
		XtpRspPrimaryAccountInitField Field;
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
		static constexpr UShortType PackageID = 0x000A;
		XtpReqPrimaryAccountQueryField Field;
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
		static constexpr UShortType PackageID = 0x000B;
		XtpRspPrimaryAccountQueryField Field;
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
		static constexpr UShortType PackageID = 0x000C;
		XtpReqQryOptionInstrumentField Field;
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
		static constexpr UShortType PackageID = 0x000D;
		XtpRspQryOptionInstrumentField Field;
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
		static constexpr UShortType PackageID = 0x000E;
		XtpRtnOptionInstrumentField Field;
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
		static constexpr UShortType PackageID = 0x1001;
		XtpReqInsertOrderField Field;
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
		static constexpr UShortType PackageID = 0x1002;
		XtpReqCancelOrderField Field;
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
		static constexpr UShortType PackageID = 0x1003;
		XtpRtnOrderField Field;
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
		static constexpr UShortType PackageID = 0x1004;
		XtpRtnTradeField Field;
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
		static constexpr UShortType PackageID = 0x1005;
		XtpRtnErrorCancelOrderField Field;
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
		static constexpr UShortType PackageID = 0x1006;
		XtpRtnCapitalField Field;
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
		static constexpr UShortType PackageID = 0x1007;
		XtpRtnPositionField Field;
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
		static constexpr UShortType PackageID = 0x2001;
		XtpReqMDOfferLoginField Field;
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
		static constexpr UShortType PackageID = 0x2002;
		XtpRspMDOfferLoginField Field;
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
		static constexpr UShortType PackageID = 0x2003;
		XtpReqMDInitField Field;
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
		static constexpr UShortType PackageID = 0x2004;
		XtpRspMDInitField Field;
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
		static constexpr UShortType PackageID = 0x2005;
		XtpReqSubscribeMDField Field;
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
		static constexpr UShortType PackageID = 0x2006;
		XtpRspSubscribeMDField Field;
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
		static constexpr UShortType PackageID = 0x3001;
		XtpRtnShortMDField Field;
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
		static constexpr UShortType PackageID = 0x3002;
		XtpRtnExchangeStatusField Field;
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
		static constexpr UShortType PackageID = 0x3003;
		XtpRtnInstrumentField Field;
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
		static constexpr UShortType PackageID = 0x3004;
		XtpRtnMDInitCompletedField Field;
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
		XtpNotifyMdClientConnectedField Field;
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
		XtpNotifyMdClientDisConnectedField Field;
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
		XtpNotifyRiskCheckClientConnectedField Field;
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
		XtpNotifyRiskCheckClientDisConnectedField Field;
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
		XtpNotifyTradeFrontConnectedField Field;
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
		XtpNotifyTradeFrontDisConnectedField Field;
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
		XtpNotifyRiskFrontConnectedField Field;
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
		XtpNotifyRiskFrontDisConnectedField Field;
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
		XtpNotifyAdminFrontConnectedField Field;
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
		XtpNotifyAdminFrontDisConnectedField Field;
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
		XtpNotifyOfferFrontConnectedField Field;
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
		XtpNotifyOfferFrontDisConnectedField Field;
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
		XtpNotifyInitCompleteField Field;
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
		XtpRspNotifyInitCompleteField Field;
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
		XtpRtnRiskCheckOrderField Field;
	};

}
