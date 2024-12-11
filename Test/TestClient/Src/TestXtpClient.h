#pragma once
#include "TcpBase.h"
#include "Protocol.h"


class XtpClient : public Protocol, public ProtocolSubscriber
{
public:
	XtpClient();
	virtual ~XtpClient();

	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnMessage(Package* package) override;

	bool m_Connected;
	SessionIDType m_SessionID;
};



void TestXtpClient();


