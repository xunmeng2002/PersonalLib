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
	ParseAddress(remoteAddressName, m_RemoteAddress, m_RemotePort);
    auto ret = GetAddrinfo(m_RemoteAddress.c_str(), m_RemotePort.c_str(), m_RemoteAddressInfo);
    if (ret < 0)
    {
        WriteLog(LogLevel::Info, "GetAddrinfo Failed. Address:%s, Port:%s, ret:%d, Errno:%d", m_RemoteAddress.c_str(), m_RemotePort.c_str(), ret, errno);
    }
}
bool TcpIocpClient::ConnectToServer(const char* ip, unsigned short port)
{
    m_RemoteAddress = ip;
    m_RemotePort = std::to_string(port);
    return PostConnect();
}

bool TcpIocpClient::PostConnect()
{
    SOCKET socketID = PrepareConnectSocket();
    if (socketID == INVALID_SOCKET)
    {
        WriteLog(LogLevel::Error, "PrepareConnectSocket SOCKET Failed.");
        return false;
    }
    TcpIocpConnect* tcpIocpConnect = TcpIocpConnect::Allocate(GetSessionID(), socketID, m_RemoteAddress, m_RemotePort);
    MyOverlapped* overlapped = MyOverlapped::Allocate();
    overlapped->SetBuffer(Buffer<BuffSize>::Allocate());
    overlapped->EventID = IocpEvent::EventConnect;
    overlapped->Connect = tcpIocpConnect;

    WriteLog(LogLevel::Info, "PostConnect For SessionID:%lld, Socket:%lld", tcpIocpConnect->SessionID, tcpIocpConnect->SocketID);
    DWORD transBytes = 0;
    auto ret = SocketApi::GetInstance().ConnectEx(tcpIocpConnect->SocketID, (const sockaddr*)m_RemoteAddressInfo->ai_addr, sizeof(SOCKADDR_IN),
        NULL, 0, &transBytes, overlapped);
    if (!ret && WSAGetLastError() != ERROR_IO_PENDING)
    {
        WriteErrorLog(WSAGetLastError(), "Call ConnectEx Failed.");
        return false;
    }
    return true;
}
void TcpIocpClient::OnConnectComplete(MyOverlapped* overlapped)
{
    PostRecv(overlapped);
    auto overlapped2 = MyOverlapped::Allocate();
    overlapped2->SetBuffer(Buffer<BuffSize>::Allocate());
    overlapped2->Connect = overlapped->Connect;
    PostRecv(overlapped2);
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

