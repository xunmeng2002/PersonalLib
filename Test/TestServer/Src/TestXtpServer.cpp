#include "TestXtpServer.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "XtpPackageFactory.h"

using namespace xtp;
using namespace std;


XtpServer::XtpServer()
	:xtp::XtpProtocol(ServerTypeType::Server, g_IOType, "XtpServer", g_Address, new XtpPackageFactory()), m_ConnectStatus(false), m_SessionID(0LL)
{
	SubscribeXtp(this);
}
XtpServer::~XtpServer()
{
}

void XtpServer::OnXtpConnect(SessionIDType sessionID, const char* ip, const char* port)
{
	WriteLog(LogLevel::Info, "XtpServer::OnXtpConnect SessionID:[%lld], IP:[%s], port:[%s]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_ConnectStatus = true;
}
void XtpServer::OnXtpDisConnect(SessionIDType sessionID, const char* ip, const char* port)
{
	WriteLog(LogLevel::Info, "XtpServer::OnXtpDisConnect SessionID:[%lld], IP:[%s], port:[%s]", sessionID, ip, port);

	m_ConnectStatus = false;
}
void XtpServer::OnXtpMessage(xtp::XtpPackageBase* xtpPackage)
{
	WriteLog(LogLevel::Info, "OnXtpMessage SessionID:[%lld], %s", xtpPackage->SessionID, xtpPackage->GetDebugString());

	Send(xtpPackage);
}


void TestXtpServer()
{
	WriteLog(LogLevel::Info, "TestXtpServer");

	XtpServer XtpServer;
	XtpServer.Init();
	XtpServer.Start();

	while (!XtpServer.m_ConnectStatus)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	//for (auto i = 0; i < 5; ++i)
	//{
	//	XtpReqInsertOrderPackage reqInsertOrder;
	//	reqInsertOrder.Prepare(XtpServer.m_SessionID);
	//	Strcpy(reqInsertOrder.Field.PrimaryAccountID, "Xunmeng001");
	//	Strcpy(reqInsertOrder.Field.ExchangeID, "SHSE");
	//	Strcpy(reqInsertOrder.Field.InstrumentID, "600000");
	//	reqInsertOrder.Field.Direction = DirectionType::Buy;
	//	reqInsertOrder.Field.OffsetFlag = OffsetFlagType::Open;
	//	reqInsertOrder.Field.OrderPriceType = OrderPriceTypeType::LimitPrice;
	//	reqInsertOrder.Field.Price = 200 + i;
	//	reqInsertOrder.Field.Volume = i;
	//	reqInsertOrder.Field.OrderID = i;

	//	XtpServer.Send(&reqInsertOrder);
	//}

	std::this_thread::sleep_for(std::chrono::seconds(300));
	XtpServer.Stop();
	XtpServer.Join();
}



