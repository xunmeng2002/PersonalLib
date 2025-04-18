#include "TcpIocpConnect.h"
#include "MemCacheTemplateSingleton.h"
#include "Logger.h"

MyOverlapped::MyOverlapped()
{
	Reset();
}
void MyOverlapped::Reset()
{
	Internal = InternalHigh = 0;
	Offset = OffsetHigh = 0;
	hEvent = nullptr;

	EventID = IocpEvent::EventNone;
	Buffer.Reset();
	WsaBuffer.buf = Buffer.GetData();
	WsaBuffer.len = BuffSize;
	Connect = nullptr;
}
