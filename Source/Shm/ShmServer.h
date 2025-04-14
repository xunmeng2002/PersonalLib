#pragma once
#include "ShmBase.h"
#include <chrono>


class ShmServer : public ShmBase
{
public:
	ShmServer(const char* shmName, int milliSeconds);
	~ShmServer();

	virtual void HandleIOEvent() override;
	void Accept();
	void CheckConnect();

	virtual void RemoveConnect(Connect* connect) override;
protected:
	unsigned m_ConnectCount;
	std::chrono::system_clock::time_point m_LastWriteTimePoint;
};


