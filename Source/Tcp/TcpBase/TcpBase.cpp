#include "TcpBase.h"
#include "Platform.h"
#include "Logger.h"
#include "TcpUtility.h"
#include "TimeUtility.h"
#include <cstring>
#include <assert.h>


TcpBase::TcpBase(ServerTypeType serverType, const char* threadName, const char* addressName)
	:IOThread(serverType, threadName, addressName), m_RemoteAddressLen(sizeof(m_RemoteAddress))
{
	memset(&m_RemoteAddress, 0, sizeof(m_RemoteAddress));
	ParseIPAddress(m_AddressName, m_IP, m_Port);
}
TcpBase::~TcpBase()
{
	for (auto& item : m_ConnectDatas)
	{
		item.second->Free();
	}
	m_ConnectDatas.clear();
}

bool TcpBase::Init()
{
	auto ret = GetAddrinfo(m_IP.c_str(), m_Port.c_str(), m_AddressInfo);
	if (ret < 0)
	{
		WriteLog(LogLevel::Info, "GetAddrinfo Failed. IP:[%s] Port[%s] ret[%d] Errno[%d]", m_IP.c_str(), m_Port.c_str(), ret, errno);
		return false;
	}
		
	m_Socket = PrepareSocket(m_AddressInfo->ai_family);
	if (m_Socket == INVALID_SOCKET)
	{
		return false;
	}
	if (m_ServerType == ServerTypeType::Server)
	{
		if (!Bind(m_Socket, m_AddressInfo))
		{
			return false;
		}
		return Listen(m_Socket);
	}
	return true;
}
int TcpBase::Send(SessionIDType sessionID, const char* data, unsigned len)
{
	auto tcpConnect = GetConnect(sessionID);
	if (!tcpConnect)
	{
		return -1;
	}
	return send(tcpConnect->SocketID, data, len, 0);
}
int TcpBase::Send(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
	auto tcpConnect = GetConnect(sessionID);
	if (!tcpConnect)
	{
		return -1;
	}
	return send(tcpConnect->SocketID, buffer->GetReadPos(), buffer->GetLength(), 0);
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
void TcpBase::DoRecv(TcpConnect* tcpConnect)
{
	Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
	auto data = buffer->GetData();
	int len = recv(tcpConnect->SocketID, data, BuffSize - 1, 0);
	if (len <= 0)
	{
		WriteLog(LogLevel::Info, "DisConnect For Recv. SessionID[%lld], ErrorID[%d]", tcpConnect->SessionID, len);
		buffer->Free();
		DisConnect(tcpConnect->SessionID);
	}
	else if (m_IOSubscriber)
	{
		data[len] = '\0';
		WriteLog(LogLevel::Ignore, "OnRecv: SessionID[%lld], RecvLen[%d]", tcpConnect->SessionID, len);
		buffer->SetLength(len);
		
		m_IOSubscriber->OnRecv(tcpConnect->SessionID, buffer);
	}
}
void TcpBase::AddConnect(TcpConnect* tcpConnect)
{
	WriteLog(LogLevel::Info, "New Connection. SessionID[%lld], Socket[%lld], RemoteIP[%s], RemotePort[%s]", tcpConnect->SessionID, tcpConnect->SocketID, tcpConnect->RemoteIP, tcpConnect->RemotePort);
	{
		std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
		m_ConnectDatas.insert(std::make_pair(tcpConnect->SessionID, tcpConnect));
	}
	if (m_IOSubscriber)
	{
		m_IOSubscriber->OnConnect(tcpConnect->SessionID, tcpConnect->RemoteIP, tcpConnect->RemotePort);
	}
}
void TcpBase::RemoveConnect(TcpConnect* tcpConnect)
{
	WriteLog(LogLevel::Info, "RemoveConnect. SessionID[%lld], Socket[%lld], RemoteIP[%s], RemotePort[%s]", tcpConnect->SessionID, tcpConnect->SocketID, tcpConnect->RemoteIP, tcpConnect->RemotePort);
	if (m_IOSubscriber)
	{
		m_IOSubscriber->OnDisConnect(tcpConnect->SessionID, tcpConnect->RemoteIP, tcpConnect->RemotePort);
	}
	std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
	m_ConnectDatas.erase(tcpConnect->SessionID);
	tcpConnect->Free();
}
TcpConnect* TcpBase::GetConnect(SessionIDType sessionID)
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
