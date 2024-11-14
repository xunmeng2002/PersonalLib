#pragma once
#include "ShmBase.h"



class ShmServer : public ShmBase
{
public:
	ShmServer(const char* threadName, const char* shmName);
	~ShmServer();

	virtual void Run() override;
	void Accept();

protected:
	unsigned m_ConnectCount;
};


