#pragma once
#include <PersonalLib/Network/NetworkExport.h>
#include <PersonalLib/Types.h>
#include <PersonalLib/TemplateLib/Buffer/Buffer.h>
#include <PersonalLib/Network/IO/IOBase.h>
#include <PersonalLib/Network/Shm/Sem.h>
#include <PersonalLib/Network/Shm/ShmConnect.h>
#include <string>
#include <map>
#include <list>
#include <mutex>
#include <chrono>



class NETWORK_EXPORTS ShmBase : public IOBase
{
public:
	ShmBase(ServerTypeType shmType, const char* shmName, int milliSeconds);
	virtual ~ShmBase();

	virtual bool Init() override;
	virtual void Send(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

	virtual void HandleIOEvent() override;
protected:
	virtual void DoSend(Connect* connect) override;
	virtual void DoRecv(Connect* connect) override;

	virtual void ConnectToServer() {}
	virtual void Accept() {}
	virtual void CheckConnect() = 0;
	virtual void CheckData() = 0;
	virtual void HandleData() = 0;

private:
	bool WindowsInit();
	bool LinuxInit();

protected:
	std::string m_ShmName;
	unsigned m_MaxConnectSize;
	SingleShmHeader* m_CommonShmHeader;
	void* m_ShmAddr;
	Sem* m_SemConnect;
	std::vector<Sem*> m_Sems;

	std::chrono::steady_clock::time_point m_LastSendTime;

#ifdef WINDOWS
	void* m_File;
	void* m_FileMap;
#endif // WINDOWS
};
