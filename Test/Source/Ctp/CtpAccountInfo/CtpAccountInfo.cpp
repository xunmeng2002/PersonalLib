#include "CtpAccountInfo.h"
#include "json/json.h"
#include <fstream>
#include <iostream>

using namespace std;


void PrintAccountInfo(AccountInfo* accountInfo)
{
	printf("AccountInfo: BrokerID[%s],  UserID[%s], Password[%s],  UserProductInfo[%s], AuthCode[%s],  AppID[%s]\n",
		accountInfo->BrokerID, accountInfo->UserID, accountInfo->Password, accountInfo->UserProductInfo, accountInfo->AuthCode, accountInfo->AppID);
	for (auto& traderFrontAddr : accountInfo->TraderFrontAddrs)
	{
		printf("TraderFrontAddrs:[%s]\t", traderFrontAddr.c_str());
	}
	printf("\n");
	for (auto& mdFrontAddr : accountInfo->MdFrontAddrs)
	{
		printf("MdFrontAddr:[%s]\t", mdFrontAddr.c_str());
	}
	printf("\n");
}
void ReadAccountInfo(std::map<std::string, AccountInfo*>& accountInfos)
{
	Json::Reader reader;
	Json::FastWriter writer;
	Json::Value root;

	ifstream in_file("AccountInfo.json", ios::binary);
	cout << "parse: " << reader.parse(in_file, root) << endl;
	in_file.close();

	for (auto i = 0u; i < root.size(); i++)
	{
		AccountInfo* accountInfo = new AccountInfo();
		strcpy(accountInfo->BrokerID, root[i]["BrokerID"].asString().c_str());
		strcpy(accountInfo->UserID, root[i]["UserID"].asString().c_str());
		strcpy(accountInfo->Password, root[i]["Password"].asString().c_str());
		strcpy(accountInfo->UserProductInfo, root[i]["UserProductInfo"].asString().c_str());
		strcpy(accountInfo->AuthCode, root[i]["AuthCode"].asString().c_str());
		strcpy(accountInfo->AppID, root[i]["AppID"].asString().c_str());
		for (auto j = 0u; j < root[i]["TraderFrontAddrs"].size(); j++)
		{
			accountInfo->TraderFrontAddrs.insert(root[i]["TraderFrontAddrs"][j].asString());
		}
		for (auto j = 0u; j < root[i]["MdFrontAddrs"].size(); j++)
		{
			accountInfo->MdFrontAddrs.insert(root[i]["MdFrontAddrs"][j].asString());
		}
		accountInfos.insert(make_pair(accountInfo->UserID, accountInfo));
	}
	for (auto& it : accountInfos)
	{
		PrintAccountInfo(it.second);
	}
}
