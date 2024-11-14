#include "ShmServer.h"
#include <string.h>


ShmServer::ShmServer(const char* threadName, const char* shmName)
	:ShmBase(ServerTypeType::Server, threadName, shmName), m_ConnectCount(0)
{

}
ShmServer::~ShmServer()
{

}
void ShmServer::Run()
{
	Accept();
	CheckConnect();
	DoDisConnect();
	HandleEvent();
}
void ShmServer::Accept()
{
	switch (m_CommonShmHeader->Status)
	{
	case 0:
	{
		if (m_ConnectCount >= m_MaxConnectSize - 1)
		{
			m_CommonShmHeader->Status = 3;
		}
		break;
	}
	case 1:
	{
		m_Sem->Lock();
		if (m_ConnectCount >= m_MaxConnectSize - 1)
		{
			m_CommonShmHeader->Status = 3;
			m_Sem->UnLock();
			break;
		}
		for (auto i = 1U; i < m_MaxConnectSize; ++i)
		{
			auto shmHeader = m_CommonShmHeader + i;
			if (shmHeader->Status == 0)
			{
				memset(shmHeader, 0, sizeof(SingleShmHeader));
				shmHeader->Status = 2;

				m_CommonShmHeader->Status = 2;
				m_CommonShmHeader->DownWriteCount = i;
				++m_ConnectCount;

				AddConnect(i);
				break;
			}
		}
		m_Sem->UnLock();
		break;
	}
	case 2:
		break;
	case 3:
	{
		if (m_ConnectCount < m_MaxConnectSize - 1)
		{
			m_CommonShmHeader->Status = 0;
		}
		break;
	}
	default:
		break;
	}
}