#include "TestXtpServer.h"
#include "Utility.h"
#include "Logger.h"
#include "TestUtility.h"
#include "PackageFactory.h"

using namespace std;


XtpServer::XtpServer()
	:Protocol(ProtocolTypeType::Xtp, ServerTypeType::Server, "XtpServer", new PackageFactory()), m_Connected(false), m_SessionID(0LL)
{
	Subscribe(this);
	RegisterFront(g_Address);
}
XtpServer::~XtpServer()
{
}

void XtpServer::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpServer::OnConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_SessionID = sessionID;
	m_Connected = true;
}
void XtpServer::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "XtpServer::OnDisConnect SessionID:[%lld], IP:[%s], port:[%d]", sessionID, ip, port);

	m_Connected = false;
}
void XtpServer::OnMessage(Package* xtpPackage)
{
	WriteLog(LogLevel::Info, "OnMessage SessionID:[%lld], %s", xtpPackage->SessionID, xtpPackage->GetDebugString());

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



