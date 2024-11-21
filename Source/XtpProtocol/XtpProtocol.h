#pragma once
#include "XtpPackageReader.h"
#include "XtpInterface.h"
#include "IOThread.h"
#include <map>

namespace xtp
{
	class XtpProtocol : public IOSubscriber
	{
	public:
		XtpProtocol(ServerTypeType serverType, IOTypeType ioType, const char* threadName, const char* addressName, XtpPackageFactoryBase* xtpPackageFactory);
		virtual ~XtpProtocol();
		void SubscribeXtp(XtpSubscriber* xtpSubscriber);
		void UnSubscribeXtp();
		virtual bool Init();

		bool Start();
		void Stop();
		void Join();

		virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
		virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
		virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

		void DisConnect(SessionIDType sessionID);
		virtual bool Send(XtpPackageBase* xtpPackage);

	protected:
		IOThread* m_IOThread;
		XtpPackageFactoryBase* m_XtpPackageFactory;
		XtpSubscriber* m_XtpSubscriber;

		std::map<SessionIDType, XtpPackageReader*> m_SessionPackageReaders;
	};
}

