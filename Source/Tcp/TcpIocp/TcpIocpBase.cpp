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
    auto connect = (TcpConnect*)GetConnect(sessionID);
    MyOverlapped* overlapped = MyOverlapped::Allocate();
    overlapped->SetBuffer(buffer);
    overlapped->Connect = connect;
    PostSend(overlapped);
}
void TcpIocpBase::HandleSendBufferCache()
{
    IOBase::HandleSendBufferCache();
    for (auto& it : m_SendBuffers)
    {
        if (!it.second.empty())
        {
            auto connect = (TcpConnect*)m_Connects[it.first];
            for (auto buffer : it.second)
            {
                MyOverlapped* overlapped = new MyOverlapped();
                overlapped->SetBuffer(buffer);
                overlapped->Connect = connect;
                PostSend(overlapped);
            }
            it.second.clear();
        }
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
        else
        {
            if (overlapped != nullptr)
            {
                WriteLog(LogLevel::Info, "GetStatus Failed. PostDisConnect For SessionID:%lld, CompetionKey:%d.", overlapped->Connect->SessionID, competionKey);
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
}

bool TcpIocpBase::PostDisConnect(Connect* connect)
{
    auto tcpConnect = (TcpConnect*)connect;
    MyOverlapped* overlapped = MyOverlapped::Allocate();
    overlapped->SetBuffer(Buffer<BuffSize>::Allocate());
    overlapped->EventID = IocpEvent::EventDisConnect;
    overlapped->Connect = tcpConnect;

    WriteLog(LogLevel::Info, "PostDisConnect SessionID:%lld, Socket:%lld", tcpConnect->SessionID, tcpConnect->SocketID);
    return PostDisConnect(overlapped);
}
bool TcpIocpBase::PostDisConnect(MyOverlapped* overlapped)
{
    overlapped->EventID = IocpEvent::EventDisConnect;

    WriteLog(LogLevel::Info, "PostDisConnect SessionID:%lld, Socket:%lld", overlapped->Connect->SessionID, overlapped->Connect->SocketID);
    DWORD transBytes = 0, flag = 0;
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

    WriteLog(LogLevel::Info, "PostSend SessionID:%lld, Socket:%lld", overlapped->Connect->SessionID, overlapped->Connect->SocketID);
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
    auto tcpConnect = (TcpConnect*)overlapped->Connect;
    overlapped->Reset();
    overlapped->EventID = IocpEvent::EventRecv;
    overlapped->Connect = tcpConnect;

    WriteLog(LogLevel::Info, "PostRecv SessionID:%lld, Socket:%lld", tcpConnect->SessionID, tcpConnect->SocketID);
    DWORD transBytes = 0, flag = 0;
    auto ret = WSARecv(tcpConnect->SocketID, &overlapped->WsaBuffer, 1, nullptr, &flag, overlapped, NULL);
    if (ret == SOCKET_ERROR)
    {
        auto lastError = WSAGetLastError();
        if (lastError != ERROR_IO_PENDING)
        {
            WriteLog(LogLevel::Error, "PostRecv: WSARecv failed. SessionID:%lld, Socket:%lld, Errno:%d", tcpConnect->SessionID, tcpConnect->SocketID, lastError);
            PostDisConnect(overlapped);
            return false;
        }
    }
    return true;
}

void TcpIocpBase::OnDisConnectComplete(MyOverlapped* overlapped)
{
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
        overlapped->Free();
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
