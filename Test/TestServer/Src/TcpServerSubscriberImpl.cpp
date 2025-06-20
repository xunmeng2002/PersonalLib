#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "Platform.h"
#include <string.h>
#include <iostream>


TcpServerSubscriberImpl::TcpServerSubscriberImpl(TcpBase* tcp)
    :m_IOThread(tcp)
{
    m_IOThread->Subscribe(this);
}
TcpServerSubscriberImpl::~TcpServerSubscriberImpl()
{
    m_IOThread->UnSubscribe();
}

void TcpServerSubscriberImpl::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
    WriteLog(LogLevel::Info, "TcpServerSubscriberImpl::OnConnect SessionID:[%lld], IP:[%s], Port:[%d]", sessionID, ip, port);
}
void TcpServerSubscriberImpl::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
    WriteLog(LogLevel::Info, "TcpServerSubscriberImpl::OnDisConnect SessionID:[%lld], IP:[%s], Port:[%d]", sessionID, ip, port);
}



void TcpServerSubscriberImpl::OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
    char message[2048] = { 0 };
    auto n = sprintf(message, "TcpServerSubscriberImpl::OnRecv SessionID:[%lld], Data:[%s]", (long long)sessionID, buffer->GetData());
    WriteLog(LogLevel::Info, message);

    auto sendLen = m_IOThread->Send(sessionID, buffer);
    if (sendLen <= 0)
    {
        WriteLog(LogLevel::Error, "m_IOThread->Send sendLen:%d, Errno:%d, buffer Len:%d, Data:%s", sendLen, GetLastError(), buffer->GetLength(), buffer->GetData());
    }
}
