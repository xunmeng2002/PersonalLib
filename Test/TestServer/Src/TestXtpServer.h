#pragma once
#include "TcpBase.h"
#include "Protocol.h"


class XtpServer : public Protocol, public ProtocolSubscriber
{
public:
	XtpServer();
	virtual ~XtpServer();

	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnMessage(Package* package) override;

	bool m_Connected;
	SessionIDType m_SessionID;
};



void TestXtpServer();


