#pragma once
#include <string>
#include "Types.h"
#include "Buffer.h"
#include "IOThread.h"
#include "ShmConnect.h"



class SingleShm : public IOThread
{
public:
	SingleShm(ServerTypeType shmType, const char* threadName, const char* shmName);
	virtual ~SingleShm();
	virtual bool Init() override;

	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) override;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;
	
protected:
	virtual void Run() override;
	virtual void CheckEvent();
	virtual void HandleEvent();

	void DoRecv();
public:
	ServerTypeType m_ShmType;
	std::string m_ShmName;
	bool m_ConnectStatus;
protected:
	SessionIDType m_SessionID;
	void* m_ShmAddr;
	ShmBuffer<ShmBuffSize>* m_ShmBuffer;
#ifdef WINDOWS
	void* m_File;
	void* m_FileMap;
#endif // WINDOWS
};



