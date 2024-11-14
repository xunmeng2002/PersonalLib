#include "StepPackageFactory.h"
#include "StepPackages.h"


namespace step
{
	StepPackageBase* StepPackageFactory::CreateStepPackage(UShortType packageID)
	{
		switch (packageID)
		{
		case StepReqAccountLoginPackage::PackageID:
		{
			return StepReqAccountLoginPackage::Allocate();
		}
		case StepRspAccountLoginPackage::PackageID:
		{
			return StepRspAccountLoginPackage::Allocate();
		}
		case StepReqAccountLogoutPackage::PackageID:
		{
			return StepReqAccountLogoutPackage::Allocate();
		}
		case StepRspAccountLogoutPackage::PackageID:
		{
			return StepRspAccountLogoutPackage::Allocate();
		}
		case StepRtnAccountLogoutPackage::PackageID:
		{
			return StepRtnAccountLogoutPackage::Allocate();
		}
		case StepReqRiskUserLoginPackage::PackageID:
		{
			return StepReqRiskUserLoginPackage::Allocate();
		}
		case StepRspRiskUserLoginPackage::PackageID:
		{
			return StepRspRiskUserLoginPackage::Allocate();
		}
		case StepReqRiskUserLogoutPackage::PackageID:
		{
			return StepReqRiskUserLogoutPackage::Allocate();
		}
		case StepRspRiskUserLogoutPackage::PackageID:
		{
			return StepRspRiskUserLogoutPackage::Allocate();
		}
		case StepRtnRiskUserLogoutPackage::PackageID:
		{
			return StepRtnRiskUserLogoutPackage::Allocate();
		}
		case StepReqAdminUserLoginPackage::PackageID:
		{
			return StepReqAdminUserLoginPackage::Allocate();
		}
		case StepRspAdminUserLoginPackage::PackageID:
		{
			return StepRspAdminUserLoginPackage::Allocate();
		}
		case StepReqAdminUserLogoutPackage::PackageID:
		{
			return StepReqAdminUserLogoutPackage::Allocate();
		}
		case StepRspAdminUserLogoutPackage::PackageID:
		{
			return StepRspAdminUserLogoutPackage::Allocate();
		}
		case StepRtnAdminUserLogoutPackage::PackageID:
		{
			return StepRtnAdminUserLogoutPackage::Allocate();
		}
		case StepReqMdUserLoginPackage::PackageID:
		{
			return StepReqMdUserLoginPackage::Allocate();
		}
		case StepRspMdUserLoginPackage::PackageID:
		{
			return StepRspMdUserLoginPackage::Allocate();
		}
		case StepReqMdUserLogoutPackage::PackageID:
		{
			return StepReqMdUserLogoutPackage::Allocate();
		}
		case StepRspMdUserLogoutPackage::PackageID:
		{
			return StepRspMdUserLogoutPackage::Allocate();
		}
		case StepReqQryAccountPackage::PackageID:
		{
			return StepReqQryAccountPackage::Allocate();
		}
		case StepRspQryAccountPackage::PackageID:
		{
			return StepRspQryAccountPackage::Allocate();
		}
		case StepReqQryHolderAccountPackage::PackageID:
		{
			return StepReqQryHolderAccountPackage::Allocate();
		}
		case StepRspQryHolderAccountPackage::PackageID:
		{
			return StepRspQryHolderAccountPackage::Allocate();
		}
		case StepReqQryCapitalPackage::PackageID:
		{
			return StepReqQryCapitalPackage::Allocate();
		}
		case StepRspQryCapitalPackage::PackageID:
		{
			return StepRspQryCapitalPackage::Allocate();
		}
		case StepReqQryPositionPackage::PackageID:
		{
			return StepReqQryPositionPackage::Allocate();
		}
		case StepRspQryPositionPackage::PackageID:
		{
			return StepRspQryPositionPackage::Allocate();
		}
		case StepRtnPositionPackage::PackageID:
		{
			return StepRtnPositionPackage::Allocate();
		}
		case StepReqQryOrderPackage::PackageID:
		{
			return StepReqQryOrderPackage::Allocate();
		}
		case StepRspQryOrderPackage::PackageID:
		{
			return StepRspQryOrderPackage::Allocate();
		}
		case StepRtnOrderPackage::PackageID:
		{
			return StepRtnOrderPackage::Allocate();
		}
		case StepReqQryTradePackage::PackageID:
		{
			return StepReqQryTradePackage::Allocate();
		}
		case StepRspQryTradePackage::PackageID:
		{
			return StepRspQryTradePackage::Allocate();
		}
		case StepRtnTradePackage::PackageID:
		{
			return StepRtnTradePackage::Allocate();
		}
		case StepReqQryInstrumentPackage::PackageID:
		{
			return StepReqQryInstrumentPackage::Allocate();
		}
		case StepRspQryInstrumentPackage::PackageID:
		{
			return StepRspQryInstrumentPackage::Allocate();
		}
		case StepReqQryOptionInstrumentPackage::PackageID:
		{
			return StepReqQryOptionInstrumentPackage::Allocate();
		}
		case StepRspQryOptionInstrumentPackage::PackageID:
		{
			return StepRspQryOptionInstrumentPackage::Allocate();
		}
		case StepReqQryCommissionRatePackage::PackageID:
		{
			return StepReqQryCommissionRatePackage::Allocate();
		}
		case StepRspQryCommissionRatePackage::PackageID:
		{
			return StepRspQryCommissionRatePackage::Allocate();
		}
		case StepReqInsertOrderPackage::PackageID:
		{
			return StepReqInsertOrderPackage::Allocate();
		}
		case StepRspInsertOrderPackage::PackageID:
		{
			return StepRspInsertOrderPackage::Allocate();
		}
		case StepReqCancelOrderPackage::PackageID:
		{
			return StepReqCancelOrderPackage::Allocate();
		}
		case StepRspCancelOrderPackage::PackageID:
		{
			return StepRspCancelOrderPackage::Allocate();
		}
		case StepReqMdInitPackage::PackageID:
		{
			return StepReqMdInitPackage::Allocate();
		}
		case StepRspMdInitPackage::PackageID:
		{
			return StepRspMdInitPackage::Allocate();
		}
		case StepReqSubscribeMdPackage::PackageID:
		{
			return StepReqSubscribeMdPackage::Allocate();
		}
		case StepRspSubscribeMdPackage::PackageID:
		{
			return StepRspSubscribeMdPackage::Allocate();
		}
		case StepRtnAccountPackage::PackageID:
		{
			return StepRtnAccountPackage::Allocate();
		}
		case StepRtnAccountDeletePackage::PackageID:
		{
			return StepRtnAccountDeletePackage::Allocate();
		}
		case StepRtnAccountRiskPackage::PackageID:
		{
			return StepRtnAccountRiskPackage::Allocate();
		}
		case StepRtnAccountRiskDeletePackage::PackageID:
		{
			return StepRtnAccountRiskDeletePackage::Allocate();
		}
		case StepRtnAccountRiskNotifyPackage::PackageID:
		{
			return StepRtnAccountRiskNotifyPackage::Allocate();
		}
		case StepRtnShortMdPackage::PackageID:
		{
			return StepRtnShortMdPackage::Allocate();
		}
		case StepRtnExchangeStatusPackage::PackageID:
		{
			return StepRtnExchangeStatusPackage::Allocate();
		}
		case StepRtnMdInitCompletedPackage::PackageID:
		{
			return StepRtnMdInitCompletedPackage::Allocate();
		}
		case StepReqQryRiskGroupAccountPackage::PackageID:
		{
			return StepReqQryRiskGroupAccountPackage::Allocate();
		}
		case StepRspQryRiskGroupAccountPackage::PackageID:
		{
			return StepRspQryRiskGroupAccountPackage::Allocate();
		}
		case StepReqQryRiskGroupCapitalPackage::PackageID:
		{
			return StepReqQryRiskGroupCapitalPackage::Allocate();
		}
		case StepRspQryRiskGroupCapitalPackage::PackageID:
		{
			return StepRspQryRiskGroupCapitalPackage::Allocate();
		}
		case StepReqQryRiskGroupPositionPackage::PackageID:
		{
			return StepReqQryRiskGroupPositionPackage::Allocate();
		}
		case StepRspQryRiskGroupPositionPackage::PackageID:
		{
			return StepRspQryRiskGroupPositionPackage::Allocate();
		}
		case StepReqQryRiskGroupOrderPackage::PackageID:
		{
			return StepReqQryRiskGroupOrderPackage::Allocate();
		}
		case StepRspQryRiskGroupOrderPackage::PackageID:
		{
			return StepRspQryRiskGroupOrderPackage::Allocate();
		}
		case StepReqQryRiskGroupTradePackage::PackageID:
		{
			return StepReqQryRiskGroupTradePackage::Allocate();
		}
		case StepRspQryRiskGroupTradePackage::PackageID:
		{
			return StepRspQryRiskGroupTradePackage::Allocate();
		}
		case StepReqQryRiskGroupAccountRiskPackage::PackageID:
		{
			return StepReqQryRiskGroupAccountRiskPackage::Allocate();
		}
		case StepRspQryRiskGroupAccountRiskPackage::PackageID:
		{
			return StepRspQryRiskGroupAccountRiskPackage::Allocate();
		}
		case StepReqQryRiskGroupAccountRiskNotifyPackage::PackageID:
		{
			return StepReqQryRiskGroupAccountRiskNotifyPackage::Allocate();
		}
		case StepRspQryRiskGroupAccountRiskNotifyPackage::PackageID:
		{
			return StepRspQryRiskGroupAccountRiskNotifyPackage::Allocate();
		}
		case StepReqRiskInsertOrderPackage::PackageID:
		{
			return StepReqRiskInsertOrderPackage::Allocate();
		}
		case StepRspRiskInsertOrderPackage::PackageID:
		{
			return StepRspRiskInsertOrderPackage::Allocate();
		}
		case StepReqRiskCancelOrderPackage::PackageID:
		{
			return StepReqRiskCancelOrderPackage::Allocate();
		}
		case StepRspRiskCancelOrderPackage::PackageID:
		{
			return StepRspRiskCancelOrderPackage::Allocate();
		}
		case StepReqAddRiskUserPackage::PackageID:
		{
			return StepReqAddRiskUserPackage::Allocate();
		}
		case StepRspAddRiskUserPackage::PackageID:
		{
			return StepRspAddRiskUserPackage::Allocate();
		}
		case StepReqUpdateRiskUserPackage::PackageID:
		{
			return StepReqUpdateRiskUserPackage::Allocate();
		}
		case StepRspUpdateRiskUserPackage::PackageID:
		{
			return StepRspUpdateRiskUserPackage::Allocate();
		}
		case StepReqRemoveRiskUserPackage::PackageID:
		{
			return StepReqRemoveRiskUserPackage::Allocate();
		}
		case StepRspRemoveRiskUserPackage::PackageID:
		{
			return StepRspRemoveRiskUserPackage::Allocate();
		}
		case StepReqAddAdminUserPackage::PackageID:
		{
			return StepReqAddAdminUserPackage::Allocate();
		}
		case StepRspAddAdminUserPackage::PackageID:
		{
			return StepRspAddAdminUserPackage::Allocate();
		}
		case StepReqUpdateAdminUserPackage::PackageID:
		{
			return StepReqUpdateAdminUserPackage::Allocate();
		}
		case StepRspUpdateAdminUserPackage::PackageID:
		{
			return StepRspUpdateAdminUserPackage::Allocate();
		}
		case StepReqRemoveAdminUserPackage::PackageID:
		{
			return StepReqRemoveAdminUserPackage::Allocate();
		}
		case StepRspRemoveAdminUserPackage::PackageID:
		{
			return StepRspRemoveAdminUserPackage::Allocate();
		}
		case StepReqAddPrimaryAccountPackage::PackageID:
		{
			return StepReqAddPrimaryAccountPackage::Allocate();
		}
		case StepRspAddPrimaryAccountPackage::PackageID:
		{
			return StepRspAddPrimaryAccountPackage::Allocate();
		}
		case StepReqUpdatePrimaryAccountPackage::PackageID:
		{
			return StepReqUpdatePrimaryAccountPackage::Allocate();
		}
		case StepRspUpdatePrimaryAccountPackage::PackageID:
		{
			return StepRspUpdatePrimaryAccountPackage::Allocate();
		}
		case StepReqRemovePrimaryAccountPackage::PackageID:
		{
			return StepReqRemovePrimaryAccountPackage::Allocate();
		}
		case StepRspRemovePrimaryAccountPackage::PackageID:
		{
			return StepRspRemovePrimaryAccountPackage::Allocate();
		}
		case StepReqAddAccountPackage::PackageID:
		{
			return StepReqAddAccountPackage::Allocate();
		}
		case StepRspAddAccountPackage::PackageID:
		{
			return StepRspAddAccountPackage::Allocate();
		}
		case StepReqUpdateAccountPackage::PackageID:
		{
			return StepReqUpdateAccountPackage::Allocate();
		}
		case StepRspUpdateAccountPackage::PackageID:
		{
			return StepRspUpdateAccountPackage::Allocate();
		}
		case StepReqRemoveAccountPackage::PackageID:
		{
			return StepReqRemoveAccountPackage::Allocate();
		}
		case StepRspRemoveAccountPackage::PackageID:
		{
			return StepRspRemoveAccountPackage::Allocate();
		}
		case StepReqAddBaseCommissionPackage::PackageID:
		{
			return StepReqAddBaseCommissionPackage::Allocate();
		}
		case StepRspAddBaseCommissionPackage::PackageID:
		{
			return StepRspAddBaseCommissionPackage::Allocate();
		}
		case StepReqUpdateBaseCommissionPackage::PackageID:
		{
			return StepReqUpdateBaseCommissionPackage::Allocate();
		}
		case StepRspUpdateBaseCommissionPackage::PackageID:
		{
			return StepRspUpdateBaseCommissionPackage::Allocate();
		}
		case StepReqRemoveBaseCommissionPackage::PackageID:
		{
			return StepReqRemoveBaseCommissionPackage::Allocate();
		}
		case StepRspRemoveBaseCommissionPackage::PackageID:
		{
			return StepRspRemoveBaseCommissionPackage::Allocate();
		}
		case StepReqAddCommissionGroupPackage::PackageID:
		{
			return StepReqAddCommissionGroupPackage::Allocate();
		}
		case StepRspAddCommissionGroupPackage::PackageID:
		{
			return StepRspAddCommissionGroupPackage::Allocate();
		}
		case StepReqUpdateCommissionGroupPackage::PackageID:
		{
			return StepReqUpdateCommissionGroupPackage::Allocate();
		}
		case StepRspUpdateCommissionGroupPackage::PackageID:
		{
			return StepRspUpdateCommissionGroupPackage::Allocate();
		}
		case StepReqRemoveCommissionGroupPackage::PackageID:
		{
			return StepReqRemoveCommissionGroupPackage::Allocate();
		}
		case StepRspRemoveCommissionGroupPackage::PackageID:
		{
			return StepRspRemoveCommissionGroupPackage::Allocate();
		}
		case StepReqAddOptionMarginParamPackage::PackageID:
		{
			return StepReqAddOptionMarginParamPackage::Allocate();
		}
		case StepRspAddOptionMarginParamPackage::PackageID:
		{
			return StepRspAddOptionMarginParamPackage::Allocate();
		}
		case StepReqUpdateOptionMarginParamPackage::PackageID:
		{
			return StepReqUpdateOptionMarginParamPackage::Allocate();
		}
		case StepRspUpdateOptionMarginParamPackage::PackageID:
		{
			return StepRspUpdateOptionMarginParamPackage::Allocate();
		}
		case StepReqRemoveOptionMarginParamPackage::PackageID:
		{
			return StepReqRemoveOptionMarginParamPackage::Allocate();
		}
		case StepRspRemoveOptionMarginParamPackage::PackageID:
		{
			return StepRspRemoveOptionMarginParamPackage::Allocate();
		}
		case StepReqAddTradeOfferPackage::PackageID:
		{
			return StepReqAddTradeOfferPackage::Allocate();
		}
		case StepRspAddTradeOfferPackage::PackageID:
		{
			return StepRspAddTradeOfferPackage::Allocate();
		}
		case StepReqUpdateTradeOfferPackage::PackageID:
		{
			return StepReqUpdateTradeOfferPackage::Allocate();
		}
		case StepRspUpdateTradeOfferPackage::PackageID:
		{
			return StepRspUpdateTradeOfferPackage::Allocate();
		}
		case StepReqRemoveTradeOfferPackage::PackageID:
		{
			return StepReqRemoveTradeOfferPackage::Allocate();
		}
		case StepRspRemoveTradeOfferPackage::PackageID:
		{
			return StepRspRemoveTradeOfferPackage::Allocate();
		}
		case StepReqAddTradeGroupPackage::PackageID:
		{
			return StepReqAddTradeGroupPackage::Allocate();
		}
		case StepRspAddTradeGroupPackage::PackageID:
		{
			return StepRspAddTradeGroupPackage::Allocate();
		}
		case StepReqUpdateTradeGroupPackage::PackageID:
		{
			return StepReqUpdateTradeGroupPackage::Allocate();
		}
		case StepRspUpdateTradeGroupPackage::PackageID:
		{
			return StepRspUpdateTradeGroupPackage::Allocate();
		}
		case StepReqRemoveTradeGroupPackage::PackageID:
		{
			return StepReqRemoveTradeGroupPackage::Allocate();
		}
		case StepRspRemoveTradeGroupPackage::PackageID:
		{
			return StepRspRemoveTradeGroupPackage::Allocate();
		}
		case StepReqAddTradeGroupItemPackage::PackageID:
		{
			return StepReqAddTradeGroupItemPackage::Allocate();
		}
		case StepRspAddTradeGroupItemPackage::PackageID:
		{
			return StepRspAddTradeGroupItemPackage::Allocate();
		}
		case StepReqUpdateTradeGroupItemPackage::PackageID:
		{
			return StepReqUpdateTradeGroupItemPackage::Allocate();
		}
		case StepRspUpdateTradeGroupItemPackage::PackageID:
		{
			return StepRspUpdateTradeGroupItemPackage::Allocate();
		}
		case StepReqRemoveTradeGroupItemPackage::PackageID:
		{
			return StepReqRemoveTradeGroupItemPackage::Allocate();
		}
		case StepRspRemoveTradeGroupItemPackage::PackageID:
		{
			return StepRspRemoveTradeGroupItemPackage::Allocate();
		}
		case StepReqAddRiskGroupPackage::PackageID:
		{
			return StepReqAddRiskGroupPackage::Allocate();
		}
		case StepRspAddRiskGroupPackage::PackageID:
		{
			return StepRspAddRiskGroupPackage::Allocate();
		}
		case StepReqUpdateRiskGroupPackage::PackageID:
		{
			return StepReqUpdateRiskGroupPackage::Allocate();
		}
		case StepRspUpdateRiskGroupPackage::PackageID:
		{
			return StepRspUpdateRiskGroupPackage::Allocate();
		}
		case StepReqRemoveRiskGroupPackage::PackageID:
		{
			return StepReqRemoveRiskGroupPackage::Allocate();
		}
		case StepRspRemoveRiskGroupPackage::PackageID:
		{
			return StepRspRemoveRiskGroupPackage::Allocate();
		}
		case StepReqAddRiskGroupItemPackage::PackageID:
		{
			return StepReqAddRiskGroupItemPackage::Allocate();
		}
		case StepRspAddRiskGroupItemPackage::PackageID:
		{
			return StepRspAddRiskGroupItemPackage::Allocate();
		}
		case StepReqUpdateRiskGroupItemPackage::PackageID:
		{
			return StepReqUpdateRiskGroupItemPackage::Allocate();
		}
		case StepRspUpdateRiskGroupItemPackage::PackageID:
		{
			return StepRspUpdateRiskGroupItemPackage::Allocate();
		}
		case StepReqRemoveRiskGroupItemPackage::PackageID:
		{
			return StepReqRemoveRiskGroupItemPackage::Allocate();
		}
		case StepRspRemoveRiskGroupItemPackage::PackageID:
		{
			return StepRspRemoveRiskGroupItemPackage::Allocate();
		}
		case StepReqAddOrUpdateRiskPackage::PackageID:
		{
			return StepReqAddOrUpdateRiskPackage::Allocate();
		}
		case StepRspAddOrUpdateRiskPackage::PackageID:
		{
			return StepRspAddOrUpdateRiskPackage::Allocate();
		}
		case StepReqRemoveRiskPackage::PackageID:
		{
			return StepReqRemoveRiskPackage::Allocate();
		}
		case StepRspRemoveRiskPackage::PackageID:
		{
			return StepRspRemoveRiskPackage::Allocate();
		}
		case StepReqAddRiskRulePackage::PackageID:
		{
			return StepReqAddRiskRulePackage::Allocate();
		}
		case StepRspAddRiskRulePackage::PackageID:
		{
			return StepRspAddRiskRulePackage::Allocate();
		}
		case StepReqAddRiskRuleItemPackage::PackageID:
		{
			return StepReqAddRiskRuleItemPackage::Allocate();
		}
		case StepRspAddRiskRuleItemPackage::PackageID:
		{
			return StepRspAddRiskRuleItemPackage::Allocate();
		}
		case StepReqAddRiskTradeScopePackage::PackageID:
		{
			return StepReqAddRiskTradeScopePackage::Allocate();
		}
		case StepRspAddRiskTradeScopePackage::PackageID:
		{
			return StepRspAddRiskTradeScopePackage::Allocate();
		}
		case StepReqAddAccountRiskPackage::PackageID:
		{
			return StepReqAddAccountRiskPackage::Allocate();
		}
		case StepRspAddAccountRiskPackage::PackageID:
		{
			return StepRspAddAccountRiskPackage::Allocate();
		}
		case StepReqRemoveAccountRiskPackage::PackageID:
		{
			return StepReqRemoveAccountRiskPackage::Allocate();
		}
		case StepRspRemoveAccountRiskPackage::PackageID:
		{
			return StepRspRemoveAccountRiskPackage::Allocate();
		}
		case StepReqMoneyTransferPackage::PackageID:
		{
			return StepReqMoneyTransferPackage::Allocate();
		}
		case StepRspMoneyTransferPackage::PackageID:
		{
			return StepRspMoneyTransferPackage::Allocate();
		}
		case StepReqQryMoneyTransferPackage::PackageID:
		{
			return StepReqQryMoneyTransferPackage::Allocate();
		}
		case StepRspQryMoneyTransferPackage::PackageID:
		{
			return StepRspQryMoneyTransferPackage::Allocate();
		}
		case StepRtnMoneyTransferPackage::PackageID:
		{
			return StepRtnMoneyTransferPackage::Allocate();
		}
		case StepReqAuditOrderPackage::PackageID:
		{
			return StepReqAuditOrderPackage::Allocate();
		}
		case StepRspAuditOrderPackage::PackageID:
		{
			return StepRspAuditOrderPackage::Allocate();
		}
		default:
			break;
		}
		return nullptr;
	}
}
