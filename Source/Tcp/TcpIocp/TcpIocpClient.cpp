#include "TcpIocpClient.h"
#include "TcpIocpCompletePort.h"
#include "TcpIocpConnect.h"
#include "TcpIocpSockApi.h"
#include "IOUtility.h"
#include "TcpUtility.h"
#include "Logger.h"


TcpIocpClient::TcpIocpClient(const char* localAddressName, const char* remoteAddressName, int milliSeconds, int backlog)
	:TcpIocpBase(ServerTypeType::Client, localAddressName, milliSeconds, backlog), m_RemoteAddressInfo(nullptr)
{
	m_RemoteAddressName = std::string(remoteAddressName);
	ParseAddress(m_RemoteAddressName, m_RemoteAddress, m_RemotePort);
}
bool TcpIocpClient::Init()
{
	auto ret = GetAddrinfo(m_RemoteAddress.c_str(), m_RemotePort.c_str(), m_RemoteAddressInfo);
	if (ret < 0)
	{
		WriteLog(LogLevel::Info, "GetAddrinfo Failed. Address:%s, Port:%s, ret:%d, Errno:%d", m_RemoteAddress.c_str(), m_RemotePort.c_str(), ret, errno);
		return false;
	}
	TcpIocpBase::Init();
	return true;
}
bool TcpIocpClient::PostConnect()
{
    SOCKET socketID = PrepareConnectSocket();
    if (socketID == INVALID_SOCKET)
    {
        WriteLog(LogLevel::Error, "PrepareSocket SOCKET Failed.");
        return false;
    }
    TcpConnect* tcpConnect = TcpConnect::Allocate(GetSessionID(), socketID, m_RemoteAddress, m_RemotePort);
    MyOverlapped* overlapped = MemCacheTemplateSingleton<MyOverlapped>::GetInstance().Allocate();
    overlapped->Reset();
    overlapped->EventID = IocpEvent::EventAccept;
    overlapped->Connect = tcpConnect;

    WriteLog(LogLevel::Info, "PostConnect For SessionID:%lld, Socket:%lld", tcpConnect->SessionID, tcpConnect->SocketID);
    DWORD transBytes = 0;
    auto ret = SocketApi::GetInstance().ConnectEx(tcpConnect->SocketID, (const sockaddr*)m_RemoteAddressInfo->ai_addr, sizeof(SOCKADDR_IN),
        NULL, 0, &transBytes, overlapped);
    if (!ret && WSAGetLastError() != ERROR_IO_PENDING)
    {
        WriteErrorLog(WSAGetLastError(), "Call ConnectEx Failed.");
        return false;
    }
    return true;
}
void TcpIocpClient::DoConnect(MyOverlapped* overlapped)
{
    PostRecv(overlapped);
    AddConnect(overlapped->Connect);
}

SOCKET TcpIocpClient::PrepareConnectSocket()
{
    SOCKET socketID = WSASocket(m_AddressInfo->ai_family, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (socketID == INVALID_SOCKET)
    {
        WriteLog(LogLevel::Error, "Create SOCKET Failed.");
        closesocket(socketID);
        return INVALID_SOCKET;
    }
    int on = 1;
    if (setsockopt(socketID, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) != 0)
    {
        WriteErrorLog(GetLastError(), "setsockopt Failed. ErrorID:%d, result:%d");
        closesocket(socketID);
        return INVALID_SOCKET;
    }
    if (!Bind(socketID, m_AddressInfo))
    {
        closesocket(socketID);
        return INVALID_SOCKET;
    }
    if (!IOCompletePort::GetInstance().AssociateDevice((HANDLE)socketID, socketID))
    {
        WriteErrorLog(GetLastError(), "AssociateDevice Failed.");
        closesocket(socketID);
        return INVALID_SOCKET;
    }
    return socketID;
}