#include "TcpSelectClient.h"
#include "TcpUtility.h"
#include "Logger.h"
#include <cstring>


TcpSelectClient::TcpSelectClient(const char* threadName, const char* addressName)
	:TcpClientBase(threadName, addressName)
{
}
void TcpSelectClient::HandleTcpEvent()
{
	DoDisConnect();
	PrepareFds();
	memcpy(&m_SelectSocketTimeOutTemp, &m_SelectSocketTimeOut, sizeof(timeval));
	::select((int)m_MaxID, &m_RecvFds, nullptr, nullptr, &m_SelectSocketTimeOutTemp);
	for (auto& it : m_ConnectDatas)
	{
		auto connectData = it.second;
		if (FD_ISSET(connectData->SocketID, &m_RecvFds))
		{
			DoRecv(connectData);
		}
	}
}

void TcpSelectClient::PrepareFds()
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
	++m_MaxID;
}


