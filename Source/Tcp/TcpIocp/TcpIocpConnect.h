#pragma once
#include "Types.h"
#include "SocketInit.h"
#include "TcpConnect.h"
#include "Buffer.h"

enum class IocpEvent : int
{
	EventNone = 0,			//请求连接
	EventConnect = 1,			//请求连接
	EventDisConnect = 2,		//请求断开连接
	EventAccept = 3,			//请求接受连接
	EventOnConnected = 4,		//已连接
	EventOnDisConnected = 5,	//已断开连接
	EventOnAccept = 6,			//已接受连接
	EventSend = 7,				//请求发送
	EventRecv = 8,				//请求接收
};

class MyOverlapped : public OVERLAPPED
{
public:
	MyOverlapped();
	void Reset();

	IocpEvent EventID;
	WSABUF WsaBuffer;
	Buffer<BuffSize> Buffer;
	TcpConnect* Connect;
};


