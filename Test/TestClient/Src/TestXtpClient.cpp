#include "TestXtpClient.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "XtpPackageFactory.h"

using namespace xtp;
using namespace std;


XtpClient::XtpClient()
	:xtp::XtpProtocol(ServerTypeType::Client, g_IOType, "XtpClient", g_Address, new XtpPackageFactory()), m_ConnectStatus(false), m_SessionID(0LL)
{
	SubscribeXtp(this);
}
XtpClient::~XtpClient()
{
}
void XtpClient::OnXtpConnect(SessionIDType sessionID, const char* ip, const char* port)
{
	WriteLog(LogLevel::Info, "XtpClient::OnXtpConnect SessionID:[%lld], IP:[%s], port:[%s]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_ConnectStatus = true;
}
void XtpClient::OnXtpDisConnect(SessionIDType sessionID, const char* ip, const char* port)
{
	WriteLog(LogLevel::Info, "XtpClient::OnXtpDisConnect SessionID:[%lld], IP:[%s], port:[%s]", sessionID, ip, port);

	m_ConnectStatus = false;
}
void XtpClient::OnXtpMessage(xtp::XtpPackageBase* xtpPackage)
{
	WriteLog(LogLevel::Info, "OnXtpMessage: %s", xtpPackage->GetDebugString());
}


void TestXtpClient()
{
	WriteLog(LogLevel::Info, "TestXtpClient");

	XtpClient xtpClient;
	xtpClient.Init();
	xtpClient.Start();

	while (!xtpClient.m_ConnectStatus)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	for (auto i = 0; i < 5; ++i)
	{
		XtpReqInsertOrderPackage reqInsertOrder;
		reqInsertOrder.Prepare(xtpClient.m_SessionID);
		Strcpy(reqInsertOrder.Field.PrimaryAccountID, "Xunmeng001");
		Strcpy(reqInsertOrder.Field.ExchangeID, "SHSE");
		Strcpy(reqInsertOrder.Field.InstrumentID, "600036");
		reqInsertOrder.Field.Direction = DirectionType::Buy;
		reqInsertOrder.Field.OffsetFlag = OffsetFlagType::Open;
		reqInsertOrder.Field.OrderPriceType = OrderPriceTypeType::LimitPrice;
		reqInsertOrder.Field.Price = 100 + i;
		reqInsertOrder.Field.Volume = i;
		reqInsertOrder.Field.OrderID = i;

		xtpClient.Send(&reqInsertOrder);
	}

	std::this_thread::sleep_for(std::chrono::seconds(20));
	xtpClient.Stop();
	xtpClient.Join();
}



