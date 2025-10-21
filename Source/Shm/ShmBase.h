#pragma once
#include <string>
#include <map>
#include <list>
#include <mutex>
#include "Types.h"
#include "Buffer.h"
#include "IOBase.h"
#include "Sem.h"
#include "ShmConnect.h"



class ShmBase : public IOBase
{
public:
	ShmBase(ServerTypeType shmType, const char* shmName, int milliSeconds);
	virtual ~ShmBase();

	virtual bool Init() override;
protected:
	virtual void DoSend(Connect* connect) override;
	virtual void DoRecv(Connect* connect) override;


private:
	bool WindowsInit();
	bool LinuxInit();

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
