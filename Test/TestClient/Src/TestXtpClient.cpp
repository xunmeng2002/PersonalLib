#include "TestXtpClient.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "PackageFactory.h"
#include "TimeUtility.h"
#include "Packages.h"

using namespace std;


XtpClient::XtpClient()
	:Protocol(ProtocolTypeType::Xtp, ServerTypeType::Client, "XtpClient", new PackageFactory()), m_Connected(false), m_SessionID(0LL)
{
	Subscribe(this);
	RegisterFront(g_Address);
}
XtpClient::~XtpClient()
{
}
void XtpClient::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpClient::OnConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_Connected = true;
}
void XtpClient::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpClient::OnDisConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_Connected = false;
}
void XtpClient::OnMessage(Package* package)
{
	WriteLog(LogLevel::Info, "OnMessage: %s", package->GetDebugString());
}


void TestXtpClient()
{
	WriteLog(LogLevel::Info, "TestXtpClient");

	XtpClient xtpClient;
	xtpClient.Init();
	xtpClient.Start();

	while (!xtpClient.m_Connected)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for (auto i = 0; i < 5; ++i)
	{
		ReqInsertOrderPackage reqInsertOrder;
		reqInsertOrder.Prepare(xtpClient.m_SessionID, false, 0);
		reqInsertOrder.ReqInsertOrder = Allocate<ReqInsertOrderField>();
		Strcpy(reqInsertOrder.ReqInsertOrder->AccountID, "Xunmeng001");
		Strcpy(reqInsertOrder.ReqInsertOrder->ExchangeID, "SHSE");
		Strcpy(reqInsertOrder.ReqInsertOrder->InstrumentID, "600036");
		reqInsertOrder.ReqInsertOrder->Direction = DirectionType::Buy;
		reqInsertOrder.ReqInsertOrder->OffsetFlag = OffsetFlagType::Open;
		reqInsertOrder.ReqInsertOrder->OrderPriceType = OrderPriceTypeType::LimitPrice;
		reqInsertOrder.ReqInsertOrder->Price = 100 + i;
		reqInsertOrder.ReqInsertOrder->Volume = i;
		reqInsertOrder.ReqInsertOrder->ClientOrderID = i;

		xtpClient.Send(&reqInsertOrder);
	}

	std::this_thread::sleep_for(std::chrono::seconds(5));
	xtpClient.Stop();
	xtpClient.Join();
}

