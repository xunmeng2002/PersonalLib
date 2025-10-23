#include "TcpIocpServer.h"
#include "TcpIocpSockApi.h"
#include "TcpIocpCompletePort.h"
#include "Logger.h"

TcpIocpServer::TcpIocpServer(const char* addressName, int milliSeconds, int backlog)
	:TcpIocpBase(ServerTypeType::Server, addressName, milliSeconds, backlog)
{

}
bool TcpIocpServer::PostAccept()
{
    SOCKET socketID = PrepareAcceptSocket();
    if (socketID == INVALID_SOCKET)
    {
        WriteLog(LogLevel::Error, "PrepareAcceptSocket SOCKET Failed.");
        return false;
    }
    TcpConnect* tcpConnect = TcpConnect::Allocate(GetSessionID(), socketID, "", "");
    MyOverlapped* overlapped = MyOverlapped::Allocate();
    overlapped->SetBuffer(Buffer<BuffSize>::Allocate());
    overlapped->EventID = IocpEvent::EventAccept;
    overlapped->Connect = tcpConnect;

    WriteLog(LogLevel::Info, "PostAccept SessionID:%lld, Socket:%lld", tcpConnect->SessionID, tcpConnect->SocketID);
    DWORD transBytes = 0;
    auto ret = SocketApi::GetInstance().AcceptEx(m_Socket, tcpConnect->SocketID, overlapped->WsaBuffer.buf, 0, (sizeof(SOCKADDR_IN) + 16), (sizeof(SOCKADDR_IN) + 16), &transBytes, overlapped);
    auto lastError = WSAGetLastError();
    if (ret != 0 && lastError != ERROR_IO_PENDING)
    {
        WriteLog(LogLevel::Error, "Call AcceptEx Failed. SessionID:%lld, Socket:%lld, Errno:%d", tcpConnect->SessionID, tcpConnect->SocketID, lastError);
        return false;
    }
    return true;
}
void TcpIocpServer::OnAcceptComplete(MyOverlapped* overlapped)
{
    auto tcpConnect = (TcpConnect*)overlapped->Connect;
    SOCKADDR_IN* remoteAddr = NULL;
    SOCKADDR_IN* localAddr = NULL;
    int remoteLen = sizeof(SOCKADDR_IN), localLen = sizeof(SOCKADDR_IN);
    SocketApi::GetInstance().GetAcceptExSockAddrs(overlapped->WsaBuffer.buf, 0,
        (sizeof(SOCKADDR_IN) + 16), (sizeof(SOCKADDR_IN) + 16), (LPSOCKADDR*)&localAddr, &localLen, (LPSOCKADDR*)&remoteAddr, &remoteLen);
    strcpy(tcpConnect->RemoteAddress, inet_ntoa(remoteAddr->sin_addr));
    tcpConnect->RemotePort = ntohs(remoteAddr->sin_port);

    WriteLog(LogLevel::Info, "AcceptComplete: From <%s:%d>, SessionID:%lld, Socket:%lld", tcpConnect->RemoteAddress, tcpConnect->RemotePort, tcpConnect->SessionID, tcpConnect->SocketID);

    AddConnect(tcpConnect);
    PostRecv(overlapped);
    PostAccept();
}

SOCKET TcpIocpServer::PrepareAcceptSocket()
{
    SOCKET socketID = WSASocket(m_AddressInfo->ai_family, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (socketID == INVALID_SOCKET)
    {
        WriteLog(LogLevel::Error, "Create SOCKET Failed.");
        return INVALID_SOCKET;
    }
    if (!IOCompletePort::GetInstance().AssociateDevice((HANDLE)socketID, socketID))
    {
        WriteLog(LogLevel::Warning, "Associate CompletionPort Failed, Socket:%lld", socketID);
        return INVALID_SOCKET;
    }
    return socketID;
}
