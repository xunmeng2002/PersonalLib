#pragma once
#include "PackageReader.h"
#include "PackageFactory.h"
#include "ProtocolSubscriber.h"
#include "IOBase.h"
#include "IOThread.h"
#include <map>

class Protocol : public IOSubscriber
{
public:
	Protocol(ProtocolTypeType protocolType, ServerTypeType serverType, int milliSeconds, PackageFactory* packageFactory);
	~Protocol();
	void Subscribe(ProtocolSubscriber* subscriber);
	void UnSubscribe();
	void RegisterFront(const char* address);
	void SetTimeOut(int milliSeconds);
	void SetIOThread(IOThread* ioThread);
	virtual bool Init();
	IOBase* GetIO();
	IOThread* GetIOThread();

	void DisConnect(SessionIDType sessionID);
	virtual bool Send(Package* package);

	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

protected:
	ProtocolTypeType m_ProtocolType;
	ServerTypeType m_ServerType;
	int m_MilliSeconds;
	IOBase* m_IOBase;
	IOThread* m_IOThread;
	PackageFactory* m_PackageFactory;
	ProtocolSubscriber* m_Subscriber;
	std::map<SessionIDType, PackageReader*> m_SessionPackageReaders;
};

