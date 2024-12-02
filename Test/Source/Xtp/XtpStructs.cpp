#include "XtpStructs.h"
#include <string>

thread_local char t_XtpDataStringBuffer[10240];

namespace xtp
{
	const char* XtpSessionCloseField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpSessionCloseField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpSessionCloseField:ErrorID:[%d], ErrorMsg:[%s]",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqOfferLoginField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s",
			OfferID, OfferPassword);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqOfferLoginField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqOfferLoginField:OfferID:[%d], OfferPassword:[%s]",
			OfferID, OfferPassword);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspOfferLoginField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%d,%s",
			ErrorID, ErrorMsg, OfferID, TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspOfferLoginField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspOfferLoginField:ErrorID:[%d], ErrorMsg:[%s], OfferID:[%d], TradingDay:[%s]",
			ErrorID, ErrorMsg, OfferID, TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountLoginField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			PrimaryAccountID, Password);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountLoginField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountLoginField:PrimaryAccountID:[%s], Password:[%s]",
			PrimaryAccountID, Password);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspPrimaryAccountLoginField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s,%s",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspPrimaryAccountLoginField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspPrimaryAccountLoginField:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountLogoutField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountLogoutField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountLogoutField:TradingDay:[%s], PrimaryAccountID:[%s]",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnPrimaryAccountLogoutField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnPrimaryAccountLogoutField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnPrimaryAccountLogoutField:TradingDay:[%s], PrimaryAccountID:[%s]",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountInitField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountInitField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountInitField:PrimaryAccountID:[%s]",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspPrimaryAccountInitField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspPrimaryAccountInitField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspPrimaryAccountInitField:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountQueryField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountQueryField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountQueryField:PrimaryAccountID:[%s]",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspPrimaryAccountQueryField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspPrimaryAccountQueryField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspPrimaryAccountQueryField:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqQryOptionInstrumentField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqQryOptionInstrumentField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqQryOptionInstrumentField:PrimaryAccountID:[%s]",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspQryOptionInstrumentField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspQryOptionInstrumentField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspQryOptionInstrumentField:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnOptionInstrumentField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%s,%d,%d,%s,%f,%f,%f,%d,%d,%s",
			TradingDay, ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)OptionType, UnderlyingInstrumentID, ExecutePrice, UnitMargin, PriceTick, MaxLimitOrderVolume, MaxMarketOrderVolume, ExpiringDate);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnOptionInstrumentField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnOptionInstrumentField:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]",
			TradingDay, ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)OptionType, UnderlyingInstrumentID, ExecutePrice, UnitMargin, PriceTick, MaxLimitOrderVolume, MaxMarketOrderVolume, ExpiringDate);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqInsertOrderField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d,%d,%d,%d,%f,%d",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, OrderID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqInsertOrderField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqInsertOrderField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, OrderID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqCancelOrderField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d,%d,%d,%s",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqCancelOrderField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqCancelOrderField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnOrderField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%s,%d,%d,%d,%f,%d,%d,%d,%d,%s,%s,%s,%s,%s,%d",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume, VolumeTotal, VolumeTraded, (int)OrderStatus, StatusMsg, OrderDate, OrderTime, CancelDate, CancelTime, IsNewOrder);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnOrderField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnOrderField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], IsNewOrder:[%d]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume, VolumeTotal, VolumeTraded, (int)OrderStatus, StatusMsg, OrderDate, OrderTime, CancelDate, CancelTime, IsNewOrder);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnTradeField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%s,%s,%d,%d,%f,%d,%s,%s",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, TradeID, (int)Direction, (int)OffsetFlag, Price, Volume, TradeDate, TradeTime);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnTradeField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnTradeField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], TradeDate:[%s], TradeTime:[%s]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, TradeID, (int)Direction, (int)OffsetFlag, Price, Volume, TradeDate, TradeTime);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnErrorCancelOrderField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s,%s,%s,%s,%d,%d,%d,%s",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnErrorCancelOrderField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnErrorCancelOrderField:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnCapitalField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%f",
			TradingDay, PrimaryAccountID, PreCashAsset);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnCapitalField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnCapitalField:TradingDay:[%s], PrimaryAccountID:[%s], PreCashAsset:[%f]",
			TradingDay, PrimaryAccountID, PreCashAsset);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnPositionField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d,%d,%f,%f,%f",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)PosiDirection, TotalPosition, PositionFrozen, TotalCostPrice, Margin, MarketValue);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnPositionField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnPositionField:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TotalCostPrice:[%f], Margin:[%f], MarketValue:[%f]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)PosiDirection, TotalPosition, PositionFrozen, TotalCostPrice, Margin, MarketValue);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqMDOfferLoginField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			UserID, Password);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqMDOfferLoginField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqMDOfferLoginField:UserID:[%s], Password:[%s]",
			UserID, Password);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspMDOfferLoginField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspMDOfferLoginField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspMDOfferLoginField:ErrorID:[%d], ErrorMsg:[%s]",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqMDInitField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqMDInitField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqMDInitField:ExchangeID:[%s], TradingDay:[%s]",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspMDInitField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%d,%s",
			ExchangeID, TradingDay, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspMDInitField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspMDInitField:ExchangeID:[%s], TradingDay:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			ExchangeID, TradingDay, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqSubscribeMDField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			ExchangeID, InstrumentID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqSubscribeMDField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqSubscribeMDField:ExchangeID:[%s], InstrumentID:[%s]",
			ExchangeID, InstrumentID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspSubscribeMDField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%d,%s",
			ExchangeID, InstrumentID, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspSubscribeMDField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspSubscribeMDField:ExchangeID:[%s], InstrumentID:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			ExchangeID, InstrumentID, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnShortMDField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%f,%f,%f,%f,%f,%f,%f",
			TradingDay, ExchangeID, InstrumentID, LastPrice, ClosePrice, PreClosePrice, SettlementPrice, PreSettlementPrice, UpperLimitPrice, LowerLimitPrice);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnShortMDField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnShortMDField:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], LastPrice:[%f], ClosePrice:[%f], PreClosePrice:[%f], SettlementPrice:[%f], PreSettlementPrice:[%f], UpperLimitPrice:[%f], LowerLimitPrice:[%f]",
			TradingDay, ExchangeID, InstrumentID, LastPrice, ClosePrice, PreClosePrice, SettlementPrice, PreSettlementPrice, UpperLimitPrice, LowerLimitPrice);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnExchangeStatusField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%d",
			ExchangeID, ExchangeDate, (int)ExchangeStatus);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnExchangeStatusField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnExchangeStatusField:ExchangeID:[%s], ExchangeDate:[%s], ExchangeStatus:[%d]",
			ExchangeID, ExchangeDate, (int)ExchangeStatus);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnInstrumentField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d",
			ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)SecurityType);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnInstrumentField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnInstrumentField:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], SecurityType:[%d]",
			ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)SecurityType);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnMDInitCompletedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnMDInitCompletedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnMDInitCompletedField:ExchangeID:[%s], TradingDay:[%s]",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyMdClientConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyMdClientConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyMdClientConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyMdClientDisConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyMdClientDisConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyMdClientDisConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskCheckClientConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskCheckClientConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskCheckClientConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskCheckClientDisConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskCheckClientDisConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskCheckClientDisConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyTradeFrontConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyTradeFrontConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyTradeFrontConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyTradeFrontDisConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyTradeFrontDisConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyTradeFrontDisConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskFrontConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskFrontConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskFrontConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskFrontDisConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskFrontDisConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskFrontDisConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyAdminFrontConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyAdminFrontConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyAdminFrontConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyAdminFrontDisConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyAdminFrontDisConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyAdminFrontDisConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyOfferFrontConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyOfferFrontConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyOfferFrontConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyOfferFrontDisConnectedField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyOfferFrontDisConnectedField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyOfferFrontDisConnectedField:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyInitCompleteField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyInitCompleteField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyInitCompleteField:TradingDay:[%s]",
			TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspNotifyInitCompleteField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspNotifyInitCompleteField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspNotifyInitCompleteField:TradingDay:[%s]",
			TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnRiskCheckOrderField::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%s,%d,%d,%d,%s",
			TradingDay, AccountID, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, RiskID, (int)RiskStatus, RiskMessage);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnRiskCheckOrderField::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnRiskCheckOrderField:TradingDay:[%s], AccountID:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], RiskID:[%d], RiskStatus:[%d], RiskMessage:[%s]",
			TradingDay, AccountID, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, RiskID, (int)RiskStatus, RiskMessage);
		return t_XtpDataStringBuffer;
	}

}
