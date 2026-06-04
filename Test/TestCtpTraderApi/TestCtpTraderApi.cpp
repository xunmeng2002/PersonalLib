#pragma warning(disable:4819)
#include "CtpWrapper/TraderApiMiddle/ThostFtdcTraderApiMiddle.h"
#include "ThostFtdcTraderSpiImpl.h"
#include "Core/Logger/Logger.h"
#include <iostream>
#include <map>
#include <string.h>
#ifdef LINUX
#include <signal.h>
#endif // LINUX



using namespace std;


#ifdef LINUX
void sigusr1_handler(int signo)
{
	printf("catch SIGUSR1\n");
	printf("back to main\n");
}
#endif // LINUX


int main(int argc, char* argv[])
{
	map<string, CtpAccountInfo*> ctpAccountInfos;
	ReadCtpAccountInfo(ctpAccountInfos);

	Logger::GetInstance().Init(argv[0]);
	Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
	Logger::GetInstance().Start();

	string userID = "229140";
	CThostFtdcTraderApi* traderApi = CThostFtdcTraderApiMiddle::CreateFtdcTraderApi();
	cout << "API Version:" << traderApi->GetApiVersion() << endl;
	CThostFtdcTraderSpiImpl* traderSpi = new CThostFtdcTraderSpiImpl(traderApi);
	traderSpi->SetCtpAccountInfo(ctpAccountInfos[userID]);
	traderApi->RegisterSpi(traderSpi);
	for (auto& traderFrontAddr : ctpAccountInfos[userID]->TraderFrontAddrs)
	{
		traderApi->RegisterFront((char*)traderFrontAddr.c_str());
	}
	traderApi->SubscribePrivateTopic(THOST_TE_RESUME_TYPE::THOST_TERT_RESTART);
	traderApi->SubscribePublicTopic(THOST_TE_RESUME_TYPE::THOST_TERT_RESTART);
	traderApi->Init();

#ifdef LINUX
	struct sigaction act;
	act.sa_handler = sigusr1_handler;
	act.sa_flags = SA_NODEFER;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		perror("fail to set handler for SIGUSR1");
		exit(1);
	}
#endif // LINUX
	std::this_thread::sleep_for(std::chrono::seconds(30));

	traderApi->Release();
	//traderApi->Join();

	Logger::GetInstance().Stop();
	Logger::GetInstance().Join();
	return 0;
}


