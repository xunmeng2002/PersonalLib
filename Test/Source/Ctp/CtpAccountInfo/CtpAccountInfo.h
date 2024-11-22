#pragma once
#include "ThostFtdcUserApiStruct.h"
#include <set>
#include <map>
#include <string>

struct AccountInfo
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	Password;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcAuthCodeType	AuthCode;
	TThostFtdcAppIDType	AppID;
	std::set<std::string> TraderFrontAddrs;
	std::set<std::string> MdFrontAddrs;
};

void PrintAccountInfo(AccountInfo* accountInfo);
void ReadAccountInfo(std::map<std::string, AccountInfo*>& accountInfos);


