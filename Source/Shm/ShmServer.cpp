#include "ShmServer.h"
#include <string.h>

using namespace std;

ShmServer::ShmServer(const char* threadName, const char* shmName)
	:ShmBase(ServerTypeType::Server, threadName, shmName), m_ConnectCount(0)
{

}
ShmServer::~ShmServer()
{
	{
		lock_guard<mutex> guard(m_ShmConnectsMutex);
		for (auto& it : m_ShmConnects)
		{
			auto shmConnect = it.second;
			shmConnect->ShmBuffer->m_ShmHeader->Status = ConnectStatusType::UnConnected;
			m_IOSubscriber->OnDisConnect(shmConnect->SessionID, m_ShmName.c_str(), std::to_string(shmConnect->Index).c_str());
			shmConnect->Free();
		}
		m_ShmConnects.clear();
	}
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
	case ConnectStatusType::UnConnected:
		break;
	case ConnectStatusType::Connecting:
	{
		if (m_Sem->Lock())
		{
			if (m_ConnectCount >= m_MaxConnectSize - 1)
			{
				m_CommonShmHeader->Status = ConnectStatusType::Rejected;
			}
			else
			{
				for (auto i = 1U; i < m_MaxConnectSize; ++i)
				{
					auto shmHeader = m_CommonShmHeader + i;
					if (shmHeader->Status == ConnectStatusType::UnConnected)
					{
						memset(shmHeader, 0, sizeof(SingleShmHeader));
						shmHeader->Status = ConnectStatusType::Accepted;

						m_CommonShmHeader->Status = ConnectStatusType::Accepted;
						m_CommonShmHeader->DownWriteCount = i;
						++m_ConnectCount;

						AddConnect(i);
						break;
					}
				}
			}
			m_LastWriteTimePoint = chrono::system_clock::now();
			m_Sem->UnLock();
		}
		else
		{
			printf("Sem Lock Failed.\n");
		}
		break;
	}
	case ConnectStatusType::Accepted:
	case ConnectStatusType::Rejected:
	{
		auto currTimePoint = chrono::system_clock::now();
		auto t = chrono::duration_cast<chrono::seconds>(currTimePoint - m_LastWriteTimePoint);
		if (t.count() >= 5)
		{
			if (m_Sem->Lock())
			{
				if (m_CommonShmHeader->Status == ConnectStatusType::Accepted || m_CommonShmHeader->Status == ConnectStatusType::Rejected)
				{
					printf("Reset Connect From Server,  Status:%d\n", (int)m_CommonShmHeader->Status);
					if (m_CommonShmHeader->Status == ConnectStatusType::Accepted)
					{
						auto index = m_CommonShmHeader->DownWriteCount;
						auto shmHeader = m_CommonShmHeader + index;
						memset(shmHeader, 0, sizeof(SingleShmHeader));
					}
					m_CommonShmHeader->Status = ConnectStatusType::UnConnected;
				}
				m_Sem->UnLock();
			}
			else
			{
				printf("Sem Lock Failed.\n");
			}
		}
	}
		break;
	case ConnectStatusType::Connected:
	case ConnectStatusType::DisConnected:
		break;
	default:
		break;
	}
}
void ShmServer::CheckConnect()
{
	lock_guard<mutex> guard(m_ShmConnectsMutex);
	lock_guard<mutex> guard2(m_DisConnectSessionIDsMutex);
	for (auto& it : m_ShmConnects)
	{
		auto shmConnect = it.second;
		if (shmConnect->ShmBuffer->m_ShmHeader->Status == ConnectStatusType::DisConnected)
		{
			m_DisConnectSessionIDs.push_back(shmConnect->SessionID);
		}
	}
}
void ShmServer::DoDisConnect()
{
	if (m_DisConnectSessionIDs.empty())
		return;

	lock_guard<mutex> guard2(m_ShmConnectsMutex);
	lock_guard<mutex> guard(m_DisConnectSessionIDsMutex);
	for (auto sessionID : m_DisConnectSessionIDs)
	{
		auto shmConnect = m_ShmConnects[sessionID];
		if (shmConnect == nullptr)
		{
			m_ShmConnects.erase(sessionID);
		}
		else
		{
			RemoveConnect(shmConnect);
		}
	}
	m_DisConnectSessionIDs.clear();
}
void ShmServer::HandleEvent()
{
	for (auto& it : m_ShmConnects)
	{
		auto shmConnect = it.second;
		if (shmConnect->ShmBuffer->GetReadBufferSize() > 0)
		{
			DoRecv(shmConnect);
		}
	}
}

ShmConnect<ShmBuffSize>* ShmServer::AddConnect(int index)
{
	auto shmConnect = ShmBase::AddConnect(index);
	lock_guard<mutex> guard(m_ShmConnectsMutex);
	m_ShmConnects.insert(make_pair(shmConnect->SessionID, shmConnect));
	return shmConnect;
}
void ShmServer::RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect)
{
	ShmBase::RemoveConnect(shmConnect);
	--m_ConnectCount;
	shmConnect->Free();
	m_ShmConnects.erase(shmConnect->SessionID);
}
ShmConnect<ShmBuffSize>* ShmServer::GetShmConnect(SessionIDType sessionID)
{
	std::lock_guard<mutex> guard(m_ShmConnectsMutex);
	if (m_ShmConnects.find(sessionID) != m_ShmConnects.end())
		return m_ShmConnects[sessionID];
	return nullptr;
}
