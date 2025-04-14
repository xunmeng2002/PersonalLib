#include "TestStepClient.h"
#include "Utility.h"
#include "TimeUtility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "PackageFactory.h"
#include "Packages.h"

using namespace std;


StepClient::StepClient()
	:Protocol(ProtocolTypeType::Step, ServerTypeType::Client, "StepClient", 0, new PackageFactory()), m_Connected(false), m_SessionID(0LL), m_RecvCount(0)
{
	m_ReqInsertOrder = new ReqInsertOrderPackage();
	Subscribe(this);
	RegisterFront(g_Address);
}
StepClient::~StepClient()
{
}

void StepClient::OnProtocolConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "StepClient::OnConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_Connected = true;
	m_StartTime = chrono::steady_clock::now();
	SendReqInsertOrder(++m_RecvCount);
}
void StepClient::OnProtocolDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "StepClient::OnDisConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_Connected = false;
	m_RecvCount = 0;
}
void StepClient::OnMessage(Package* package)
{
	if (++m_RecvCount % 10000 == 0)
	{
		WriteLog(LogLevel::Info, "OnMessage: %s", package->GetDebugString());
	}
	if (m_RecvCount < 1000000)
	{
		SendReqInsertOrder(m_RecvCount);
	}
	else
	{
		WriteLog(LogLevel::Info, "OnMessage: %s", package->GetDebugString());
		WriteLog(LogLevel::Info, "Total Cost: %lld ms", GetDuration<chrono::milliseconds>(m_StartTime));
		Stop();
	}
}
void StepClient::SendReqInsertOrder(int index)
{
	m_ReqInsertOrder->Prepare(m_SessionID, false, index);
	m_ReqInsertOrder->ReqInsertOrder = Allocate<ReqInsertOrderField>();
	memset(m_ReqInsertOrder->ReqInsertOrder, 0, sizeof(ReqInsertOrderField));
	Strcpy(m_ReqInsertOrder->ReqInsertOrder->AccountID, "Xunmeng001");
	Strcpy(m_ReqInsertOrder->ReqInsertOrder->ExchangeID, "SHSE");
	Strcpy(m_ReqInsertOrder->ReqInsertOrder->InstrumentID, "600036");
	m_ReqInsertOrder->ReqInsertOrder->Direction = DirectionType::Buy;
	m_ReqInsertOrder->ReqInsertOrder->OffsetFlag = OffsetFlagType::Open;
	m_ReqInsertOrder->ReqInsertOrder->OrderPriceType = OrderPriceTypeType::LimitPrice;
	m_ReqInsertOrder->ReqInsertOrder->Price = 100 + index;
	m_ReqInsertOrder->ReqInsertOrder->Volume = index;
	m_ReqInsertOrder->ReqInsertOrder->ClientOrderID = index;
	Send(m_ReqInsertOrder);
}

void TestStepClient()
{
	WriteLog(LogLevel::Info, "TestStepClient");

	StepClient stepClient;
	if (!stepClient.Init())
		return;
	stepClient.Start();

	//while (!stepClient.m_Connected)
	//{
	//	std::this_thread::sleep_for(std::chrono::seconds(1));
	//}
	//for (auto i = 0; i < 5; ++i)
	//{
	//	ReqInsertOrderPackage reqInsertOrder;
	//	reqInsertOrder.Prepare(stepClient.m_SessionID, false, i);
	//	reqInsertOrder.ReqInsertOrder = Allocate<ReqInsertOrderField>();
	//	memset(reqInsertOrder.ReqInsertOrder, 0, sizeof(ReqInsertOrderField));
	//	Strcpy(reqInsertOrder.ReqInsertOrder->AccountID, "Xunmeng001");
	//	Strcpy(reqInsertOrder.ReqInsertOrder->ExchangeID, "SHSE");
	//	Strcpy(reqInsertOrder.ReqInsertOrder->InstrumentID, "600036");
	//	reqInsertOrder.ReqInsertOrder->Direction = DirectionType::Buy;
	//	reqInsertOrder.ReqInsertOrder->OffsetFlag = OffsetFlagType::Open;
	//	reqInsertOrder.ReqInsertOrder->OrderPriceType = OrderPriceTypeType::LimitPrice;
	//	reqInsertOrder.ReqInsertOrder->Price = 100 + i;
	//	reqInsertOrder.ReqInsertOrder->Volume = i;
	//	reqInsertOrder.ReqInsertOrder->ClientOrderID = i;

	//	stepClient.Send(&reqInsertOrder);
	//}

	//std::this_thread::sleep_for(std::chrono::seconds(5));
	//stepClient.Stop();
	stepClient.Join();
}



