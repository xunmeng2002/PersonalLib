#pragma once
#include <stdint.h>

//布尔类型
typedef bool BoolType;


//短整型类型
typedef unsigned short UShortType;


//客户端委托编号类型
typedef int ClientOrderIDType;

//指令类型
typedef int CommandType;

//错误代码类型
typedef int ErrorIDType;

//前置代码类型
typedef int FrontIDType;

//组代码类型
typedef int GroupIDType;

//整型类型
typedef int IntType;

//最大委托编号类型
typedef int MaxOrderIDType;

//整型类型
typedef int NumberType;

//报盘代码类型
typedef int OfferIDType;

//委托编号类型
typedef int OrderIDType;

//请求代码类型
typedef int RequestIDType;

//风控代码类型
typedef int RiskIDType;

//风控指标代码类型
typedef int RiskIndexIDType;

//风控等级
typedef int RiskLevelType;

//风控规则代码类型
typedef int RiskRuleIDType;

//风控规则子项代码类型
typedef int RiskRuleItemIDType;

//风控文本引用序号
typedef int RiskTextRefType;

//角色代码类型
typedef int RoleIDType;

//时间秒数类型
typedef int SecondType;

//序号类型
typedef int SequenceNoType;

//合约乘数类型
typedef int VolumeMultipleType;


	//64位整型类型
typedef long long Int64Type;

	//会话代码类型
typedef long long SessionIDType;

	//数量类型
typedef long long VolumeType;


//双精度浮点类型
typedef double DoubleType;

//金额类型
typedef double MoneyType;

//价格类型
typedef double PriceType;

//比率
typedef double RateType;

//大额数量
typedef double LargeVolumeType;


//账号类型
typedef char AccountIDType[32];

//账号名称类型
typedef char AccountNameType[64];

//App代码类型
typedef char AppIDType[32];

//App版本类型
typedef char AppVersionType[32];

//授权码类型
typedef char AuthCodeType[64];

//银行卡号类型
typedef char BankCardIDType[32];

//主板时间类型
typedef char BiosTimeType[16];

//经纪公司代码
typedef char BrokerIDType[16];

//经纪公司名称
typedef char BrokerNameType[16];

//经纪公司委托编号类型
typedef char BrokerOrderIDType[32];

//币种类型
typedef char CurrencyIDType[8];

//币种组类型
typedef char CurrencyGroupType[8];

//CPU编号类型
typedef char CpuIDType[32];

//日期类型
typedef char DateType[16];

//数据库名称类型
typedef char DBNameType[32];

//磁盘序号类型
typedef char DiskIDType[64];

//磁盘路径类型
typedef char DiskPathType[32];

//交易所代码类型
typedef char ExchangeIDType[8];

//交易所名称类型
typedef char ExchangeNameType[64];

//交易所成交编号类型
typedef char ExchangeTradeIDType[32];

//组名称类型
typedef char GroupNameType[64];

//主机名类型
typedef char HostNameType[32];

//合约代码类型
typedef char InstrumentIDType[32];

//合约名称类型
typedef char InstrumentNameType[64];

//IP地址类型
typedef char IPAddressType[32];

//Mac地址类型
typedef char MacAddressType[32];

//错误信息类型
typedef char MessageType[256];

//名称类型
typedef char NameType[64];

//报盘名称类型
typedef char OfferNameType[32];

//机构代码类型
typedef char OrgIDType[16];

//系统委托编号类型
typedef char OrderSysIDType[64];

//密码类型
typedef char PasswordType[64];

//参数值类型
typedef char ParamValueType[256];

//手机号码类型
typedef char PhoneNumberType[32];

//品种代码类型
typedef char ProductIDType[32];

//用户产品信息类型
typedef char ProductInfoType[32];

//品种名称类型
typedef char ProductNameType[32];

//协议地址类型
typedef char ProtocolAddressType[32];

//预留字段类型
typedef char ReserveType[32];

//风控名称
typedef char RiskNameType[256];

//角色名称类型
typedef char RoleNameType[32];

//席位号
typedef char SeatNoType[24];

//交易节名称
typedef char SessionNameType[32];

//Tick买卖标志
typedef char TickBSFlagType[8];

//时间类型
typedef char TimeType[16];

//成交编号类型
typedef char TradeIDType[64];

//用户代码类型
typedef char UserIDType[32];

//用户名称类型
typedef char UserNameType[64];


//账户类别
enum class AccountClassType : int
{
	//期货
	Future = 0,
	//股票
	Stock = 1,
	//期权
	Option = 2,
};
inline const char* GetAccountClassString(AccountClassType value)
{
	switch (value)
	{
		case AccountClassType::Future:
			return "Future";
		case AccountClassType::Stock:
			return "Stock";
		case AccountClassType::Option:
			return "Option";
		default:
			return "Unknown";
	}
	return "";
}

//账户结算状态
enum class AccountSettlementStatusType : int
{
	//未开始
	NotStart = 0,
	//结算失败
	SettlementFailed = 1,
	//结算完成
	SettlementCompleted = 2,
};
inline const char* GetAccountSettlementStatusString(AccountSettlementStatusType value)
{
	switch (value)
	{
		case AccountSettlementStatusType::NotStart:
			return "NotStart";
		case AccountSettlementStatusType::SettlementFailed:
			return "SettlementFailed";
		case AccountSettlementStatusType::SettlementCompleted:
			return "SettlementCompleted";
		default:
			return "Unknown";
	}
	return "";
}

//账户类型
enum class AccountTypeType : int
{
	//主账户
	Primary = 0,
	//子账户
	Sub = 1,
};
inline const char* GetAccountTypeString(AccountTypeType value)
{
	switch (value)
	{
		case AccountTypeType::Primary:
			return "Primary";
		case AccountTypeType::Sub:
			return "Sub";
		default:
			return "Unknown";
	}
	return "";
}

//账户状态
enum class AccountStatusType : int
{
	//启用
	Normal = 0,
	//禁用
	Forbidden = 1,
};
inline const char* GetAccountStatusString(AccountStatusType value)
{
	switch (value)
	{
		case AccountStatusType::Normal:
			return "Normal";
		case AccountStatusType::Forbidden:
			return "Forbidden";
		default:
			return "Unknown";
	}
	return "";
}

//应用平台类型
enum class AppPlatformType : int
{
	Windows = 0,
	Linux = 1,
	IOS = 2,
	Android = 3,
};
inline const char* GetAppPlatformString(AppPlatformType value)
{
	switch (value)
	{
		case AppPlatformType::Windows:
			return "Windows";
		case AppPlatformType::Linux:
			return "Linux";
		case AppPlatformType::IOS:
			return "IOS";
		case AppPlatformType::Android:
			return "Android";
		default:
			return "Unknown";
	}
	return "";
}

//审核状态
enum class AuditStatusType : int
{
	//通过
	Approve = 0,
	//驳回
	Reject = 1,
};
inline const char* GetAuditStatusString(AuditStatusType value)
{
	switch (value)
	{
		case AuditStatusType::Approve:
			return "Approve";
		case AuditStatusType::Reject:
			return "Reject";
		default:
			return "Unknown";
	}
	return "";
}

//Bar精度
enum class BarPrecesType : int
{
	//秒
	Second = 0,
	//分
	Minute = 1,
	//日
	Day = 2,
};
inline const char* GetBarPrecesString(BarPrecesType value)
{
	switch (value)
	{
		case BarPrecesType::Second:
			return "Second";
		case BarPrecesType::Minute:
			return "Minute";
		case BarPrecesType::Day:
			return "Day";
		default:
			return "Unknown";
	}
	return "";
}

//组件类型
enum class ComponentType : int
{
	//交易前置
	TradeFront = 0,
	//风控前置
	RiskFront = 1,
	//管理前置
	AdminFront = 2,
	//报盘前置
	OfferFront = 3,
	//行情
	MarketData = 4,
};
inline const char* GetComponentString(ComponentType value)
{
	switch (value)
	{
		case ComponentType::TradeFront:
			return "TradeFront";
		case ComponentType::RiskFront:
			return "RiskFront";
		case ComponentType::AdminFront:
			return "AdminFront";
		case ComponentType::OfferFront:
			return "OfferFront";
		case ComponentType::MarketData:
			return "MarketData";
		default:
			return "Unknown";
	}
	return "";
}

//触发条件类型
enum class ContingentConditionType : int
{
	//立即
	Immediately = 0,
	//止损
	Touch = 1,
	//止赢
	TouchProfit = 2,
	//预埋单
	ParkedOrder = 3,
};
inline const char* GetContingentConditionString(ContingentConditionType value)
{
	switch (value)
	{
		case ContingentConditionType::Immediately:
			return "Immediately";
		case ContingentConditionType::Touch:
			return "Touch";
		case ContingentConditionType::TouchProfit:
			return "TouchProfit";
		case ContingentConditionType::ParkedOrder:
			return "ParkedOrder";
		default:
			return "Unknown";
	}
	return "";
}

//连接状态
enum class ConnectStatusType : int
{
	//未连接
	UnConnected = 0,
	//正在链接
	Connecting = 1,
	//已接受
	Accepted = 2,
	//已拒绝
	Rejected = 3,
	//已连接
	Connected = 4,
	//已断开连接
	DisConnected = 5,
};
inline const char* GetConnectStatusString(ConnectStatusType value)
{
	switch (value)
	{
		case ConnectStatusType::UnConnected:
			return "UnConnected";
		case ConnectStatusType::Connecting:
			return "Connecting";
		case ConnectStatusType::Accepted:
			return "Accepted";
		case ConnectStatusType::Rejected:
			return "Rejected";
		case ConnectStatusType::Connected:
			return "Connected";
		case ConnectStatusType::DisConnected:
			return "DisConnected";
		default:
			return "Unknown";
	}
	return "";
}

//数据库操作
enum class DBOperateType : int
{
	//创建所有表
	CreateTables = 0,
	//删除所有表
	DropTables = 1,
	//清空所有表
	TruncateTables = 2,
	//插入
	Insert = 3,
	//删除
	Delete = 4,
	//按索引删除
	DeleteByIndex = 5,
	//更新
	Update = 6,
	//批量插入
	BatchInsert = 7,
	//清空
	Truncate = 8,
};
inline const char* GetDBOperateString(DBOperateType value)
{
	switch (value)
	{
		case DBOperateType::CreateTables:
			return "CreateTables";
		case DBOperateType::DropTables:
			return "DropTables";
		case DBOperateType::TruncateTables:
			return "TruncateTables";
		case DBOperateType::Insert:
			return "Insert";
		case DBOperateType::Delete:
			return "Delete";
		case DBOperateType::DeleteByIndex:
			return "DeleteByIndex";
		case DBOperateType::Update:
			return "Update";
		case DBOperateType::BatchInsert:
			return "BatchInsert";
		case DBOperateType::Truncate:
			return "Truncate";
		default:
			return "Unknown";
	}
	return "";
}

//数据库类型
enum class DBTypeType : int
{
	//duckdb
	DuckDB = 0,
	//sqlite
	SqliteDB = 1,
	//mysql
	MysqlDB = 2,
	//maria
	MariaDB = 3,
};
inline const char* GetDBTypeString(DBTypeType value)
{
	switch (value)
	{
		case DBTypeType::DuckDB:
			return "DuckDB";
		case DBTypeType::SqliteDB:
			return "SqliteDB";
		case DBTypeType::MysqlDB:
			return "MysqlDB";
		case DBTypeType::MariaDB:
			return "MariaDB";
		default:
			return "Unknown";
	}
	return "";
}

//交割方式
enum class DeliveryMethodType : int
{
	//现金交割
	Cash = 0,
	//实物交割
	Commodity = 1,
};
inline const char* GetDeliveryMethodString(DeliveryMethodType value)
{
	switch (value)
	{
		case DeliveryMethodType::Cash:
			return "Cash";
		case DeliveryMethodType::Commodity:
			return "Commodity";
		default:
			return "Unknown";
	}
	return "";
}

//买卖方向
enum class DirectionType : int
{
	//买
	Buy = 0,
	//卖
	Sell = 1,
};
inline const char* GetDirectionString(DirectionType value)
{
	switch (value)
	{
		case DirectionType::Buy:
			return "Buy";
		case DirectionType::Sell:
			return "Sell";
		default:
			return "Unknown";
	}
	return "";
}

//交易所状态
enum class ExchangeStatusType : int
{
	//开盘前
	BeforeTrading = 0,
	//非交易
	NoTrading = 1,
	//连续交易
	Continous = 2,
	//集合竞价报单
	AuctionOrdering = 3,
	//集合竞价平衡
	AuctionBalance = 4,
	//集合竞价撮合
	AuctionMatch = 5,
	//收盘
	Closed = 6,
	//初始化
	Initializing = 7,
};
inline const char* GetExchangeStatusString(ExchangeStatusType value)
{
	switch (value)
	{
		case ExchangeStatusType::BeforeTrading:
			return "BeforeTrading";
		case ExchangeStatusType::NoTrading:
			return "NoTrading";
		case ExchangeStatusType::Continous:
			return "Continous";
		case ExchangeStatusType::AuctionOrdering:
			return "AuctionOrdering";
		case ExchangeStatusType::AuctionBalance:
			return "AuctionBalance";
		case ExchangeStatusType::AuctionMatch:
			return "AuctionMatch";
		case ExchangeStatusType::Closed:
			return "Closed";
		case ExchangeStatusType::Initializing:
			return "Initializing";
		default:
			return "Unknown";
	}
	return "";
}

//强平原因
enum class ForceCloseReasonType : int
{
	//非强平
	NotForceClose = 0,
	//资金不足
	LackDeposit = 1,
	//客户超仓
	ClientOverPositionLimit = 2,
	//会员超仓
	MemberOverPositionLimit = 3,
	//持仓非整数倍
	NotMultiple = 4,
	//违规
	Violation = 5,
	//其它
	Other = 6,
	//自然人临近交割
	PersonDeliv = 7,
};
inline const char* GetForceCloseReasonString(ForceCloseReasonType value)
{
	switch (value)
	{
		case ForceCloseReasonType::NotForceClose:
			return "NotForceClose";
		case ForceCloseReasonType::LackDeposit:
			return "LackDeposit";
		case ForceCloseReasonType::ClientOverPositionLimit:
			return "ClientOverPositionLimit";
		case ForceCloseReasonType::MemberOverPositionLimit:
			return "MemberOverPositionLimit";
		case ForceCloseReasonType::NotMultiple:
			return "NotMultiple";
		case ForceCloseReasonType::Violation:
			return "Violation";
		case ForceCloseReasonType::Other:
			return "Other";
		case ForceCloseReasonType::PersonDeliv:
			return "PersonDeliv";
		default:
			return "Unknown";
	}
	return "";
}

//投保标志
enum class HedgeFlagType : int
{
	//投机
	Speculation = 0,
	//套利
	Arbitrage = 1,
	//保值
	Hedge = 2,
};
inline const char* GetHedgeFlagString(HedgeFlagType value)
{
	switch (value)
	{
		case HedgeFlagType::Speculation:
			return "Speculation";
		case HedgeFlagType::Arbitrage:
			return "Arbitrage";
		case HedgeFlagType::Hedge:
			return "Hedge";
		default:
			return "Unknown";
	}
	return "";
}

//行情初始化状态
enum class InitStatusType : int
{
	//未初始化
	UnInitialized = 0,
	//正在初始化
	Initializing = 1,
	//已初始化
	Initialized = 2,
};
inline const char* GetInitStatusString(InitStatusType value)
{
	switch (value)
	{
		case InitStatusType::UnInitialized:
			return "UnInitialized";
		case InitStatusType::Initializing:
			return "Initializing";
		case InitStatusType::Initialized:
			return "Initialized";
		default:
			return "Unknown";
	}
	return "";
}

//合约类别
enum class InstrumentClassType : int
{
	//普通合约
	Normal = 0,
	//主力合约
	Main = 1,
};
inline const char* GetInstrumentClassString(InstrumentClassType value)
{
	switch (value)
	{
		case InstrumentClassType::Normal:
			return "Normal";
		case InstrumentClassType::Main:
			return "Main";
		default:
			return "Unknown";
	}
	return "";
}

//IO模型
enum class IOModelType : int
{
	//Select
	Select = 0,
	//Epoll
	Epoll = 1,
	//Iocp
	Iocp = 2,
};
inline const char* GetIOModelString(IOModelType value)
{
	switch (value)
	{
		case IOModelType::Select:
			return "Select";
		case IOModelType::Epoll:
			return "Epoll";
		case IOModelType::Iocp:
			return "Iocp";
		default:
			return "Unknown";
	}
	return "";
}

//IO类型
enum class IOTypeType : int
{
	//Tcp
	Tcp = 0,
	//Udp
	Udp = 1,
	//共享内存
	Shm = 2,
};
inline const char* GetIOTypeString(IOTypeType value)
{
	switch (value)
	{
		case IOTypeType::Tcp:
			return "Tcp";
		case IOTypeType::Udp:
			return "Udp";
		case IOTypeType::Shm:
			return "Shm";
		default:
			return "Unknown";
	}
	return "";
}

//逻辑运算函数
enum class LogicFuncType : int
{
	//等于
	Equal = 0,
	//不等于
	NotEqual = 1,
	//小于
	LessThan = 2,
	//小于等于
	LessEqual = 3,
	//大于
	GreatThan = 4,
	//大于等于
	GreatEqual = 5,
	//在区间范围内
	In = 6,
	//在区间范围内包含等于
	EqualIn = 7,
	//在区间范围外
	Out = 8,
	//在区间范围外包含等于
	EqualOut = 9,
	//在百分比范围内
	PctIn = 10,
	//在百分比范围内包含等于
	PctEqualIn = 11,
	//在百分比范围外
	PctOut = 12,
	//在百分比范围外包含等于
	PctEqualOut = 13,
};
inline const char* GetLogicFuncString(LogicFuncType value)
{
	switch (value)
	{
		case LogicFuncType::Equal:
			return "Equal";
		case LogicFuncType::NotEqual:
			return "NotEqual";
		case LogicFuncType::LessThan:
			return "LessThan";
		case LogicFuncType::LessEqual:
			return "LessEqual";
		case LogicFuncType::GreatThan:
			return "GreatThan";
		case LogicFuncType::GreatEqual:
			return "GreatEqual";
		case LogicFuncType::In:
			return "In";
		case LogicFuncType::EqualIn:
			return "EqualIn";
		case LogicFuncType::Out:
			return "Out";
		case LogicFuncType::EqualOut:
			return "EqualOut";
		case LogicFuncType::PctIn:
			return "PctIn";
		case LogicFuncType::PctEqualIn:
			return "PctEqualIn";
		case LogicFuncType::PctOut:
			return "PctOut";
		case LogicFuncType::PctEqualOut:
			return "PctEqualOut";
		default:
			return "Unknown";
	}
	return "";
}

//登录状态
enum class LoginStatusType : int
{
	//未登录
	NotLog = 0,
	//登录中
	Logging = 1,
	//已登录
	Logged = 2,
};
inline const char* GetLoginStatusString(LoginStatusType value)
{
	switch (value)
	{
		case LoginStatusType::NotLog:
			return "NotLog";
		case LoginStatusType::Logging:
			return "Logging";
		case LoginStatusType::Logged:
			return "Logged";
		default:
			return "Unknown";
	}
	return "";
}

//保证金价格类型
enum class MarginPriceTypeType : int
{
	//昨结算价
	PreSettlementPrice = 0,
	//最新价
	SettlementPrice = 1,
	//成交均价
	AveragePrice = 2,
	//开仓价
	OpenPrice = 3,
};
inline const char* GetMarginPriceTypeString(MarginPriceTypeType value)
{
	switch (value)
	{
		case MarginPriceTypeType::PreSettlementPrice:
			return "PreSettlementPrice";
		case MarginPriceTypeType::SettlementPrice:
			return "SettlementPrice";
		case MarginPriceTypeType::AveragePrice:
			return "AveragePrice";
		case MarginPriceTypeType::OpenPrice:
			return "OpenPrice";
		default:
			return "Unknown";
	}
	return "";
}

//保证金类型
enum class MarginTypeType : int
{
	//比例
	Rate = 0,
	//固定金额
	Fixed = 1,
};
inline const char* GetMarginTypeString(MarginTypeType value)
{
	switch (value)
	{
		case MarginTypeType::Rate:
			return "Rate";
		case MarginTypeType::Fixed:
			return "Fixed";
		default:
			return "Unknown";
	}
	return "";
}

//行情数据类型
enum class MarketDataTypeType : int
{
	//快照行情
	Tick = 0,
	//Bar行情
	Bar = 1,
};
inline const char* GetMarketDataTypeString(MarketDataTypeType value)
{
	switch (value)
	{
		case MarketDataTypeType::Tick:
			return "Tick";
		case MarketDataTypeType::Bar:
			return "Bar";
		default:
			return "Unknown";
	}
	return "";
}

//撮合模式
enum class MatchModeType : int
{
	//订单簿
	OrderBook = 0,
	//最新价
	LastPrice = 1,
	//对手价
	OppositePrice = 2,
	//Bar撮合
	Bar = 3,
};
inline const char* GetMatchModeString(MatchModeType value)
{
	switch (value)
	{
		case MatchModeType::OrderBook:
			return "OrderBook";
		case MatchModeType::LastPrice:
			return "LastPrice";
		case MatchModeType::OppositePrice:
			return "OppositePrice";
		case MatchModeType::Bar:
			return "Bar";
		default:
			return "Unknown";
	}
	return "";
}

//持仓方向
enum class PosiDirectionType : int
{
	//多头
	Long = 0,
	//空头
	Short = 1,
	//净持仓
	Net = 2,
};
inline const char* GetPosiDirectionString(PosiDirectionType value)
{
	switch (value)
	{
		case PosiDirectionType::Long:
			return "Long";
		case PosiDirectionType::Short:
			return "Short";
		case PosiDirectionType::Net:
			return "Net";
		default:
			return "Unknown";
	}
	return "";
}

//报盘类型
enum class OfferTypeType : int
{
	//模拟
	SE = 0,
	//汇点标准中间件
	Stds = 1,
};
inline const char* GetOfferTypeString(OfferTypeType value)
{
	switch (value)
	{
		case OfferTypeType::SE:
			return "SE";
		case OfferTypeType::Stds:
			return "Stds";
		default:
			return "Unknown";
	}
	return "";
}

//开平标志
enum class OffsetFlagType : int
{
	//开仓
	Open = 0,
	//平仓
	Close = 1,
	//平今
	CloseToday = 2,
};
inline const char* GetOffsetFlagString(OffsetFlagType value)
{
	switch (value)
	{
		case OffsetFlagType::Open:
			return "Open";
		case OffsetFlagType::Close:
			return "Close";
		case OffsetFlagType::CloseToday:
			return "CloseToday";
		default:
			return "Unknown";
	}
	return "";
}

//期权指标类型
enum class OptionIndicatorTypeType : int
{
	//Delta
	Delta = 0,
	//Gamma
	Gamma = 1,
	//Rho
	Rho = 2,
	//Theta
	Theta = 3,
	//Vega
	Vega = 4,
};
inline const char* GetOptionIndicatorTypeString(OptionIndicatorTypeType value)
{
	switch (value)
	{
		case OptionIndicatorTypeType::Delta:
			return "Delta";
		case OptionIndicatorTypeType::Gamma:
			return "Gamma";
		case OptionIndicatorTypeType::Rho:
			return "Rho";
		case OptionIndicatorTypeType::Theta:
			return "Theta";
		case OptionIndicatorTypeType::Vega:
			return "Vega";
		default:
			return "Unknown";
	}
	return "";
}

//期权委托价格类型
enum class OptionOrderPriceTypeType : int
{
	//限价
	LimitPrice = 0,
	//市价剩余转限价
	FAL = 1,
	//市价剩余撤销
	FAK = 2,
	//限价FOK，全部成交否则撤销
	FOKXJ = 3,
	//市价FOK，全部成交否则撤销
	FOK = 4,
	//对方最优价
	DBestPrice = 5,
	//本方最优价
	WBestPrice = 6,
	//即时成交剩余撤销
	FAKSZ = 7,
	//最优五档即时成交剩余撤销
	FAK5SZ = 8,
	//全额成交否则撤销-深圳
	FOKSZ = 9,
};
inline const char* GetOptionOrderPriceTypeString(OptionOrderPriceTypeType value)
{
	switch (value)
	{
		case OptionOrderPriceTypeType::LimitPrice:
			return "LimitPrice";
		case OptionOrderPriceTypeType::FAL:
			return "FAL";
		case OptionOrderPriceTypeType::FAK:
			return "FAK";
		case OptionOrderPriceTypeType::FOKXJ:
			return "FOKXJ";
		case OptionOrderPriceTypeType::FOK:
			return "FOK";
		case OptionOrderPriceTypeType::DBestPrice:
			return "DBestPrice";
		case OptionOrderPriceTypeType::WBestPrice:
			return "WBestPrice";
		case OptionOrderPriceTypeType::FAKSZ:
			return "FAKSZ";
		case OptionOrderPriceTypeType::FAK5SZ:
			return "FAK5SZ";
		case OptionOrderPriceTypeType::FOKSZ:
			return "FOKSZ";
		default:
			return "Unknown";
	}
	return "";
}

//期权类型
enum class OptionTypeType : int
{
	//认购期权
	Call = 0,
	//认沽期权
	Put = 1,
};
inline const char* GetOptionTypeString(OptionTypeType value)
{
	switch (value)
	{
		case OptionTypeType::Call:
			return "Call";
		case OptionTypeType::Put:
			return "Put";
		default:
			return "Unknown";
	}
	return "";
}

//委托价格类型
enum class OrderPriceTypeType : int
{
	//限价
	LimitPrice = 0,
	//市价 暂废
	AnyPrice = 1,
	//最优五档即时成交剩余撤销
	StockFAK5 = 2,
	//最优五档即时成交剩余转限价
	StockFAL5 = 3,
	//即时成交剩余撤销
	StockFAK = 4,
	//全额成交或撤销
	StockFOK = 5,
	//对方最优价
	StockDBestPrice = 6,
	//本方最优价
	StockWBestPrice = 7,
	//市价剩余转限价
	OptFAL = 8,
	//市价剩余撤销
	OptFAK = 9,
	//限价FOK，全部成交否则撤销
	OptFOKXJ = 10,
	//市价FOK，全部成交否则撤销
	OptFOK = 11,
	//对方最优价
	OptDBestPrice = 12,
	//本方最优价
	OptWBestPrice = 13,
	//即时成交剩余撤销
	OptFAKSZ = 14,
	//最优五档即时成交剩余撤销
	OptFAK5SZ = 15,
	//全额成交否则撤销-深圳
	OptFOKSZ = 16,
};
inline const char* GetOrderPriceTypeString(OrderPriceTypeType value)
{
	switch (value)
	{
		case OrderPriceTypeType::LimitPrice:
			return "LimitPrice";
		case OrderPriceTypeType::AnyPrice:
			return "AnyPrice";
		case OrderPriceTypeType::StockFAK5:
			return "StockFAK5";
		case OrderPriceTypeType::StockFAL5:
			return "StockFAL5";
		case OrderPriceTypeType::StockFAK:
			return "StockFAK";
		case OrderPriceTypeType::StockFOK:
			return "StockFOK";
		case OrderPriceTypeType::StockDBestPrice:
			return "StockDBestPrice";
		case OrderPriceTypeType::StockWBestPrice:
			return "StockWBestPrice";
		case OrderPriceTypeType::OptFAL:
			return "OptFAL";
		case OrderPriceTypeType::OptFAK:
			return "OptFAK";
		case OrderPriceTypeType::OptFOKXJ:
			return "OptFOKXJ";
		case OrderPriceTypeType::OptFOK:
			return "OptFOK";
		case OrderPriceTypeType::OptDBestPrice:
			return "OptDBestPrice";
		case OrderPriceTypeType::OptWBestPrice:
			return "OptWBestPrice";
		case OrderPriceTypeType::OptFAKSZ:
			return "OptFAKSZ";
		case OrderPriceTypeType::OptFAK5SZ:
			return "OptFAK5SZ";
		case OrderPriceTypeType::OptFOKSZ:
			return "OptFOKSZ";
		default:
			return "Unknown";
	}
	return "";
}

//委托状态
enum class OrderStatusType : int
{
	//正在申报
	Inserting = 0,
	//已报
	Inserted = 1,
	//部成
	PartTraded = 2,
	//已成
	AllTraded = 3,
	//已撤
	Canceled = 4,
	//部成部撤
	PartTradedCanceled = 5,
	//审核中
	Auditing = 6,
	//审核驳回
	AuditReject = 7,
	//风控检查中
	RiskChecking = 8,
	//风控检查失败
	RiskCheckFailed = 9,
	//废单
	Error = 10,
	//未触发
	NotTouched = 11,
	//已触发
	Touched = 12,
	//未知
	Unknown = 13,
};
inline const char* GetOrderStatusString(OrderStatusType value)
{
	switch (value)
	{
		case OrderStatusType::Inserting:
			return "Inserting";
		case OrderStatusType::Inserted:
			return "Inserted";
		case OrderStatusType::PartTraded:
			return "PartTraded";
		case OrderStatusType::AllTraded:
			return "AllTraded";
		case OrderStatusType::Canceled:
			return "Canceled";
		case OrderStatusType::PartTradedCanceled:
			return "PartTradedCanceled";
		case OrderStatusType::Auditing:
			return "Auditing";
		case OrderStatusType::AuditReject:
			return "AuditReject";
		case OrderStatusType::RiskChecking:
			return "RiskChecking";
		case OrderStatusType::RiskCheckFailed:
			return "RiskCheckFailed";
		case OrderStatusType::Error:
			return "Error";
		case OrderStatusType::NotTouched:
			return "NotTouched";
		case OrderStatusType::Touched:
			return "Touched";
		case OrderStatusType::Unknown:
			return "Unknown";
		default:
			return "Unknown";
	}
	return "";
}

//委托类型
enum class OrderTypeType : int
{
	//普通单
	Normal = 0,
	//互换单
	Swap = 1,
	//组合委托
	Combination = 2,
};
inline const char* GetOrderTypeString(OrderTypeType value)
{
	switch (value)
	{
		case OrderTypeType::Normal:
			return "Normal";
		case OrderTypeType::Swap:
			return "Swap";
		case OrderTypeType::Combination:
			return "Combination";
		default:
			return "Unknown";
	}
	return "";
}

//参数类型
enum class ParamTypeType : int
{
	//常量
	Const = 0,
	//指标
	Index = 1,
};
inline const char* GetParamTypeString(ParamTypeType value)
{
	switch (value)
	{
		case ParamTypeType::Const:
			return "Const";
		case ParamTypeType::Index:
			return "Index";
		default:
			return "Unknown";
	}
	return "";
}

//产品类型
enum class ProductClassType : int
{
	//期货
	Future = 0,
	//期货期权
	FutureOption = 1,
	//组合
	Combination = 2,
	//即期
	Spot = 3,
	//期转现
	EFP = 4,
	//指数
	Index = 5,
	//股票
	Stock = 6,
	//股票期权
	StockOption = 7,
	//ETF
	ETF = 8,
};
inline const char* GetProductClassString(ProductClassType value)
{
	switch (value)
	{
		case ProductClassType::Future:
			return "Future";
		case ProductClassType::FutureOption:
			return "FutureOption";
		case ProductClassType::Combination:
			return "Combination";
		case ProductClassType::Spot:
			return "Spot";
		case ProductClassType::EFP:
			return "EFP";
		case ProductClassType::Index:
			return "Index";
		case ProductClassType::Stock:
			return "Stock";
		case ProductClassType::StockOption:
			return "StockOption";
		case ProductClassType::ETF:
			return "ETF";
		default:
			return "Unknown";
	}
	return "";
}

//协议类型
enum class ProtocolTypeType : int
{
	//Xtp协议
	Xtp = 0,
	//Step协议
	Step = 1,
};
inline const char* GetProtocolTypeString(ProtocolTypeType value)
{
	switch (value)
	{
		case ProtocolTypeType::Xtp:
			return "Xtp";
		case ProtocolTypeType::Step:
			return "Step";
		default:
			return "Unknown";
	}
	return "";
}

//查询状态
enum class QueryStatusType : int
{
	//未查询
	UnQueried = 0,
	//正在查询
	Quering = 1,
	//已查询
	Queried = 2,
};
inline const char* GetQueryStatusString(QueryStatusType value)
{
	switch (value)
	{
		case QueryStatusType::UnQueried:
			return "UnQueried";
		case QueryStatusType::Quering:
			return "Quering";
		case QueryStatusType::Queried:
			return "Queried";
		default:
			return "Unknown";
	}
	return "";
}

//风控动作
enum class RiskActionType : int
{
	//警告
	Warn = 0,
	//禁止开仓
	ForbiddenOpen = 1,
	//禁止买入开仓
	ForbiddenBuyOpen = 2,
	//禁止卖出开仓
	ForbiddenSellOpen = 3,
};
inline const char* GetRiskActionString(RiskActionType value)
{
	switch (value)
	{
		case RiskActionType::Warn:
			return "Warn";
		case RiskActionType::ForbiddenOpen:
			return "ForbiddenOpen";
		case RiskActionType::ForbiddenBuyOpen:
			return "ForbiddenBuyOpen";
		case RiskActionType::ForbiddenSellOpen:
			return "ForbiddenSellOpen";
		default:
			return "Unknown";
	}
	return "";
}

//风控类别代码
enum class RiskClassIDType : int
{
	//交易范围控制
	TradeScope = 0,
	//量价控制
	VolumePrice = 1,
	//仓位控制
	Position = 2,
	//净值线
	NetValueLine = 3,
	//集中度控制
	Concentration = 4,
	//盈亏控制
	Profit = 5,
	//回撤控制
	Retracement = 6,
	//风险度控制
	RiskLevel = 7,
	//期权指标控制
	OptionIndicator = 8,
};
inline const char* GetRiskClassIDString(RiskClassIDType value)
{
	switch (value)
	{
		case RiskClassIDType::TradeScope:
			return "TradeScope";
		case RiskClassIDType::VolumePrice:
			return "VolumePrice";
		case RiskClassIDType::Position:
			return "Position";
		case RiskClassIDType::NetValueLine:
			return "NetValueLine";
		case RiskClassIDType::Concentration:
			return "Concentration";
		case RiskClassIDType::Profit:
			return "Profit";
		case RiskClassIDType::Retracement:
			return "Retracement";
		case RiskClassIDType::RiskLevel:
			return "RiskLevel";
		case RiskClassIDType::OptionIndicator:
			return "OptionIndicator";
		default:
			return "Unknown";
	}
	return "";
}

//风控指标类型
enum class RiskIndexTypeType : int
{
	//整型
	Int = 0,
	//浮点型
	Double = 1,
	//字符串
	String = 2,
};
inline const char* GetRiskIndexTypeString(RiskIndexTypeType value)
{
	switch (value)
	{
		case RiskIndexTypeType::Int:
			return "Int";
		case RiskIndexTypeType::Double:
			return "Double";
		case RiskIndexTypeType::String:
			return "String";
		default:
			return "Unknown";
	}
	return "";
}

//风险度类型
enum class RiskLevelTypeType : int
{
	//保证金
	Margin = 0,
	//市值
	MarketValue = 1,
};
inline const char* GetRiskLevelTypeString(RiskLevelTypeType value)
{
	switch (value)
	{
		case RiskLevelTypeType::Margin:
			return "Margin";
		case RiskLevelTypeType::MarketValue:
			return "MarketValue";
		default:
			return "Unknown";
	}
	return "";
}

//风控类型
enum class RiskRuleStyleType : int
{
	//事后风控
	Afterward = 0,
	//事前风控
	Beforehand = 1,
};
inline const char* GetRiskRuleStyleString(RiskRuleStyleType value)
{
	switch (value)
	{
		case RiskRuleStyleType::Afterward:
			return "Afterward";
		case RiskRuleStyleType::Beforehand:
			return "Beforehand";
		default:
			return "Unknown";
	}
	return "";
}

//风控状态
enum class RiskStatusType : int
{
	//正常
	Normal = 0,
	//已触发
	Triggered = 1,
};
inline const char* GetRiskStatusString(RiskStatusType value)
{
	switch (value)
	{
		case RiskStatusType::Normal:
			return "Normal";
		case RiskStatusType::Triggered:
			return "Triggered";
		default:
			return "Unknown";
	}
	return "";
}

//证券细分类别
enum class SecurityDetailTypeType : int
{
	//指数
	Index = 0,
	//主板
	MainBoard = 1,
	//科创板
	Star = 2,
	//中小板
	SMEBoard = 3,
	//创业板
	SecondBoard = 4,
	//B股
	BShares = 5,
	//ETF
	ETF = 6,
	//配股
	AllotmentCode = 7,
	//债券
	Bond = 8,
	//可转债
	ConvertibleBond = 9,
	//逆回购
	ReverseRepo = 10,
	//期权
	Option = 11,
	//其他
	Other = 12,
	//优先股
	PreferredStock = 13,
	//期货
	Future = 14,
	//期货期权
	FutureOption = 15,
};
inline const char* GetSecurityDetailTypeString(SecurityDetailTypeType value)
{
	switch (value)
	{
		case SecurityDetailTypeType::Index:
			return "Index";
		case SecurityDetailTypeType::MainBoard:
			return "MainBoard";
		case SecurityDetailTypeType::Star:
			return "Star";
		case SecurityDetailTypeType::SMEBoard:
			return "SMEBoard";
		case SecurityDetailTypeType::SecondBoard:
			return "SecondBoard";
		case SecurityDetailTypeType::BShares:
			return "BShares";
		case SecurityDetailTypeType::ETF:
			return "ETF";
		case SecurityDetailTypeType::AllotmentCode:
			return "AllotmentCode";
		case SecurityDetailTypeType::Bond:
			return "Bond";
		case SecurityDetailTypeType::ConvertibleBond:
			return "ConvertibleBond";
		case SecurityDetailTypeType::ReverseRepo:
			return "ReverseRepo";
		case SecurityDetailTypeType::Option:
			return "Option";
		case SecurityDetailTypeType::Other:
			return "Other";
		case SecurityDetailTypeType::PreferredStock:
			return "PreferredStock";
		case SecurityDetailTypeType::Future:
			return "Future";
		case SecurityDetailTypeType::FutureOption:
			return "FutureOption";
		default:
			return "Unknown";
	}
	return "";
}

//交易节类别
enum class SectionClassType : int
{
	//集合竞价
	Auction = 0,
	//连续竞价
	Section = 1,
};
inline const char* GetSectionClassString(SectionClassType value)
{
	switch (value)
	{
		case SectionClassType::Auction:
			return "Auction";
		case SectionClassType::Section:
			return "Section";
		default:
			return "Unknown";
	}
	return "";
}

//服务类别
enum class ServerTypeType : int
{
	//客户端
	Client = 0,
	//服务端
	Server = 1,
};
inline const char* GetServerTypeString(ServerTypeType value)
{
	switch (value)
	{
		case ServerTypeType::Client:
			return "Client";
		case ServerTypeType::Server:
			return "Server";
		default:
			return "Unknown";
	}
	return "";
}

//系统运行状态
enum class SystemRunningStatusType : int
{
	//未运行
	NotRun = 0,
	//已初始化
	Initialized = 1,
	//运行中
	IsRunning = 2,
};
inline const char* GetSystemRunningStatusString(SystemRunningStatusType value)
{
	switch (value)
	{
		case SystemRunningStatusType::NotRun:
			return "NotRun";
		case SystemRunningStatusType::Initialized:
			return "Initialized";
		case SystemRunningStatusType::IsRunning:
			return "IsRunning";
		default:
			return "Unknown";
	}
	return "";
}

//系统结算状态
enum class SystemSettlementStatusType : int
{
	//未开始
	NotStart = 0,
	//结算数据已准备
	SettleDataPrepared = 1,
	//结算中
	Settling = 2,
	//结算失败
	SettlementFailed = 3,
	//结算完成
	SettlementCompleted = 4,
};
inline const char* GetSystemSettlementStatusString(SystemSettlementStatusType value)
{
	switch (value)
	{
		case SystemSettlementStatusType::NotStart:
			return "NotStart";
		case SystemSettlementStatusType::SettleDataPrepared:
			return "SettleDataPrepared";
		case SystemSettlementStatusType::Settling:
			return "Settling";
		case SystemSettlementStatusType::SettlementFailed:
			return "SettlementFailed";
		case SystemSettlementStatusType::SettlementCompleted:
			return "SettlementCompleted";
		default:
			return "Unknown";
	}
	return "";
}

//证券委托价格类型
enum class StockOrderPriceTypeType : int
{
	//限价
	LimitPrice = 0,
	//最优五档即时成交剩余撤销
	FAK5 = 1,
	//最优五档即时成交剩余转限价
	FAL5 = 2,
	//即时成交剩余撤销
	FAK = 3,
	//全额成交或撤销
	FOK = 4,
	//对方最优价
	DBestPrice = 5,
	//本方最优价
	WBestPrice = 6,
};
inline const char* GetStockOrderPriceTypeString(StockOrderPriceTypeType value)
{
	switch (value)
	{
		case StockOrderPriceTypeType::LimitPrice:
			return "LimitPrice";
		case StockOrderPriceTypeType::FAK5:
			return "FAK5";
		case StockOrderPriceTypeType::FAL5:
			return "FAL5";
		case StockOrderPriceTypeType::FAK:
			return "FAK";
		case StockOrderPriceTypeType::FOK:
			return "FOK";
		case StockOrderPriceTypeType::DBestPrice:
			return "DBestPrice";
		case StockOrderPriceTypeType::WBestPrice:
			return "WBestPrice";
		default:
			return "Unknown";
	}
	return "";
}

//Tick类型
enum class TickTypeType : int
{
	//新增委托
	Add = 0,
	//删除委托
	Delete = 1,
	//产品状态
	Status = 2,
	//成交
	Trade = 3,
};
inline const char* GetTickTypeString(TickTypeType value)
{
	switch (value)
	{
		case TickTypeType::Add:
			return "Add";
		case TickTypeType::Delete:
			return "Delete";
		case TickTypeType::Status:
			return "Status";
		case TickTypeType::Trade:
			return "Trade";
		default:
			return "Unknown";
	}
	return "";
}

//有效期类型
enum class TimeConditionType : int
{
	//立即完成，否则撤销
	IOC = 0,
	//本节有效
	GFS = 1,
	//当日有效
	GFD = 2,
	//指定日期前有效
	GTD = 3,
	//撤销前有效
	GTC = 4,
	//集合竞价有效
	GFA = 5,
};
inline const char* GetTimeConditionString(TimeConditionType value)
{
	switch (value)
	{
		case TimeConditionType::IOC:
			return "IOC";
		case TimeConditionType::GFS:
			return "GFS";
		case TimeConditionType::GFD:
			return "GFD";
		case TimeConditionType::GTD:
			return "GTD";
		case TimeConditionType::GTC:
			return "GTC";
		case TimeConditionType::GFA:
			return "GFA";
		default:
			return "Unknown";
	}
	return "";
}

//交易范围类别
enum class TradeScopeTypeType : int
{
	//黑名单
	BlackList = 0,
	//白名单
	WhiteList = 1,
};
inline const char* GetTradeScopeTypeString(TradeScopeTypeType value)
{
	switch (value)
	{
		case TradeScopeTypeType::BlackList:
			return "BlackList";
		case TradeScopeTypeType::WhiteList:
			return "WhiteList";
		default:
			return "Unknown";
	}
	return "";
}

//交易状态
enum class TradeStatusType : int
{
	//忽略
	Ignore = 0,
	//正常
	Normal = 1,
	//只可平仓
	CloseOnly = 2,
	//禁止交易
	BanTrading = 3,
};
inline const char* GetTradeStatusString(TradeStatusType value)
{
	switch (value)
	{
		case TradeStatusType::Ignore:
			return "Ignore";
		case TradeStatusType::Normal:
			return "Normal";
		case TradeStatusType::CloseOnly:
			return "CloseOnly";
		case TradeStatusType::BanTrading:
			return "BanTrading";
		default:
			return "Unknown";
	}
	return "";
}

//成交类型
enum class TradeTypeType : int
{
	//普通成交
	Common = 0,
	//期权执行
	OptionsExecution = 1,
	//OTC成交
	OTC = 2,
	//期转现衍生成交
	EFPDerived = 3,
	//组合衍生成交
	CombinationDerived = 4,
};
inline const char* GetTradeTypeString(TradeTypeType value)
{
	switch (value)
	{
		case TradeTypeType::Common:
			return "Common";
		case TradeTypeType::OptionsExecution:
			return "OptionsExecution";
		case TradeTypeType::OTC:
			return "OTC";
		case TradeTypeType::EFPDerived:
			return "EFPDerived";
		case TradeTypeType::CombinationDerived:
			return "CombinationDerived";
		default:
			return "Unknown";
	}
	return "";
}

//出入金方向
enum class TransferDirectionType : int
{
	//入金
	TransferIn = 0,
	//出金
	TransferOut = 1,
};
inline const char* GetTransferDirectionString(TransferDirectionType value)
{
	switch (value)
	{
		case TransferDirectionType::TransferIn:
			return "TransferIn";
		case TransferDirectionType::TransferOut:
			return "TransferOut";
		default:
			return "Unknown";
	}
	return "";
}

//出入金标记
enum class TransferFlagType : int
{
	//正常
	Normal = 0,
	//手动录入
	Import = 1,
};
inline const char* GetTransferFlagString(TransferFlagType value)
{
	switch (value)
	{
		case TransferFlagType::Normal:
			return "Normal";
		case TransferFlagType::Import:
			return "Import";
		default:
			return "Unknown";
	}
	return "";
}

//出入金方式
enum class TransferMethodType : int
{
	//转账
	Transfer = 0,
	//支票
	Cheque = 1,
	//现金
	Cash = 2,
	//银期转账
	BFTransfer = 3,
};
inline const char* GetTransferMethodString(TransferMethodType value)
{
	switch (value)
	{
		case TransferMethodType::Transfer:
			return "Transfer";
		case TransferMethodType::Cheque:
			return "Cheque";
		case TransferMethodType::Cash:
			return "Cash";
		case TransferMethodType::BFTransfer:
			return "BFTransfer";
		default:
			return "Unknown";
	}
	return "";
}

//成交量类型
enum class VolumeConditionType : int
{
	//任何数量
	AV = 0,
	//最小数量
	MV = 1,
	//全部数量
	CV = 2,
};
inline const char* GetVolumeConditionString(VolumeConditionType value)
{
	switch (value)
	{
		case VolumeConditionType::AV:
			return "AV";
		case VolumeConditionType::MV:
			return "MV";
		case VolumeConditionType::CV:
			return "CV";
		default:
			return "Unknown";
	}
	return "";
}


