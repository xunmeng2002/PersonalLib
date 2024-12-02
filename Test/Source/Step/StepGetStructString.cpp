#include "StepGetStructString.h"
#include <cstring>

static thread_local char t_StepFieldStringBuffer[10240];


namespace step
{
	std::string GetString(StepRspInfoField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%d, %s", field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspInfoField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspInfoField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspInfo:ErrorID:[0x%04X], ErrorMsg:[%s]", field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAccountLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AccountID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAccountLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLoginField:AccountID:[%s], Password:[%s]", field->AccountID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAccountLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %lld", field->AccountID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAccountLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLoginField:AccountID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->AccountID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAccountLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAccountLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLogoutField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAccountLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAccountLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLogoutField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s", field->AccountID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepAccountLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountLogoutField:AccountID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->AccountID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskUserLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->UserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRiskUserLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLoginField:UserID:[%s], Password:[%s]", field->UserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRiskUserLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s, %s, %lld", field->UserID, field->RiskGroupID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRiskUserLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLoginField:UserID:[%s], RiskGroupID:[%d], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->UserID, field->RiskGroupID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRiskUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLogoutField:UserID:[%s]", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRiskUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRiskUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLogoutField:UserID:[%s]", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRiskUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s", field->UserID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRiskUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRiskUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRiskUserLogoutField:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->UserID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAdminUserLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAdminUserLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLoginField:AdminUserID:[%s], Password:[%s]", field->AdminUserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAdminUserLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %lld", field->AdminUserID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAdminUserLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLoginField:AdminUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->AdminUserID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAdminUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AdminUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAdminUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLogoutField:AdminUserID:[%s]", field->AdminUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAdminUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AdminUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAdminUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLogoutField:AdminUserID:[%s]", field->AdminUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAdminUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s", field->UserID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepAdminUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAdminUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAdminUserLogoutField:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->UserID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMdUserLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->MdUserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqMdUserLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLoginField:MdUserID:[%s], Password:[%s]", field->MdUserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMdUserLoginField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %lld", field->MdUserID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspMdUserLoginField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLoginField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLoginField:MdUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->MdUserID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMdUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->MdUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqMdUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLogoutField:MdUserID:[%s]", field->MdUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMdUserLogoutField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->MdUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspMdUserLogoutField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLogoutField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLogoutField:MdUserID:[%s]", field->MdUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryAccountField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d, %d, %d, %d", field->AccountID, (int)field->AccountType, (int)field->AccountStatus, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountField:AccountID:[%s], AccountType:[%d], AccountStatus:[%d], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d]", field->AccountID, (int)field->AccountType, (int)field->AccountStatus, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryHolderAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryHolderAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryHolderAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryHolderAccountField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepHolderAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d", field->ExchangeID, field->HolderAccountID, field->PrimaryFlag);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepHolderAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepHolderAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepHolderAccountField:ExchangeID:[%s], HolderAccountID:[%s], PrimaryFlag:[%d]", field->ExchangeID, field->HolderAccountID, field->PrimaryFlag);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountDeleteField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepAccountDeleteField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountDeleteField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountDeleteField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryCapitalField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryCapitalField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCapitalField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCapitalField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepCapitalField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->TradingDay, field->AccountID, (int)field->AccountType, field->Asset, field->PreAsset, field->CashAsset, field->PreCashAsset, field->Available, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee, field->MarketValue, field->TotalProfit, field->TodayProfit, field->Deposit, field->Withdraw);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepCapitalField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepCapitalField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepCapitalField:TradingDay:[%s], AccountID:[%s], AccountType:[%d], Asset:[%f], PreAsset:[%f], CashAsset:[%f], PreCashAsset:[%f], Available:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f], MarketValue:[%f], TotalProfit:[%f], TodayProfit:[%f], Deposit:[%f], Withdraw:[%f]", field->TradingDay, field->AccountID, (int)field->AccountType, field->Asset, field->PreAsset, field->CashAsset, field->PreCashAsset, field->Available, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee, field->MarketValue, field->TotalProfit, field->TodayProfit, field->Deposit, field->Withdraw);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryPositionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryPositionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryPositionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryPositionField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepPositionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %s, %s, %d, %d, %d, %d, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d, %f, %f, %f, %f, %f, %f", field->TradingDay, field->AccountID, (int)field->AccountType, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, (int)field->PosiDirection, field->TotalPosition, field->PositionFrozen, field->TodayPosition, field->TotalCostPrice, field->TodayCostPrice, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->MarketValue, field->VolumeMultiple, field->TotalCost, field->TodayCost, field->TotalProfit, field->TodayProfit, field->LastPrice, field->PrePrice);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepPositionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepPositionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepPositionField:TradingDay:[%s], AccountID:[%s], AccountType:[%d], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TodayPosition:[%d], TotalCostPrice:[%f], TodayCostPrice:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], MarketValue:[%f], VolumeMultiple:[%d], TotalCost:[%f], TodayCost:[%f], TotalProfit:[%f], TodayProfit:[%f], LastPrice:[%f], PrePrice:[%f]", field->TradingDay, field->AccountID, (int)field->AccountType, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, (int)field->PosiDirection, field->TotalPosition, field->PositionFrozen, field->TodayPosition, field->TotalCostPrice, field->TodayCostPrice, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->MarketValue, field->VolumeMultiple, field->TotalCost, field->TodayCost, field->TotalProfit, field->TodayProfit, field->LastPrice, field->PrePrice);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOrderField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %d, %d, %d, %f, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s, %lld, %d, %d, %f, %f, %f, %f, %f", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->VolumeTotal, field->VolumeTraded, field->VolumeMultiple, (int)field->OrderStatus, field->StatusMsg, field->OrderDate, field->OrderTime, field->CancelDate, field->CancelTime, field->SessionID, field->ClientOrderID, field->RequestID, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepOrderField:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->VolumeTotal, field->VolumeTraded, field->VolumeMultiple, (int)field->OrderStatus, field->StatusMsg, field->OrderDate, field->OrderTime, field->CancelDate, field->CancelTime, field->SessionID, field->ClientOrderID, field->RequestID, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryTradeField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryTradeField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryTradeField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryTradeField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepTradeField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %s, %d, %d, %f, %d, %d, %f, %f, %f, %f, %s, %s", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, field->TradeID, (int)field->Direction, (int)field->OffsetFlag, field->Price, field->Volume, field->VolumeMultiple, field->TradeAmount, field->Commission, field->StampTax, field->TransferFee, field->TradeDate, field->TradeTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepTradeField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepTradeField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepTradeField:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], VolumeMultiple:[%d], TradeAmount:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], TradeDate:[%s], TradeTime:[%s]", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, field->TradeID, (int)field->Direction, (int)field->OffsetFlag, field->Price, field->Volume, field->VolumeMultiple, field->TradeAmount, field->Commission, field->StampTax, field->TransferFee, field->TradeDate, field->TradeTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryInstrumentField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryInstrumentField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryInstrumentField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryInstrumentField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepInstrumentField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %d", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepInstrumentField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepInstrumentField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepInstrumentField:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], SecurityType:[%d]", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryOptionInstrumentField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryOptionInstrumentField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOptionInstrumentField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOptionInstrumentField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepOptionInstrumentField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %f, %f, %f, %d, %d, %s", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->OptionType, field->UnderlyingInstrumentID, field->ExecutePrice, field->UnitMargin, field->PriceTick, field->MaxLimitOrderVolume, field->MaxMarketOrderVolume, field->ExpiringDate);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepOptionInstrumentField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepOptionInstrumentField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepOptionInstrumentField:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->OptionType, field->UnderlyingInstrumentID, field->ExecutePrice, field->UnitMargin, field->PriceTick, field->MaxLimitOrderVolume, field->MaxMarketOrderVolume, field->ExpiringDate);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryCommissionRateField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d", field->AccountID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryCommissionRateField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCommissionRateField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCommissionRateField:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AccountID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepCommissionRateField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->AccountID, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepCommissionRateField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepCommissionRateField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepCommissionRateField:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AccountID, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqInsertOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d, %d, %d, %f, %d, %d", field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqInsertOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqInsertOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqInsertOrderField:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqCancelOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d, %d, %s, %d", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqCancelOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqCancelOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqCancelOrderField:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepCancelOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d, %d, %s, %d", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepCancelOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepCancelOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepCancelOrderField:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMdInitField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqMdInitField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdInitField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdInitField:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMdInitField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspMdInitField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdInitField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdInitField:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqSubscribeMdField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqSubscribeMdField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqSubscribeMdField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqSubscribeMdField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspSubscribeMdField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspSubscribeMdField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspSubscribeMdField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspSubscribeMdField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AccountID, field->RiskID, (int)field->RiskStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepAccountRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskField:AccountID:[%s], RiskID:[%d], RiskStatus:[%d]", field->AccountID, field->RiskID, (int)field->RiskStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountRiskDeleteField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepAccountRiskDeleteField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskDeleteField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskDeleteField:AccountID:[%s], RiskID:[%d]", field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountRiskNotifyField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d, %d, %d, %s", field->NotifyDate, field->NotifyTime, field->AccountID, field->RiskID, field->RiskRuleID, (int)field->RiskStatus, field->RiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepAccountRiskNotifyField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskNotifyField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskNotifyField:NotifyDate:[%s], NotifyTime:[%s], AccountID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskStatus:[%d], RiskMessage:[%s]", field->NotifyDate, field->NotifyTime, field->AccountID, field->RiskID, field->RiskRuleID, (int)field->RiskStatus, field->RiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepShortMdField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %f, %f, %f, %f, %f, %f, %f", field->TradingDay, field->ExchangeID, field->InstrumentID, field->LastPrice, field->ClosePrice, field->PreClosePrice, field->SettlementPrice, field->PreSettlementPrice, field->UpperLimitPrice, field->LowerLimitPrice);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepShortMdField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepShortMdField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepShortMdField:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], LastPrice:[%f], ClosePrice:[%f], PreClosePrice:[%f], SettlementPrice:[%f], PreSettlementPrice:[%f], UpperLimitPrice:[%f], LowerLimitPrice:[%f]", field->TradingDay, field->ExchangeID, field->InstrumentID, field->LastPrice, field->ClosePrice, field->PreClosePrice, field->SettlementPrice, field->PreSettlementPrice, field->UpperLimitPrice, field->LowerLimitPrice);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRtnExchangeStatusField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d", field->ExchangeID, field->ExchangeDate, (int)field->ExchangeStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRtnExchangeStatusField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRtnExchangeStatusField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRtnExchangeStatusField:ExchangeID:[%s], ExchangeDate:[%s], ExchangeStatus:[%d]", field->ExchangeID, field->ExchangeDate, (int)field->ExchangeStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepMdInitCompletedField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepMdInitCompletedField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepMdInitCompletedField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepMdInitCompletedField:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryRiskGroupAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountField:UserID:[%s]", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupCapitalField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryRiskGroupCapitalField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupCapitalField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupCapitalField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupPositionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryRiskGroupPositionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupPositionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupPositionField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryRiskGroupOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupOrderField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupTradeField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryRiskGroupTradeField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupTradeField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupTradeField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupAccountRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryRiskGroupAccountRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRiskField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupAccountRiskNotifyField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryRiskGroupAccountRiskNotifyField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRiskNotifyField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRiskNotifyField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskInsertOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %d, %d, %f, %d, %d, %d", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID, field->IsForceClose);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRiskInsertOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskInsertOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskInsertOrderField:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d], IsForceClose:[%d]", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID, field->IsForceClose);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskCancelOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %d", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRiskCancelOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskCancelOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskCancelOrderField:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddRiskUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddRiskUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateRiskUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateRiskUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateRiskUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateRiskUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRiskUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveRiskUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRiskUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveRiskUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddAdminUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s", field->AdminUserID, field->UserID, field->UserName, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddAdminUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAdminUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAdminUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]", field->AdminUserID, field->UserID, field->UserName, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddAdminUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddAdminUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAdminUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateAdminUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s", field->AdminUserID, field->UserID, field->UserName, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateAdminUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAdminUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAdminUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]", field->AdminUserID, field->UserID, field->UserName, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateAdminUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateAdminUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAdminUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveAdminUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveAdminUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAdminUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveAdminUserField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveAdminUserField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAdminUserField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddPrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d, %s, %d, %d, %d", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddPrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddPrimaryAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddPrimaryAccountField:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddPrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddPrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddPrimaryAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddPrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdatePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d, %s, %d, %d, %d", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdatePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdatePrimaryAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdatePrimaryAccountField:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdatePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdatePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdatePrimaryAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdatePrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemovePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemovePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemovePrimaryAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemovePrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemovePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemovePrimaryAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemovePrimaryAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemovePrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccountField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAccountField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveAccountField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveAccountField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccountField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddBaseCommissionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddBaseCommissionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateBaseCommissionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateBaseCommissionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveBaseCommissionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveBaseCommissionField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveBaseCommissionField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddCommissionGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddCommissionGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateCommissionGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateCommissionGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveCommissionGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveCommissionGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveCommissionGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOptionMarginParamField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOptionMarginParamField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOptionMarginParamField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateOptionMarginParamField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateOptionMarginParamField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateOptionMarginParamField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveOptionMarginParamField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveOptionMarginParamField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveOptionMarginParamField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddTradeOfferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s, %d, %s", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddTradeOfferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeOfferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeOfferField:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddTradeOfferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddTradeOfferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeOfferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateTradeOfferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s, %d, %s", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateTradeOfferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeOfferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeOfferField:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateTradeOfferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateTradeOfferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeOfferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveTradeOfferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveTradeOfferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeOfferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveTradeOfferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveTradeOfferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeOfferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddTradeGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddTradeGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddTradeGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddTradeGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateTradeGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateTradeGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateTradeGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateTradeGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveTradeGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveTradeGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveTradeGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveTradeGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d, %s", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d, %s", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveTradeGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddRiskGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddRiskGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateRiskGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateRiskGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateRiskGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateRiskGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRiskGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveRiskGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRiskGroupField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveRiskGroupField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroupField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqUpdateRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspUpdateRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveRiskGroupItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroupItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddOrUpdateRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %s, %d", field->AdminUserID, field->RiskID, field->RiskName, (int)field->RiskClassID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddOrUpdateRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOrUpdateRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOrUpdateRiskField:AdminUserID:[%s], RiskID:[%d], RiskName:[%s], RiskClassID:[%d]", field->AdminUserID, field->RiskID, field->RiskName, (int)field->RiskClassID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddOrUpdateRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddOrUpdateRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOrUpdateRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOrUpdateRiskField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskRuleField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d, %d, %s", field->AdminUserID, field->RiskID, field->RiskRuleID, (int)field->RiskRuleStyle, field->FormatRiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddRiskRuleField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRuleField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRuleField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleStyle:[%d], FormatRiskMessage:[%s]", field->AdminUserID, field->RiskID, field->RiskRuleID, (int)field->RiskRuleStyle, field->FormatRiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskRuleField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskID, field->RiskRuleID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddRiskRuleField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRuleField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRuleField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskRuleItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s, %s, %d, %d, %s, %d, %d, %s, %d", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID, (int)field->RiskIndexType, field->RiskIndexID, field->RiskIndexTextRef, field->IndexParam1, field->IndexParam2, field->IndexParam3, field->IndexParam4, field->IndexParam5, field->IndexParam6, (int)field->LogicFunc, (int)field->LogicParamType1, field->LogicParam1, field->LogicParam1TextRef, (int)field->LogicParamType2, field->LogicParam2, field->LogicParam2TextRef);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddRiskRuleItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRuleItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRuleItemField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d], RiskIndexType:[%d], RiskIndexID:[%d], RiskIndexTextRef:[%d], IndexParam1:[%s], IndexParam2:[%s], IndexParam3:[%s], IndexParam4:[%s], IndexParam5:[%s], IndexParam6:[%s], LogicFunc:[%d], LogicParamType1:[%d], LogicParam1:[%s], LogicParam1TextRef:[%d], LogicParamType2:[%d], LogicParam2:[%s], LogicParam2TextRef:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID, (int)field->RiskIndexType, field->RiskIndexID, field->RiskIndexTextRef, field->IndexParam1, field->IndexParam2, field->IndexParam3, field->IndexParam4, field->IndexParam5, field->IndexParam6, (int)field->LogicFunc, (int)field->LogicParamType1, field->LogicParam1, field->LogicParam1TextRef, (int)field->LogicParamType2, field->LogicParam2, field->LogicParam2TextRef);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskRuleItemField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d, %d", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddRiskRuleItemField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRuleItemField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRuleItemField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskTradeScopeField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d, %d, %d, %s", field->AdminUserID, field->RiskID, (int)field->TradeScopeType, field->InstrumentGroupID, field->FormatRiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddRiskTradeScopeField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskTradeScopeField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskTradeScopeField:AdminUserID:[%s], RiskID:[%d], TradeScopeType:[%d], InstrumentGroupID:[%d], FormatRiskMessage:[%s]", field->AdminUserID, field->RiskID, (int)field->TradeScopeType, field->InstrumentGroupID, field->FormatRiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskTradeScopeField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddRiskTradeScopeField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskTradeScopeField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskTradeScopeField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddAccountRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAddAccountRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccountRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddAccountRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAddAccountRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccountRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveAccountRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqRemoveAccountRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccountRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveAccountRiskField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspRemoveAccountRiskField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccountRiskField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d, %d, %d, %f, %s, %s, %s, %s", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMoneyTransferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMoneyTransferField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMoneyTransferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMoneyTransferField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqQryMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryMoneyTransferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryMoneyTransferField:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %d, %d, %d, %f, %s, %s, %s, %s", field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepMoneyTransferField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepMoneyTransferField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepMoneyTransferField:TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]", field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAuditOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %s, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepReqAuditOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAuditOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAuditOrderField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAuditOrderField* field)
	{
		if (field == nullptr)
		{
			memset(t_StepFieldStringBuffer, 0, sizeof(t_StepFieldStringBuffer));
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "%s, %s, %s, %s, %s, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetDebugString(StepRspAuditOrderField* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAuditOrderField:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAuditOrderField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
		}
		return t_StepFieldStringBuffer;
	}
}
