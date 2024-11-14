#pragma once
#include "StepPackageReader.h"
#include "StepInterface.h"
#include "IOThread.h"
#include <map>

namespace step
{
	class StepProtocol : public IOSubscriber
	{
	public:
		StepProtocol(ServerTypeType serverType, IOTypeType ioType, const char* threadName, const char* addressName, StepPackageFactoryBase* stepPackageFactory);
		~StepProtocol();
		void SubscribeStep(StepSubscriber* stepSubscriber);
		void UnSubscribeStep();
		virtual bool Init();
		
		bool Start();
		void Stop();
		void Join();
	
		void DisConnect(SessionIDType sessionID);
		virtual bool Send(StepPackageBase* stepPackage);

		virtual void OnConnect(SessionIDType sessionID, const char* ip, const char* port) override;
		virtual void OnDisConnect(SessionIDType sessionID, const char* ip, const char* port) override;
		virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

	protected:
		IOThread* m_IOThread;
		StepPackageFactoryBase* m_StepPackageFactory;
		StepSubscriber* m_StepSubscriber;
		std::map<SessionIDType, StepPackageReader*> m_SessionPackageReaders;
	};
}

