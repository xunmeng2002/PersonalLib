#include "ShmClient.h"
#include "Logger.h"
#include <string.h>

using namespace std;

ShmClient::ShmClient(const char* threadName, const char* shmName, int milliSeconds)
	:ShmBase(ServerTypeType::Client, threadName, shmName, milliSeconds), m_HasSendConnected(false), m_ShmConnect(nullptr)
{
}
ShmClient::~ShmClient()
{
	m_ShmConnect = nullptr;
}


void ShmClient::Run()
{
	Connect();
	CheckConnect();
	DoDisConnect();
	if (m_Connected)
	{
		unique_lock guard(m_Mutex);
		m_ThreadConditionVariable.wait_for(guard, m_TimeOut, [&]() {return m_ShmConnect->m_ShmBuffer->GetReadBufferSize() > 0; });
		DoRecv(m_ShmConnect->SessionID);
	}
	else
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(m_TimeOut));
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
			WriteLog(LogLevel::Info, "Sem Lock Failed. Sleep 10ms\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
				m_ShmConnect = ShmConnect<ShmBuffSize>::Allocate(GetSessionID(), m_Address.c_str(), index, m_ServerType, m_ShmAddr, ConnectStatusType::Connected);
				AddConnect(m_ShmConnect);
				m_Connected = true;
				m_CommonShmHeader->Status = ConnectStatusType::UnConnected;
			}
			else if (m_CommonShmHeader->Status == ConnectStatusType::Rejected)
			{
				m_CommonShmHeader->Status = ConnectStatusType::UnConnected;
			}
			else
			{
				WriteLog(LogLevel::Info, "UnExpected Status:%d\n", (int)m_CommonShmHeader->Status);
			}
			m_Sem->UnLock();
			if (!m_Connected)
			{
				WriteLog(LogLevel::Info, "Connect Failed. Sleep 1s\n");
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
		else
		{
			WriteLog(LogLevel::Info, "Sem Lock Failed. Sleep 10ms\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}
void ShmClient::CheckConnect()
{
	if (!m_Connected)
		return;
	if (m_ShmConnect->m_ShmBuffer->m_ShmHeader->Status == ConnectStatusType::DisConnected)
	{
		RemoveConnect(m_ShmConnect);
	}
}

void ShmClient::RemoveConnect(::Connect* connect)
{
	ShmBase::RemoveConnect(connect);
	m_Connected = false;
	m_HasSendConnected = false;
	m_ShmConnect = nullptr;
}
