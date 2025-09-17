#pragma once
#include "TcpBase.h"
#include "TcpIocpConnect.h"


class TcpIocpBase : public TcpBase
{
public:
	TcpIocpBase(ServerTypeType serverType, const char* addressName, int milliSeconds, int backlog = 5);
	~TcpIocpBase();
	
	virtual bool Init() override;
protected:
	virtual void HandleTcpEvent() override;
	virtual void DoDisConnect() override;

	virtual bool PostAccept() { return false; }
	virtual bool PostConnect() { return false; }
	virtual bool PostDisConnect(Connect* connect);
	virtual bool PostRecv(MyOverlapped* connect);

	virtual void DoAccept(MyOverlapped* overlapped) {}
	virtual void DoConnect(MyOverlapped* overlapped) {}
	void DoDisConnect(MyOverlapped* overlapped);
	void DoRecv(MyOverlapped* overlapped);
protected:
	int m_BackLog;
};

