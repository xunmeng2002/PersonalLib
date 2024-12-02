#pragma once
#include "Types.h"

namespace xtp
{
	class XtpSessionCloseField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqOfferLoginField
	{
	public:
		OfferIDType OfferID;		//报盘代码
		PasswordType OfferPassword;		//报盘密码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspOfferLoginField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
		OfferIDType OfferID;		//报盘代码
		DateType TradingDay;		//交易日

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqPrimaryAccountLoginField
	{
	public:
		AccountIDType PrimaryAccountID;		//主账户代码
		PasswordType Password;		//密码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspPrimaryAccountLoginField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqPrimaryAccountLogoutField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnPrimaryAccountLogoutField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqPrimaryAccountInitField
	{
	public:
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspPrimaryAccountInitField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqPrimaryAccountQueryField
	{
	public:
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspPrimaryAccountQueryField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqQryOptionInstrumentField
	{
	public:
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspQryOptionInstrumentField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
		AccountIDType PrimaryAccountID;		//主账户代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnOptionInstrumentField
	{
	public:
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		InstrumentIDType ExchangeInstID;		//交易所合约代码
		InstrumentNameType InstrumentName;		//合约名称
		VolumeMultipleType VolumeMultiple;		//合约数量乘数
		OptionTypeType OptionType;		//期权类型
		InstrumentIDType UnderlyingInstrumentID;		//标的合约代码
		PriceType ExecutePrice;		//行权价
		MoneyType UnitMargin;		//单位保证金
		PriceType PriceTick;		//最小变动价位
		VolumeType MaxLimitOrderVolume;		//限价最大下单数量
		VolumeType MaxMarketOrderVolume;		//市价最大下单数量
		DateType ExpiringDate;		//到期日

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqInsertOrderField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		SecurityTypeType SecurityType;		//证券类别
		OrderIDType OrderID;		//委托编号
		DirectionType Direction;		//买卖方向
		OffsetFlagType OffsetFlag;		//开平标志
		OrderPriceTypeType OrderPriceType;		//委托价格类型
		PriceType Price;		//委托价格
		VolumeType Volume;		//委托数量

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqCancelOrderField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		SecurityTypeType SecurityType;		//证券类别
		DirectionType Direction;		//买卖方向
		OrderIDType CancelOrderID;		//本地撤单编号
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnOrderField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号
		DirectionType Direction;		//买卖方向
		OffsetFlagType OffsetFlag;		//开平标志
		OrderPriceTypeType OrderPriceType;		//委托价格类型
		PriceType Price;		//委托价格
		VolumeType Volume;		//委托数量
		VolumeType VolumeTotal;		//剩余数量
		VolumeType VolumeTraded;		//成交数量
		OrderStatusType OrderStatus;		//委托状态
		MessageType StatusMsg;		//状态信息
		DateType OrderDate;		//委托日期
		TimeType OrderTime;		//委托时间
		DateType CancelDate;		//撤单日期
		TimeType CancelTime;		//撤单时间
		BoolType IsNewOrder;		//是否新委托

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnTradeField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号
		TradeIDType TradeID;		//成交编号
		DirectionType Direction;		//买卖方向
		OffsetFlagType OffsetFlag;		//开平标志
		PriceType Price;		//委托价格
		VolumeType Volume;		//成交数量
		DateType TradeDate;		//成交日期
		TimeType TradeTime;		//成交时间

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnErrorCancelOrderField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		DirectionType Direction;		//买卖方向
		OrderIDType CancelOrderID;		//本地撤单编号
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnCapitalField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		MoneyType PreCashAsset;		//上日现金资产

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnPositionField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		PosiDirectionType PosiDirection;		//持仓方向
		VolumeType TotalPosition;		//持仓数量
		VolumeType PositionFrozen;		//冻结数量
		PriceType TotalCostPrice;		//总成本价
		MoneyType Margin;		//保证金
		MoneyType MarketValue;		//市值

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqMDOfferLoginField
	{
	public:
		UserIDType UserID;		//用户代码
		PasswordType Password;		//密码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspMDOfferLoginField
	{
	public:
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqMDInitField
	{
	public:
		ExchangeIDType ExchangeID;		//交易所代码
		DateType TradingDay;		//交易日

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspMDInitField
	{
	public:
		ExchangeIDType ExchangeID;		//交易所代码
		DateType TradingDay;		//交易日
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpReqSubscribeMDField
	{
	public:
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspSubscribeMDField
	{
	public:
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnShortMDField
	{
	public:
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		PriceType LastPrice;		//最新价
		PriceType ClosePrice;		//收盘价
		PriceType PreClosePrice;		//昨收盘价
		PriceType SettlementPrice;		//结算价
		PriceType PreSettlementPrice;		//昨结算价
		PriceType UpperLimitPrice;		//涨停板价
		PriceType LowerLimitPrice;		//跌停板价

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnExchangeStatusField
	{
	public:
		ExchangeIDType ExchangeID;		//交易所代码
		DateType ExchangeDate;		//交易所日期
		ExchangeStatusType ExchangeStatus;		//交易所状态

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnInstrumentField
	{
	public:
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		InstrumentIDType ExchangeInstID;		//交易所合约代码
		InstrumentNameType InstrumentName;		//合约名称
		VolumeMultipleType VolumeMultiple;		//合约数量乘数
		SecurityTypeType SecurityType;		//证券类别

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnMDInitCompletedField
	{
	public:
		ExchangeIDType ExchangeID;		//交易所代码
		DateType TradingDay;		//交易日

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyMdClientConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyMdClientDisConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyRiskCheckClientConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyRiskCheckClientDisConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyTradeFrontConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyTradeFrontDisConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyRiskFrontConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyRiskFrontDisConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyAdminFrontConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyAdminFrontDisConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyOfferFrontConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyOfferFrontDisConnectedField
	{
	public:
		SessionIDType SessionID;		//会话编号

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpNotifyInitCompleteField
	{
	public:
		DateType TradingDay;		//交易日

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRspNotifyInitCompleteField
	{
	public:
		DateType TradingDay;		//交易日

		const char* GetString() const;
		const char* GetDebugString() const;
	};
	class XtpRtnRiskCheckOrderField
	{
	public:
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		AccountIDType PrimaryAccountID;		//主账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		OrderIDType OrderID;		//委托编号
		RiskIDType RiskID;		//风控代码
		RiskStatusType RiskStatus;		//风控状态
		MessageType RiskMessage;		//风控信息

		const char* GetString() const;
		const char* GetDebugString() const;
	};
}