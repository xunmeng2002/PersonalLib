#pragma once
#include "ShmBase.h"
#include <chrono>


class ShmServer : public ShmBase
{
public:
	ShmServer(const char* threadName, const char* shmName);
	~ShmServer();

	virtual void Run() override;
	void Accept();
	void CheckConnect();
	void DoDisConnect();
	void HandleEvent();

	virtual ShmConnect<ShmBuffSize>* AddConnect(int index) override;
	virtual void RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect) override;
	virtual ShmConnect<ShmBuffSize>* GetShmConnect(SessionIDType sessionID) override;
protected:
	unsigned m_ConnectCount;
	std::chrono::system_clock::time_point m_LastWriteTimePoint;
};


