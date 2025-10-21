#include "TcpIocpConnect.h"
#include "MemCacheTemplateSingleton.h"
#include "Logger.h"

MyOverlapped::MyOverlapped()
{
	Internal = InternalHigh = 0;
	Offset = OffsetHigh = 0;
	hEvent = nullptr;

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
	}
	Reset();
	MemCacheTemplateSingleton<MyOverlapped>::GetInstance().Free(this);
}
void MyOverlapped::SetBuffer(Buffer<BuffSize>* buffer)
{
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
