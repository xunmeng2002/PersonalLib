#pragma once
#include <PersonalLib/Network/NetworkExport.h>
#include <list>
#include <map>
#include <PersonalLib/Network/Tcp/SocketInit.h>
#include <PersonalLib/Network/Tcp/TcpBase.h>


class NETWORK_EXPORTS TcpSelectBase : public TcpBase
{
public:
	TcpSelectBase(ServerTypeType serverType, const char* addressName, int milliSeconds);
	virtual void SetTimeOut(int milliSeconds) override;
protected:
	virtual void PrepareFds();
	virtual void HandleTcpEvent() override;

protected:
	fd_set m_ReadFds;
	fd_set m_WriteFds;
	fd_set m_ErrorFds;
	SOCKET m_MaxID;
	timeval m_SelectSocketTimeOut;
	timeval m_SelectSocketTimeOutTemp;
};
