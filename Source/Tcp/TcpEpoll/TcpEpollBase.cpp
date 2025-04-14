#include "TcpEpollBase.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>

TcpEpollBase::TcpEpollBase(ServerTypeType serverType, const char* threadName, const char* addressName, int milliSeconds)
	:TcpBase(serverType, threadName, addressName, milliSeconds), m_EpollFd(0)
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

void TcpEpollBase::HandleTcpEvent()
{
#ifdef LINUX
	int eventNum = sizeof(m_EpollEvents) / sizeof(epoll_event);
	int number = epoll_wait(m_EpollFd, m_EpollEvents, eventNum, m_TimeOut.count());
	if (number < 0 && errno != EINTR)
	{
		WriteLog(LogLevel::Info, "epoll wait failed. number:[%d], errno:[%d]\n", number, errno);
		return;
	}
	for (int i = 0; i < number; i++)
	{
		auto epollEvent = m_EpollEvents[i];
		auto tcpConnect = (TcpConnect*)m_EpollEvents[i].data.ptr;
		if (m_ServerType == ServerTypeType::Server && tcpConnect->SocketID == m_Socket)
		{
			DoAccept();
		}
		else if (epollEvent.events & EPOLLIN)
		{
			DoRecv(tcpConnect->SessionID);
		}
	}
#endif
}
void TcpEpollBase::AddConnect(::Connect* connect)
{
	TcpBase::AddConnect(connect);
	AddEpollEvent((TcpConnect*)connect);
}
void TcpEpollBase::RemoveConnect(::Connect* connect)
{
	RemoveEpollEvent((TcpConnect*)connect);
	TcpBase::RemoveConnect(connect);
}

void TcpEpollBase::AddEpollEvent(TcpConnect* connect)
{
#ifdef LINUX
	epoll_event epollEvent;
	epollEvent.data.ptr = connect;
	epollEvent.events = EPOLLIN;
	epoll_ctl(m_EpollFd, EPOLL_CTL_ADD, connect->SocketID, &epollEvent);
#endif
}
void TcpEpollBase::RemoveEpollEvent(TcpConnect* connect)
{
#ifdef LINUX
	epoll_ctl(m_EpollFd, EPOLL_CTL_DEL, connect->SocketID, NULL);
#endif
}


