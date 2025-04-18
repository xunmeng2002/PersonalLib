#pragma once
#include "TcpBase.h"
#include "TcpIocpConnect.h"


class TcpIocpBase : public TcpBase
{
public:
	TcpIocpBase(ServerTypeType serverType, const char* addressName, int milliSeconds, int backlog = 5);
	~TcpIocpBase();
	
	virtual bool Init() override;
	virtual void DisConnect(SessionIDType sessionID) override;
	void DoRecv(MyOverlapped* overlapped);
	virtual void DoAccept(MyOverlapped* overlapped);
	virtual void DoConnect(MyOverlapped* overlapped) {}
	void DoDisConnect(MyOverlapped* overlapped);

protected:
	virtual void HandleTcpEvent() override;
	virtual void CheckConnect() override;
	virtual void RemoveConnect(Connect* connect) override;

	virtual bool PostConnect() { return false; }
	virtual bool PostDisConnect(Connect* connect);
	virtual bool PostAccept();
	virtual bool PostRecv(MyOverlapped* connect);

protected:
	int m_BackLog;
	bool m_HasSendConnect;
};

