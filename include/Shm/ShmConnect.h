#pragma once
#include "Types/Types.h"
#include "IO/Connect.h"
#include "Buffer/ShmBuffer.h"
#include "MemCache/MemCacheTemplateSingleton.h"


template<unsigned SIZE>
class ShmConnect : public Connect
{
public:
	ShmBuffer<SIZE>* m_ShmBuffer;

	static ShmConnect* Allocate(SessionIDType sessionID, const char* remoteAddress, int remotePort, ServerTypeType serverType, void* shmAddr, ConnectStatusType connectStatus)
	{
		auto item = ::Allocate<ShmConnect<SIZE>>();
		item->SessionID = sessionID;
		strncpy(item->RemoteAddress, remoteAddress, sizeof(RemoteAddress));
		item->RemotePort = remotePort;
		item->m_ShmBuffer = ShmBuffer<SIZE>::Allocate(serverType, remotePort, shmAddr, connectStatus);
		return item;
	}
	void Free()
	{
		m_ShmBuffer->Free();
		m_ShmBuffer = nullptr;
		MemCacheTemplateSingleton<ShmConnect<SIZE>>::GetInstance().Free(this);
	}
};
