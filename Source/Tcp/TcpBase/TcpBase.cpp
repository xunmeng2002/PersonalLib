#include "TcpBase.h"
#include "Platform.h"
#include "Logger.h"
#include "TcpUtility.h"
#include "TimeUtility.h"
#include <cstring>
#include <assert.h>
#include <chrono>

using namespace std;

TcpBase::TcpBase(ServerTypeType serverType, const char* addressName, int milliSeconds)
	:IOBase(serverType, addressName, milliSeconds), m_AddressInfo(nullptr), m_Socket(INVALID_SOCKET), m_RemoteAddressLen(sizeof(m_RemoteAddress))
{
	memset(&m_RemoteAddress, 0, sizeof(m_RemoteAddress));
}
TcpBase::~TcpBase()
{
	if (m_Socket != INVALID_SOCKET)
	{
		closesocket(m_Socket);
		m_Socket = INVALID_SOCKET;
	}
}

bool TcpBase::Init()
{
	SocketInit::GetInstance().Init();
	auto ret = GetAddrinfo(m_Address.c_str(), m_Port.c_str(), m_AddressInfo);
	if (ret < 0)
	{
		WriteLog(LogLevel::Info, "GetAddrinfo Failed. Address:%s Port:%s ret:%d, Errno:%d", m_Address.c_str(), m_Port.c_str(), ret, errno);
		return false;
	}
	if (m_ServerType == ServerTypeType::Client)
	{
		ConnectToServer(m_Address.c_str(), atoi(m_Port.c_str()));
	}
	else if (m_ServerType == ServerTypeType::Server)
	{
		m_Socket = socket(m_AddressInfo->ai_family, SOCK_STREAM, IPPROTO_TCP);
		if (m_Socket == INVALID_SOCKET)
		{
			return false;
		}
		if (!InitSocket(m_Socket))
		{
			closesocket(m_Socket);
			return false;
		}
		if (!Bind(m_Socket, m_AddressInfo))
		{
			return false;
		}
		return Listen(m_Socket);
	}
	return true;
}
void TcpBase::DoSend(Connect* connect)
{
	auto& buffers = m_SendBuffers[connect->SessionID];
	auto it = buffers.begin();
	while (it != buffers.end())
	{
		auto buffer = *it;
		int len = send(((TcpConnect*)connect)->SocketID, buffer->GetData(), buffer->GetLength(), 0);
		if (len > 0)
		{
			buffer->Shift(len);
			if (buffer->GetLength() > 0)
			{
				break;
			}
			else
			{
				it = buffers.erase(it);
			}
		}
		else
		{
			//TODO:Handle SocketError
		}
	}
}

void TcpBase::DoRecv(Connect* connect)
{
	auto tcpConnect = (TcpConnect*)connect;
	Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
	auto data = buffer->GetData();
	int len = recv(tcpConnect->SocketID, data, BuffSize - 1, 0);
	if (len <= 0)
	{
		WriteLog(LogLevel::Info, "DisConnect For Recv. SessionID:%lld, Socket:%lld, ErrorID:%d", tcpConnect->SessionID, tcpConnect->SocketID, len);
		buffer->Free();
		DisConnect(tcpConnect->SessionID);
	}
	else if (m_IOSubscriber)
	{
		data[len] = '\0';
		WriteLog(LogLevel::Ignore, "OnRecv: SessionID:%lld, Socket:%lld, RecvLen:%d", tcpConnect->SessionID, tcpConnect->SocketID, len);
		buffer->SetLength(len);

		m_IOSubscriber->OnRecv(tcpConnect->SessionID, buffer);
	}
}

void TcpBase::HandleIOEvent()
{
	if (m_ServerType == ServerTypeType::Client)
		CheckConnect();
	DoDisConnect();
	HandleSendBufferCache();
	HandleTcpEvent();
}
void TcpBase::DoAccept()
{
	for (int i = 0; i < 5; i++)
	{
		SOCKET socketID = accept(m_Socket, (sockaddr*)&m_RemoteAddress, &m_RemoteAddressLen);
		if (socketID == INVALID_SOCKET)
		{
			break;
		}
		std::string ip, port;
		auto ret = GetNameinfo((sockaddr*)&m_RemoteAddress, m_RemoteAddressLen, ip, port);
		SetSockNodelay(socketID);
		auto connect = TcpConnect::Allocate(GetSessionID(), socketID, ip, port);
		AddConnect(connect);
	}
}

bool TcpBase::InitSocket(SOCKET socketID)
{
	if (!SetSockUnblock(socketID) || !SetSockReuse(socketID)|| !SetSockNodelay(socketID))
	{
		WriteLog(LogLevel::Warning, "InitSocket Failed. ErrorID:%d", GetLastError());
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
