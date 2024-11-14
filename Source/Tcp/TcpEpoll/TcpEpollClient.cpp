#include "TcpEpollClient.h"
#include "Logger.h"


TcpEpollClient::TcpEpollClient(const char* threadName, const char* addressName)
	:TcpClientBase(threadName, addressName)
{
}
TcpEpollClient::~TcpEpollClient()
{
	for (auto& item : m_ConnectDatas)
	{
		RemoveEpollEvent(item.second);
	}
}
void TcpEpollClient::HandleTcpEvent()
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
		if (epollEvent.events & EPOLLIN)
		{
			DoRecv(connectData);
		}
	}
#endif
}

void TcpEpollClient::AddConnect(ConnectData* connectData)
{
	TcpClientBase::AddConnect(connectData);
	AddEpollEvent(connectData);
}
void TcpEpollClient::RemoveConnect(ConnectData* connectData)
{
	RemoveEpollEvent(connectData);
	TcpClientBase::RemoveConnect(connectData);
}

