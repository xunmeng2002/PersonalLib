#include "TcpEpollServer.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>


TcpEpollServer::TcpEpollServer(const char* threadName, const char* addressName)
	:TcpServerBase(threadName, addressName)
{
}
TcpEpollServer::~TcpEpollServer()
{
	for (auto& item : m_ConnectDatas)
	{
		RemoveEpollEvent(item.second);
	}
}
bool TcpEpollServer::Init()
{
	if (!TcpServerBase::Init())
	{
		return false;
	}
	ConnectData* connectData = ConnectData::Allocate(0, m_ListenSocket, m_BindIP, m_BindPort);
	AddEpollEvent(connectData);
	return true;
}

void TcpEpollServer::HandleTcpEvent()
{
#ifdef LINUX
	DoDisConnect();
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
		auto connectData = (ConnectData*)m_EpollEvents[i].data.ptr;
		if (connectData->SocketID == m_ListenSocket)
		{
			DoAccept();
		}
		else if (epollEvent.events & EPOLLIN)
		{
			DoRecv(connectData);
		}
	}
#endif
}

void TcpEpollServer::AddConnect(ConnectData* connectData)
{
	TcpServerBase::AddConnect(connectData);
	AddEpollEvent(connectData);
}
void TcpEpollServer::RemoveConnect(ConnectData* connectData)
{
	RemoveEpollEvent(connectData);
	TcpServerBase::RemoveConnect(connectData);
}

