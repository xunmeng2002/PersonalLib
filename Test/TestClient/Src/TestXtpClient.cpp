#include "TestXtpClient.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "PackageFactory.h"
#include "TimeUtility.h"
#include "Packages.h"

using namespace std;


XtpClient::XtpClient()
	:Protocol(ProtocolTypeType::Xtp, ServerTypeType::Client, "XtpClient", 0, new PackageFactory()), m_Connected(false), m_SessionID(0LL), m_RecvCount(0)
{
	m_ReqInsertOrder = new ReqInsertOrderPackage();
	Subscribe(this);
	RegisterFront(g_Address);
}
XtpClient::~XtpClient()
{
}
void XtpClient::OnProtocolConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpClient::OnConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_Connected = true;
	m_StartTime = chrono::steady_clock::now();
	SendReqInsertOrder(++m_RecvCount);
}
void XtpClient::OnProtocolDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpClient::OnDisConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_Connected = false;
	m_RecvCount = 0;
}
void XtpClient::OnMessage(Package* package)
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

void XtpClient::SendReqInsertOrder(int index)
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


void TestXtpClient()
{
	WriteLog(LogLevel::Info, "TestXtpClient");

	XtpClient xtpClient;
	if (!xtpClient.Init())
		return;
	xtpClient.Start();

	//while (!xtpClient.m_Connected)
	//{
	//	std::this_thread::sleep_for(std::chrono::seconds(1));
	//}
	//for (auto i = 0; i < 5; ++i)
	//{
	//	ReqInsertOrderPackage reqInsertOrder;
	//	reqInsertOrder.Prepare(xtpClient.m_SessionID, false, 0);
	//	reqInsertOrder.ReqInsertOrder = Allocate<ReqInsertOrderField>();
	//	Strcpy(reqInsertOrder.ReqInsertOrder->AccountID, "Xunmeng001");
	//	Strcpy(reqInsertOrder.ReqInsertOrder->ExchangeID, "SHSE");
	//	Strcpy(reqInsertOrder.ReqInsertOrder->InstrumentID, "600036");
	//	reqInsertOrder.ReqInsertOrder->Direction = DirectionType::Buy;
	//	reqInsertOrder.ReqInsertOrder->OffsetFlag = OffsetFlagType::Open;
	//	reqInsertOrder.ReqInsertOrder->OrderPriceType = OrderPriceTypeType::LimitPrice;
	//	reqInsertOrder.ReqInsertOrder->Price = 100 + i;
	//	reqInsertOrder.ReqInsertOrder->Volume = i;
	//	reqInsertOrder.ReqInsertOrder->ClientOrderID = i;

	//	xtpClient.Send(&reqInsertOrder);
	//}

	//std::this_thread::sleep_for(std::chrono::seconds(5));
	//xtpClient.Stop();
	xtpClient.Join();
}

