#include "TestXtpServer.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "XtpPackageFactory.h"

using namespace xtp;
using namespace std;


XtpServer::XtpServer()
	:xtp::XtpProtocol(ServerTypeType::Server, g_IOType, "XtpServer", g_Address, new XtpPackageFactory()), m_Connected(false), m_SessionID(0LL)
{
	SubscribeXtp(this);
}
XtpServer::~XtpServer()
{
}

void XtpServer::OnXtpConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpServer::OnXtpConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_Connected = true;
}
void XtpServer::OnXtpDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpServer::OnXtpDisConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_Connected = false;
}
void XtpServer::OnXtpMessage(xtp::XtpPackageBase* xtpPackage)
{
	WriteLog(LogLevel::Info, "OnXtpMessage SessionID:[%lld], %s", xtpPackage->SessionID, xtpPackage->GetDebugString());

	Send(xtpPackage);
}


void TestXtpServer()
{
	WriteLog(LogLevel::Info, "TestXtpServer");

	XtpServer xtpServer;
	xtpServer.Init();
	xtpServer.Start();

	while (!xtpServer.m_Connected)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	std::this_thread::sleep_for(std::chrono::seconds(60));
	xtpServer.Stop();
	xtpServer.Join();
}



