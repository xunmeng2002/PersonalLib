#pragma once
#include "TcpBase.h"
#include "XtpProtocol.h"


class XtpServer : public xtp::XtpProtocol, public xtp::XtpSubscriber
{
public:
	XtpServer();
	virtual ~XtpServer();

	virtual void OnXtpConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnXtpDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnXtpMessage(xtp::XtpPackageBase* xtpPackage) override;

	bool m_Connected;
	SessionIDType m_SessionID;
};



void TestXtpServer();


