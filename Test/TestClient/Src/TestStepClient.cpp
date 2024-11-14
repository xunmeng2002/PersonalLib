#include "TestStepClient.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "StepPackageFactory.h"

using namespace step;
using namespace std;


StepClient::StepClient()
	:step::StepProtocol(ServerTypeType::Client, g_IOType, "StepClient", g_Address, new StepPackageFactory()), m_ConnectStatus(false), m_SessionID(0LL)
{
	SubscribeStep(this);
}
StepClient::~StepClient()
{
}

void StepClient::OnStepConnect(SessionIDType sessionID, const char* ip, const char* port)
{
	WriteLog(LogLevel::Info, "StepClient::OnStepConnect SessionID:[%lld], IP:[%s], port:[%s]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_ConnectStatus = true;
}
void StepClient::OnStepDisConnect(SessionIDType sessionID, const char* ip, const char* port)
{
	WriteLog(LogLevel::Info, "StepClient::OnStepDisConnect SessionID:[%lld], IP:[%s], port:[%s]", sessionID, ip, port);

	m_ConnectStatus = false;
}
void StepClient::OnStepMessage(step::StepPackageBase* stepPackage)
{
	WriteLog(LogLevel::Info, "OnStepMessage: %s", stepPackage->GetDebugString());
}


void TestStepClient()
{
	WriteLog(LogLevel::Info, "TestStepClient");

	StepClient stepClient;
	stepClient.Init();
	stepClient.Start();

	while (!stepClient.m_ConnectStatus)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for (auto i = 0; i < 5; ++i)
	{
		StepReqInsertOrderPackage reqInsertOrder;
		reqInsertOrder.Prepare(stepClient.m_SessionID, false, i);
		reqInsertOrder.ReqInsertOrder = Allocate<StepReqInsertOrder>();
		memset(reqInsertOrder.ReqInsertOrder, 0, sizeof(StepReqInsertOrder));
		Strcpy(reqInsertOrder.ReqInsertOrder->AccountID, "Xunmeng001");
		Strcpy(reqInsertOrder.ReqInsertOrder->ExchangeID, "SHSE");
		Strcpy(reqInsertOrder.ReqInsertOrder->InstrumentID, "600036");
		reqInsertOrder.ReqInsertOrder->Direction = DirectionType::Buy;
		reqInsertOrder.ReqInsertOrder->OffsetFlag = OffsetFlagType::Open;
		reqInsertOrder.ReqInsertOrder->OrderPriceType = OrderPriceTypeType::LimitPrice;
		reqInsertOrder.ReqInsertOrder->Price = 100 + i;
		reqInsertOrder.ReqInsertOrder->Volume = i;
		reqInsertOrder.ReqInsertOrder->ClientOrderID = i;

		stepClient.Send(&reqInsertOrder);
	}

	std::this_thread::sleep_for(std::chrono::seconds(20));
	stepClient.Stop();
	stepClient.Join();
}



