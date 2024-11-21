#include "TcpSelectBase.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectBase::TcpSelectBase(ServerTypeType serverType, const char* threadName, const char* addressName)
	:TcpBase(serverType, threadName, addressName)
{
	FD_ZERO(&m_RecvFds);
	m_MaxID = 0;
	m_SelectSocketTimeOut.tv_sec = 0;
	m_SelectSocketTimeOut.tv_usec = 100 * 1000;
	m_SelectSocketTimeOutTemp.tv_sec = 0;
	m_SelectSocketTimeOutTemp.tv_usec = 100 * 1000;
}
void TcpSelectBase::SetSelectTimeOut(int milliSeconds)
{
	m_SelectSocketTimeOut.tv_sec = milliSeconds / 1000;
	m_SelectSocketTimeOut.tv_usec = (milliSeconds % 1000) * 1000;
	memcpy(&m_SelectSocketTimeOutTemp, &m_SelectSocketTimeOut, sizeof(timeval));
}
void TcpSelectBase::PrepareFds()
{
	FD_ZERO(&m_RecvFds);
	m_MaxID = 0;
	for (auto& it : m_Connects)
	{
		auto connect = (TcpConnect*)it.second;
		FD_SET(connect->SocketID, &m_RecvFds);
		if (connect->SocketID > m_MaxID)
		{
			m_MaxID = connect->SocketID;
		}
	}
	if (m_ServerType == ServerTypeType::Server)
	{
		FD_SET(m_Socket, &m_RecvFds);
		if (m_Socket > m_MaxID)
		{
			m_MaxID = m_Socket;
		}
	}
	++m_MaxID;
}
void TcpSelectBase::HandleTcpEvent()
{
	PrepareFds();
	memcpy(&m_SelectSocketTimeOutTemp, &m_SelectSocketTimeOut, sizeof(timeval));
	::select((int)m_MaxID, &m_RecvFds, nullptr, nullptr, &m_SelectSocketTimeOutTemp);
	for (auto& it : m_Connects)
	{
		auto connect = (TcpConnect*)it.second;
		if (FD_ISSET(connect->SocketID, &m_RecvFds))
		{
			DoRecv(connect);
		}
	}
	if (m_ServerType == ServerTypeType::Server)
	{
		if (FD_ISSET(m_Socket, &m_RecvFds))
		{
			DoAccept();
		}
	}
}

