#include "Tcp/TcpIocp/TcpIocpConnect.h"
#include "MemCache/MemCacheTemplateSingleton.h"
#include "Logger/Logger.h"



TcpIocpConnect* TcpIocpConnect::Allocate(SessionIDType sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	TcpIocpConnect* tcpIocpConnect = MemCacheTemplateSingleton<TcpIocpConnect>::GetInstance().Allocate();
	tcpIocpConnect->Set(sessionID, socketID, remoteIP, remotePort);
	return tcpIocpConnect;
}
void TcpIocpConnect::Free()
{
	WriteLog(LogLevel::Info, "TcpIocpConnect::Close SessionID:%lld, Socket:%lld", SessionID, SocketID);
#ifdef WINDOWS
	shutdown(SocketID, SD_BOTH);
#endif
#ifdef LINUX
	shutdown(SocketID, SHUT_RDWR);
#endif
	closesocket(SocketID);
	SocketID = INVALID_SOCKET;
	MemCacheTemplateSingleton<TcpConnect>::GetInstance().Free(this);
}

MyOverlapped::MyOverlapped()
{
	Internal = InternalHigh = 0;
	Offset = OffsetHigh = 0;
	hEvent = nullptr;

	EventID = IocpEvent::EventNone;
	MyBuffer = nullptr;
	WsaBuffer.buf = nullptr;
	WsaBuffer.len = 0;
	Connect = nullptr;
}
MyOverlapped* MyOverlapped::Allocate()
{
	return ::Allocate<MyOverlapped>();
}
void MyOverlapped::Free()
{
	if (MyBuffer)
	{
		MyBuffer->Reset();
		MyBuffer->Free();
		MyBuffer = nullptr;
	}
	Reset();
	MemCacheTemplateSingleton<MyOverlapped>::GetInstance().Free(this);
}
void MyOverlapped::SetBuffer(Buffer<BuffSize>* buffer)
{
	if (MyBuffer != nullptr)
	{
		MyBuffer->Free();
	}
	MyBuffer = buffer;
	WsaBuffer.buf = MyBuffer->GetData();
	WsaBuffer.len = MyBuffer->GetLength();
}
void MyOverlapped::Shift(unsigned int len)
{
	MyBuffer->Shift(len);
	WsaBuffer.buf = MyBuffer->GetData();
	WsaBuffer.len = MyBuffer->GetLength();
}
void MyOverlapped::Reset()
{
	Internal = InternalHigh = 0;
	Offset = OffsetHigh = 0;
	hEvent = nullptr;

	EventID = IocpEvent::EventNone;
	if (MyBuffer)
	{
		MyBuffer->Reset();
		WsaBuffer.buf = MyBuffer->GetData();
		WsaBuffer.len = BuffSize;
	}
	else
	{
		WsaBuffer.buf = nullptr;
		WsaBuffer.len = 0;
	}
	Connect = nullptr;
}
