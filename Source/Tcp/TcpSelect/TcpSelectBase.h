#pragma once
#include <list>
#include <map>
#include "SocketInit.h"



class TcpSelectBase
{
public:
	TcpSelectBase();
	void SetSelectTimeOut(int milliSeconds);
protected:
	virtual void PrepareFds() = 0;

protected:
	fd_set m_RecvFds;
	SOCKET m_MaxID;
	timeval m_SelectSocketTimeOut;
	timeval m_SelectSocketTimeOutTemp;
};
