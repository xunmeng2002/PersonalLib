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
	void CheckConnect();
	void DoDisConnect();

	virtual void RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect) override;
	virtual ShmConnect<ShmBuffSize>* GetShmConnect(SessionIDType sessionID) override;
protected:
	bool m_Connected;
	bool m_HasSendConnected;
	SessionIDType m_SessionID;
	ShmConnect<ShmBuffSize>* m_ShmConnect;
};
