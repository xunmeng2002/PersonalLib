#include "XtpStructs.h"
#include <string>

thread_local char t_XtpDataStringBuffer[10240];

namespace xtp
{
	const char* XtpSessionClose::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpSessionClose::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpSessionClose:ErrorID:[%d], ErrorMsg:[%s]",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqOfferLogin::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s",
			OfferID, OfferPassword);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqOfferLogin::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqOfferLogin:OfferID:[%d], OfferPassword:[%s]",
			OfferID, OfferPassword);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspOfferLogin::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%d,%s",
			ErrorID, ErrorMsg, OfferID, TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspOfferLogin::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspOfferLogin:ErrorID:[%d], ErrorMsg:[%s], OfferID:[%d], TradingDay:[%s]",
			ErrorID, ErrorMsg, OfferID, TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountLogin::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			PrimaryAccountID, Password);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountLogin::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountLogin:PrimaryAccountID:[%s], Password:[%s]",
			PrimaryAccountID, Password);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspPrimaryAccountLogin::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s,%s",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspPrimaryAccountLogin::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspPrimaryAccountLogin:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountLogout::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountLogout::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountLogout:TradingDay:[%s], PrimaryAccountID:[%s]",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnPrimaryAccountLogout::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnPrimaryAccountLogout::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnPrimaryAccountLogout:TradingDay:[%s], PrimaryAccountID:[%s]",
			TradingDay, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountInit::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountInit::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountInit:PrimaryAccountID:[%s]",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspPrimaryAccountInit::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspPrimaryAccountInit::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspPrimaryAccountInit:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqPrimaryAccountQuery::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqPrimaryAccountQuery::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqPrimaryAccountQuery:PrimaryAccountID:[%s]",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspPrimaryAccountQuery::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspPrimaryAccountQuery::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspPrimaryAccountQuery:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqQryOptionInstrument::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqQryOptionInstrument::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqQryOptionInstrument:PrimaryAccountID:[%s]",
			PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspQryOptionInstrument::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspQryOptionInstrument::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspQryOptionInstrument:ErrorID:[%d], ErrorMsg:[%s], PrimaryAccountID:[%s]",
			ErrorID, ErrorMsg, PrimaryAccountID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnOptionInstrument::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%s,%d,%d,%s,%f,%f,%f,%d,%d,%s",
			TradingDay, ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)OptionType, UnderlyingInstrumentID, ExecutePrice, UnitMargin, PriceTick, MaxLimitOrderVolume, MaxMarketOrderVolume, ExpiringDate);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnOptionInstrument::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnOptionInstrument:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], OptionType:[%d], UnderlyingInstrumentID:[%s], ExecutePrice:[%f], UnitMargin:[%f], PriceTick:[%f], MaxLimitOrderVolume:[%d], MaxMarketOrderVolume:[%d], ExpiringDate:[%s]",
			TradingDay, ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)OptionType, UnderlyingInstrumentID, ExecutePrice, UnitMargin, PriceTick, MaxLimitOrderVolume, MaxMarketOrderVolume, ExpiringDate);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqInsertOrder::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d,%d,%d,%d,%f,%d",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, OrderID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqInsertOrder::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqInsertOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], OrderID:[%d], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, OrderID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqCancelOrder::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d,%d,%d,%s",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqCancelOrder::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqCancelOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], SecurityType:[%d], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)SecurityType, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnOrder::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%s,%d,%d,%d,%f,%d,%d,%d,%d,%s,%s,%s,%s,%s,%d",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume, VolumeTotal, VolumeTraded, (int)OrderStatus, StatusMsg, OrderDate, OrderTime, CancelDate, CancelTime, IsNewOrder);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnOrder::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnOrder:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], Direction:[%d], OffsetFlag:[%d], OrderPriceType:[%d], Price:[%f], Volume:[%d], VolumeTotal:[%d], VolumeTraded:[%d], OrderStatus:[%d], StatusMsg:[%s], OrderDate:[%s], OrderTime:[%s], CancelDate:[%s], CancelTime:[%s], IsNewOrder:[%d]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, (int)Direction, (int)OffsetFlag, (int)OrderPriceType, Price, Volume, VolumeTotal, VolumeTraded, (int)OrderStatus, StatusMsg, OrderDate, OrderTime, CancelDate, CancelTime, IsNewOrder);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnTrade::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%s,%s,%d,%d,%f,%d,%s,%s",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, TradeID, (int)Direction, (int)OffsetFlag, Price, Volume, TradeDate, TradeTime);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnTrade::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnTrade:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], OrderSysID:[%s], TradeID:[%s], Direction:[%d], OffsetFlag:[%d], Price:[%f], Volume:[%d], TradeDate:[%s], TradeTime:[%s]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, OrderSysID, TradeID, (int)Direction, (int)OffsetFlag, Price, Volume, TradeDate, TradeTime);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnErrorCancelOrder::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s,%s,%s,%s,%s,%d,%d,%d,%s",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnErrorCancelOrder::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnErrorCancelOrder:ErrorID:[%d], ErrorMsg:[%s], TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], Direction:[%d], CancelOrderID:[%d], OrderID:[%d], OrderSysID:[%s]",
			ErrorID, ErrorMsg, TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)Direction, CancelOrderID, OrderID, OrderSysID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnCapital::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%f",
			TradingDay, PrimaryAccountID, PreCashAsset);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnCapital::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnCapital:TradingDay:[%s], PrimaryAccountID:[%s], PreCashAsset:[%f]",
			TradingDay, PrimaryAccountID, PreCashAsset);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnPosition::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d,%d,%f,%f,%f",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)PosiDirection, TotalPosition, PositionFrozen, TotalCostPrice, Margin, MarketValue);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnPosition::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnPosition:TradingDay:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], PosiDirection:[%d], TotalPosition:[%d], PositionFrozen:[%d], TotalCostPrice:[%f], Margin:[%f], MarketValue:[%f]",
			TradingDay, PrimaryAccountID, ExchangeID, InstrumentID, (int)PosiDirection, TotalPosition, PositionFrozen, TotalCostPrice, Margin, MarketValue);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqMDOfferLogin::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			UserID, Password);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqMDOfferLogin::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqMDOfferLogin:UserID:[%s], Password:[%s]",
			UserID, Password);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspMDOfferLogin::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%d,%s",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspMDOfferLogin::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspMDOfferLogin:ErrorID:[%d], ErrorMsg:[%s]",
			ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqMDInit::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqMDInit::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqMDInit:ExchangeID:[%s], TradingDay:[%s]",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspMDInit::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%d,%s",
			ExchangeID, TradingDay, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspMDInit::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspMDInit:ExchangeID:[%s], TradingDay:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			ExchangeID, TradingDay, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpReqSubscribeMD::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			ExchangeID, InstrumentID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpReqSubscribeMD::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpReqSubscribeMD:ExchangeID:[%s], InstrumentID:[%s]",
			ExchangeID, InstrumentID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspSubscribeMD::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%d,%s",
			ExchangeID, InstrumentID, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspSubscribeMD::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspSubscribeMD:ExchangeID:[%s], InstrumentID:[%s], ErrorID:[%d], ErrorMsg:[%s]",
			ExchangeID, InstrumentID, ErrorID, ErrorMsg);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnShortMD::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%f,%f,%f,%f,%f,%f,%f",
			TradingDay, ExchangeID, InstrumentID, LastPrice, ClosePrice, PreClosePrice, SettlementPrice, PreSettlementPrice, UpperLimitPrice, LowerLimitPrice);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnShortMD::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnShortMD:TradingDay:[%s], ExchangeID:[%s], InstrumentID:[%s], LastPrice:[%f], ClosePrice:[%f], PreClosePrice:[%f], SettlementPrice:[%f], PreSettlementPrice:[%f], UpperLimitPrice:[%f], LowerLimitPrice:[%f]",
			TradingDay, ExchangeID, InstrumentID, LastPrice, ClosePrice, PreClosePrice, SettlementPrice, PreSettlementPrice, UpperLimitPrice, LowerLimitPrice);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnExchangeStatus::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%d",
			ExchangeID, ExchangeDate, (int)ExchangeStatus);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnExchangeStatus::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnExchangeStatus:ExchangeID:[%s], ExchangeDate:[%s], ExchangeStatus:[%d]",
			ExchangeID, ExchangeDate, (int)ExchangeStatus);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnInstrument::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%d,%d",
			ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)SecurityType);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnInstrument::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnInstrument:ExchangeID:[%s], InstrumentID:[%s], ExchangeInstID:[%s], InstrumentName:[%s], VolumeMultiple:[%d], SecurityType:[%d]",
			ExchangeID, InstrumentID, ExchangeInstID, InstrumentName, VolumeMultiple, (int)SecurityType);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnMDInitCompleted::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnMDInitCompleted::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnMDInitCompleted:ExchangeID:[%s], TradingDay:[%s]",
			ExchangeID, TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyMdClientConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyMdClientConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyMdClientConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyMdClientDisConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyMdClientDisConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyMdClientDisConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskCheckClientConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskCheckClientConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskCheckClientConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskCheckClientDisConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskCheckClientDisConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskCheckClientDisConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyTradeFrontConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyTradeFrontConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyTradeFrontConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyTradeFrontDisConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyTradeFrontDisConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyTradeFrontDisConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskFrontConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskFrontConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskFrontConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyRiskFrontDisConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyRiskFrontDisConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyRiskFrontDisConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyAdminFrontConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyAdminFrontConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyAdminFrontConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyAdminFrontDisConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyAdminFrontDisConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyAdminFrontDisConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyOfferFrontConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyOfferFrontConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyOfferFrontConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyOfferFrontDisConnected::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%lld",
			SessionID);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyOfferFrontDisConnected::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyOfferFrontDisConnected:SessionID:[%lld]",
			SessionID);
		return t_XtpDataStringBuffer;
	}

	const char* XtpNotifyInitComplete::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpNotifyInitComplete::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpNotifyInitComplete:TradingDay:[%s]",
			TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRspNotifyInitComplete::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s",
			TradingDay);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRspNotifyInitComplete::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRspNotifyInitComplete:TradingDay:[%s]",
			TradingDay);
		return t_XtpDataStringBuffer;
	}

	const char* XtpRtnRiskCheckOrder::GetString() const
	{
		sprintf(t_XtpDataStringBuffer, "%s,%s,%s,%s,%s,%d,%d,%d,%s",
			TradingDay, AccountID, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, RiskID, (int)RiskStatus, RiskMessage);
		return t_XtpDataStringBuffer;
	}
	const char* XtpRtnRiskCheckOrder::GetDebugString() const
	{
		sprintf(t_XtpDataStringBuffer, "XtpRtnRiskCheckOrder:TradingDay:[%s], AccountID:[%s], PrimaryAccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderID:[%d], RiskID:[%d], RiskStatus:[%d], RiskMessage:[%s]",
			TradingDay, AccountID, PrimaryAccountID, ExchangeID, InstrumentID, OrderID, RiskID, (int)RiskStatus, RiskMessage);
		return t_XtpDataStringBuffer;
	}

}
