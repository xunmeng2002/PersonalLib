#include "XtpPackageFactory.h"
#include "XtpPackages.h"



namespace xtp
{
	XtpPackageBase* XtpPackageFactory::CreateXtpPackage(UShortType packageID)
	{
		switch (packageID)
		{
		case XtpNotifyComponentConnectStatusPackage::PackageID:
		{
			return XtpNotifyComponentConnectStatusPackage::Allocate();
		}
		case XtpReqAccountLoginPackage::PackageID:
		{
			return XtpReqAccountLoginPackage::Allocate();
		}
		case XtpRspAccountLoginPackage::PackageID:
		{
			return XtpRspAccountLoginPackage::Allocate();
		}
		case XtpReqAccountLogoutPackage::PackageID:
		{
			return XtpReqAccountLogoutPackage::Allocate();
		}
		case XtpRspAccountLogoutPackage::PackageID:
		{
			return XtpRspAccountLogoutPackage::Allocate();
		}
		case XtpReqQryAccountPackage::PackageID:
		{
			return XtpReqQryAccountPackage::Allocate();
		}
		case XtpRspQryAccountPackage::PackageID:
		{
			return XtpRspQryAccountPackage::Allocate();
		}
		case XtpReqQryHolderAccountPackage::PackageID:
		{
			return XtpReqQryHolderAccountPackage::Allocate();
		}
		case XtpRspQryHolderAccountPackage::PackageID:
		{
			return XtpRspQryHolderAccountPackage::Allocate();
		}
		case XtpReqQryCapitalPackage::PackageID:
		{
			return XtpReqQryCapitalPackage::Allocate();
		}
		case XtpRspQryCapitalPackage::PackageID:
		{
			return XtpRspQryCapitalPackage::Allocate();
		}
		case XtpReqQryPositionPackage::PackageID:
		{
			return XtpReqQryPositionPackage::Allocate();
		}
		case XtpRspQryPositionPackage::PackageID:
		{
			return XtpRspQryPositionPackage::Allocate();
		}
		case XtpReqQryOrderPackage::PackageID:
		{
			return XtpReqQryOrderPackage::Allocate();
		}
		case XtpRspQryOrderPackage::PackageID:
		{
			return XtpRspQryOrderPackage::Allocate();
		}
		case XtpReqQryTradePackage::PackageID:
		{
			return XtpReqQryTradePackage::Allocate();
		}
		case XtpRspQryTradePackage::PackageID:
		{
			return XtpRspQryTradePackage::Allocate();
		}
		case XtpReqQryInstrumentPackage::PackageID:
		{
			return XtpReqQryInstrumentPackage::Allocate();
		}
		case XtpRspQryInstrumentPackage::PackageID:
		{
			return XtpRspQryInstrumentPackage::Allocate();
		}
		case XtpReqQryOptionInstrumentPackage::PackageID:
		{
			return XtpReqQryOptionInstrumentPackage::Allocate();
		}
		case XtpRspQryOptionInstrumentPackage::PackageID:
		{
			return XtpRspQryOptionInstrumentPackage::Allocate();
		}
		case XtpReqQryCommissionRatePackage::PackageID:
		{
			return XtpReqQryCommissionRatePackage::Allocate();
		}
		case XtpRspQryCommissionRatePackage::PackageID:
		{
			return XtpRspQryCommissionRatePackage::Allocate();
		}
		case XtpReqQryMoneyTransferPackage::PackageID:
		{
			return XtpReqQryMoneyTransferPackage::Allocate();
		}
		case XtpRspQryMoneyTransferPackage::PackageID:
		{
			return XtpRspQryMoneyTransferPackage::Allocate();
		}
		case XtpReqInsertOrderPackage::PackageID:
		{
			return XtpReqInsertOrderPackage::Allocate();
		}
		case XtpRspInsertOrderPackage::PackageID:
		{
			return XtpRspInsertOrderPackage::Allocate();
		}
		case XtpReqCancelOrderPackage::PackageID:
		{
			return XtpReqCancelOrderPackage::Allocate();
		}
		case XtpRspCancelOrderPackage::PackageID:
		{
			return XtpRspCancelOrderPackage::Allocate();
		}
		case XtpRtnOrderPackage::PackageID:
		{
			return XtpRtnOrderPackage::Allocate();
		}
		case XtpRtnTradePackage::PackageID:
		{
			return XtpRtnTradePackage::Allocate();
		}
		case XtpRtnMoneyTransferPackage::PackageID:
		{
			return XtpRtnMoneyTransferPackage::Allocate();
		}
		case XtpRtnAccountLogoutPackage::PackageID:
		{
			return XtpRtnAccountLogoutPackage::Allocate();
		}
		case XtpReqRiskUserLoginPackage::PackageID:
		{
			return XtpReqRiskUserLoginPackage::Allocate();
		}
		case XtpRspRiskUserLoginPackage::PackageID:
		{
			return XtpRspRiskUserLoginPackage::Allocate();
		}
		case XtpReqRiskUserLogoutPackage::PackageID:
		{
			return XtpReqRiskUserLogoutPackage::Allocate();
		}
		case XtpRspRiskUserLogoutPackage::PackageID:
		{
			return XtpRspRiskUserLogoutPackage::Allocate();
		}
		case XtpRtnRiskUserLogoutPackage::PackageID:
		{
			return XtpRtnRiskUserLogoutPackage::Allocate();
		}
		case XtpRtnAccountPackage::PackageID:
		{
			return XtpRtnAccountPackage::Allocate();
		}
		case XtpRtnAccountDeletePackage::PackageID:
		{
			return XtpRtnAccountDeletePackage::Allocate();
		}
		case XtpRtnPositionPackage::PackageID:
		{
			return XtpRtnPositionPackage::Allocate();
		}
		case XtpRtnAccountRiskPackage::PackageID:
		{
			return XtpRtnAccountRiskPackage::Allocate();
		}
		case XtpRtnAccountRiskDeletePackage::PackageID:
		{
			return XtpRtnAccountRiskDeletePackage::Allocate();
		}
		case XtpRtnAccountRiskNotifyPackage::PackageID:
		{
			return XtpRtnAccountRiskNotifyPackage::Allocate();
		}
		case XtpReqQryRiskGroupAccountPackage::PackageID:
		{
			return XtpReqQryRiskGroupAccountPackage::Allocate();
		}
		case XtpRspQryRiskGroupAccountPackage::PackageID:
		{
			return XtpRspQryRiskGroupAccountPackage::Allocate();
		}
		case XtpReqQryRiskGroupCapitalPackage::PackageID:
		{
			return XtpReqQryRiskGroupCapitalPackage::Allocate();
		}
		case XtpRspQryRiskGroupCapitalPackage::PackageID:
		{
			return XtpRspQryRiskGroupCapitalPackage::Allocate();
		}
		case XtpReqQryRiskGroupPositionPackage::PackageID:
		{
			return XtpReqQryRiskGroupPositionPackage::Allocate();
		}
		case XtpRspQryRiskGroupPositionPackage::PackageID:
		{
			return XtpRspQryRiskGroupPositionPackage::Allocate();
		}
		case XtpReqQryRiskGroupOrderPackage::PackageID:
		{
			return XtpReqQryRiskGroupOrderPackage::Allocate();
		}
		case XtpRspQryRiskGroupOrderPackage::PackageID:
		{
			return XtpRspQryRiskGroupOrderPackage::Allocate();
		}
		case XtpReqQryRiskGroupTradePackage::PackageID:
		{
			return XtpReqQryRiskGroupTradePackage::Allocate();
		}
		case XtpRspQryRiskGroupTradePackage::PackageID:
		{
			return XtpRspQryRiskGroupTradePackage::Allocate();
		}
		case XtpReqQryRiskGroupAccountRiskPackage::PackageID:
		{
			return XtpReqQryRiskGroupAccountRiskPackage::Allocate();
		}
		case XtpRspQryRiskGroupAccountRiskPackage::PackageID:
		{
			return XtpRspQryRiskGroupAccountRiskPackage::Allocate();
		}
		case XtpReqQryRiskGroupAccountRiskNotifyPackage::PackageID:
		{
			return XtpReqQryRiskGroupAccountRiskNotifyPackage::Allocate();
		}
		case XtpRspQryRiskGroupAccountRiskNotifyPackage::PackageID:
		{
			return XtpRspQryRiskGroupAccountRiskNotifyPackage::Allocate();
		}
		case XtpReqRiskInsertOrderPackage::PackageID:
		{
			return XtpReqRiskInsertOrderPackage::Allocate();
		}
		case XtpRspRiskInsertOrderPackage::PackageID:
		{
			return XtpRspRiskInsertOrderPackage::Allocate();
		}
		case XtpReqRiskCancelOrderPackage::PackageID:
		{
			return XtpReqRiskCancelOrderPackage::Allocate();
		}
		case XtpRspRiskCancelOrderPackage::PackageID:
		{
			return XtpRspRiskCancelOrderPackage::Allocate();
		}
		case XtpReqMdUserLoginPackage::PackageID:
		{
			return XtpReqMdUserLoginPackage::Allocate();
		}
		case XtpRspMdUserLoginPackage::PackageID:
		{
			return XtpRspMdUserLoginPackage::Allocate();
		}
		case XtpReqMdUserLogoutPackage::PackageID:
		{
			return XtpReqMdUserLogoutPackage::Allocate();
		}
		case XtpRspMdUserLogoutPackage::PackageID:
		{
			return XtpRspMdUserLogoutPackage::Allocate();
		}
		case XtpReqMdInitPackage::PackageID:
		{
			return XtpReqMdInitPackage::Allocate();
		}
		case XtpRspMdInitPackage::PackageID:
		{
			return XtpRspMdInitPackage::Allocate();
		}
		case XtpReqSubscribeMdPackage::PackageID:
		{
			return XtpReqSubscribeMdPackage::Allocate();
		}
		case XtpRspSubscribeMdPackage::PackageID:
		{
			return XtpRspSubscribeMdPackage::Allocate();
		}
		case XtpRtnShortMdPackage::PackageID:
		{
			return XtpRtnShortMdPackage::Allocate();
		}
		case XtpRtnExchangeStatusPackage::PackageID:
		{
			return XtpRtnExchangeStatusPackage::Allocate();
		}
		case XtpRtnMdInitCompletedPackage::PackageID:
		{
			return XtpRtnMdInitCompletedPackage::Allocate();
		}
		case XtpReqAdminUserLoginPackage::PackageID:
		{
			return XtpReqAdminUserLoginPackage::Allocate();
		}
		case XtpRspAdminUserLoginPackage::PackageID:
		{
			return XtpRspAdminUserLoginPackage::Allocate();
		}
		case XtpReqAdminUserLogoutPackage::PackageID:
		{
			return XtpReqAdminUserLogoutPackage::Allocate();
		}
		case XtpRspAdminUserLogoutPackage::PackageID:
		{
			return XtpRspAdminUserLogoutPackage::Allocate();
		}
		case XtpRtnAdminUserLogoutPackage::PackageID:
		{
			return XtpRtnAdminUserLogoutPackage::Allocate();
		}
		case XtpReqAddRiskUserPackage::PackageID:
		{
			return XtpReqAddRiskUserPackage::Allocate();
		}
		case XtpRspAddRiskUserPackage::PackageID:
		{
			return XtpRspAddRiskUserPackage::Allocate();
		}
		case XtpReqUpdateRiskUserPackage::PackageID:
		{
			return XtpReqUpdateRiskUserPackage::Allocate();
		}
		case XtpRspUpdateRiskUserPackage::PackageID:
		{
			return XtpRspUpdateRiskUserPackage::Allocate();
		}
		case XtpReqRemoveRiskUserPackage::PackageID:
		{
			return XtpReqRemoveRiskUserPackage::Allocate();
		}
		case XtpRspRemoveRiskUserPackage::PackageID:
		{
			return XtpRspRemoveRiskUserPackage::Allocate();
		}
		case XtpReqAddAdminUserPackage::PackageID:
		{
			return XtpReqAddAdminUserPackage::Allocate();
		}
		case XtpRspAddAdminUserPackage::PackageID:
		{
			return XtpRspAddAdminUserPackage::Allocate();
		}
		case XtpReqUpdateAdminUserPackage::PackageID:
		{
			return XtpReqUpdateAdminUserPackage::Allocate();
		}
		case XtpRspUpdateAdminUserPackage::PackageID:
		{
			return XtpRspUpdateAdminUserPackage::Allocate();
		}
		case XtpReqRemoveAdminUserPackage::PackageID:
		{
			return XtpReqRemoveAdminUserPackage::Allocate();
		}
		case XtpRspRemoveAdminUserPackage::PackageID:
		{
			return XtpRspRemoveAdminUserPackage::Allocate();
		}
		case XtpReqAddPrimaryAccountPackage::PackageID:
		{
			return XtpReqAddPrimaryAccountPackage::Allocate();
		}
		case XtpRspAddPrimaryAccountPackage::PackageID:
		{
			return XtpRspAddPrimaryAccountPackage::Allocate();
		}
		case XtpReqUpdatePrimaryAccountPackage::PackageID:
		{
			return XtpReqUpdatePrimaryAccountPackage::Allocate();
		}
		case XtpRspUpdatePrimaryAccountPackage::PackageID:
		{
			return XtpRspUpdatePrimaryAccountPackage::Allocate();
		}
		case XtpReqRemovePrimaryAccountPackage::PackageID:
		{
			return XtpReqRemovePrimaryAccountPackage::Allocate();
		}
		case XtpRspRemovePrimaryAccountPackage::PackageID:
		{
			return XtpRspRemovePrimaryAccountPackage::Allocate();
		}
		case XtpReqAddAccountPackage::PackageID:
		{
			return XtpReqAddAccountPackage::Allocate();
		}
		case XtpRspAddAccountPackage::PackageID:
		{
			return XtpRspAddAccountPackage::Allocate();
		}
		case XtpReqUpdateAccountPackage::PackageID:
		{
			return XtpReqUpdateAccountPackage::Allocate();
		}
		case XtpRspUpdateAccountPackage::PackageID:
		{
			return XtpRspUpdateAccountPackage::Allocate();
		}
		case XtpReqRemoveAccountPackage::PackageID:
		{
			return XtpReqRemoveAccountPackage::Allocate();
		}
		case XtpRspRemoveAccountPackage::PackageID:
		{
			return XtpRspRemoveAccountPackage::Allocate();
		}
		case XtpReqAddBaseCommissionPackage::PackageID:
		{
			return XtpReqAddBaseCommissionPackage::Allocate();
		}
		case XtpRspAddBaseCommissionPackage::PackageID:
		{
			return XtpRspAddBaseCommissionPackage::Allocate();
		}
		case XtpReqUpdateBaseCommissionPackage::PackageID:
		{
			return XtpReqUpdateBaseCommissionPackage::Allocate();
		}
		case XtpRspUpdateBaseCommissionPackage::PackageID:
		{
			return XtpRspUpdateBaseCommissionPackage::Allocate();
		}
		case XtpReqRemoveBaseCommissionPackage::PackageID:
		{
			return XtpReqRemoveBaseCommissionPackage::Allocate();
		}
		case XtpRspRemoveBaseCommissionPackage::PackageID:
		{
			return XtpRspRemoveBaseCommissionPackage::Allocate();
		}
		case XtpReqAddCommissionGroupPackage::PackageID:
		{
			return XtpReqAddCommissionGroupPackage::Allocate();
		}
		case XtpRspAddCommissionGroupPackage::PackageID:
		{
			return XtpRspAddCommissionGroupPackage::Allocate();
		}
		case XtpReqUpdateCommissionGroupPackage::PackageID:
		{
			return XtpReqUpdateCommissionGroupPackage::Allocate();
		}
		case XtpRspUpdateCommissionGroupPackage::PackageID:
		{
			return XtpRspUpdateCommissionGroupPackage::Allocate();
		}
		case XtpReqRemoveCommissionGroupPackage::PackageID:
		{
			return XtpReqRemoveCommissionGroupPackage::Allocate();
		}
		case XtpRspRemoveCommissionGroupPackage::PackageID:
		{
			return XtpRspRemoveCommissionGroupPackage::Allocate();
		}
		case XtpReqAddOptionMarginParamPackage::PackageID:
		{
			return XtpReqAddOptionMarginParamPackage::Allocate();
		}
		case XtpRspAddOptionMarginParamPackage::PackageID:
		{
			return XtpRspAddOptionMarginParamPackage::Allocate();
		}
		case XtpReqUpdateOptionMarginParamPackage::PackageID:
		{
			return XtpReqUpdateOptionMarginParamPackage::Allocate();
		}
		case XtpRspUpdateOptionMarginParamPackage::PackageID:
		{
			return XtpRspUpdateOptionMarginParamPackage::Allocate();
		}
		case XtpReqRemoveOptionMarginParamPackage::PackageID:
		{
			return XtpReqRemoveOptionMarginParamPackage::Allocate();
		}
		case XtpRspRemoveOptionMarginParamPackage::PackageID:
		{
			return XtpRspRemoveOptionMarginParamPackage::Allocate();
		}
		case XtpReqAddTradeOfferPackage::PackageID:
		{
			return XtpReqAddTradeOfferPackage::Allocate();
		}
		case XtpRspAddTradeOfferPackage::PackageID:
		{
			return XtpRspAddTradeOfferPackage::Allocate();
		}
		case XtpReqUpdateTradeOfferPackage::PackageID:
		{
			return XtpReqUpdateTradeOfferPackage::Allocate();
		}
		case XtpRspUpdateTradeOfferPackage::PackageID:
		{
			return XtpRspUpdateTradeOfferPackage::Allocate();
		}
		case XtpReqRemoveTradeOfferPackage::PackageID:
		{
			return XtpReqRemoveTradeOfferPackage::Allocate();
		}
		case XtpRspRemoveTradeOfferPackage::PackageID:
		{
			return XtpRspRemoveTradeOfferPackage::Allocate();
		}
		case XtpReqAddTradeGroupPackage::PackageID:
		{
			return XtpReqAddTradeGroupPackage::Allocate();
		}
		case XtpRspAddTradeGroupPackage::PackageID:
		{
			return XtpRspAddTradeGroupPackage::Allocate();
		}
		case XtpReqUpdateTradeGroupPackage::PackageID:
		{
			return XtpReqUpdateTradeGroupPackage::Allocate();
		}
		case XtpRspUpdateTradeGroupPackage::PackageID:
		{
			return XtpRspUpdateTradeGroupPackage::Allocate();
		}
		case XtpReqRemoveTradeGroupPackage::PackageID:
		{
			return XtpReqRemoveTradeGroupPackage::Allocate();
		}
		case XtpRspRemoveTradeGroupPackage::PackageID:
		{
			return XtpRspRemoveTradeGroupPackage::Allocate();
		}
		case XtpReqAddTradeGroupItemPackage::PackageID:
		{
			return XtpReqAddTradeGroupItemPackage::Allocate();
		}
		case XtpRspAddTradeGroupItemPackage::PackageID:
		{
			return XtpRspAddTradeGroupItemPackage::Allocate();
		}
		case XtpReqUpdateTradeGroupItemPackage::PackageID:
		{
			return XtpReqUpdateTradeGroupItemPackage::Allocate();
		}
		case XtpRspUpdateTradeGroupItemPackage::PackageID:
		{
			return XtpRspUpdateTradeGroupItemPackage::Allocate();
		}
		case XtpReqRemoveTradeGroupItemPackage::PackageID:
		{
			return XtpReqRemoveTradeGroupItemPackage::Allocate();
		}
		case XtpRspRemoveTradeGroupItemPackage::PackageID:
		{
			return XtpRspRemoveTradeGroupItemPackage::Allocate();
		}
		case XtpReqAddRiskGroupPackage::PackageID:
		{
			return XtpReqAddRiskGroupPackage::Allocate();
		}
		case XtpRspAddRiskGroupPackage::PackageID:
		{
			return XtpRspAddRiskGroupPackage::Allocate();
		}
		case XtpReqUpdateRiskGroupPackage::PackageID:
		{
			return XtpReqUpdateRiskGroupPackage::Allocate();
		}
		case XtpRspUpdateRiskGroupPackage::PackageID:
		{
			return XtpRspUpdateRiskGroupPackage::Allocate();
		}
		case XtpReqRemoveRiskGroupPackage::PackageID:
		{
			return XtpReqRemoveRiskGroupPackage::Allocate();
		}
		case XtpRspRemoveRiskGroupPackage::PackageID:
		{
			return XtpRspRemoveRiskGroupPackage::Allocate();
		}
		case XtpReqAddRiskGroupItemPackage::PackageID:
		{
			return XtpReqAddRiskGroupItemPackage::Allocate();
		}
		case XtpRspAddRiskGroupItemPackage::PackageID:
		{
			return XtpRspAddRiskGroupItemPackage::Allocate();
		}
		case XtpReqUpdateRiskGroupItemPackage::PackageID:
		{
			return XtpReqUpdateRiskGroupItemPackage::Allocate();
		}
		case XtpRspUpdateRiskGroupItemPackage::PackageID:
		{
			return XtpRspUpdateRiskGroupItemPackage::Allocate();
		}
		case XtpReqRemoveRiskGroupItemPackage::PackageID:
		{
			return XtpReqRemoveRiskGroupItemPackage::Allocate();
		}
		case XtpRspRemoveRiskGroupItemPackage::PackageID:
		{
			return XtpRspRemoveRiskGroupItemPackage::Allocate();
		}
		case XtpReqAddOrUpdateRiskPackage::PackageID:
		{
			return XtpReqAddOrUpdateRiskPackage::Allocate();
		}
		case XtpRspAddOrUpdateRiskPackage::PackageID:
		{
			return XtpRspAddOrUpdateRiskPackage::Allocate();
		}
		case XtpReqRemoveRiskPackage::PackageID:
		{
			return XtpReqRemoveRiskPackage::Allocate();
		}
		case XtpRspRemoveRiskPackage::PackageID:
		{
			return XtpRspRemoveRiskPackage::Allocate();
		}
		case XtpReqAddRiskRulePackage::PackageID:
		{
			return XtpReqAddRiskRulePackage::Allocate();
		}
		case XtpRspAddRiskRulePackage::PackageID:
		{
			return XtpRspAddRiskRulePackage::Allocate();
		}
		case XtpReqAddRiskRuleItemPackage::PackageID:
		{
			return XtpReqAddRiskRuleItemPackage::Allocate();
		}
		case XtpRspAddRiskRuleItemPackage::PackageID:
		{
			return XtpRspAddRiskRuleItemPackage::Allocate();
		}
		case XtpReqAddRiskTradeScopePackage::PackageID:
		{
			return XtpReqAddRiskTradeScopePackage::Allocate();
		}
		case XtpRspAddRiskTradeScopePackage::PackageID:
		{
			return XtpRspAddRiskTradeScopePackage::Allocate();
		}
		case XtpReqAddAccountRiskPackage::PackageID:
		{
			return XtpReqAddAccountRiskPackage::Allocate();
		}
		case XtpRspAddAccountRiskPackage::PackageID:
		{
			return XtpRspAddAccountRiskPackage::Allocate();
		}
		case XtpReqRemoveAccountRiskPackage::PackageID:
		{
			return XtpReqRemoveAccountRiskPackage::Allocate();
		}
		case XtpRspRemoveAccountRiskPackage::PackageID:
		{
			return XtpRspRemoveAccountRiskPackage::Allocate();
		}
		case XtpReqMoneyTransferPackage::PackageID:
		{
			return XtpReqMoneyTransferPackage::Allocate();
		}
		case XtpRspMoneyTransferPackage::PackageID:
		{
			return XtpRspMoneyTransferPackage::Allocate();
		}
		case XtpReqAuditOrderPackage::PackageID:
		{
			return XtpReqAuditOrderPackage::Allocate();
		}
		case XtpRspAuditOrderPackage::PackageID:
		{
			return XtpRspAuditOrderPackage::Allocate();
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
		case XtpReqQryOfferOptionInstrumentPackage::PackageID:
		{
			return XtpReqQryOfferOptionInstrumentPackage::Allocate();
		}
		case XtpRspQryOfferOptionInstrumentPackage::PackageID:
		{
			return XtpRspQryOfferOptionInstrumentPackage::Allocate();
		}
		case XtpRtnOfferOptionInstrumentPackage::PackageID:
		{
			return XtpRtnOfferOptionInstrumentPackage::Allocate();
		}
		case XtpReqOfferOrderPackage::PackageID:
		{
			return XtpReqOfferOrderPackage::Allocate();
		}
		case XtpReqOfferCancelOrderPackage::PackageID:
		{
			return XtpReqOfferCancelOrderPackage::Allocate();
		}
		case XtpRtnOfferOrderPackage::PackageID:
		{
			return XtpRtnOfferOrderPackage::Allocate();
		}
		case XtpRtnOfferTradePackage::PackageID:
		{
			return XtpRtnOfferTradePackage::Allocate();
		}
		case XtpRtnOfferErrorCancelOrderPackage::PackageID:
		{
			return XtpRtnOfferErrorCancelOrderPackage::Allocate();
		}
		case XtpRtnOfferCapitalPackage::PackageID:
		{
			return XtpRtnOfferCapitalPackage::Allocate();
		}
		case XtpRtnOfferPositionPackage::PackageID:
		{
			return XtpRtnOfferPositionPackage::Allocate();
		}
		default:
			break;
		}
		return nullptr;
	}
}
