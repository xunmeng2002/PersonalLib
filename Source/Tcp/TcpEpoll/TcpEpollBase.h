#pragma once
#include "TcpBase.h"
#include "TcpConnect.h"
#include <list>
#include <map>
#ifdef LINUX
#include <sys/epoll.h>
#endif


#define EpollEventNumber 1024

class TcpEpollBase : public TcpBase
{
public:
	TcpEpollBase(ServerTypeType serverType, const char* threadName, const char* addressName);
	~TcpEpollBase();
	
protected:
	virtual void HandleTcpEvent() override;

	virtual void AddConnect(::Connect* connect) override;
	virtual void RemoveConnect(::Connect* connect) override;
	

	void AddEpollEvent(Connect* connect);
	void RemoveEpollEvent(Connect* connect);

protected:
	int m_EpollFd;
#ifdef LINUX
	epoll_event m_EpollEvents[EpollEventNumber];
#endif
};

