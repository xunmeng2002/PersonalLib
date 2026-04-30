#pragma once
#include "Types/Types.h"
#include "Buffer/Buffer.h"
#include <list>
#include <mutex>

class Connect
{
public:
	virtual void Free() = 0;
	void PushBack(Buffer<BuffSize>* buffer);
	void PushFront(Buffer<BuffSize>* buffer);
	Buffer<BuffSize>* GetNextBuffer();

	SessionIDType SessionID = 0LL;
	ConnectStatusType ConnectStatus = ConnectStatusType::UnConnected;
	char RemoteAddress[40]{ 0 };
	int RemotePort = 0;
	std::list<Buffer<BuffSize>*> Buffers;
	std::mutex BuffersMutex;
};


