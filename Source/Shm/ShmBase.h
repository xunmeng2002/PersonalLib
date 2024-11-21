#pragma once
#include <string>
#include <map>
#include <list>
#include <mutex>
#include "Types.h"
#include "Buffer.h"
#include "IOThread.h"
#include "Sem.h"
#include "ShmConnect.h"



class ShmBase : public IOThread
{
public:
	ShmBase(ServerTypeType shmType, const char* threadName, const char* shmName);
	virtual ~ShmBase();
	virtual bool Init() override;

	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) override;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

protected:
	void DoRecv(ShmConnect<ShmBuffSize>* shmConnect);

protected:
	std::string m_ShmName;
	unsigned m_MaxConnectSize;
	SingleShmHeader* m_CommonShmHeader;
	void* m_ShmAddr;
	Sem* m_Sem;

#ifdef WINDOWS
	void* m_File;
	void* m_FileMap;
#endif // WINDOWS
};
