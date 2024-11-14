#include "XtpPackageFactory.h"
#include "XtpPackages.h"



namespace xtp
{
	XtpPackageBase* XtpPackageFactory::CreateXtpPackage(UShortType packageID)
	{
		switch (packageID)
		{
		case XtpSessionClosePackage::PackageID:
		{
			return XtpSessionClosePackage::Allocate();
		}
		case XtpReqOfferLoginPackage::PackageID:
		{
			return XtpReqOfferLoginPackage::Allocate();
		}
		case XtpRspOfferLoginPackage::PackageID:
		{
			return XtpRspOfferLoginPackage::Allocate();
		}
		case XtpReqPrimaryAccountLoginPackage::PackageID:
		{
			return XtpReqPrimaryAccountLoginPackage::Allocate();
		}
		case XtpRspPrimaryAccountLoginPackage::PackageID:
		{
			return XtpRspPrimaryAccountLoginPackage::Allocate();
		}
		case XtpReqPrimaryAccountLogoutPackage::PackageID:
		{
			return XtpReqPrimaryAccountLogoutPackage::Allocate();
		}
		case XtpRtnPrimaryAccountLogoutPackage::PackageID:
		{
			return XtpRtnPrimaryAccountLogoutPackage::Allocate();
		}
		case XtpReqPrimaryAccountInitPackage::PackageID:
		{
			return XtpReqPrimaryAccountInitPackage::Allocate();
		}
		case XtpRspPrimaryAccountInitPackage::PackageID:
		{
			return XtpRspPrimaryAccountInitPackage::Allocate();
		}
		case XtpReqPrimaryAccountQueryPackage::PackageID:
		{
			return XtpReqPrimaryAccountQueryPackage::Allocate();
		}
		case XtpRspPrimaryAccountQueryPackage::PackageID:
		{
			return XtpRspPrimaryAccountQueryPackage::Allocate();
		}
		case XtpReqQryOptionInstrumentPackage::PackageID:
		{
			return XtpReqQryOptionInstrumentPackage::Allocate();
		}
		case XtpRspQryOptionInstrumentPackage::PackageID:
		{
			return XtpRspQryOptionInstrumentPackage::Allocate();
		}
		case XtpRtnOptionInstrumentPackage::PackageID:
		{
			return XtpRtnOptionInstrumentPackage::Allocate();
		}
		case XtpReqInsertOrderPackage::PackageID:
		{
			return XtpReqInsertOrderPackage::Allocate();
		}
		case XtpReqCancelOrderPackage::PackageID:
		{
			return XtpReqCancelOrderPackage::Allocate();
		}
		case XtpRtnOrderPackage::PackageID:
		{
			return XtpRtnOrderPackage::Allocate();
		}
		case XtpRtnTradePackage::PackageID:
		{
			return XtpRtnTradePackage::Allocate();
		}
		case XtpRtnErrorCancelOrderPackage::PackageID:
		{
			return XtpRtnErrorCancelOrderPackage::Allocate();
		}
		case XtpRtnCapitalPackage::PackageID:
		{
			return XtpRtnCapitalPackage::Allocate();
		}
		case XtpRtnPositionPackage::PackageID:
		{
			return XtpRtnPositionPackage::Allocate();
		}
		case XtpReqMDOfferLoginPackage::PackageID:
		{
			return XtpReqMDOfferLoginPackage::Allocate();
		}
		case XtpRspMDOfferLoginPackage::PackageID:
		{
			return XtpRspMDOfferLoginPackage::Allocate();
		}
		case XtpReqMDInitPackage::PackageID:
		{
			return XtpReqMDInitPackage::Allocate();
		}
		case XtpRspMDInitPackage::PackageID:
		{
			return XtpRspMDInitPackage::Allocate();
		}
		case XtpReqSubscribeMDPackage::PackageID:
		{
			return XtpReqSubscribeMDPackage::Allocate();
		}
		case XtpRspSubscribeMDPackage::PackageID:
		{
			return XtpRspSubscribeMDPackage::Allocate();
		}
		case XtpRtnShortMDPackage::PackageID:
		{
			return XtpRtnShortMDPackage::Allocate();
		}
		case XtpRtnExchangeStatusPackage::PackageID:
		{
			return XtpRtnExchangeStatusPackage::Allocate();
		}
		case XtpRtnInstrumentPackage::PackageID:
		{
			return XtpRtnInstrumentPackage::Allocate();
		}
		case XtpRtnMDInitCompletedPackage::PackageID:
		{
			return XtpRtnMDInitCompletedPackage::Allocate();
		}
		case XtpNotifyMdClientConnectedPackage::PackageID:
		{
			return XtpNotifyMdClientConnectedPackage::Allocate();
		}
		case XtpNotifyMdClientDisConnectedPackage::PackageID:
		{
			return XtpNotifyMdClientDisConnectedPackage::Allocate();
		}
		case XtpNotifyRiskCheckClientConnectedPackage::PackageID:
		{
			return XtpNotifyRiskCheckClientConnectedPackage::Allocate();
		}
		case XtpNotifyRiskCheckClientDisConnectedPackage::PackageID:
		{
			return XtpNotifyRiskCheckClientDisConnectedPackage::Allocate();
		}
		case XtpNotifyTradeFrontConnectedPackage::PackageID:
		{
			return XtpNotifyTradeFrontConnectedPackage::Allocate();
		}
		case XtpNotifyTradeFrontDisConnectedPackage::PackageID:
		{
			return XtpNotifyTradeFrontDisConnectedPackage::Allocate();
		}
		case XtpNotifyRiskFrontConnectedPackage::PackageID:
		{
			return XtpNotifyRiskFrontConnectedPackage::Allocate();
		}
		case XtpNotifyRiskFrontDisConnectedPackage::PackageID:
		{
			return XtpNotifyRiskFrontDisConnectedPackage::Allocate();
		}
		case XtpNotifyAdminFrontConnectedPackage::PackageID:
		{
			return XtpNotifyAdminFrontConnectedPackage::Allocate();
		}
		case XtpNotifyAdminFrontDisConnectedPackage::PackageID:
		{
			return XtpNotifyAdminFrontDisConnectedPackage::Allocate();
		}
		case XtpNotifyOfferFrontConnectedPackage::PackageID:
		{
			return XtpNotifyOfferFrontConnectedPackage::Allocate();
		}
		case XtpNotifyOfferFrontDisConnectedPackage::PackageID:
		{
			return XtpNotifyOfferFrontDisConnectedPackage::Allocate();
		}
		case XtpNotifyInitCompletePackage::PackageID:
		{
			return XtpNotifyInitCompletePackage::Allocate();
		}
		case XtpRspNotifyInitCompletePackage::PackageID:
		{
			return XtpRspNotifyInitCompletePackage::Allocate();
		}
		case XtpRtnRiskCheckOrderPackage::PackageID:
		{
			return XtpRtnRiskCheckOrderPackage::Allocate();
		}
		default:
			break;
		}
		return nullptr;
	}
}
