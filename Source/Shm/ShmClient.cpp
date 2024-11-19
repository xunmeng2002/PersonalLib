#include "ShmClient.h"
#include <string.h>

using namespace std;

ShmClient::ShmClient(const char* threadName, const char* shmName)
	:ShmBase(ServerTypeType::Client, threadName, shmName), m_Connected(false), m_HasSendConnected(false), m_SessionID(0LL), m_ShmConnect(nullptr)
{
}
ShmClient::~ShmClient()
{
	if (m_ShmConnect != nullptr)
	{
		m_ShmConnect->ShmBuffer->m_ShmHeader->Status = ConnectStatusType::DisConnected;
		m_IOSubscriber->OnDisConnect(m_ShmConnect->SessionID, m_ShmName.c_str(), std::to_string(m_ShmConnect->Index).c_str());
		m_ShmConnect->Free();
		m_ShmConnect = nullptr;
	}
}


void ShmClient::Run()
{
	Connect();
	CheckConnect();
	DoDisConnect();
	if (m_Connected)
	{
		DoRecv(m_ShmConnect);
	}
}

void ShmClient::Connect()
{
	if (m_Connected)
		return;
	if (!m_HasSendConnected && m_CommonShmHeader->Status == ConnectStatusType::UnConnected)
	{
		if (m_Sem->Lock())
		{
			if (m_CommonShmHeader->Status == ConnectStatusType::UnConnected)
			{
				m_CommonShmHeader->Status = ConnectStatusType::Connecting;
				m_HasSendConnected = true;
			}
			m_Sem->UnLock();
		}
		else
		{
			printf("Sem Lock Failed.\n");
		}
	}
	else if (m_HasSendConnected && m_CommonShmHeader->Status != ConnectStatusType::Connecting)
	{
		if (m_Sem->Lock())
		{
			m_HasSendConnected = false;
			if (m_CommonShmHeader->Status == ConnectStatusType::Accepted)
			{
				auto index = m_CommonShmHeader->DownWriteCount;
				m_CommonShmHeader->Status = ConnectStatusType::UnConnected;
				m_ShmConnect = AddConnect(index);
				m_ShmConnect->ShmBuffer->m_ShmHeader->Status = ConnectStatusType::Connected;
				m_Connected = true;
			}
			else if (m_CommonShmHeader->Status == ConnectStatusType::Rejected)
			{
				m_CommonShmHeader->Status = ConnectStatusType::UnConnected;
			}
			else
			{
				printf("UnExpected Status:%d\n", (int)m_CommonShmHeader->Status);
			}
			m_Sem->UnLock();
			if (!m_Connected)
			{
				printf("Connect Failed. Sleep 5s\n");
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}
		else
		{
			printf("Sem Lock Failed.\n");
		}
	}
}
void ShmClient::CheckConnect()
{
	if (!m_Connected)
		return;
	lock_guard<mutex> guard(m_ShmConnectsMutex);
	if (m_ShmConnect->ShmBuffer->m_ShmHeader->Status == ConnectStatusType::DisConnected)
	{
		RemoveConnect(m_ShmConnect);
	}
}
void ShmClient::DoDisConnect()
{
	if (m_DisConnectSessionIDs.empty())
		return;

	RemoveConnect(m_ShmConnect);

	lock_guard<mutex> guard(m_DisConnectSessionIDsMutex);
	m_DisConnectSessionIDs.clear();
}

void ShmClient::RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect)
{
	ShmBase::RemoveConnect(shmConnect);
	m_Connected = false;
	m_HasSendConnected = false;
}
ShmConnect<ShmBuffSize>* ShmClient::GetShmConnect(SessionIDType sessionID)
{
	return m_ShmConnect;
}
