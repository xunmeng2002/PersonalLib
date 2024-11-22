#pragma once

#include "ThostFtdcMdSpiMiddle.h"
#include <set>
#include <string>


typedef char TThostFtdcAccountTypeType[10];

struct AccountInfo
{
	TThostFtdcAccountTypeType AccountType;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	Password;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcAuthCodeType	AuthCode;
	TThostFtdcAppIDType	AppID;
	std::set<std::string> FrontAddrs;
};

class CThostFtdcMdSpiImpl : public CThostFtdcMdSpiMiddle
{
public:
	CThostFtdcMdSpiImpl(CThostFtdcMdApi* MdApi);

	virtual void OnFrontConnected();

	virtual void OnFrontDisconnected(int nReason);

	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

public:
	void SetAccountInfo(AccountInfo* accountInfo);

private:
	void ReqUserLogin();
	void ReqSubscribeMd();

private:
	CThostFtdcMdApi* m_MdApi;
	int m_RequestID;

	AccountInfo* m_AccountInfo;
};
