#pragma once
#include "PersonalLib/Network/NetworkExport.h"
#include "PersonalLib/Network/Tcp/TcpSelect/TcpSelectBase.h"


class NETWORK_EXPORTS TcpSelectClient : public TcpSelectBase
{
public:
	TcpSelectClient(const char* addressName, int milliSeconds);

	virtual bool ConnectToServer(const char* ip, unsigned short port) override;

	void CheckConnect();

protected:
	fd_set m_WriteFds;

	std::map<SessionIDType, TcpConnect*> m_Connectings;
	std::list<SessionIDType> m_ConnectSuccessedSessions;
	std::list<SessionIDType> m_ConnectFailedSessions;
};

