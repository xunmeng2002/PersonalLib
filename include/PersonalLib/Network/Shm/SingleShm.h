#pragma once
#include "PersonalLib/Network/NetworkExport.h"
#include <string>
#include "PersonalLib/Types.h"
#include "PersonalLib/Core/Buffer/Buffer.h"
#include "PersonalLib/Network/IO/IOBase.h"
#include "PersonalLib/Network/Shm/ShmConnect.h"



class NETWORK_EXPORTS SingleShm : public IOBase
{
public:
	SingleShm(ServerTypeType shmType, const char* shmName);
	virtual ~SingleShm();
	virtual bool Init() override;
	
	virtual void Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;
	virtual void DoRecv(Connect* connect) override;
	virtual void HandleIOEvent() override;

protected:
	virtual void CheckConnectStatus();
	virtual void CheckEvent();
	virtual void HandleEvent();

public:
	std::string m_ShmName;
protected:
	bool m_Connected;
	SessionIDType m_SessionID;
	void* m_ShmAddr;
	ShmBuffer<ShmBuffSize>* m_ShmBuffer;
#ifdef WINDOWS
	void* m_File;
	void* m_FileMap;
#endif // WINDOWS
};



