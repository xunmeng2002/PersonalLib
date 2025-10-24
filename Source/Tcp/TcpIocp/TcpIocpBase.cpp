#include "TcpIocpBase.h"
#include "TcpIocpConnect.h"
#include "TcpIocpSockApi.h"
#include "TcpIocpCompletePort.h"
#include "TcpUtility.h"
#include "Logger.h"

using namespace std;

TcpIocpBase::TcpIocpBase(ServerTypeType serverType, const char* addressName, int milliSeconds, int backlog)
	:TcpBase(serverType, addressName, milliSeconds), m_BackLog(backlog)
{
}
TcpIocpBase::~TcpIocpBase()
{
    IOCompletePort::GetInstance().PostStatus(0, 0, NULL);
}

bool TcpIocpBase::Init()
{
    auto ret = GetAddrinfo(m_Address.c_str(), m_Port.c_str(), m_AddressInfo);
    if (ret != 0)
    {
        WriteLog(LogLevel::Info, "GetAddrinfo Failed. Address:%s, Port%s, ret:%d", m_Address.c_str(), m_Port.c_str(), ret);
        return false;
    }
    m_Socket = WSASocket(m_AddressInfo->ai_family, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (m_Socket == INVALID_SOCKET)
    {
        WriteLog(LogLevel::Error, "Create SOCKET Failed.");
        return false;
    }
    int on = 1;
    if (setsockopt(m_Socket, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) != 0)
    {
        WriteErrorLog(GetLastError(), "setsockopt Failed. ErrorID:%d, result:%d");
        return false;
    }
    if (!SocketApi::GetInstance().Init(m_Socket))
    {
        return false;
    }
    if (!IOCompletePort::GetInstance().Create())
    {
        WriteErrorLog(LogLevel::Error, "Create IOCompletePort Failed.");
        return false;
    }
    if (!IOCompletePort::GetInstance().AssociateDevice((HANDLE)m_Socket, m_Socket))
    {
        WriteErrorLog(GetLastError(), "AssociateDevice Failed.");
        return false;
    }
    if (!Bind(m_Socket, m_AddressInfo))
    {
        return false;
    }
    if (m_ServerType == ServerTypeType::Client)
    {
        PostConnect();
    }
    if (m_ServerType == ServerTypeType::Server)
    {

        if (!Listen(m_Socket, m_BackLog))
        {
            return false;
        }

        for (auto i = 0; i < m_BackLog; i++)
        {
            if (!PostAccept())
            {
                WriteLog(LogLevel::Error, "PostAccept Failed.");
                return false;
            }
        }
    }

    return true;
}
void TcpIocpBase::Send(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
    auto connect = (TcpIocpConnect*)GetConnect(sessionID);
    if (connect->HasPendingSend || !connect->Buffers.empty())
    {
        lock_guard<mutex> guard(connect->BuffersMutex);
        connect->Buffers.push_back(buffer);
    }
    else
    {
        connect->HasPendingSend = true;
        MyOverlapped* overlapped = MyOverlapped::Allocate();
        overlapped->SetBuffer(buffer);
        overlapped->Connect = connect;
        PostSend(overlapped);
    }
}
void TcpIocpBase::HandleTcpEvent()
{
    DWORD len;
    ULONG_PTR competionKey;
    MyOverlapped* overlapped;

    auto bOK = IOCompletePort::GetInstance().GetStatus(&len, &competionKey, (LPOVERLAPPED*)&overlapped, (DWORD)m_TimeOut.count());
    WriteLog(LogLevel::Debug, "CompletionKey:%d, Len:%d, Ret:%d.", competionKey, len, bOK);
    if (!bOK)
    {
        auto errorID = GetLastError();
        if (errorID == WAIT_TIMEOUT)
        {
            return;
        }
        else if (errorID == ERROR_OPERATION_ABORTED)
        {
            WriteLog(LogLevel::Info, "GetStatus Failed For CancelIoEx. errorID:%d, SessionID:%lld, CompetionKey:%d.", errorID, overlapped->Connect->SessionID, competionKey);
            overlapped->Free();
            return;
        }
        else
        {
            if (overlapped != nullptr)
            {
                WriteLog(LogLevel::Info, "GetStatus Failed. ErrorID:%d, SessionID:%lld, CompetionKey:%d.", errorID, overlapped->Connect->SessionID, competionKey);
                PostDisConnect(overlapped);
                return;
            }
            else
            {
                WriteLog(LogLevel::Warning, "GetStatus Failed. Overlapped is NULL. Errno:%d", errorID);
                return;
            }
        }
    }
    if (overlapped == nullptr)
    {
        WriteLog(LogLevel::Error, "CompetionKey:%d, OVERLAPPED is null.", competionKey);
        return;
    }
    auto tcpConnect = overlapped->Connect;

    if (len == 0 && (overlapped->EventID == IocpEvent::EventSend || overlapped->EventID == IocpEvent::EventRecv))
    {
        PostDisConnect(overlapped);
        return;
    }
    
    switch (overlapped->EventID)
    {
    case IocpEvent::EventAccept:
        OnAcceptComplete(overlapped);
        break;
    case IocpEvent::EventConnect:
        OnConnectComplete(overlapped);
        break;
    case IocpEvent::EventDisConnect:
        OnDisConnectComplete(overlapped);
        break;
    case IocpEvent::EventSend:
        OnSendComplete(overlapped, len);
        break;
    case IocpEvent::EventRecv:
        OnRecvComplete(overlapped, len);
        break;
    default:
        WriteLog(LogLevel::Error, "INVALID EventID:%d, SessionID:%lld, Socket:%lld.", overlapped->EventID, tcpConnect->SessionID, tcpConnect->SocketID);
        break;
    }
}
void TcpIocpBase::DoDisConnect()
{
    lock_guard<mutex> guard(m_DisConnectSessionIDsMutex);
    for (auto sessionID : m_DisConnectSessionIDs)
    {
        auto connect = (TcpConnect*)m_Connects[sessionID];
        if (connect != nullptr)
            PostDisConnect(connect);
    }
    m_DisConnectSessionIDs.clear();
}

bool TcpIocpBase::PostDisConnect(Connect* connect)
{
    auto tcpIocpConnect = (TcpIocpConnect*)connect;
    MyOverlapped* overlapped = MyOverlapped::Allocate();
    overlapped->SetBuffer(Buffer<BuffSize>::Allocate());
    overlapped->EventID = IocpEvent::EventDisConnect;
    overlapped->Connect = tcpIocpConnect;
    
    return PostDisConnect(overlapped);
}
bool TcpIocpBase::PostDisConnect(MyOverlapped* overlapped)
{
    overlapped->EventID = IocpEvent::EventDisConnect;

    WriteLog(LogLevel::Info, "PostDisConnect SessionID:%lld, Socket:%lld", overlapped->Connect->SessionID, overlapped->Connect->SocketID);
    DWORD transBytes = 0, flag = 0;
    CancelIoEx((HANDLE)overlapped->Connect->SocketID, NULL);
    auto ret = SocketApi::GetInstance().DisconnectEx(overlapped->Connect->SocketID, overlapped, TF_REUSE_SOCKET, 0);
    auto lastError = WSAGetLastError();
    if (ret != 0 && lastError != ERROR_IO_PENDING)
    {
        WriteLog(LogLevel::Error, "Call DisConnectEx Failed. SessionID:%lld, Socket:%lld, Errno:%d", overlapped->Connect->SessionID, overlapped->Connect->SocketID, lastError);
        OnDisConnectComplete(overlapped);
        return false;
    }
    return true;
}
bool TcpIocpBase::PostSend(MyOverlapped* overlapped)
{
    overlapped->EventID = IocpEvent::EventSend;

    WriteLog(LogLevel::Debug, "PostSend SessionID:%lld, Socket:%lld", overlapped->Connect->SessionID, overlapped->Connect->SocketID);
    DWORD transBytes = 0, flag = 0;
    auto ret = WSASend(overlapped->Connect->SocketID, &overlapped->WsaBuffer, 1, &transBytes, flag, overlapped, NULL);
    if (ret == SOCKET_ERROR)
    {
        auto lastError = WSAGetLastError();
        if (lastError != ERROR_IO_PENDING)
        {
            WriteLog(LogLevel::Error, "PostSend: WSASend failed. SessionID:%lld, Socket:%lld, Errno:%d", overlapped->Connect->SessionID, overlapped->Connect->SocketID, lastError);
            PostDisConnect(overlapped);
            return false;
        }
    }
    return true;
}
bool TcpIocpBase::PostRecv(MyOverlapped* overlapped)
{
    auto tcpIocpConnect = (TcpIocpConnect*)overlapped->Connect;
    overlapped->Reset();
    overlapped->EventID = IocpEvent::EventRecv;
    overlapped->Connect = tcpIocpConnect;

    WriteLog(LogLevel::Debug, "PostRecv SessionID:%lld, Socket:%lld", tcpIocpConnect->SessionID, tcpIocpConnect->SocketID);
    DWORD transBytes = 0, flag = 0;
    auto ret = WSARecv(tcpIocpConnect->SocketID, &overlapped->WsaBuffer, 1, nullptr, &flag, overlapped, NULL);
    if (ret == SOCKET_ERROR)
    {
        auto lastError = WSAGetLastError();
        if (lastError != ERROR_IO_PENDING)
        {
            WriteLog(LogLevel::Error, "PostRecv: WSARecv failed. SessionID:%lld, Socket:%lld, Errno:%d", tcpIocpConnect->SessionID, tcpIocpConnect->SocketID, lastError);
            PostDisConnect(overlapped);
            return false;
        }
    }
    return true;
}

void TcpIocpBase::OnDisConnectComplete(MyOverlapped* overlapped)
{
    WriteLog(LogLevel::Info, "OnDisConnectComplete SessionID:%lld, Socket:%lld", overlapped->Connect->SessionID, overlapped->Connect->SocketID);
    RemoveConnect(overlapped->Connect);
    overlapped->Free();
}
void TcpIocpBase::OnSendComplete(MyOverlapped* overlapped, int bytesTransferred)
{
    WriteLog(LogLevel::Info, "OnSendComplete SessionID:%lld, Socket:%lld, BufferLen:%d, bytesTransferred:%d", overlapped->Connect->SessionID, overlapped->Connect->SocketID, overlapped->MyBuffer->GetLength(), bytesTransferred);
    if (bytesTransferred < overlapped->MyBuffer->GetLength())
    {
        WriteLog(LogLevel::Warning, "OnSendComplete PartSended. PostSend Again. BufferLen:%d, bytesTransferred:%d", overlapped->MyBuffer->GetLength(), bytesTransferred);
        overlapped->Shift(bytesTransferred);
        PostSend(overlapped);
    }
    else
    {
        auto buffer = overlapped->Connect->GetBuffer();
        if (buffer != nullptr)
        {
            overlapped->SetBuffer(buffer);
            PostSend(overlapped);
        }
        else
        {
            overlapped->Connect->HasPendingSend = false;
            overlapped->Free();
        }
    }
}
void TcpIocpBase::OnRecvComplete(MyOverlapped* overlapped, int bytesTransferred)
{
    WriteLog(LogLevel::Info, "OnRecvComplete SessionID:%lld, Socket:%lld, bytesTransferred:%d", overlapped->Connect->SessionID, overlapped->Connect->SocketID, bytesTransferred);
    overlapped->MyBuffer->SetLength(bytesTransferred);
    auto tcpConnect = (TcpConnect*)overlapped->Connect;
    if (m_IOSubscriber)
    {
        m_IOSubscriber->OnRecv(tcpConnect->SessionID, overlapped->MyBuffer);
    }
    PostRecv(overlapped);
}
