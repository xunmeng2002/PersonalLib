#pragma once
#include "ShmBase.h"



class ShmClient : public ShmBase
{
public:
	ShmClient(const char* shmName, int milliSeconds);
	virtual ~ShmClient();

protected:
	virtual void HandleIOEvent() override;

	void Connect();
	void CheckConnectStatus();

	void SendConnect();
	void CheckConnect();

	virtual void RemoveConnect(::Connect* connect) override;
protected:
	bool m_Connected;
	bool m_HasSendConnect;
	ShmConnect<ShmBuffSize>* m_ShmConnect;
};
