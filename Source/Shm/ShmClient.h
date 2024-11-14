#pragma once
#include "ShmBase.h"



class ShmClient : public ShmBase
{
public:
	ShmClient(const char* threadName, const char* shmName);
	virtual ~ShmClient();

protected:
	virtual void Run() override;
	void Connect();


	virtual void RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect) override;
protected:
	bool m_Connected;
	bool m_HasSendConnected;
};
