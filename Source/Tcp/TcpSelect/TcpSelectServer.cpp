#include "TcpSelectServer.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectServer::TcpSelectServer(const char* threadName, const char* addressName)
	:TcpServerBase(threadName, addressName)
{
}
void TcpSelectServer::HandleTcpEvent()
{
	DoDisConnect();
	PrepareFds();
	memcpy(&m_SelectSocketTimeOutTemp, &m_SelectSocketTimeOut, sizeof(timeval));
	::select((int)m_MaxID, &m_RecvFds, nullptr, nullptr, &m_SelectSocketTimeOutTemp);
	if (FD_ISSET(m_ListenSocket, &m_RecvFds))
	{
		DoAccept();
	}
	for (auto& it : m_ConnectDatas)
	{
		auto connectData = it.second;
		if (FD_ISSET(connectData->SocketID, &m_RecvFds))
		{
			DoRecv(connectData);
		}
	}
}

void TcpSelectServer::PrepareFds()
{
	FD_ZERO(&m_RecvFds);
	m_MaxID = 0;
	for (auto& it : m_ConnectDatas)
	{
		FD_SET(it.second->SocketID, &m_RecvFds);
		if (it.second->SocketID > m_MaxID)
		{
			m_MaxID = it.second->SocketID;
		}
	}
	FD_SET(m_ListenSocket, &m_RecvFds);
	if (m_ListenSocket > m_MaxID)
	{
		m_MaxID = m_ListenSocket;
	}
	++m_MaxID;
}

