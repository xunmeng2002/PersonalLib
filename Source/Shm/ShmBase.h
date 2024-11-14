#pragma once
#include <string>
#include <map>
#include <list>
#include <mutex>
#include "Types.h"
#include "Buffer.h"
#include "IOThread.h"
#include "Sem.h"
#include "SingleShmBuffer.h"



class ShmBase : public IOThread
{
public:
	ShmBase(ServerTypeType shmType, const char* threadName, const char* shmName);
	virtual ~ShmBase();
	virtual bool Init() override;

	virtual void DisConnect(SessionIDType sessionID) override;
	virtual int Send(SessionIDType sessionID, const char* data, unsigned len) override;
	virtual int Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

protected:
	virtual void CheckConnect();
	virtual void DoDisConnect();
	virtual void HandleEvent();

	void DoRecv(ShmConnect<ShmBuffSize>* shmConnect);

	ShmConnect<ShmBuffSize>* GetShmConnect(SessionIDType sessionID);
	virtual void AddConnect(int index);
	virtual void RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect);

protected:
	ServerTypeType m_ShmType;
	std::string m_ShmName;
	unsigned m_MaxConnectSize;
	SingleShmHeader* m_CommonShmHeader;
	void* m_ShmAddr;
	Sem* m_Sem;
	std::map<int64_t, ShmConnect<ShmBuffSize>*> m_ShmConnects;
	std::mutex m_ShmConnectsMutex;
	std::list<ShmConnect<ShmBuffSize>*> m_ShmDisConnects;
	std::mutex m_ShmDisConnectsMutex;
#ifdef WINDOWS
	void* m_File;
	void* m_FileMap;
#endif // WINDOWS
};
