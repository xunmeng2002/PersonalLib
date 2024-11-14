#include "TcpServerBase.h"
#include "TcpUtility.h"
#include "Logger.h"


TcpServerBase::TcpServerBase(const char* threadName, const char* addressName)
	:TcpBase(threadName, addressName), m_ListenSocket(INVALID_SOCKET), m_BindAddressInfo(nullptr)
{
	ParseIPAddress(m_AddressName, m_BindIP, m_BindPort);
	GetAddrinfo(m_BindIP.c_str(), m_BindPort.c_str(), m_BindAddressInfo);
}
TcpServerBase::~TcpServerBase()
{
	if (m_ListenSocket != INVALID_SOCKET)
	{
		closesocket(m_ListenSocket);
		m_ListenSocket = INVALID_SOCKET;
	}
}

bool TcpServerBase::Init()
{
	m_ListenSocket = PrepareSocket(m_BindAddressInfo->ai_family);
	if (m_ListenSocket == INVALID_SOCKET)
	{
		return false;
	}
	if (!Bind(m_ListenSocket, m_BindAddressInfo))
	{
		return false;
	}
	return Listen(m_ListenSocket);
}
void TcpServerBase::DoAccept()
{
	for (int i = 0; i < 5; i++)
	{
		SOCKET socketID = accept(m_ListenSocket, (sockaddr*)&m_RemoteAddress, &m_RemoteAddressLen);
		if (socketID == INVALID_SOCKET)
		{
			break;
		}
		std::string ip, port;
		auto ret = GetNameinfo((sockaddr*)&m_RemoteAddress, m_RemoteAddressLen, ip, port);
		SetSockNodelay(socketID);
		auto sessionID = GetSessionID();
		WriteLog(LogLevel::Info, "accept: SessionID[%lld], SocketID[%lld], RemoteIP[%s], RemotePort[%s]", sessionID, socketID, ip.c_str(), port.c_str());
		auto connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
		AddConnect(connectData);
	}
}

void TcpServerBase::Run()
{
	HandleTcpEvent();
}

