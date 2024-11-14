#pragma once
#include "Types.h"

namespace step
{
	class StepRspInfo
	{
	public:
		static constexpr UShortType FieldID = 0x0003;
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
	};
	class StepReqAccountLogin
	{
	public:
		static constexpr UShortType FieldID = 0x0004;
		AccountIDType AccountID;		//账户代码
		PasswordType Password;		//密码
	};
	class StepRspAccountLogin
	{
	public:
		static constexpr UShortType FieldID = 0x0005;
		AccountIDType AccountID;		//账户代码
		DateType LoginDate;		//登录日期
		TimeType LoginTime;		//登录时间
		SessionIDType SessionID;		//会话编号
	};
	class StepReqAccountLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0006;
		AccountIDType AccountID;		//账户代码
	};
	class StepRspAccountLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0007;
		AccountIDType AccountID;		//账户代码
	};
	class StepAccountLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0008;
		AccountIDType AccountID;		//账户代码
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
	};
	class StepReqRiskUserLogin
	{
	public:
		static constexpr UShortType FieldID = 0x0009;
		UserIDType UserID;		//用户代码
		PasswordType Password;		//密码
	};
	class StepRspRiskUserLogin
	{
	public:
		static constexpr UShortType FieldID = 0x000A;
		UserIDType UserID;		//用户代码
		GroupIDType RiskGroupID;		//交易组代码
		DateType LoginDate;		//登录日期
		TimeType LoginTime;		//登录时间
		SessionIDType SessionID;		//会话编号
	};
	class StepReqRiskUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x000B;
		UserIDType UserID;		//用户代码
	};
	class StepRspRiskUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x000C;
		UserIDType UserID;		//用户代码
	};
	class StepRiskUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x000D;
		UserIDType UserID;		//用户代码
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
	};
	class StepReqAdminUserLogin
	{
	public:
		static constexpr UShortType FieldID = 0x000E;
		UserIDType AdminUserID;		//管理用户代码
		PasswordType Password;		//密码
	};
	class StepRspAdminUserLogin
	{
	public:
		static constexpr UShortType FieldID = 0x000F;
		UserIDType AdminUserID;		//管理用户代码
		DateType LoginDate;		//登录日期
		TimeType LoginTime;		//登录时间
		SessionIDType SessionID;		//会话编号
	};
	class StepReqAdminUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0010;
		UserIDType AdminUserID;		//管理用户代码
	};
	class StepRspAdminUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0011;
		UserIDType AdminUserID;		//管理用户代码
	};
	class StepAdminUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0012;
		UserIDType UserID;		//用户代码
		ErrorIDType ErrorID;		//错误代码
		MessageType ErrorMsg;		//错误信息
	};
	class StepReqMdUserLogin
	{
	public:
		static constexpr UShortType FieldID = 0x0013;
		UserIDType MdUserID;		//行情用户代码
		PasswordType Password;		//密码
	};
	class StepRspMdUserLogin
	{
	public:
		static constexpr UShortType FieldID = 0x0014;
		UserIDType MdUserID;		//行情用户代码
		DateType LoginDate;		//登录日期
		TimeType LoginTime;		//登录时间
		SessionIDType SessionID;		//会话编号
	};
	class StepReqMdUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0015;
		UserIDType MdUserID;		//行情用户代码
	};
	class StepRspMdUserLogout
	{
	public:
		static constexpr UShortType FieldID = 0x0016;
		UserIDType MdUserID;		//行情用户代码
	};
	class StepReqQryAccount
	{
	public:
		static constexpr UShortType FieldID = 0x1001;
		AccountIDType AccountID;		//账户代码
	};
	class StepAccount
	{
	public:
		static constexpr UShortType FieldID = 0x1002;
		AccountIDType AccountID;		//账户代码
		AccountTypeType AccountType;		//账户类型
		AccountStatusType AccountStatus;		//账户状态
		GroupIDType TradeGroupID;		//交易组代码
		GroupIDType RiskGroupID;		//交易组代码
		GroupIDType CommissionGroupID;		//交易组代码
	};
	class StepReqQryHolderAccount
	{
	public:
		static constexpr UShortType FieldID = 0x1003;
		AccountIDType AccountID;		//账户代码
	};
	class StepHolderAccount
	{
	public:
		static constexpr UShortType FieldID = 0x1004;
		ExchangeIDType ExchangeID;		//交易所代码
		AccountIDType HolderAccountID;		//股东账户代码
		BoolType PrimaryFlag;		//主账号标志
	};
	class StepAccountDelete
	{
	public:
		static constexpr UShortType FieldID = 0x1005;
		AccountIDType AccountID;		//账户代码
	};
	class StepReqQryCapital
	{
	public:
		static constexpr UShortType FieldID = 0x1006;
		AccountIDType AccountID;		//账户代码
	};
	class StepCapital
	{
	public:
		static constexpr UShortType FieldID = 0x1007;
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		AccountTypeType AccountType;		//账户类型
		MoneyType Asset;		//总资产
		MoneyType PreAsset;		//上日总资产
		MoneyType CashAsset;		//现金资产
		MoneyType PreCashAsset;		//上日现金资产
		MoneyType Available;		//可用资金
		MoneyType CashIn;		//现金收入
		MoneyType CashOut;		//现金支出
		MoneyType Margin;		//保证金
		MoneyType Commission;		//手续费
		MoneyType StampTax;		//印花税
		MoneyType TransferFee;		//过户费
		MoneyType FrozenCash;		//冻结资金
		MoneyType FrozenMargin;		//冻结保证金
		MoneyType FrozenCommission;		//冻结手续费
		MoneyType FrozenStampTax;		//冻结印花税
		MoneyType FrozenTransferFee;		//冻结过户费
		MoneyType MarketValue;		//市值
		MoneyType TotalProfit;		//总盈亏
		MoneyType TodayProfit;		//当日盈亏
		MoneyType Deposit;		//入金
		MoneyType Withdraw;		//出金
	};
	class StepReqQryPosition
	{
	public:
		static constexpr UShortType FieldID = 0x1008;
		AccountIDType AccountID;		//账户代码
	};
	class StepPosition
	{
	public:
		static constexpr UShortType FieldID = 0x1009;
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		AccountTypeType AccountType;		//账户类型
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		SecurityTypeType SecurityType;		//证券类别
		PosiDirectionType PosiDirection;		//持仓方向
		VolumeType TotalPosition;		//持仓数量
		VolumeType PositionFrozen;		//冻结持仓
		VolumeType TodayPosition;		//今日持仓
		PriceType TotalCostPrice;		//总成本价
		PriceType TodayCostPrice;		//当日成本价
		MoneyType CashIn;		//现金收入
		MoneyType CashOut;		//现金支出
		MoneyType Margin;		//保证金
		MoneyType Commission;		//手续费
		MoneyType StampTax;		//印花税
		MoneyType TransferFee;		//过户费
		MoneyType MarketValue;		//市值
		VolumeMultipleType VolumeMultiple;		//合约乘数
		MoneyType TotalCost;		//总成本
		MoneyType TodayCost;		//当日成本
		MoneyType TotalProfit;		//总盈亏
		MoneyType TodayProfit;		//当日盈亏
		PriceType LastPrice;		//最新价
		PriceType PrePrice;		//昨收盘价或昨结算价
	};
	class StepReqQryOrder
	{
	public:
		static constexpr UShortType FieldID = 0x100A;
		AccountIDType AccountID;		//账户代码
	};
	class StepOrder
	{
	public:
		static constexpr UShortType FieldID = 0x100B;
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		SecurityTypeType SecurityType;		//证券类别
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号
		DirectionType Direction;		//买卖方向
		OffsetFlagType OffsetFlag;		//开平标志
		OrderPriceTypeType OrderPriceType;		//委托价格类型
		PriceType Price;		//委托价格
		VolumeType Volume;		//委托数量
		VolumeType VolumeTotal;		//剩余数量
		VolumeType VolumeTraded;		//成交数量
		VolumeMultipleType VolumeMultiple;		//合约乘数
		OrderStatusType OrderStatus;		//委托状态
		MessageType StatusMsg;		//状态信息
		DateType OrderDate;		//委托日期
		TimeType OrderTime;		//委托时间
		DateType CancelDate;		//撤单日期
		TimeType CancelTime;		//撤单时间
		SessionIDType SessionID;		//会话编号
		ClientOrderIDType ClientOrderID;		//客户端委托编号
		RequestIDType RequestID;		//客户端请求编号
		MoneyType FrozenCash;		//冻结资金
		MoneyType FrozenMargin;		//冻结保证金
		MoneyType FrozenCommission;		//冻结手续费
		MoneyType FrozenStampTax;		//冻结印花税
		MoneyType FrozenTransferFee;		//冻结过户费
	};
	class StepReqQryTrade
	{
	public:
		static constexpr UShortType FieldID = 0x100C;
		AccountIDType AccountID;		//账户代码
	};
	class StepTrade
	{
	public:
		static constexpr UShortType FieldID = 0x100D;
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		SecurityTypeType SecurityType;		//证券类别
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号
		TradeIDType TradeID;		//成交编号
		DirectionType Direction;		//买卖方向
		OffsetFlagType OffsetFlag;		//开平标志
		PriceType Price;		//委托价格
		VolumeType Volume;		//委托数量
		VolumeMultipleType VolumeMultiple;		//合约乘数
		MoneyType TradeAmount;		//成交金额
		MoneyType Commission;		//手续费
		MoneyType StampTax;		//印花税
		MoneyType TransferFee;		//过户费
		DateType TradeDate;		//成交日期
		TimeType TradeTime;		//成交时间
	};
	class StepReqQryInstrument
	{
	public:
		static constexpr UShortType FieldID = 0x100E;
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
	};
	class StepInstrument
	{
	public:
		static constexpr UShortType FieldID = 0x100F;
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		InstrumentIDType ExchangeInstID;		//交易所合约代码
		InstrumentNameType InstrumentName;		//合约名称
		VolumeMultipleType VolumeMultiple;		//合约乘数
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepReqQryOptionInstrument
	{
	public:
		static constexpr UShortType FieldID = 0x1010;
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
	};
	class StepOptionInstrument
	{
	public:
		static constexpr UShortType FieldID = 0x1011;
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		InstrumentIDType ExchangeInstID;		//交易所合约代码
		InstrumentNameType InstrumentName;		//合约名称
		VolumeMultipleType VolumeMultiple;		//合约乘数
		OptionTypeType OptionType;		//期权类型
		InstrumentIDType UnderlyingInstrumentID;		//标的合约代码
		PriceType ExecutePrice;		//行权价
		MoneyType UnitMargin;		//单位保证金
		PriceType PriceTick;		//最小变动价位
		VolumeType MaxLimitOrderVolume;		//限价最大下单数量
		VolumeType MaxMarketOrderVolume;		//市价最大下单数量
		DateType ExpiringDate;		//到期日
	};
	class StepReqQryCommissionRate
	{
	public:
		static constexpr UShortType FieldID = 0x1012;
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepCommissionRate
	{
	public:
		static constexpr UShortType FieldID = 0x1013;
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
		RateType OpenBuyByMoney;		//买开仓费率
		RateType OpenSellByMoney;		//卖开仓费率
		RateType CloseBuyByMoney;		//买平仓费率
		RateType CloseSellByMoney;		//卖平仓费率
		RateType OpenBuyByVolume;		//每手买开仓费用
		RateType OpenSellByVolume;		//每手卖开仓费用
		RateType CloseBuyByVolume;		//每手买平仓费用
		RateType CloseSellByVolume;		//每手卖平仓费用
		MoneyType MinCommission;		//最低手续费
		MoneyType MaxCommission;		//最高手续费
	};
	class StepReqInsertOrder
	{
	public:
		static constexpr UShortType FieldID = 0x2001;
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		DirectionType Direction;		//买卖方向
		OffsetFlagType OffsetFlag;		//开平标志
		OrderPriceTypeType OrderPriceType;		//委托价格类型
		PriceType Price;		//委托价格
		VolumeType Volume;		//委托数量
		ClientOrderIDType ClientOrderID;		//客户端委托编号
	};
	class StepReqCancelOrder
	{
	public:
		static constexpr UShortType FieldID = 0x2002;
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		ClientOrderIDType ClientCancelOrderID;		//客户端撤单委托编号
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号
		ClientOrderIDType ClientOrderID;		//客户端委托编号
	};
	class StepCancelOrder
	{
	public:
		static constexpr UShortType FieldID = 0x2003;
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		ClientOrderIDType ClientCancelOrderID;		//客户端撤单委托编号
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号
		ClientOrderIDType ClientOrderID;		//客户端委托编号
	};
	class StepReqMdInit
	{
	public:
		static constexpr UShortType FieldID = 0x2101;
		ExchangeIDType ExchangeID;		//交易所代码
		DateType TradingDay;		//交易日
	};
	class StepRspMdInit
	{
	public:
		static constexpr UShortType FieldID = 0x2102;
		ExchangeIDType ExchangeID;		//交易所代码
		DateType TradingDay;		//交易日
	};
	class StepReqSubscribeMd
	{
	public:
		static constexpr UShortType FieldID = 0x2103;
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
	};
	class StepRspSubscribeMd
	{
	public:
		static constexpr UShortType FieldID = 0x2104;
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
	};
	class StepAccountRisk
	{
	public:
		static constexpr UShortType FieldID = 0x3001;
		AccountIDType AccountID;		//账户代码
		RiskIDType RiskID;		//风控代码
		RiskStatusType RiskStatus;		//风控状态
	};
	class StepAccountRiskDelete
	{
	public:
		static constexpr UShortType FieldID = 0x3002;
		AccountIDType AccountID;		//账户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepAccountRiskNotify
	{
	public:
		static constexpr UShortType FieldID = 0x3003;
		DateType NotifyDate;		//通知日期
		TimeType NotifyTime;		//通知时间
		AccountIDType AccountID;		//账户代码
		RiskIDType RiskID;		//风控代码
		RiskRuleIDType RiskRuleID;		//风控规则代码
		RiskStatusType RiskStatus;		//风控状态
		MessageType RiskMessage;		//风控信息
	};
	class StepShortMd
	{
	public:
		static constexpr UShortType FieldID = 0x3101;
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
	};
	class StepRtnExchangeStatus
	{
	public:
		static constexpr UShortType FieldID = 0x3102;
		ExchangeIDType ExchangeID;		//交易所代码
		DateType ExchangeDate;		//交易所日期
		ExchangeStatusType ExchangeStatus;		//交易所状态
	};
	class StepMdInitCompleted
	{
	public:
		static constexpr UShortType FieldID = 0x3103;
		ExchangeIDType ExchangeID;		//交易所代码
		DateType TradingDay;		//交易日
	};
	class StepReqQryRiskGroupAccount
	{
	public:
		static constexpr UShortType FieldID = 0x4001;
		UserIDType UserID;		//用户代码
	};
	class StepReqQryRiskGroupCapital
	{
	public:
		static constexpr UShortType FieldID = 0x4002;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqQryRiskGroupPosition
	{
	public:
		static constexpr UShortType FieldID = 0x4003;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqQryRiskGroupOrder
	{
	public:
		static constexpr UShortType FieldID = 0x4004;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqQryRiskGroupTrade
	{
	public:
		static constexpr UShortType FieldID = 0x4005;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqQryRiskGroupAccountRisk
	{
	public:
		static constexpr UShortType FieldID = 0x4006;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqQryRiskGroupAccountRiskNotify
	{
	public:
		static constexpr UShortType FieldID = 0x4007;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqRiskInsertOrder
	{
	public:
		static constexpr UShortType FieldID = 0x4008;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		DirectionType Direction;		//买卖方向
		OffsetFlagType OffsetFlag;		//开平标志
		OrderPriceTypeType OrderPriceType;		//委托价格类型
		PriceType Price;		//委托价格
		VolumeType Volume;		//委托数量
		ClientOrderIDType ClientOrderID;		//客户端委托编号
		BoolType IsForceClose;		//是否强平单
	};
	class StepReqRiskCancelOrder
	{
	public:
		static constexpr UShortType FieldID = 0x4009;
		UserIDType UserID;		//用户代码
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		ClientOrderIDType ClientCancelOrderID;		//客户端撤单委托编号
		OrderIDType OrderID;		//委托编号
		OrderSysIDType OrderSysID;		//系统委托编号
		ClientOrderIDType ClientOrderID;		//客户端委托编号
	};
	class StepReqAddRiskUser
	{
	public:
		static constexpr UShortType FieldID = 0x5001;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
		UserNameType UserName;		//用户名称
		PasswordType Password;		//密码
		GroupIDType RiskGroupID;		//交易组代码
	};
	class StepRspAddRiskUser
	{
	public:
		static constexpr UShortType FieldID = 0x5002;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepReqUpdateRiskUser
	{
	public:
		static constexpr UShortType FieldID = 0x5003;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
		UserNameType UserName;		//用户名称
		PasswordType Password;		//密码
		GroupIDType RiskGroupID;		//交易组代码
	};
	class StepRspUpdateRiskUser
	{
	public:
		static constexpr UShortType FieldID = 0x5004;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepReqRemoveRiskUser
	{
	public:
		static constexpr UShortType FieldID = 0x5005;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepRspRemoveRiskUser
	{
	public:
		static constexpr UShortType FieldID = 0x5006;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepReqAddAdminUser
	{
	public:
		static constexpr UShortType FieldID = 0x5007;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
		UserNameType UserName;		//用户名称
		PasswordType Password;		//密码
	};
	class StepRspAddAdminUser
	{
	public:
		static constexpr UShortType FieldID = 0x5008;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepReqUpdateAdminUser
	{
	public:
		static constexpr UShortType FieldID = 0x5009;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
		UserNameType UserName;		//用户名称
		PasswordType Password;		//密码
	};
	class StepRspUpdateAdminUser
	{
	public:
		static constexpr UShortType FieldID = 0x500A;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepReqRemoveAdminUser
	{
	public:
		static constexpr UShortType FieldID = 0x500B;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepRspRemoveAdminUser
	{
	public:
		static constexpr UShortType FieldID = 0x500C;
		UserIDType AdminUserID;		//管理用户代码
		UserIDType UserID;		//用户代码
	};
	class StepReqAddPrimaryAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6001;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		AccountNameType PrimaryAccountName;		//主账户名称
		AccountClassType AccountClass;		//账户类别
		PasswordType BrokerPassword;		//经纪公司密码
		OfferIDType OfferID;		//报盘代码
		BoolType IsAllowLogin;		//是否允许登陆
		BoolType IsSimulateAccount;		//是否模拟账号
		AccountStatusType AccountStatus;		//账户状态
		PasswordType Password;		//密码
		GroupIDType RiskGroupID;		//交易组代码
		GroupIDType CommissionGroupID;		//交易组代码
		BoolType IsAutoAudit;		//是否自动审核
	};
	class StepRspAddPrimaryAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6002;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType PrimaryAccountID;		//主账户代码
	};
	class StepReqUpdatePrimaryAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6003;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType PrimaryAccountID;		//主账户代码
		AccountNameType PrimaryAccountName;		//主账户名称
		AccountClassType AccountClass;		//账户类别
		PasswordType BrokerPassword;		//经纪公司密码
		OfferIDType OfferID;		//报盘代码
		BoolType IsAllowLogin;		//是否允许登陆
		BoolType IsSimulateAccount;		//是否模拟账号
		AccountStatusType AccountStatus;		//账户状态
		PasswordType Password;		//密码
		GroupIDType RiskGroupID;		//交易组代码
		GroupIDType CommissionGroupID;		//交易组代码
		BoolType IsAutoAudit;		//是否自动审核
	};
	class StepRspUpdatePrimaryAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6004;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType PrimaryAccountID;		//主账户代码
	};
	class StepReqRemovePrimaryAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6005;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType PrimaryAccountID;		//主账户代码
	};
	class StepRspRemovePrimaryAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6006;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType PrimaryAccountID;		//主账户代码
	};
	class StepReqAddAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6007;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		AccountNameType AccountName;		//账户名称
		AccountStatusType AccountStatus;		//账户状态
		PasswordType Password;		//密码
		GroupIDType TradeGroupID;		//交易组代码
		GroupIDType RiskGroupID;		//交易组代码
		GroupIDType CommissionGroupID;		//交易组代码
		BoolType IsAutoAudit;		//是否自动审核
	};
	class StepRspAddAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6008;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqUpdateAccount
	{
	public:
		static constexpr UShortType FieldID = 0x6009;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		AccountNameType AccountName;		//账户名称
		AccountStatusType AccountStatus;		//账户状态
		PasswordType Password;		//密码
		GroupIDType TradeGroupID;		//交易组代码
		GroupIDType RiskGroupID;		//交易组代码
		GroupIDType CommissionGroupID;		//交易组代码
		BoolType IsAutoAudit;		//是否自动审核
	};
	class StepRspUpdateAccount
	{
	public:
		static constexpr UShortType FieldID = 0x600A;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqRemoveAccount
	{
	public:
		static constexpr UShortType FieldID = 0x600B;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepRspRemoveAccount
	{
	public:
		static constexpr UShortType FieldID = 0x600C;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
	};
	class StepReqAddBaseCommission
	{
	public:
		static constexpr UShortType FieldID = 0x7001;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
		RateType OpenStampTaxByMoney;		//开仓印花税率
		RateType CloseStampTaxByMoney;		//平仓印花税率
		RateType OpenTransferFeeByMoney;		//开仓过户费率
		RateType CloseTransferFeeByMoney;		//平仓过户费率
	};
	class StepRspAddBaseCommission
	{
	public:
		static constexpr UShortType FieldID = 0x7002;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepReqUpdateBaseCommission
	{
	public:
		static constexpr UShortType FieldID = 0x7003;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
		RateType OpenStampTaxByMoney;		//开仓印花税率
		RateType CloseStampTaxByMoney;		//平仓印花税率
		RateType OpenTransferFeeByMoney;		//开仓过户费率
		RateType CloseTransferFeeByMoney;		//平仓过户费率
	};
	class StepRspUpdateBaseCommission
	{
	public:
		static constexpr UShortType FieldID = 0x7004;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepReqRemoveBaseCommission
	{
	public:
		static constexpr UShortType FieldID = 0x7005;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepRspRemoveBaseCommission
	{
	public:
		static constexpr UShortType FieldID = 0x7006;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepReqAddCommissionGroup
	{
	public:
		static constexpr UShortType FieldID = 0x7007;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		GroupIDType CommissionGroupID;		//交易组代码
		GroupNameType CommissionGroupName;		//手续费组名称
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
		RateType OpenBuyByMoney;		//买开仓费率
		RateType OpenSellByMoney;		//卖开仓费率
		RateType CloseBuyByMoney;		//买平仓费率
		RateType CloseSellByMoney;		//卖平仓费率
		RateType OpenBuyByVolume;		//每手买开仓费用
		RateType OpenSellByVolume;		//每手卖开仓费用
		RateType CloseBuyByVolume;		//每手买平仓费用
		RateType CloseSellByVolume;		//每手卖平仓费用
		MoneyType MinCommission;		//最低手续费
		MoneyType MaxCommission;		//最高手续费
	};
	class StepRspAddCommissionGroup
	{
	public:
		static constexpr UShortType FieldID = 0x7008;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		GroupIDType CommissionGroupID;		//交易组代码
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepReqUpdateCommissionGroup
	{
	public:
		static constexpr UShortType FieldID = 0x7009;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		GroupIDType CommissionGroupID;		//交易组代码
		GroupNameType CommissionGroupName;		//手续费组名称
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
		RateType OpenBuyByMoney;		//买开仓费率
		RateType OpenSellByMoney;		//卖开仓费率
		RateType CloseBuyByMoney;		//买平仓费率
		RateType CloseSellByMoney;		//卖平仓费率
		RateType OpenBuyByVolume;		//每手买开仓费用
		RateType OpenSellByVolume;		//每手卖开仓费用
		RateType CloseBuyByVolume;		//每手买平仓费用
		RateType CloseSellByVolume;		//每手卖平仓费用
		MoneyType MinCommission;		//最低手续费
		MoneyType MaxCommission;		//最高手续费
	};
	class StepRspUpdateCommissionGroup
	{
	public:
		static constexpr UShortType FieldID = 0x700A;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		GroupIDType CommissionGroupID;		//交易组代码
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepReqRemoveCommissionGroup
	{
	public:
		static constexpr UShortType FieldID = 0x700B;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		GroupIDType CommissionGroupID;		//交易组代码
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepRspRemoveCommissionGroup
	{
	public:
		static constexpr UShortType FieldID = 0x700C;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		GroupIDType CommissionGroupID;		//交易组代码
		ExchangeIDType ExchangeID;		//交易所代码
		SecurityTypeType SecurityType;		//证券类别
	};
	class StepReqAddOptionMarginParam
	{
	public:
		static constexpr UShortType FieldID = 0x700D;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		RateType Param1;		//参数1
		RateType Param2;		//参数2
	};
	class StepRspAddOptionMarginParam
	{
	public:
		static constexpr UShortType FieldID = 0x700E;
		UserIDType AdminUserID;		//管理用户代码
		ExchangeIDType ExchangeID;		//交易所代码
	};
	class StepReqUpdateOptionMarginParam
	{
	public:
		static constexpr UShortType FieldID = 0x700F;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		ExchangeIDType ExchangeID;		//交易所代码
		RateType Param1;		//参数1
		RateType Param2;		//参数2
	};
	class StepRspUpdateOptionMarginParam
	{
	public:
		static constexpr UShortType FieldID = 0x7010;
		UserIDType AdminUserID;		//管理用户代码
		ExchangeIDType ExchangeID;		//交易所代码
	};
	class StepReqRemoveOptionMarginParam
	{
	public:
		static constexpr UShortType FieldID = 0x7011;
		UserIDType AdminUserID;		//管理用户代码
		ExchangeIDType ExchangeID;		//交易所代码
	};
	class StepRspRemoveOptionMarginParam
	{
	public:
		static constexpr UShortType FieldID = 0x7012;
		UserIDType AdminUserID;		//管理用户代码
		ExchangeIDType ExchangeID;		//交易所代码
	};
	class StepReqAddTradeOffer
	{
	public:
		static constexpr UShortType FieldID = 0x8001;
		UserIDType AdminUserID;		//管理用户代码
		OfferIDType OfferID;		//报盘代码
		OfferNameType OfferName;		//报盘名称
		OfferTypeType OfferType;		//报盘类型
		PasswordType OfferPassword;		//报盘密码
	};
	class StepRspAddTradeOffer
	{
	public:
		static constexpr UShortType FieldID = 0x8002;
		UserIDType AdminUserID;		//管理用户代码
		OfferIDType OfferID;		//报盘代码
	};
	class StepReqUpdateTradeOffer
	{
	public:
		static constexpr UShortType FieldID = 0x8003;
		UserIDType AdminUserID;		//管理用户代码
		OfferIDType OfferID;		//报盘代码
		OfferNameType OfferName;		//报盘名称
		OfferTypeType OfferType;		//报盘类型
		PasswordType OfferPassword;		//报盘密码
	};
	class StepRspUpdateTradeOffer
	{
	public:
		static constexpr UShortType FieldID = 0x8004;
		UserIDType AdminUserID;		//管理用户代码
		OfferIDType OfferID;		//报盘代码
	};
	class StepReqRemoveTradeOffer
	{
	public:
		static constexpr UShortType FieldID = 0x8005;
		UserIDType AdminUserID;		//管理用户代码
		OfferIDType OfferID;		//报盘代码
	};
	class StepRspRemoveTradeOffer
	{
	public:
		static constexpr UShortType FieldID = 0x8006;
		UserIDType AdminUserID;		//管理用户代码
		OfferIDType OfferID;		//报盘代码
	};
	class StepReqAddTradeGroup
	{
	public:
		static constexpr UShortType FieldID = 0x8007;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		GroupNameType TradeGroupName;		//交易组名称
	};
	class StepRspAddTradeGroup
	{
	public:
		static constexpr UShortType FieldID = 0x8008;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
	};
	class StepReqUpdateTradeGroup
	{
	public:
		static constexpr UShortType FieldID = 0x8009;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		GroupNameType TradeGroupName;		//交易组名称
	};
	class StepRspUpdateTradeGroup
	{
	public:
		static constexpr UShortType FieldID = 0x800A;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
	};
	class StepReqRemoveTradeGroup
	{
	public:
		static constexpr UShortType FieldID = 0x800B;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
	};
	class StepRspRemoveTradeGroup
	{
	public:
		static constexpr UShortType FieldID = 0x800C;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
	};
	class StepReqAddTradeGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x800D;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		AccountClassType AccountClass;		//账户类别
		AccountIDType PrimaryAccountID;		//主账户代码
	};
	class StepRspAddTradeGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x800E;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		AccountClassType AccountClass;		//账户类别
	};
	class StepReqUpdateTradeGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x800F;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		AccountClassType AccountClass;		//账户类别
		AccountIDType PrimaryAccountID;		//主账户代码
	};
	class StepRspUpdateTradeGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x8010;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		AccountClassType AccountClass;		//账户类别
	};
	class StepReqRemoveTradeGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x8011;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		AccountClassType AccountClass;		//账户类别
	};
	class StepRspRemoveTradeGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x8012;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType TradeGroupID;		//交易组代码
		AccountClassType AccountClass;		//账户类别
	};
	class StepReqAddRiskGroup
	{
	public:
		static constexpr UShortType FieldID = 0x9001;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		GroupNameType RiskGroupName;		//风控组名称
	};
	class StepRspAddRiskGroup
	{
	public:
		static constexpr UShortType FieldID = 0x9002;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
	};
	class StepReqUpdateRiskGroup
	{
	public:
		static constexpr UShortType FieldID = 0x9003;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		GroupNameType RiskGroupName;		//风控组名称
	};
	class StepRspUpdateRiskGroup
	{
	public:
		static constexpr UShortType FieldID = 0x9004;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
	};
	class StepReqRemoveRiskGroup
	{
	public:
		static constexpr UShortType FieldID = 0x9005;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
	};
	class StepRspRemoveRiskGroup
	{
	public:
		static constexpr UShortType FieldID = 0x9006;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
	};
	class StepReqAddRiskGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x9007;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		RiskIDType RiskID;		//风控代码
	};
	class StepRspAddRiskGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x9008;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqUpdateRiskGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x9009;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		RiskIDType RiskID;		//风控代码
	};
	class StepRspUpdateRiskGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x900A;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqRemoveRiskGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x900B;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		RiskIDType RiskID;		//风控代码
	};
	class StepRspRemoveRiskGroupItem
	{
	public:
		static constexpr UShortType FieldID = 0x900C;
		UserIDType AdminUserID;		//管理用户代码
		GroupIDType RiskGroupID;		//交易组代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqAddOrUpdateRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA001;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
		RiskNameType RiskName;		//风控名称
		RiskClassIDType RiskClassID;		//风控类别代码
	};
	class StepRspAddOrUpdateRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA002;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqRemoveRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA003;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepRspRemoveRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA004;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqAddRiskRule
	{
	public:
		static constexpr UShortType FieldID = 0xA005;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
		RiskRuleIDType RiskRuleID;		//风控规则代码
		RiskRuleStyleType RiskRuleStyle;		//风控类型
		MessageType FormatRiskMessage;		//带格式的风控信息
	};
	class StepRspAddRiskRule
	{
	public:
		static constexpr UShortType FieldID = 0xA006;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
		RiskRuleIDType RiskRuleID;		//风控规则代码
	};
	class StepReqAddRiskRuleItem
	{
	public:
		static constexpr UShortType FieldID = 0xA007;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
		RiskRuleIDType RiskRuleID;		//风控规则代码
		RiskRuleItemIDType RiskRuleItemID;		//风控规则分项编号
		RiskIndexTypeType RiskIndexType;		//风控指标类型
		RiskIndexIDType RiskIndexID;		//风控指标代码
		RiskTextRefType RiskIndexTextRef;		//风控指标文本引用序号
		ParamValueType IndexParam1;		//指标参数1
		ParamValueType IndexParam2;		//指标参数2
		ParamValueType IndexParam3;		//指标参数3
		ParamValueType IndexParam4;		//指标参数4
		ParamValueType IndexParam5;		//指标参数5
		ParamValueType IndexParam6;		//指标参数6
		LogicFuncType LogicFunc;		//逻辑函数
		ParamTypeType LogicParamType1;		//逻辑函数参数类型1
		ParamValueType LogicParam1;		//逻辑函数参数1
		RiskTextRefType LogicParam1TextRef;		//逻辑参数1文本引用序号
		ParamTypeType LogicParamType2;		//逻辑函数参数类型2
		ParamValueType LogicParam2;		//逻辑函数参数2
		RiskTextRefType LogicParam2TextRef;		//逻辑参数2文本引用序号
	};
	class StepRspAddRiskRuleItem
	{
	public:
		static constexpr UShortType FieldID = 0xA008;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
		RiskRuleIDType RiskRuleID;		//风控规则代码
		RiskRuleItemIDType RiskRuleItemID;		//风控规则分项编号
	};
	class StepReqAddRiskTradeScope
	{
	public:
		static constexpr UShortType FieldID = 0xA009;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
		TradeScopeTypeType TradeScopeType;		//交易范围类别
		GroupIDType InstrumentGroupID;		//合约组代码
		MessageType FormatRiskMessage;		//带格式的风控信息
	};
	class StepRspAddRiskTradeScope
	{
	public:
		static constexpr UShortType FieldID = 0xA00A;
		UserIDType AdminUserID;		//管理用户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqAddAccountRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA00B;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepRspAddAccountRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA00C;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqRemoveAccountRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA00D;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepRspRemoveAccountRisk
	{
	public:
		static constexpr UShortType FieldID = 0xA00E;
		UserIDType AdminUserID;		//管理用户代码
		AccountIDType AccountID;		//账户代码
		RiskIDType RiskID;		//风控代码
	};
	class StepReqMoneyTransfer
	{
	public:
		static constexpr UShortType FieldID = 0xB001;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		SequenceNoType MoneyTransferID;		//出入金编号
		AccountTypeType AccountType;		//账户类型
		TransferDirectionType TransferDirection;		//转移方向
		MoneyType TransferAmount;		//转移金额
		MessageType InfoMessage;		//备注信息
		UserIDType UserID;		//用户代码
		DateType TransferDate;		//操作日期
		TimeType TransferTime;		//操作时间
	};
	class StepRspMoneyTransfer
	{
	public:
		static constexpr UShortType FieldID = 0xB002;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		SequenceNoType MoneyTransferID;		//出入金编号
	};
	class StepReqQryMoneyTransfer
	{
	public:
		static constexpr UShortType FieldID = 0xB003;
		AccountIDType AccountID;		//账户代码
	};
	class StepMoneyTransfer
	{
	public:
		static constexpr UShortType FieldID = 0xB004;
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		SequenceNoType MoneyTransferID;		//出入金编号
		AccountTypeType AccountType;		//账户类型
		TransferDirectionType TransferDirection;		//转移方向
		MoneyType TransferAmount;		//转移金额
		MessageType InfoMessage;		//备注信息
		UserIDType UserID;		//用户代码
		DateType TransferDate;		//操作日期
		TimeType TransferTime;		//操作时间
	};
	class StepReqAuditOrder
	{
	public:
		static constexpr UShortType FieldID = 0xB005;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		OrderIDType OrderID;		//委托编号
		AuditStatusType AuditStatus;		//审核状态
	};
	class StepRspAuditOrder
	{
	public:
		static constexpr UShortType FieldID = 0xB006;
		UserIDType AdminUserID;		//管理用户代码
		DateType TradingDay;		//交易日
		AccountIDType AccountID;		//账户代码
		ExchangeIDType ExchangeID;		//交易所代码
		InstrumentIDType InstrumentID;		//合约代码
		OrderIDType OrderID;		//委托编号
		AuditStatusType AuditStatus;		//审核状态
	};
}
