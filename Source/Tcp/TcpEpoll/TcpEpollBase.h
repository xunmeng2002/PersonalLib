#pragma once
#include "TcpBase.h"
#include "TcpConnect.h"
#include <list>
#include <map>
#ifdef LINUX
#include <sys/epoll.h>
#endif


#define EpollEventNumber 1024

class TcpEpollBase
{
public:
	TcpEpollBase();
	~TcpEpollBase();
	
protected:
	void AddEpollEvent(TcpConnect* connectData);
	void RemoveEpollEvent(TcpConnect* connectData);

protected:
	int m_EpollFd;
#ifdef LINUX
	epoll_event m_EpollEvents[EpollEventNumber];
#endif
};

