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
    if (ret < 0 || m_AddressInfo == nullptr)
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


void TcpIocpBase::HandleTcpEvent()
{
    DWORD len;
    ULONG_PTR competionKey;
    MyOverlapped* overlapped;

    auto bOK = IOCompletePort::GetInstance().GetStatus(&len, &competionKey, (LPOVERLAPPED*)&overlapped, (DWORD)m_TimeOut.count());
    WriteLog(LogLevel::Debug, "CompletionKey:%d, Len:%d, Ret:%d.", competionKey, len, bOK);
    if (overlapped == nullptr)
    {
        WriteLog(LogLevel::Info, "CompetionKey:%d, OVERLAPPED is null.", competionKey);
        return;
    }
    auto tcpConnect = overlapped->Connect;
    if (!bOK)
    {
        WriteLog(LogLevel::Warning, "GetQueuedCompletionStatus Failed. Errno:%d, SessionID:%lld, Socket:%lld.", 
            GetLastError(), tcpConnect->SessionID, tcpConnect->SocketID);
        if (tcpConnect != nullptr && tcpConnect->SocketID != INVALID_SOCKET)
        {
            DoDisConnect(overlapped);
        }
        MemCacheTemplateSingleton<MyOverlapped>::GetInstance().Free(overlapped);
        return;
    }
    if (len == 0 && (overlapped->EventID == IocpEvent::EventSend || overlapped->EventID == IocpEvent::EventRecv))
    {
        DoDisConnect(overlapped);
        return;
    }
    overlapped->Buffer.SetLength(len);
    switch (overlapped->EventID)
    {
    case IocpEvent::EventConnect:
        DoConnect(overlapped);
        break;
    case IocpEvent::EventDisConnect:
        DoDisConnect(overlapped);
        break;
    case IocpEvent::EventAccept:
        DoAccept(overlapped);
        break;
    case IocpEvent::EventRecv:
        DoRecv(overlapped);
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
    MyOverlapped* overlapped = MemCacheTemplateSingleton<MyOverlapped>::GetInstance().Allocate();
    overlapped->Reset();
    overlapped->EventID = IocpEvent::EventDisConnect;
    overlapped->Connect = tcpConnect;

    WriteLog(LogLevel::Info, "PostDisConnect SessionID:%lld, Socket:%lld", tcpConnect->SessionID, tcpConnect->SocketID);
    DWORD transBytes = 0, flag = 0;
    auto ret = SocketApi::GetInstance().DisconnectEx(tcpConnect->SocketID, overlapped, TF_REUSE_SOCKET, 0);
    auto lastError = WSAGetLastError();
    if (ret != 0 && lastError != ERROR_IO_PENDING)
    {
        WriteLog(LogLevel::Error, "Call DisConnectEx Failed. SessionID:%lld, Socket:%lld, Errno:%d", tcpConnect->SessionID, tcpConnect->SocketID, lastError);
        DoDisConnect(overlapped);
        return false;
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
    auto lastError = WSAGetLastError();
    if (ret != 0 && lastError != ERROR_IO_PENDING)
    {
        WriteLog(LogLevel::Error, "PostRecv: WSARecv failed. SessionID:%lld, Socket:%lld, Errno:%d", tcpConnect->SessionID, tcpConnect->SocketID, lastError);
        DoDisConnect(overlapped);
        return false;
    }
    return true;
}

void TcpIocpBase::DoDisConnect(MyOverlapped* overlapped)
{
    RemoveConnect(overlapped->Connect);
    MemCacheTemplateSingleton<MyOverlapped>::GetInstance().Free(overlapped);
}
void TcpIocpBase::DoRecv(MyOverlapped* overlapped)
{
    auto tcpConnect = (TcpConnect*)overlapped->Connect;
    if (m_IOSubscriber)
    {
        m_IOSubscriber->OnRecv(tcpConnect->SessionID, &overlapped->Buffer);
    }
    PostRecv(overlapped);
}
