#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "Platform.h"
#include <string.h>
#include <iostream>


TcpServerSubscriberImpl::TcpServerSubscriberImpl(TcpBase* tcp)
    :m_IO(tcp)
{
    m_IO->Subscribe(this);
}
TcpServerSubscriberImpl::~TcpServerSubscriberImpl()
{
    m_IO->UnSubscribe();
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

    auto responseBuffer = new Buffer<BuffSize>();
    responseBuffer->Append(buffer->GetData(), buffer->GetLength());
    m_IO->Send(sessionID, responseBuffer);
}
