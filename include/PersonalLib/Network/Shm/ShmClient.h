#pragma once
#include "PersonalLib/Network/NetworkExport.h"
#include "PersonalLib/Network/Shm/ShmBase.h"



class NETWORK_EXPORTS ShmClient : public ShmBase
{
public:
	ShmClient(const char* shmName, int milliSeconds);
	virtual ~ShmClient();

protected:
	virtual void ConnectToServer() override;
	virtual void CheckConnect() override;
	virtual void CheckData() override;
	virtual void HandleData() override;


	void SendConnect();
	void CheckConnectResult();
	virtual void RemoveConnect(::Connect* connect) override;
protected:
	bool m_Connected;
	bool m_HasSendConnect;
	ShmConnect<ShmBuffSize>* m_ShmConnect;
};
