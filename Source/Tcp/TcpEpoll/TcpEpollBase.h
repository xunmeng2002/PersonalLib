#pragma once
#include "TcpBase.h"
#include "ConnectData.h"
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
	void AddEpollEvent(ConnectData* connectData);
	void RemoveEpollEvent(ConnectData* connectData);

protected:
	int m_EpollFd;
#ifdef LINUX
	epoll_event m_EpollEvents[EpollEventNumber];
#endif
};

