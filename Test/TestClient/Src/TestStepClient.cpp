#include "TestStepClient.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "PackageFactory.h"
#include "Packages.h"

using namespace std;


StepClient::StepClient()
	:Protocol(ProtocolTypeType::Step, ServerTypeType::Client, "StepClient", new PackageFactory()), m_Connected(false), m_SessionID(0LL)
{
	Subscribe(this);
	RegisterFront(g_Address);
}
StepClient::~StepClient()
{
}

void StepClient::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "StepClient::OnConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_Connected = true;
}
void StepClient::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "StepClient::OnDisConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_Connected = false;
}
void StepClient::OnMessage(Package* package)
{
	WriteLog(LogLevel::Info, "OnMessage: %s", package->GetDebugString());
}


void TestStepClient()
{
	WriteLog(LogLevel::Info, "TestStepClient");

	StepClient stepClient;
	stepClient.Init();
	stepClient.Start();

	while (!stepClient.m_Connected)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for (auto i = 0; i < 5; ++i)
	{
		ReqInsertOrderPackage reqInsertOrder;
		reqInsertOrder.Prepare(stepClient.m_SessionID, false, i);
		reqInsertOrder.ReqInsertOrder = Allocate<ReqInsertOrderField>();
		memset(reqInsertOrder.ReqInsertOrder, 0, sizeof(ReqInsertOrderField));
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

	std::this_thread::sleep_for(std::chrono::seconds(5));
	stepClient.Stop();
	stepClient.Join();
}



