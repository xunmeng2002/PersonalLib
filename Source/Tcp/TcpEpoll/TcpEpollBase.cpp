#include "TcpEpollBase.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>

TcpEpollBase::TcpEpollBase()
{
#ifdef LINUX
	m_EpollFd = epoll_create(5);
#endif
}
TcpEpollBase::~TcpEpollBase()
{
#ifdef LINUX
	close(m_EpollFd);
#endif
}


void TcpEpollBase::AddEpollEvent(ConnectData* connectData)
{
#ifdef LINUX
	epoll_event epollEvent;
	epollEvent.data.ptr = connectData;
	epollEvent.events = EPOLLIN;
	epoll_ctl(m_EpollFd, EPOLL_CTL_ADD, connectData->SocketID, &epollEvent);
#endif
}
void TcpEpollBase::RemoveEpollEvent(ConnectData* connectData)
{
#ifdef LINUX
	epoll_ctl(m_EpollFd, EPOLL_CTL_DEL, connectData->SocketID, NULL);
#endif
}


