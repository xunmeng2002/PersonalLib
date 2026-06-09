#pragma once
#include <PersonalLib/Network/NetworkExport.h>
#include <PersonalLib/Network/Tcp/TcpEpoll/TcpEpollBase.h>


class NETWORK_EXPORTS TcpEpollServer : public TcpEpollBase
{
public:
	TcpEpollServer(const char* addressName, int milliSeconds);
	~TcpEpollServer();

	virtual bool Init() override;

};
