#include "ShmClient.h"
#include <string.h>


ShmClient::ShmClient(const char* threadName, const char* shmName)
	:ShmBase(ServerTypeType::Client, threadName, shmName), m_Connected(false), m_HasSendConnected(false)
{
}
ShmClient::~ShmClient()
{
}


void ShmClient::Run()
{
	Connect();
	CheckConnect();
	DoDisConnect();
	HandleEvent();
}
void ShmClient::Connect()
{
	if (m_Connected)
		return;
	m_Sem->Lock();
	if (!m_HasSendConnected && m_CommonShmHeader->Status == 0)
	{
		m_CommonShmHeader->Status = 1;
		m_HasSendConnected = true;
		m_Sem->UnLock();
	}
	else if (m_HasSendConnected && m_CommonShmHeader->Status == 2)
	{
		m_Connected = true;
		m_HasSendConnected = false;
		auto index = m_CommonShmHeader->DownWriteCount;
		m_CommonShmHeader->Status = 0;
		m_Sem->UnLock();
		
		AddConnect(index);
	}
	else
	{
		m_Sem->UnLock();
	}
}
void ShmClient::RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect)
{
	m_Connected = false;
	ShmBase::RemoveConnect(shmConnect);
}

