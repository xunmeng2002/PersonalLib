#pragma once
#include "PackageReader.h"
#include "PackageFactory.h"
#include "ProtocolSubscriber.h"
#include "IOThread.h"
#include <map>

class Protocol : public IOSubscriber
{
public:
	Protocol(ProtocolTypeType protocolType, ServerTypeType serverType, const char* threadName, PackageFactory* packageFactory);
	~Protocol();
	void Subscribe(ProtocolSubscriber* subscriber);
	void UnSubscribe();
	void RegisterFront(const char* address);
	virtual bool Init();

	bool Start();
	void Stop();
	void Join();

	void DisConnect(SessionIDType sessionID);
	virtual bool Send(Package* package);

	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

protected:
	ProtocolTypeType m_ProtocolType;
	ServerTypeType m_ServerType;
	std::string m_ThreadName;
	IOThread* m_IOThread;
	PackageFactory* m_PackageFactory;
	ProtocolSubscriber* m_Subscriber;
	std::map<SessionIDType, PackageReader*> m_SessionPackageReaders;
};

