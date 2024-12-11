#include "TestStepServer.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "PackageFactory.h"

using namespace std;


StepServer::StepServer()
	:Protocol(ProtocolTypeType::Step, ServerTypeType::Server, g_IOType, "StepServer", g_Address, new PackageFactory()), m_Connected(false), m_SessionID(0LL)
{
	Subscribe(this);
}
StepServer::~StepServer()
{
}

void StepServer::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "StepServer::OnConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_Connected = true;
}
void StepServer::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "StepServer::OnDisConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_Connected = false;
}
void StepServer::OnMessage(Package* stepPackage)
{
	WriteLog(LogLevel::Info, "OnMessage SessionID:[%lld], %s", stepPackage->SessionID, stepPackage->GetDebugString());

	Send(stepPackage);
}


void TestStepServer()
{
	WriteLog(LogLevel::Info, "TestStepServer");

	StepServer StepServer;
	StepServer.Init();
	StepServer.Start();

	while (!StepServer.m_Connected)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	//for (auto i = 0; i < 5; ++i)
	//{
	//	StepReqInsertOrderPackage reqInsertOrder;
	//	reqInsertOrder.Prepare(StepServer.m_SessionID, false, i);
	//	reqInsertOrder.ReqInsertOrder = Allocate<StepReqInsertOrder>();
	//	memset(reqInsertOrder.ReqInsertOrder, 0, sizeof(StepReqInsertOrder));
	//	Strcpy(reqInsertOrder.ReqInsertOrder->AccountID, "Xunmeng001");
	//	Strcpy(reqInsertOrder.ReqInsertOrder->ExchangeID, "SHSE");
	//	Strcpy(reqInsertOrder.ReqInsertOrder->InstrumentID, "600036");
	//	reqInsertOrder.ReqInsertOrder->Direction = DirectionType::Buy;
	//	reqInsertOrder.ReqInsertOrder->OffsetFlag = OffsetFlagType::Open;
	//	reqInsertOrder.ReqInsertOrder->OrderPriceType = OrderPriceTypeType::LimitPrice;
	//	reqInsertOrder.ReqInsertOrder->Price = 100 + i;
	//	reqInsertOrder.ReqInsertOrder->Volume = i;
	//	reqInsertOrder.ReqInsertOrder->ClientOrderID = i;

	//	StepServer.Send(&reqInsertOrder);
	//}

	std::this_thread::sleep_for(std::chrono::seconds(60));
	StepServer.Stop();
	StepServer.Join();
}



