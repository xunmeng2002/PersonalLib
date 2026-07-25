#pragma once
#include <PersonalLib/Network/NetworkExport.h>
#include <PersonalLib/Types.h>
#include <PersonalLib/Network/IO/Connect.h>
#include <PersonalLib/TemplateLib/Buffer/ShmBuffer.h>
#include <PersonalLib/TemplateLib/ObjectPool/ObjectPool.h>


template<unsigned SIZE>
class ShmConnect : public Connect
{
public:
	ShmConnect(SessionIDType sessionID, const char* remoteAddress, int remotePort, ServerTypeType serverType, void* shmAddr, ConnectStatusType connectStatus)
		:Connect(sessionID, remoteAddress, remotePort, connectStatus)
	{
		m_ShmBuffer = ShmBuffer<SIZE>::Allocate(serverType, remotePort, shmAddr, connectStatus);
	}
	virtual ~ShmConnect()
	{
		m_ShmBuffer->Deallocate();
		m_ShmBuffer = nullptr;
	}

	static ShmConnect* Allocate(SessionIDType sessionID, const char* remoteAddress, int remotePort, ServerTypeType serverType, void* shmAddr, ConnectStatusType connectStatus)
	{
		return ObjectPool<ShmConnect<SIZE>>::GetInstance().Allocate(sessionID, remoteAddress, remotePort, serverType, shmAddr, connectStatus);
	}
	virtual void Deallocate() override
	{
		ObjectPool<ShmConnect<SIZE>>::GetInstance().Deallocate(this);
	}

public:
	ShmBuffer<SIZE>* m_ShmBuffer;
};
