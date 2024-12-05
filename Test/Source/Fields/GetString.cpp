#include "GetString.h"
#include <cstring>

static thread_local char t_FieldStringBuffer[10240];


std::string GetString(RspInfoField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s", field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspInfoField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspInfoField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "StepRspInfo:ErrorID:[0x%04X], ErrorMsg:[%s]", field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetString(NotifyComponentConnectStatusField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%lld, %d, %d", field->SessionID, (int)field->Component, field->IsConnected);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(NotifyComponentConnectStatusField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "NotifyComponentConnectStatusField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "NotifyComponentConnectStatusField:SessionID:[%lld], Component:[%d], IsConnected:[%d]", field->SessionID, (int)field->Component, field->IsConnected);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAccountLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AccountID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAccountLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAccountLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAccountLoginField:AccountID:[%s], Password:[%s]", field->AccountID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAccountLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %lld", field->AccountID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAccountLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAccountLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAccountLoginField:AccountID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->AccountID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAccountLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAccountLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAccountLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAccountLogoutField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAccountLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAccountLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAccountLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAccountLogoutField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(AccountLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s", field->AccountID, field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(AccountLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "AccountLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "AccountLogoutField:AccountID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->AccountID, field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryAccountField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(AccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d, %d, %d, %d", field->AccountID, (int)field->AccountType, (int)field->AccountStatus, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(AccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "AccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "AccountField:AccountID:[%s], AccountType:[%d], AccountStatus:[%d], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d]", field->AccountID, (int)field->AccountType, (int)field->AccountStatus, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryHolderAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryHolderAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryHolderAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryHolderAccountField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(HolderAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d", field->ExchangeID, field->HolderAccountID, field->PrimaryFlag);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(HolderAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "HolderAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "HolderAccountField:ExchangeID:[%s], HolderAccountID:[%s], PrimaryFlag:[%d]", field->ExchangeID, field->HolderAccountID, field->PrimaryFlag);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryCapitalField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryCapitalField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryCapitalField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryCapitalField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(CapitalField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->TradingDay, field->AccountID, (int)field->AccountType, field->Asset, field->PreAsset, field->CashAsset, field->PreCashAsset, field->Available, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee, field->MarketValue, field->TotalProfit, field->TodayProfit, field->Deposit, field->Withdraw);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(CapitalField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "CapitalField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "CapitalField:TradingDay:[%s], AccountID:[%s], AccountType:[%d], Asset:[%f], PreAsset:[%f], CashAsset:[%f], PreCashAsset:[%f], Available:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f], MarketValue:[%f], TotalProfit:[%f], TodayProfit:[%f], Deposit:[%f], Withdraw:[%f]", field->TradingDay, field->AccountID, (int)field->AccountType, field->Asset, field->PreAsset, field->CashAsset, field->PreCashAsset, field->Available, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee, field->MarketValue, field->TotalProfit, field->TodayProfit, field->Deposit, field->Withdraw);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryPositionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryPositionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryPositionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryPositionField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(PositionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %s, %s, %d, %d, %d, %d, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d, %f, %f, %f, %f, %f, %f", field->TradingDay, field->AccountID, (int)field->AccountType, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, (int)field->PosiDirection, field->TotalPosition, field->PositionFrozen, field->TodayPosition, field->TotalCostPrice, field->TodayCostPrice, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->MarketValue, field->VolumeMultiple, field->TotalCost, field->TodayCost, field->TotalProfit, field->TodayProfit, field->LastPrice, field->PrePrice);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(PositionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "PositionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "PositionField:TradingDay:[%s], AccountID:[%s], AccountType:[%d], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TodayPosition:[%d], TotalCostPrice:[%f], TodayCostPrice:[%f], CashIn:[%f], CashOut:[%f], Margin:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], MarketValue:[%f], VolumeMultiple:[%d], TotalCost:[%f], TodayCost:[%f], TotalProfit:[%f], TodayProfit:[%f], LastPrice:[%f], PrePrice:[%f]", field->TradingDay, field->AccountID, (int)field->AccountType, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, (int)field->PosiDirection, field->TotalPosition, field->PositionFrozen, field->TodayPosition, field->TotalCostPrice, field->TodayCostPrice, field->CashIn, field->CashOut, field->Margin, field->Commission, field->StampTax, field->TransferFee, field->MarketValue, field->VolumeMultiple, field->TotalCost, field->TodayCost, field->TotalProfit, field->TodayProfit, field->LastPrice, field->PrePrice);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryOrderField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %d, %d, %d, %f, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s, %lld, %d, %d, %f, %f, %f, %f, %f", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->VolumeTotal, field->VolumeTraded, field->VolumeMultiple, (int)field->OrderStatus, field->StatusMsg, field->OrderDate, field->OrderTime, field->CancelDate, field->CancelTime, field->SessionID, field->ClientOrderID, field->RequestID, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OrderField:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], VolumeMultiple:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], SessionID:[%lld], ClientOrderID:[%d], RequestID:[%d], FrozenCash:[%f], FrozenMargin:[%f], FrozenCommission:[%f], FrozenStampTax:[%f], FrozenTransferFee:[%f]", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->VolumeTotal, field->VolumeTraded, field->VolumeMultiple, (int)field->OrderStatus, field->StatusMsg, field->OrderDate, field->OrderTime, field->CancelDate, field->CancelTime, field->SessionID, field->ClientOrderID, field->RequestID, field->FrozenCash, field->FrozenMargin, field->FrozenCommission, field->FrozenStampTax, field->FrozenTransferFee);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryTradeField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryTradeField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryTradeField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryTradeField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(TradeField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %s, %d, %d, %f, %d, %d, %f, %f, %f, %f, %s, %s", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, field->TradeID, (int)field->Direction, (int)field->OffsetFlag, field->Price, field->Volume, field->VolumeMultiple, field->TradeAmount, field->Commission, field->StampTax, field->TransferFee, field->TradeDate, field->TradeTime);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(TradeField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "TradeField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "TradeField:TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], VolumeMultiple:[%d], TradeAmount:[%f], Commission:[%f], StampTax:[%f], TransferFee:[%f], TradeDate:[%s], TradeTime:[%s]", field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, field->OrderSysID, field->TradeID, (int)field->Direction, (int)field->OffsetFlag, field->Price, field->Volume, field->VolumeMultiple, field->TradeAmount, field->Commission, field->StampTax, field->TransferFee, field->TradeDate, field->TradeTime);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryInstrumentField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryInstrumentField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryInstrumentField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryInstrumentField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(InstrumentField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(InstrumentField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "InstrumentField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "InstrumentField:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], SecurityType:[%d]", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryOptionInstrumentField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryOptionInstrumentField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OptionInstrumentField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %f, %f, %f, %d, %d, %s", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->OptionType, field->UnderlyingInstrumentID, field->ExecutePrice, field->UnitMargin, field->PriceTick, field->MaxLimitOrderVolume, field->MaxMarketOrderVolume, field->ExpiringDate);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OptionInstrumentField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OptionInstrumentField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OptionInstrumentField:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]", field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->OptionType, field->UnderlyingInstrumentID, field->ExecutePrice, field->UnitMargin, field->PriceTick, field->MaxLimitOrderVolume, field->MaxMarketOrderVolume, field->ExpiringDate);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryCommissionRateField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d", field->AccountID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryCommissionRateField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryCommissionRateField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryCommissionRateField:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AccountID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(CommissionRateField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->AccountID, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(CommissionRateField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "CommissionRateField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "CommissionRateField:AccountID:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AccountID, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryMoneyTransferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryMoneyTransferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryMoneyTransferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryMoneyTransferField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(MoneyTransferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %d, %d, %f, %s, %s, %s, %s", field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(MoneyTransferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "MoneyTransferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "MoneyTransferField:TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]", field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqInsertOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d, %d, %d, %f, %d, %d", field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqInsertOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqInsertOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqInsertOrderField:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqCancelOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d, %d, %s, %d", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqCancelOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqCancelOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqCancelOrderField:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(CancelOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d, %d, %s, %d", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(CancelOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "CancelOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "CancelOrderField:AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRiskUserLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->UserID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRiskUserLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRiskUserLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRiskUserLoginField:UserID:[%s], Password:[%s]", field->UserID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRiskUserLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s, %s, %lld", field->UserID, field->RiskGroupID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRiskUserLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRiskUserLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRiskUserLoginField:UserID:[%s], RiskGroupID:[%d], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->UserID, field->RiskGroupID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRiskUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRiskUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRiskUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRiskUserLogoutField:UserID:[%s]", field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRiskUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRiskUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRiskUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRiskUserLogoutField:UserID:[%s]", field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RiskUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s", field->UserID, field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RiskUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RiskUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RiskUserLogoutField:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->UserID, field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetString(AccountDeleteField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(AccountDeleteField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "AccountDeleteField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "AccountDeleteField:AccountID:[%s]", field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(AccountRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AccountID, field->RiskID, (int)field->RiskStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(AccountRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "AccountRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "AccountRiskField:AccountID:[%s], RiskID:[%d], RiskStatus:[%d]", field->AccountID, field->RiskID, (int)field->RiskStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetString(AccountRiskDeleteField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(AccountRiskDeleteField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "AccountRiskDeleteField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "AccountRiskDeleteField:AccountID:[%s], RiskID:[%d]", field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(AccountRiskNotifyField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d, %d, %d, %s", field->NotifyDate, field->NotifyTime, field->AccountID, field->RiskID, field->RiskRuleID, (int)field->RiskStatus, field->RiskMessage);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(AccountRiskNotifyField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "AccountRiskNotifyField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "AccountRiskNotifyField:NotifyDate:[%s], NotifyTime:[%s], AccountID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskStatus:[%d], RiskMessage:[%s]", field->NotifyDate, field->NotifyTime, field->AccountID, field->RiskID, field->RiskRuleID, (int)field->RiskStatus, field->RiskMessage);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryRiskGroupAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryRiskGroupAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupAccountField:UserID:[%s]", field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryRiskGroupCapitalField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryRiskGroupCapitalField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupCapitalField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupCapitalField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryRiskGroupPositionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryRiskGroupPositionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupPositionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupPositionField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryRiskGroupOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryRiskGroupOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupOrderField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryRiskGroupTradeField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryRiskGroupTradeField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupTradeField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupTradeField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryRiskGroupAccountRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryRiskGroupAccountRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupAccountRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupAccountRiskField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryRiskGroupAccountRiskNotifyField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryRiskGroupAccountRiskNotifyField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupAccountRiskNotifyField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryRiskGroupAccountRiskNotifyField:UserID:[%s], AccountID:[%s]", field->UserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRiskInsertOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %d, %f, %d, %d, %d", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID, field->IsForceClose);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRiskInsertOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRiskInsertOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRiskInsertOrderField:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], ClientOrderID:[%d], IsForceClose:[%d]", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->ClientOrderID, field->IsForceClose);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRiskCancelOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %s, %d", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRiskCancelOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRiskCancelOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRiskCancelOrderField:UserID:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], ClientCancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s], ClientOrderID:[%d]", field->UserID, field->AccountID, field->ExchangeID, field->InstrumentID, field->ClientCancelOrderID, field->OrderID, field->OrderSysID, field->ClientOrderID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqMdUserLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->MdUserID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqMdUserLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqMdUserLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqMdUserLoginField:MdUserID:[%s], Password:[%s]", field->MdUserID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspMdUserLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %lld", field->MdUserID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspMdUserLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspMdUserLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspMdUserLoginField:MdUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->MdUserID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqMdUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->MdUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqMdUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqMdUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqMdUserLogoutField:MdUserID:[%s]", field->MdUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspMdUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->MdUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspMdUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspMdUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspMdUserLogoutField:MdUserID:[%s]", field->MdUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqMdInitField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->ExchangeID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqMdInitField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqMdInitField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqMdInitField:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspMdInitField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->ExchangeID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspMdInitField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspMdInitField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspMdInitField:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqSubscribeMdField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqSubscribeMdField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqSubscribeMdField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqSubscribeMdField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspSubscribeMdField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspSubscribeMdField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspSubscribeMdField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspSubscribeMdField:ExchangeID:[%s], InstrumentID:[%s]", field->ExchangeID, field->InstrumentID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ShortMdField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %f, %f, %f, %f, %f, %f, %f", field->TradingDay, field->ExchangeID, field->InstrumentID, field->LastPrice, field->ClosePrice, field->PreClosePrice, field->SettlementPrice, field->PreSettlementPrice, field->UpperLimitPrice, field->LowerLimitPrice);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ShortMdField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ShortMdField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ShortMdField:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], LastPrice:[%f], ClosePrice:[%f], PreClosePrice:[%f], SettlementPrice:[%f], PreSettlementPrice:[%f], UpperLimitPrice:[%f], LowerLimitPrice:[%f]", field->TradingDay, field->ExchangeID, field->InstrumentID, field->LastPrice, field->ClosePrice, field->PreClosePrice, field->SettlementPrice, field->PreSettlementPrice, field->UpperLimitPrice, field->LowerLimitPrice);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RtnExchangeStatusField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d", field->ExchangeID, field->ExchangeDate, (int)field->ExchangeStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RtnExchangeStatusField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RtnExchangeStatusField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RtnExchangeStatusField:ExchangeID:[%s], ExchangeDate:[%s], ExchangeStatus:[%d]", field->ExchangeID, field->ExchangeDate, (int)field->ExchangeStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetString(MdInitCompletedField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->ExchangeID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(MdInitCompletedField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "MdInitCompletedField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "MdInitCompletedField:ExchangeID:[%s], TradingDay:[%s]", field->ExchangeID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAdminUserLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAdminUserLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAdminUserLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAdminUserLoginField:AdminUserID:[%s], Password:[%s]", field->AdminUserID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAdminUserLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %lld", field->AdminUserID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAdminUserLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAdminUserLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAdminUserLoginField:AdminUserID:[%s], LoginDate:[%s], LoginTime:[%s], SessionID:[%lld]", field->AdminUserID, field->LoginDate, field->LoginTime, field->SessionID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAdminUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AdminUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAdminUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAdminUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAdminUserLogoutField:AdminUserID:[%s]", field->AdminUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAdminUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->AdminUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAdminUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAdminUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAdminUserLogoutField:AdminUserID:[%s]", field->AdminUserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(AdminUserLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s", field->UserID, field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(AdminUserLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "AdminUserLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "AdminUserLogoutField:UserID:[%s], ErrorID:[%d], ErrorMsg:[%s]", field->UserID, field->ErrorID, field->ErrorMsg);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddRiskUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddRiskUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddRiskUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddRiskUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateRiskUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateRiskUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateRiskUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateRiskUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s], RiskGroupID:[%d]", field->AdminUserID, field->UserID, field->UserName, field->Password, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateRiskUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateRiskUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateRiskUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveRiskUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveRiskUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveRiskUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveRiskUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddAdminUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s", field->AdminUserID, field->UserID, field->UserName, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddAdminUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddAdminUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddAdminUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]", field->AdminUserID, field->UserID, field->UserName, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddAdminUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddAdminUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddAdminUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateAdminUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s", field->AdminUserID, field->UserID, field->UserName, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateAdminUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateAdminUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateAdminUserField:AdminUserID:[%s], UserID:[%s], UserName:[%s], Password:[%s]", field->AdminUserID, field->UserID, field->UserName, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateAdminUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateAdminUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateAdminUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveAdminUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveAdminUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveAdminUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveAdminUserField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveAdminUserField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveAdminUserField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveAdminUserField:AdminUserID:[%s], UserID:[%s]", field->AdminUserID, field->UserID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddPrimaryAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d, %s, %d, %d, %d", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddPrimaryAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddPrimaryAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddPrimaryAccountField:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddPrimaryAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddPrimaryAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddPrimaryAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddPrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdatePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d, %s, %d, %d, %d", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdatePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdatePrimaryAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdatePrimaryAccountField:AdminUserID:[%s], TradingDay:[%s], PrimaryAccountID:[%s], PrimaryAccountName:[%s], AccountClass:[%d], BrokerPassword:[%s], OfferID:[%d], IsAllowLogin:[%d], IsSimulateAccount:[%d], AccountStatus:[%d], Password:[%s], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->PrimaryAccountID, field->PrimaryAccountName, (int)field->AccountClass, field->BrokerPassword, field->OfferID, field->IsAllowLogin, field->IsSimulateAccount, (int)field->AccountStatus, field->Password, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdatePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdatePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdatePrimaryAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdatePrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemovePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemovePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemovePrimaryAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemovePrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemovePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemovePrimaryAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemovePrimaryAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemovePrimaryAccountField:AdminUserID:[%s], PrimaryAccountID:[%s]", field->AdminUserID, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddAccountField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateAccountField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], AccountName:[%s], AccountStatus:[%d], Password:[%s], TradeGroupID:[%d], RiskGroupID:[%d], CommissionGroupID:[%d], IsAutoAudit:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->AccountName, (int)field->AccountStatus, field->Password, field->TradeGroupID, field->RiskGroupID, field->CommissionGroupID, field->IsAutoAudit);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveAccountField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveAccountField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveAccountField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveAccountField:AdminUserID:[%s], AccountID:[%s]", field->AdminUserID, field->AccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddBaseCommissionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddBaseCommissionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddBaseCommissionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddBaseCommissionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddBaseCommissionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddBaseCommissionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateBaseCommissionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateBaseCommissionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateBaseCommissionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d], OpenStampTaxByMoney:[%f], CloseStampTaxByMoney:[%f], OpenTransferFeeByMoney:[%f], CloseTransferFeeByMoney:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType, field->OpenStampTaxByMoney, field->CloseStampTaxByMoney, field->OpenTransferFeeByMoney, field->CloseTransferFeeByMoney);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateBaseCommissionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateBaseCommissionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateBaseCommissionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveBaseCommissionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveBaseCommissionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveBaseCommissionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveBaseCommissionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveBaseCommissionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveBaseCommissionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveBaseCommissionField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddCommissionGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddCommissionGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddCommissionGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddCommissionGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddCommissionGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddCommissionGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateCommissionGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %s, %s, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateCommissionGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateCommissionGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], CommissionGroupName:[%s], ExchangeID:[%s], SecurityType:[%d], OpenBuyByMoney:[%f], OpenSellByMoney:[%f], CloseBuyByMoney:[%f], CloseSellByMoney:[%f], OpenBuyByVolume:[%f], OpenSellByVolume:[%f], CloseBuyByVolume:[%f], CloseSellByVolume:[%f], MinCommission:[%f], MaxCommission:[%f]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->CommissionGroupName, field->ExchangeID, (int)field->SecurityType, field->OpenBuyByMoney, field->OpenSellByMoney, field->CloseBuyByMoney, field->CloseSellByMoney, field->OpenBuyByVolume, field->OpenSellByVolume, field->CloseBuyByVolume, field->CloseSellByVolume, field->MinCommission, field->MaxCommission);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateCommissionGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateCommissionGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateCommissionGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveCommissionGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveCommissionGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveCommissionGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveCommissionGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d, %s, %d", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveCommissionGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveCommissionGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveCommissionGroupField:AdminUserID:[%s], TradingDay:[%s], CommissionGroupID:[%d], ExchangeID:[%s], SecurityType:[%d]", field->AdminUserID, field->TradingDay, field->CommissionGroupID, field->ExchangeID, (int)field->SecurityType);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddOptionMarginParamField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddOptionMarginParamField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddOptionMarginParamField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %f, %f", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateOptionMarginParamField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateOptionMarginParamField:AdminUserID:[%s], TradingDay:[%s], ExchangeID:[%s], Param1:[%f], Param2:[%f]", field->AdminUserID, field->TradingDay, field->ExchangeID, field->Param1, field->Param2);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateOptionMarginParamField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveOptionMarginParamField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveOptionMarginParamField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveOptionMarginParamField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveOptionMarginParamField:AdminUserID:[%s], ExchangeID:[%s]", field->AdminUserID, field->ExchangeID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddTradeOfferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s, %d, %s", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddTradeOfferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddTradeOfferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddTradeOfferField:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddTradeOfferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddTradeOfferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddTradeOfferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateTradeOfferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s, %d, %s", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateTradeOfferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateTradeOfferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateTradeOfferField:AdminUserID:[%s], OfferID:[%d], OfferName:[%s], OfferType:[%d], OfferPassword:[%s]", field->AdminUserID, field->OfferID, field->OfferName, (int)field->OfferType, field->OfferPassword);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateTradeOfferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateTradeOfferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateTradeOfferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveTradeOfferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveTradeOfferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveTradeOfferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveTradeOfferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveTradeOfferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveTradeOfferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveTradeOfferField:AdminUserID:[%s], OfferID:[%d]", field->AdminUserID, field->OfferID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddTradeGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddTradeGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddTradeGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddTradeGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddTradeGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddTradeGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateTradeGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateTradeGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateTradeGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d], TradeGroupName:[%s]", field->AdminUserID, field->TradeGroupID, field->TradeGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateTradeGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateTradeGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateTradeGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveTradeGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveTradeGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveTradeGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveTradeGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveTradeGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveTradeGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveTradeGroupField:AdminUserID:[%s], TradeGroupID:[%d]", field->AdminUserID, field->TradeGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d, %s", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddTradeGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddTradeGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d, %s", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateTradeGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d], PrimaryAccountID:[%s]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateTradeGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveTradeGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveTradeGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveTradeGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveTradeGroupItemField:AdminUserID:[%s], TradeGroupID:[%d], AccountClass:[%d]", field->AdminUserID, field->TradeGroupID, (int)field->AccountClass);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddRiskGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddRiskGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddRiskGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddRiskGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateRiskGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateRiskGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateRiskGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d], RiskGroupName:[%s]", field->AdminUserID, field->RiskGroupID, field->RiskGroupName);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateRiskGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateRiskGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateRiskGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveRiskGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveRiskGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveRiskGroupField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveRiskGroupField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskGroupField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskGroupField:AdminUserID:[%s], RiskGroupID:[%d]", field->AdminUserID, field->RiskGroupID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqUpdateRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqUpdateRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateRiskGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqUpdateRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspUpdateRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspUpdateRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspUpdateRiskGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspUpdateRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveRiskGroupItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskGroupItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskGroupItemField:AdminUserID:[%s], RiskGroupID:[%d], RiskID:[%d]", field->AdminUserID, field->RiskGroupID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddOrUpdateRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %s, %d", field->AdminUserID, field->RiskID, field->RiskName, (int)field->RiskClassID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddOrUpdateRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddOrUpdateRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddOrUpdateRiskField:AdminUserID:[%s], RiskID:[%d], RiskName:[%s], RiskClassID:[%d]", field->AdminUserID, field->RiskID, field->RiskName, (int)field->RiskClassID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddOrUpdateRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddOrUpdateRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddOrUpdateRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddOrUpdateRiskField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveRiskField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveRiskField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddRiskRuleField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d, %d, %s", field->AdminUserID, field->RiskID, field->RiskRuleID, (int)field->RiskRuleStyle, field->FormatRiskMessage);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddRiskRuleField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskRuleField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskRuleField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleStyle:[%d], FormatRiskMessage:[%s]", field->AdminUserID, field->RiskID, field->RiskRuleID, (int)field->RiskRuleStyle, field->FormatRiskMessage);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddRiskRuleField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d", field->AdminUserID, field->RiskID, field->RiskRuleID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddRiskRuleField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskRuleField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskRuleField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddRiskRuleItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s, %s, %d, %d, %s, %d, %d, %s, %d", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID, (int)field->RiskIndexType, field->RiskIndexID, field->RiskIndexTextRef, field->IndexParam1, field->IndexParam2, field->IndexParam3, field->IndexParam4, field->IndexParam5, field->IndexParam6, (int)field->LogicFunc, (int)field->LogicParamType1, field->LogicParam1, field->LogicParam1TextRef, (int)field->LogicParamType2, field->LogicParam2, field->LogicParam2TextRef);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddRiskRuleItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskRuleItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskRuleItemField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d], RiskIndexType:[%d], RiskIndexID:[%d], RiskIndexTextRef:[%d], IndexParam1:[%s], IndexParam2:[%s], IndexParam3:[%s], IndexParam4:[%s], IndexParam5:[%s], IndexParam6:[%s], LogicFunc:[%d], LogicParamType1:[%d], LogicParam1:[%s], LogicParam1TextRef:[%d], LogicParamType2:[%d], LogicParam2:[%s], LogicParam2TextRef:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID, (int)field->RiskIndexType, field->RiskIndexID, field->RiskIndexTextRef, field->IndexParam1, field->IndexParam2, field->IndexParam3, field->IndexParam4, field->IndexParam5, field->IndexParam6, (int)field->LogicFunc, (int)field->LogicParamType1, field->LogicParam1, field->LogicParam1TextRef, (int)field->LogicParamType2, field->LogicParam2, field->LogicParam2TextRef);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddRiskRuleItemField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d, %d", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddRiskRuleItemField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskRuleItemField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskRuleItemField:AdminUserID:[%s], RiskID:[%d], RiskRuleID:[%d], RiskRuleItemID:[%d]", field->AdminUserID, field->RiskID, field->RiskRuleID, field->RiskRuleItemID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddRiskTradeScopeField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d, %d, %d, %s", field->AdminUserID, field->RiskID, (int)field->TradeScopeType, field->InstrumentGroupID, field->FormatRiskMessage);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddRiskTradeScopeField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskTradeScopeField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddRiskTradeScopeField:AdminUserID:[%s], RiskID:[%d], TradeScopeType:[%d], InstrumentGroupID:[%d], FormatRiskMessage:[%s]", field->AdminUserID, field->RiskID, (int)field->TradeScopeType, field->InstrumentGroupID, field->FormatRiskMessage);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddRiskTradeScopeField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %d", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddRiskTradeScopeField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskTradeScopeField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddRiskTradeScopeField:AdminUserID:[%s], RiskID:[%d]", field->AdminUserID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAddAccountRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAddAccountRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAddAccountRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAddAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAddAccountRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAddAccountRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAddAccountRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAddAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqRemoveAccountRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqRemoveAccountRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveAccountRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqRemoveAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspRemoveAccountRiskField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %d", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspRemoveAccountRiskField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspRemoveAccountRiskField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspRemoveAccountRiskField:AdminUserID:[%s], AccountID:[%s], RiskID:[%d]", field->AdminUserID, field->AccountID, field->RiskID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqMoneyTransferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d, %d, %d, %f, %s, %s, %s, %s", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqMoneyTransferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqMoneyTransferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqMoneyTransferField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d], AccountType:[%d], TransferDirection:[%d], TransferAmount:[%f], InfoMessage:[%s], UserID:[%s], TransferDate:[%s], TransferTime:[%s]", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID, (int)field->AccountType, (int)field->TransferDirection, field->TransferAmount, field->InfoMessage, field->UserID, field->TransferDate, field->TransferTime);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspMoneyTransferField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspMoneyTransferField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspMoneyTransferField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspMoneyTransferField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], MoneyTransferID:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->MoneyTransferID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqAuditOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %s, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqAuditOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqAuditOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqAuditOrderField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspAuditOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %s, %d, %d", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspAuditOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspAuditOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspAuditOrderField:AdminUserID:[%s], TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], AuditStatus:[%d]", field->AdminUserID, field->TradingDay, field->AccountID, field->ExchangeID, field->InstrumentID, field->OrderID, (int)field->AuditStatus);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqOfferLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s", field->OfferID, field->OfferPassword);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqOfferLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqOfferLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqOfferLoginField:OfferID:[%d], OfferPassword:[%s]", field->OfferID, field->OfferPassword);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspOfferLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s, %d, %s", field->ErrorID, field->ErrorMsg, field->OfferID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspOfferLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspOfferLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspOfferLoginField:ErrorID:[%d], ErrorMsg:[%s], OfferID:[%d], TradingDay:[%s]", field->ErrorID, field->ErrorMsg, field->OfferID, field->TradingDay);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqPrimaryAccountLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->PrimaryAccountID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqPrimaryAccountLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountLoginField:PrimaryAccountID:[%s], Password:[%s]", field->PrimaryAccountID, field->Password);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspPrimaryAccountLoginField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s, %s, %s", field->ErrorID, field->ErrorMsg, field->TradingDay, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspPrimaryAccountLoginField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspPrimaryAccountLoginField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspPrimaryAccountLoginField:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s]", field->ErrorID, field->ErrorMsg, field->TradingDay, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqPrimaryAccountLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->TradingDay, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqPrimaryAccountLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountLogoutField:TradingDay:[%s], PrimaryAccountID:[%s]", field->TradingDay, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RtnPrimaryAccountLogoutField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s", field->TradingDay, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RtnPrimaryAccountLogoutField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RtnPrimaryAccountLogoutField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RtnPrimaryAccountLogoutField:TradingDay:[%s], PrimaryAccountID:[%s]", field->TradingDay, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqPrimaryAccountInitField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqPrimaryAccountInitField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountInitField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountInitField:PrimaryAccountID:[%s]", field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspPrimaryAccountInitField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s, %s", field->ErrorID, field->ErrorMsg, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspPrimaryAccountInitField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspPrimaryAccountInitField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspPrimaryAccountInitField:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]", field->ErrorID, field->ErrorMsg, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqPrimaryAccountQueryField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqPrimaryAccountQueryField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountQueryField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqPrimaryAccountQueryField:PrimaryAccountID:[%s]", field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspPrimaryAccountQueryField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s, %s", field->ErrorID, field->ErrorMsg, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspPrimaryAccountQueryField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspPrimaryAccountQueryField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspPrimaryAccountQueryField:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]", field->ErrorID, field->ErrorMsg, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqQryOfferOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s", field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqQryOfferOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqQryOfferOptionInstrumentField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqQryOfferOptionInstrumentField:PrimaryAccountID:[%s]", field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(RspQryOfferOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s, %s", field->ErrorID, field->ErrorMsg, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(RspQryOfferOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "RspQryOfferOptionInstrumentField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "RspQryOfferOptionInstrumentField:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]", field->ErrorID, field->ErrorMsg, field->PrimaryAccountID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OfferOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %s, %d, %d, %s, %f, %f, %f, %d, %d, %s", field->TradingDay, field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->OptionType, field->UnderlyingInstrumentID, field->ExecutePrice, field->UnitMargin, field->PriceTick, field->MaxLimitOrderVolume, field->MaxMarketOrderVolume, field->ExpiringDate);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OfferOptionInstrumentField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OfferOptionInstrumentField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OfferOptionInstrumentField:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]", field->TradingDay, field->ExchangeID, field->InstrumentID, field->ExchangeInstID, field->InstrumentName, field->VolumeMultiple, (int)field->OptionType, field->UnderlyingInstrumentID, field->ExecutePrice, field->UnitMargin, field->PriceTick, field->MaxLimitOrderVolume, field->MaxMarketOrderVolume, field->ExpiringDate);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqOfferOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %d, %d, %d, %f, %d", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqOfferOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqOfferOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqOfferOrderField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d]", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, field->OrderID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume);
	}
	return t_FieldStringBuffer;
}
std::string GetString(ReqOfferCancelOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %d, %d, %s", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, (int)field->Direction, field->CancelOrderID, field->OrderID, field->OrderSysID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(ReqOfferCancelOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "ReqOfferCancelOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "ReqOfferCancelOrderField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->SecurityType, (int)field->Direction, field->CancelOrderID, field->OrderID, field->OrderSysID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OfferOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %s, %d, %d, %d, %f, %d, %d, %d, %d, %s, %s, %s, %s, %s, %d", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, field->OrderID, field->OrderSysID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->VolumeTotal, field->VolumeTraded, (int)field->OrderStatus, field->StatusMsg, field->OrderDate, field->OrderTime, field->CancelDate, field->CancelTime, field->IsNewOrder);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OfferOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OfferOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OfferOrderField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], IsNewOrder:[%d]", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, field->OrderID, field->OrderSysID, (int)field->Direction, (int)field->OffsetFlag, (int)field->OrderPriceType, field->Price, field->Volume, field->VolumeTotal, field->VolumeTraded, (int)field->OrderStatus, field->StatusMsg, field->OrderDate, field->OrderTime, field->CancelDate, field->CancelTime, field->IsNewOrder);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OfferTradeField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %s, %s, %d, %d, %f, %d, %s, %s", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, field->OrderID, field->OrderSysID, field->TradeID, (int)field->Direction, (int)field->OffsetFlag, field->Price, field->Volume, field->TradeDate, field->TradeTime);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OfferTradeField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OfferTradeField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OfferTradeField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], TradeDate:[%s], TradeTime:[%s]", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, field->OrderID, field->OrderSysID, field->TradeID, (int)field->Direction, (int)field->OffsetFlag, field->Price, field->Volume, field->TradeDate, field->TradeTime);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OfferErrorCancelOrderField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%d, %s, %s, %s, %s, %s, %d, %d, %d, %s", field->ErrorID, field->ErrorMsg, field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, field->CancelOrderID, field->OrderID, field->OrderSysID);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OfferErrorCancelOrderField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OfferErrorCancelOrderField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OfferErrorCancelOrderField:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]", field->ErrorID, field->ErrorMsg, field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->Direction, field->CancelOrderID, field->OrderID, field->OrderSysID);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OfferCapitalField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %f", field->TradingDay, field->PrimaryAccountID, field->PreCashAsset);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OfferCapitalField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OfferCapitalField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OfferCapitalField:TradingDay:[%s], PrimaryAccountID:[%s], PreCashAsset:[%f]", field->TradingDay, field->PrimaryAccountID, field->PreCashAsset);
	}
	return t_FieldStringBuffer;
}
std::string GetString(OfferPositionField* field)
{
	if (field == nullptr)
	{
		memset(t_FieldStringBuffer, 0, sizeof(t_FieldStringBuffer));
	}
	else
	{
		sprintf(t_FieldStringBuffer, "%s, %s, %s, %s, %d, %d, %d, %f, %f, %f", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->PosiDirection, field->TotalPosition, field->PositionFrozen, field->TotalCostPrice, field->Margin, field->MarketValue);
	}
	return t_FieldStringBuffer;
}
std::string GetDebugString(OfferPositionField* field)
{
	if (field == nullptr)
	{
		sprintf(t_FieldStringBuffer, "OfferPositionField:nullptr");
	}
	else
	{
		sprintf(t_FieldStringBuffer, "OfferPositionField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TotalCostPrice:[%f], Margin:[%f], MarketValue:[%f]", field->TradingDay, field->PrimaryAccountID, field->ExchangeID, field->InstrumentID, (int)field->PosiDirection, field->TotalPosition, field->PositionFrozen, field->TotalCostPrice, field->Margin, field->MarketValue);
	}
	return t_FieldStringBuffer;
}
