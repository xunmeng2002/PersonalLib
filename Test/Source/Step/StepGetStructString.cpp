#include "StepGetStructString.h"
#include <cstring>

static thread_local char t_StepFieldStringBuffer[10240];


namespace step
{
	std::string GetString(StepRspInfo* field)
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
	std::string GetDebugString(StepRspInfo* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspInfo:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspInfo:ErrorID:[0x%04X], ErrorMsg:[%s]", field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAccountLogin* field)
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
	std::string GetDebugString(StepReqAccountLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLogin:AccountID:[%s], Password:[%s]", field->AccountID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAccountLogin* field)
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
	std::string GetDebugString(StepRspAccountLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLogin:AccountID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->AccountID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAccountLogout* field)
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
	std::string GetDebugString(StepReqAccountLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAccountLogout:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAccountLogout* field)
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
	std::string GetDebugString(StepRspAccountLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAccountLogout:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountLogout* field)
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
	std::string GetDebugString(StepAccountLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountLogout:AccountID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->AccountID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskUserLogin* field)
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
	std::string GetDebugString(StepReqRiskUserLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLogin:UserID:[%s], Password:[%s]", field->UserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRiskUserLogin* field)
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
	std::string GetDebugString(StepRspRiskUserLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLogin:UserID:[%s], RiskGroupID:[%d], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->UserID, field->RiskGroupID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskUserLogout* field)
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
	std::string GetDebugString(StepReqRiskUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskUserLogout:UserID:[%s]", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRiskUserLogout* field)
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
	std::string GetDebugString(StepRspRiskUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRiskUserLogout:UserID:[%s]", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRiskUserLogout* field)
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
	std::string GetDebugString(StepRiskUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRiskUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRiskUserLogout:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->UserID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAdminUserLogin* field)
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
	std::string GetDebugString(StepReqAdminUserLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLogin:AdminUserID:[%s], Password:[%s]", field->AdminUserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAdminUserLogin* field)
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
	std::string GetDebugString(StepRspAdminUserLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLogin:AdminUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->AdminUserID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAdminUserLogout* field)
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
	std::string GetDebugString(StepReqAdminUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAdminUserLogout:AdminUserID:[%s]", field->AdminUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAdminUserLogout* field)
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
	std::string GetDebugString(StepRspAdminUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAdminUserLogout:AdminUserID:[%s]", field->AdminUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAdminUserLogout* field)
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
	std::string GetDebugString(StepAdminUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAdminUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAdminUserLogout:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->UserID, field->ErrorID, field->ErrorMsg);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMdUserLogin* field)
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
	std::string GetDebugString(StepReqMdUserLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLogin:MdUserID:[%s], Password:[%s]", field->MdUserID, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMdUserLogin* field)
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
	std::string GetDebugString(StepRspMdUserLogin* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLogin:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLogin:MdUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->MdUserID, field->LoginDate, field->LoginTime, field->SessionID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMdUserLogout* field)
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
	std::string GetDebugString(StepReqMdUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdUserLogout:MdUserID:[%s]", field->MdUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMdUserLogout* field)
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
	std::string GetDebugString(StepRspMdUserLogout* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLogout:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdUserLogout:MdUserID:[%s]", field->MdUserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryAccount* field)
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
	std::string GetDebugString(StepReqQryAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryAccount:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccount* field)
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
	std::string GetDebugString(StepAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccount:AccountID:[%s], AccountType:[%d], AccountStatus:[%d], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d]", field->AccountID, (int)field->AccountType, (int)field->AccountStatus, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryHolderAccount* field)
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
	std::string GetDebugString(StepReqQryHolderAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryHolderAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryHolderAccount:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepHolderAccount* field)
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
	std::string GetDebugString(StepHolderAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepHolderAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepHolderAccount:ExchangeID:[%s], HolderAccountID:[%s], PrimaryFlag:[%d]", field->ExchangeID, field->HolderAccountID, field->PrimaryFlag);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountDelete* field)
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
	std::string GetDebugString(StepAccountDelete* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountDelete:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountDelete:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryCapital* field)
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
	std::string GetDebugString(StepReqQryCapital* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCapital:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCapital:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepCapital* field)
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
	std::string GetDebugString(StepCapital* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepCapital:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepCapital:TradingDay:[%s], AccountID:[%s], AccountType:[%d], Asset:[%f], PreAsset:[%f], CashAsset:[%f], PreCashAsset:[%f], Available:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f], MarketValue:[%f], TotalProfit:[%f], TodayProfit:[%f], Deposit:[%f], Withdraw:[%f]", field->TradingDay, field->AccountID, (int)field->AccountType, field->Asset, field->PreAsset, field->CashAsset, field->PreCashAsset, field->Available, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee, field->MarketValue, field->TotalProfit, field->TodayProfit, field->Deposit, field->Withdraw);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryPosition* field)
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
	std::string GetDebugString(StepReqQryPosition* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryPosition:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryPosition:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepPosition* field)
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
	std::string GetDebugString(StepPosition* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepPosition:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepPosition:TradingDay:[%s], AccountID:[%s], AccountType:[%d], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TodayPosition:[%d], TotalCostPrice:[%f], TodayCostPrice:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], MarketValue:[%f], VolumeMultiple:[%d], TotalCost:[%f], TodayCost:[%f], TotalProfit:[%f], TodayProfit:[%f], LastPrice:[%f], PrePrice:[%f]", field->TradingDay, field->AccountID, (int)field->AccountType, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, (int)field->PosiDirection, field->TotalPosition, field->PositionFrozen, field->TodayPosition, field->TotalCostPrice, field->TodayCostPrice, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->MarketValue, field->VolumeMultiple, field->TotalCost, field->TodayCost, field->TotalProfit, field->TodayProfit, field->LastPrice, field->PrePrice);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryOrder* field)
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
	std::string GetDebugString(StepReqQryOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOrder:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepOrder* field)
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
	std::string GetDebugString(StepOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepOrder:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->VolumeTotal, field->VolumeTraded, field->VolumeMultiple, (int)field->OrderStatus, field->StatusMsg, field->OrderDate, field->OrderTime, field->CancelDate, field->CancelTime, field->SessionID, field->ClientOrderID, field->RequestID, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryTrade* field)
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
	std::string GetDebugString(StepReqQryTrade* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryTrade:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryTrade:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepTrade* field)
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
	std::string GetDebugString(StepTrade* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepTrade:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepTrade:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], VolumeMultiple:[%d], TradeAmount:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], TradeDate:[%s], TradeTime:[%s]", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, field->TradeID, (int)field->Direction, (int)field->OffsetFlag, field->Price, field->Volume, field->VolumeMultiple, field->TradeAmount, field->Commission, field->StampTax, field->TransferFee, field->TradeDate, field->TradeTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryInstrument* field)
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
	std::string GetDebugString(StepReqQryInstrument* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryInstrument:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryInstrument:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepInstrument* field)
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
	std::string GetDebugString(StepInstrument* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepInstrument:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepInstrument:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], SecurityType:[%d]", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryOptionInstrument* field)
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
	std::string GetDebugString(StepReqQryOptionInstrument* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOptionInstrument:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryOptionInstrument:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepOptionInstrument* field)
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
	std::string GetDebugString(StepOptionInstrument* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepOptionInstrument:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepOptionInstrument:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->OptionType, field->UnderlyingInstrumentID, field->ExecutePrice, field->UnitMargin, field->PriceTick, field->MaxLimitOrderVolume, field->MaxMarketOrderVolume, field->ExpiringDate);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryCommissionRate* field)
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
	std::string GetDebugString(StepReqQryCommissionRate* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCommissionRate:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryCommissionRate:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AccountID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepCommissionRate* field)
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
	std::string GetDebugString(StepCommissionRate* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepCommissionRate:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepCommissionRate:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AccountID, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqInsertOrder* field)
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
	std::string GetDebugString(StepReqInsertOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqInsertOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqInsertOrder:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqCancelOrder* field)
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
	std::string GetDebugString(StepReqCancelOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqCancelOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqCancelOrder:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepCancelOrder* field)
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
	std::string GetDebugString(StepCancelOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepCancelOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepCancelOrder:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMdInit* field)
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
	std::string GetDebugString(StepReqMdInit* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdInit:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMdInit:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMdInit* field)
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
	std::string GetDebugString(StepRspMdInit* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdInit:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMdInit:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqSubscribeMd* field)
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
	std::string GetDebugString(StepReqSubscribeMd* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqSubscribeMd:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqSubscribeMd:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspSubscribeMd* field)
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
	std::string GetDebugString(StepRspSubscribeMd* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspSubscribeMd:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspSubscribeMd:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountRisk* field)
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
	std::string GetDebugString(StepAccountRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRisk:AccountID:[%s], RiskID:[%d], RiskStatus:[%d]", field->AccountID, field->RiskID, (int)field->RiskStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountRiskDelete* field)
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
	std::string GetDebugString(StepAccountRiskDelete* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskDelete:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskDelete:AccountID:[%s], RiskID:[%d]", field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepAccountRiskNotify* field)
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
	std::string GetDebugString(StepAccountRiskNotify* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskNotify:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepAccountRiskNotify:NotifyDate:[%s], NotifyTime:[%s], AccountID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskStatus:[%d], RiskMessage:[%s]", field->NotifyDate, field->NotifyTime, field->AccountID, field->RiskID, field->RiskRuleID, (int)field->RiskStatus, field->RiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepShortMd* field)
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
	std::string GetDebugString(StepShortMd* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepShortMd:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepShortMd:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], LastPrice:[%f], ClosePrice:[%f], PreClosePrice:[%f], SettlementPrice:[%f], PreSettlementPrice:[%f], UpperLimitPrice:[%f], LowerLimitPrice:[%f]", field->TradingDay, field->ExchangeID, field->InstrumentID, field->LastPrice, field->ClosePrice, field->PreClosePrice, field->SettlementPrice, field->PreSettlementPrice, field->UpperLimitPrice, field->LowerLimitPrice);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRtnExchangeStatus* field)
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
	std::string GetDebugString(StepRtnExchangeStatus* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRtnExchangeStatus:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRtnExchangeStatus:ExchangeID:[%s], ExchangeDate:[%s], ExchangeStatus:[%d]", field->ExchangeID, field->ExchangeDate, (int)field->ExchangeStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepMdInitCompleted* field)
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
	std::string GetDebugString(StepMdInitCompleted* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepMdInitCompleted:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepMdInitCompleted:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupAccount* field)
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
	std::string GetDebugString(StepReqQryRiskGroupAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccount:UserID:[%s]", field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupCapital* field)
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
	std::string GetDebugString(StepReqQryRiskGroupCapital* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupCapital:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupCapital:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupPosition* field)
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
	std::string GetDebugString(StepReqQryRiskGroupPosition* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupPosition:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupPosition:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupOrder* field)
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
	std::string GetDebugString(StepReqQryRiskGroupOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupOrder:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupTrade* field)
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
	std::string GetDebugString(StepReqQryRiskGroupTrade* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupTrade:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupTrade:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupAccountRisk* field)
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
	std::string GetDebugString(StepReqQryRiskGroupAccountRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRisk:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryRiskGroupAccountRiskNotify* field)
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
	std::string GetDebugString(StepReqQryRiskGroupAccountRiskNotify* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRiskNotify:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryRiskGroupAccountRiskNotify:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskInsertOrder* field)
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
	std::string GetDebugString(StepReqRiskInsertOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskInsertOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskInsertOrder:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d], IsForceClose:[%d]", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID, field->IsForceClose);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRiskCancelOrder* field)
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
	std::string GetDebugString(StepReqRiskCancelOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskCancelOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRiskCancelOrder:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskUser* field)
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
	std::string GetDebugString(StepReqAddRiskUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskUser* field)
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
	std::string GetDebugString(StepRspAddRiskUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateRiskUser* field)
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
	std::string GetDebugString(StepReqUpdateRiskUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateRiskUser* field)
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
	std::string GetDebugString(StepRspUpdateRiskUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRiskUser* field)
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
	std::string GetDebugString(StepReqRemoveRiskUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRiskUser* field)
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
	std::string GetDebugString(StepRspRemoveRiskUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddAdminUser* field)
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
	std::string GetDebugString(StepReqAddAdminUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAdminUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAdminUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]", field->AdminUserID, field->UserID, field->UserName, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddAdminUser* field)
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
	std::string GetDebugString(StepRspAddAdminUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAdminUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAdminUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateAdminUser* field)
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
	std::string GetDebugString(StepReqUpdateAdminUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAdminUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAdminUser:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]", field->AdminUserID, field->UserID, field->UserName, field->Password);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateAdminUser* field)
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
	std::string GetDebugString(StepRspUpdateAdminUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAdminUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAdminUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveAdminUser* field)
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
	std::string GetDebugString(StepReqRemoveAdminUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAdminUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAdminUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveAdminUser* field)
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
	std::string GetDebugString(StepRspRemoveAdminUser* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAdminUser:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAdminUser:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddPrimaryAccount* field)
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
	std::string GetDebugString(StepReqAddPrimaryAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddPrimaryAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddPrimaryAccount:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddPrimaryAccount* field)
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
	std::string GetDebugString(StepRspAddPrimaryAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddPrimaryAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddPrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdatePrimaryAccount* field)
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
	std::string GetDebugString(StepReqUpdatePrimaryAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdatePrimaryAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdatePrimaryAccount:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdatePrimaryAccount* field)
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
	std::string GetDebugString(StepRspUpdatePrimaryAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdatePrimaryAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdatePrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemovePrimaryAccount* field)
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
	std::string GetDebugString(StepReqRemovePrimaryAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemovePrimaryAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemovePrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemovePrimaryAccount* field)
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
	std::string GetDebugString(StepRspRemovePrimaryAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemovePrimaryAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemovePrimaryAccount:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddAccount* field)
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
	std::string GetDebugString(StepReqAddAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccount:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddAccount* field)
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
	std::string GetDebugString(StepRspAddAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccount:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateAccount* field)
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
	std::string GetDebugString(StepReqUpdateAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateAccount:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateAccount* field)
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
	std::string GetDebugString(StepRspUpdateAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateAccount:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveAccount* field)
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
	std::string GetDebugString(StepReqRemoveAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccount:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveAccount* field)
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
	std::string GetDebugString(StepRspRemoveAccount* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccount:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccount:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddBaseCommission* field)
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
	std::string GetDebugString(StepReqAddBaseCommission* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddBaseCommission:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddBaseCommission* field)
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
	std::string GetDebugString(StepRspAddBaseCommission* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddBaseCommission:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateBaseCommission* field)
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
	std::string GetDebugString(StepReqUpdateBaseCommission* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateBaseCommission:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateBaseCommission* field)
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
	std::string GetDebugString(StepRspUpdateBaseCommission* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateBaseCommission:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveBaseCommission* field)
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
	std::string GetDebugString(StepReqRemoveBaseCommission* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveBaseCommission:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveBaseCommission* field)
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
	std::string GetDebugString(StepRspRemoveBaseCommission* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveBaseCommission:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveBaseCommission:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddCommissionGroup* field)
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
	std::string GetDebugString(StepReqAddCommissionGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddCommissionGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddCommissionGroup* field)
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
	std::string GetDebugString(StepRspAddCommissionGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddCommissionGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateCommissionGroup* field)
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
	std::string GetDebugString(StepReqUpdateCommissionGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateCommissionGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateCommissionGroup* field)
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
	std::string GetDebugString(StepRspUpdateCommissionGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateCommissionGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveCommissionGroup* field)
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
	std::string GetDebugString(StepReqRemoveCommissionGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveCommissionGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveCommissionGroup* field)
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
	std::string GetDebugString(StepRspRemoveCommissionGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveCommissionGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveCommissionGroup:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddOptionMarginParam* field)
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
	std::string GetDebugString(StepReqAddOptionMarginParam* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOptionMarginParam:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOptionMarginParam:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddOptionMarginParam* field)
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
	std::string GetDebugString(StepRspAddOptionMarginParam* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOptionMarginParam:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateOptionMarginParam* field)
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
	std::string GetDebugString(StepReqUpdateOptionMarginParam* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateOptionMarginParam:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateOptionMarginParam:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateOptionMarginParam* field)
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
	std::string GetDebugString(StepRspUpdateOptionMarginParam* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateOptionMarginParam:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveOptionMarginParam* field)
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
	std::string GetDebugString(StepReqRemoveOptionMarginParam* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveOptionMarginParam:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveOptionMarginParam* field)
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
	std::string GetDebugString(StepRspRemoveOptionMarginParam* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveOptionMarginParam:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveOptionMarginParam:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddTradeOffer* field)
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
	std::string GetDebugString(StepReqAddTradeOffer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeOffer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeOffer:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddTradeOffer* field)
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
	std::string GetDebugString(StepRspAddTradeOffer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeOffer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeOffer:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateTradeOffer* field)
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
	std::string GetDebugString(StepReqUpdateTradeOffer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeOffer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeOffer:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateTradeOffer* field)
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
	std::string GetDebugString(StepRspUpdateTradeOffer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeOffer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeOffer:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveTradeOffer* field)
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
	std::string GetDebugString(StepReqRemoveTradeOffer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeOffer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeOffer:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveTradeOffer* field)
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
	std::string GetDebugString(StepRspRemoveTradeOffer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeOffer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeOffer:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddTradeGroup* field)
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
	std::string GetDebugString(StepReqAddTradeGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroup:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddTradeGroup* field)
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
	std::string GetDebugString(StepRspAddTradeGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateTradeGroup* field)
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
	std::string GetDebugString(StepReqUpdateTradeGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroup:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateTradeGroup* field)
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
	std::string GetDebugString(StepRspUpdateTradeGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveTradeGroup* field)
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
	std::string GetDebugString(StepReqRemoveTradeGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveTradeGroup* field)
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
	std::string GetDebugString(StepRspRemoveTradeGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroup:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddTradeGroupItem* field)
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
	std::string GetDebugString(StepReqAddTradeGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddTradeGroupItem* field)
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
	std::string GetDebugString(StepRspAddTradeGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateTradeGroupItem* field)
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
	std::string GetDebugString(StepReqUpdateTradeGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateTradeGroupItem* field)
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
	std::string GetDebugString(StepRspUpdateTradeGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveTradeGroupItem* field)
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
	std::string GetDebugString(StepReqRemoveTradeGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveTradeGroupItem* field)
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
	std::string GetDebugString(StepRspRemoveTradeGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveTradeGroupItem:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskGroup* field)
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
	std::string GetDebugString(StepReqAddRiskGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroup:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskGroup* field)
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
	std::string GetDebugString(StepRspAddRiskGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateRiskGroup* field)
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
	std::string GetDebugString(StepReqUpdateRiskGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroup:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateRiskGroup* field)
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
	std::string GetDebugString(StepRspUpdateRiskGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRiskGroup* field)
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
	std::string GetDebugString(StepReqRemoveRiskGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRiskGroup* field)
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
	std::string GetDebugString(StepRspRemoveRiskGroup* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroup:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroup:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskGroupItem* field)
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
	std::string GetDebugString(StepReqAddRiskGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskGroupItem* field)
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
	std::string GetDebugString(StepRspAddRiskGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqUpdateRiskGroupItem* field)
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
	std::string GetDebugString(StepReqUpdateRiskGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqUpdateRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspUpdateRiskGroupItem* field)
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
	std::string GetDebugString(StepRspUpdateRiskGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspUpdateRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRiskGroupItem* field)
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
	std::string GetDebugString(StepReqRemoveRiskGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRiskGroupItem* field)
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
	std::string GetDebugString(StepRspRemoveRiskGroupItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroupItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRiskGroupItem:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddOrUpdateRisk* field)
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
	std::string GetDebugString(StepReqAddOrUpdateRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOrUpdateRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddOrUpdateRisk:AdminUserID:[%s], RiskID:[%d], RiskName:[%s], RiskClassID:[%d]", field->AdminUserID, field->RiskID, field->RiskName, (int)field->RiskClassID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddOrUpdateRisk* field)
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
	std::string GetDebugString(StepRspAddOrUpdateRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOrUpdateRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddOrUpdateRisk:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveRisk* field)
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
	std::string GetDebugString(StepReqRemoveRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveRisk:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveRisk* field)
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
	std::string GetDebugString(StepRspRemoveRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveRisk:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskRule* field)
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
	std::string GetDebugString(StepReqAddRiskRule* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRule:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRule:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleStyle:[%d], FormatRiskMessage:[%s]", field->AdminUserID, field->RiskID, field->RiskRuleID, (int)field->RiskRuleStyle, field->FormatRiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskRule* field)
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
	std::string GetDebugString(StepRspAddRiskRule* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRule:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRule:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskRuleItem* field)
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
	std::string GetDebugString(StepReqAddRiskRuleItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRuleItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskRuleItem:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d], RiskIndexType:[%d], RiskIndexID:[%d], RiskIndexTextRef:[%d], IndexParam1:[%s], IndexParam2:[%s], IndexParam3:[%s], IndexParam4:[%s], IndexParam5:[%s], IndexParam6:[%s], LogicFunc:[%d], LogicParamType1:[%d], LogicParam1:[%s], LogicParam1TextRef:[%d], LogicParamType2:[%d], LogicParam2:[%s], LogicParam2TextRef:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID, (int)field->RiskIndexType, field->RiskIndexID, field->RiskIndexTextRef, field->IndexParam1, field->IndexParam2, field->IndexParam3, field->IndexParam4, field->IndexParam5, field->IndexParam6, (int)field->LogicFunc, (int)field->LogicParamType1, field->LogicParam1, field->LogicParam1TextRef, (int)field->LogicParamType2, field->LogicParam2, field->LogicParam2TextRef);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskRuleItem* field)
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
	std::string GetDebugString(StepRspAddRiskRuleItem* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRuleItem:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskRuleItem:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddRiskTradeScope* field)
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
	std::string GetDebugString(StepReqAddRiskTradeScope* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskTradeScope:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddRiskTradeScope:AdminUserID:[%s], RiskID:[%d], TradeScopeType:[%d], InstrumentGroupID:[%d], FormatRiskMessage:[%s]", field->AdminUserID, field->RiskID, (int)field->TradeScopeType, field->InstrumentGroupID, field->FormatRiskMessage);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddRiskTradeScope* field)
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
	std::string GetDebugString(StepRspAddRiskTradeScope* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskTradeScope:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddRiskTradeScope:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAddAccountRisk* field)
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
	std::string GetDebugString(StepReqAddAccountRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccountRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAddAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAddAccountRisk* field)
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
	std::string GetDebugString(StepRspAddAccountRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccountRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAddAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqRemoveAccountRisk* field)
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
	std::string GetDebugString(StepReqRemoveAccountRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccountRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqRemoveAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspRemoveAccountRisk* field)
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
	std::string GetDebugString(StepRspRemoveAccountRisk* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccountRisk:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspRemoveAccountRisk:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqMoneyTransfer* field)
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
	std::string GetDebugString(StepReqMoneyTransfer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMoneyTransfer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqMoneyTransfer:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspMoneyTransfer* field)
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
	std::string GetDebugString(StepRspMoneyTransfer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMoneyTransfer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspMoneyTransfer:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqQryMoneyTransfer* field)
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
	std::string GetDebugString(StepReqQryMoneyTransfer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryMoneyTransfer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqQryMoneyTransfer:AccountID:[%s]", field->AccountID);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepMoneyTransfer* field)
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
	std::string GetDebugString(StepMoneyTransfer* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepMoneyTransfer:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepMoneyTransfer:TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]", field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepReqAuditOrder* field)
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
	std::string GetDebugString(StepReqAuditOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAuditOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepReqAuditOrder:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
		}
		return t_StepFieldStringBuffer;
	}
	std::string GetString(StepRspAuditOrder* field)
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
	std::string GetDebugString(StepRspAuditOrder* field)
	{
		if (field == nullptr)
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAuditOrder:nullptr");
		}
		else
		{
			sprintf(t_StepFieldStringBuffer, "StepRspAuditOrder:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
		}
		return t_StepFieldStringBuffer;
	}
}
