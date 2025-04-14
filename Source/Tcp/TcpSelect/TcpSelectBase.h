#pragma once
#include <list>
#include <map>
#include "SocketInit.h"
#include "TcpBase.h"


class TcpSelectBase : public TcpBase
{
public:
	TcpSelectBase(ServerTypeType serverType, const char* threadName, const char* addressName, int milliSeconds);
	void SetTimeOut(int milliSeconds);
protected:
	virtual void PrepareFds();
	virtual void HandleTcpEvent() override;

protected:
	fd_set m_RecvFds;
	SOCKET m_MaxID;
	timeval m_SelectSocketTimeOut;
	timeval m_SelectSocketTimeOutTemp;
};
