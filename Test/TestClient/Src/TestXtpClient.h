#pragma once
#include "TcpBase.h"
#include "XtpProtocol.h"
#include "XtpPackages.h"


class XtpClient : public xtp::XtpProtocol, public xtp::XtpSubscriber
{
public:
	XtpClient();
	virtual ~XtpClient();

	virtual void OnXtpConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnXtpDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnXtpMessage(xtp::XtpPackageBase* xtpPackage) override;

	bool m_Connected;
	SessionIDType m_SessionID;
};



void TestXtpClient();


