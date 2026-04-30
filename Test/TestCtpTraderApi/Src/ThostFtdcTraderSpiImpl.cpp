#include "ThostFtdcTraderSpiImpl.h"
#include "Logger/Logger.h"
#include <string.h>


CThostFtdcTraderSpiImpl::CThostFtdcTraderSpiImpl(CThostFtdcTraderApi* traderApi)
	:m_TraderApi(traderApi), m_RequestID(0), m_CtpAccountInfo(nullptr)
{
}
void CThostFtdcTraderSpiImpl::OnFrontConnected()
{
	CThostFtdcTraderSpiMiddle::OnFrontConnected();
	ReqAuthenticate();
}
void CThostFtdcTraderSpiImpl::OnFrontDisconnected(int nReason)
{
	CThostFtdcTraderSpiMiddle::OnFrontDisconnected(nReason);
}
void CThostFtdcTraderSpiImpl::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspAuthenticate(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
	ReqUserLogin();
}
void CThostFtdcTraderSpiImpl::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	ReqQryInstrument();
}
void CThostFtdcTraderSpiImpl::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryInstrument(pInstrument, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		ReqQryTradingAccount();
	}
}
void CThostFtdcTraderSpiImpl::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryTradingAccount(pTradingAccount, pRspInfo, nRequestID, bIsLast);
	ReqQryInvestorPosition();
}
void CThostFtdcTraderSpiImpl::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryInvestorPosition(pInvestorPosition, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		ReqQryOrder();
	}
}
void CThostFtdcTraderSpiImpl::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryOrder(pOrder, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		ReqQryTrade();
	}
}
void CThostFtdcTraderSpiImpl::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryTrade(pTrade, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		
	}
}

void CThostFtdcTraderSpiImpl::SetCtpAccountInfo(CtpAccountInfo* ctpAccountInfo)
{
	m_CtpAccountInfo = ctpAccountInfo;
}

void CThostFtdcTraderSpiImpl::ReqAuthenticate()
{
	CThostFtdcReqAuthenticateField authenticate;
	::memset(&authenticate, 0, sizeof(authenticate));
	strcpy(authenticate.BrokerID, m_CtpAccountInfo->BrokerID);
	strcpy(authenticate.UserID, m_CtpAccountInfo->UserID);
	strcpy(authenticate.UserProductInfo, m_CtpAccountInfo->UserProductInfo);
	strcpy(authenticate.AuthCode, m_CtpAccountInfo->AuthCode);
	strcpy(authenticate.AppID, m_CtpAccountInfo->AppID);

	int ret = m_TraderApi->ReqAuthenticate(&authenticate, m_RequestID++);
	WriteLog(LogLevel::Info, "ReqAuthenticate: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqUserLogin()
{
	CThostFtdcReqUserLoginField userLogin;
	::memset(&userLogin, 0, sizeof(userLogin));
	strcpy(userLogin.TradingDay, "");
	strcpy(userLogin.BrokerID, m_CtpAccountInfo->BrokerID);
	strcpy(userLogin.UserID, m_CtpAccountInfo->UserID);
	strcpy(userLogin.Password, m_CtpAccountInfo->Password);
	strcpy(userLogin.UserProductInfo, m_CtpAccountInfo->UserProductInfo);

	int ret = m_TraderApi->ReqUserLogin(&userLogin, m_RequestID++);
	WriteLog(LogLevel::Info, "ReqUserLogin: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryInstrument()
{
	CThostFtdcQryInstrumentField qryInstrument;
	::memset(&qryInstrument, 0, sizeof(qryInstrument));
	int ret = m_TraderApi->ReqQryInstrument(&qryInstrument, m_RequestID++);
	WriteLog(LogLevel::Info, "ReqQryInstrument: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryTradingAccount()
{
	CThostFtdcQryTradingAccountField qryTradingAccount;
	::memset(&qryTradingAccount, 0, sizeof(qryTradingAccount));
	int ret = m_TraderApi->ReqQryTradingAccount(&qryTradingAccount, m_RequestID++);
	WriteLog(LogLevel::Info, "ReqQryTradingAccount: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryInvestorPosition()
{
	CThostFtdcQryInvestorPositionField qryInvestorPosition;
	::memset(&qryInvestorPosition, 0, sizeof(qryInvestorPosition));
	int ret = m_TraderApi->ReqQryInvestorPosition(&qryInvestorPosition, m_RequestID++);
	WriteLog(LogLevel::Info, "ReqQryInvestorPosition: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryOrder()
{
	CThostFtdcQryOrderField qryOrder;
	::memset(&qryOrder, 0, sizeof(qryOrder));
	int ret = m_TraderApi->ReqQryOrder(&qryOrder, m_RequestID++);
	WriteLog(LogLevel::Info, "ReqQryOrder: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryTrade()
{
	CThostFtdcQryTradeField qryTrade;
	::memset(&qryTrade, 0, sizeof(qryTrade));
	int ret = m_TraderApi->ReqQryTrade(&qryTrade, m_RequestID++);
	WriteLog(LogLevel::Info, "ReqQryTrade: ret[%d]", ret);
}
