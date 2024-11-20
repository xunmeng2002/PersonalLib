#include "TcpBase.h"
#include "Platform.h"
#include "Logger.h"
#include "TcpUtility.h"
#include "TimeUtility.h"
#include <cstring>
#include <assert.h>


TcpBase::TcpBase(const char* threadName, const char* addressName)
	:IOThread(threadName, addressName), m_RemoteAddressLen(sizeof(m_RemoteAddress))
{
	memset(&m_RemoteAddress, 0, sizeof(m_RemoteAddress));
}
TcpBase::~TcpBase()
{
	for (auto& item : m_ConnectDatas)
	{
		item.second->Free();
	}
	m_ConnectDatas.clear();
}


int TcpBase::Send(SessionIDType sessionID, const char* data, unsigned len)
{
	auto connectData = GetConnect(sessionID);
	if (!connectData)
	{
		return -1;
	}
	return send(connectData->SocketID, data, len, 0);
}
int TcpBase::Send(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
	auto connectData = GetConnect(sessionID);
	if (!connectData)
	{
		return -1;
	}
	return send(connectData->SocketID, buffer->GetReadPos(), buffer->GetLength(), 0);
}

void TcpBase::ThreadExit()
{
	std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
	if (m_IOSubscriber)
	{
		for (auto& it : m_ConnectDatas)
		{
			m_IOSubscriber->OnDisConnect(it.second->SessionID, it.second->RemoteIP, it.second->RemotePort);
			it.second->Free();
		}
	}
	m_ConnectDatas.clear();
	ThreadBase::ThreadExit();
}
void TcpBase::DoDisConnect()
{
	if (m_DisConnectSessionIDs.empty())
		return;
	
	std::lock_guard<std::mutex> guard(m_DisConnectSessionIDsMutex);
	for (auto sessionID : m_DisConnectSessionIDs)
	{
		auto connectData = GetConnect(sessionID);
		if (connectData != nullptr)
		{
			RemoveConnect(connectData);
		}
	}
	m_DisConnectSessionIDs.clear();
}
void TcpBase::DoRecv(ConnectData* connectData)
{
	Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
	auto data = buffer->GetData();
	int len = recv(connectData->SocketID, data, BuffSize - 1, 0);
	if (len <= 0)
	{
		WriteLog(LogLevel::Info, "DisConnect For Recv. SessionID[%lld], ErrorID[%d]", connectData->SessionID, len);
		buffer->Free();
		DisConnect(connectData->SessionID);
	}
	else if (m_IOSubscriber)
	{
		data[len] = '\0';
		WriteLog(LogLevel::Ignore, "OnRecv: SessionID[%lld], RecvLen[%d]", connectData->SessionID, len);
		buffer->SetLength(len);
		
		m_IOSubscriber->OnRecv(connectData->SessionID, buffer);
	}
}
void TcpBase::AddConnect(ConnectData* connectData)
{
	WriteLog(LogLevel::Info, "New Connection. SessionID[%lld], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP, connectData->RemotePort);
	{
		std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
		m_ConnectDatas.insert(std::make_pair(connectData->SessionID, connectData));
	}
	if (m_IOSubscriber)
	{
		m_IOSubscriber->OnConnect(connectData->SessionID, connectData->RemoteIP, connectData->RemotePort);
	}
}
void TcpBase::RemoveConnect(ConnectData* connectData)
{
	WriteLog(LogLevel::Info, "RemoveConnect. SessionID[%lld], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP, connectData->RemotePort);
	if (m_IOSubscriber)
	{
		m_IOSubscriber->OnDisConnect(connectData->SessionID, connectData->RemoteIP, connectData->RemotePort);
	}
	std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
	m_ConnectDatas.erase(connectData->SessionID);
	connectData->Free();
}
ConnectData* TcpBase::GetConnect(SessionIDType sessionID)
{
	std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
	if (m_ConnectDatas.find(sessionID) == m_ConnectDatas.end())
	{
		WriteLog(LogLevel::Warning, "Connect not Exist For SessionID[%lld]", sessionID);
		return nullptr;
	}
	return m_ConnectDatas[sessionID];
}


bool TcpBase::InitSocket(SOCKET socketID)
{
	if (!SetSockUnblock(socketID) || !SetSockReuse(socketID)|| !SetSockNodelay(socketID))
	{
		WriteLog(LogLevel::Warning, "InitSocket Failed. ErrorID[%d]", GetLastError());
		return false;
	}
	return true;
}
SOCKET TcpBase::PrepareSocket(int family)
{
	auto socketID = socket(family, SOCK_STREAM, IPPROTO_TCP);
	if (!InitSocket(socketID))
	{
		closesocket(socketID);
		return INVALID_SOCKET;
	}
	return socketID;
}
