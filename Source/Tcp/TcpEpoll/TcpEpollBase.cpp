#include "TcpEpollBase.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>

TcpEpollBase::TcpEpollBase(ServerTypeType serverType, const char* addressName, int milliSeconds)
	:TcpBase(serverType, addressName, milliSeconds), m_EpollFd(0)
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
	int number = epoll_wait(m_EpollFd, m_EpollEvents, EpollEventNumber, m_TimeOut.count());
	if (number < 0 && errno != EINTR)
	{
		WriteLog(LogLevel::Info, "epoll wait failed. number:%d, errno:%d\n", number, errno);
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
			DoRecv(tcpConnect);
		}
		else if (epollEvent.events & EPOLLOUT)
		{
			int error = 0;
			socklen_t len = sizeof(error);
			int ret = getsockopt(tcpConnect->SocketID, SOL_SOCKET, SO_ERROR, &error, &len);
			if (ret == -1)
			{
				WriteLog(LogLevel::Warning, "getsockopt Failed. SessionID:%lld, SocketID:%lld", tcpConnect->SessionID, tcpConnect->SocketID);
				RemoveConnect(tcpConnect);
				continue;
			}
			if (errno != 0)
			{
				WriteLog(LogLevel::Warning, "Connect Failed. SessionID:%lld, SocketID:%lld, errno:%d", tcpConnect->SessionID, tcpConnect->SocketID, errno);
				RemoveConnect(tcpConnect);
				continue;
			}
			else
			{
				RemoveEpollEvent(tcpConnect);
				AddConnect(tcpConnect);
			}
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

