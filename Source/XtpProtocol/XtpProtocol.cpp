#include "XtpProtocol.h"
#include "Logger.h"
#include "IOThreadFactory.h"
#include <assert.h>

namespace xtp
{
	XtpProtocol::XtpProtocol(ServerTypeType serverType, IOTypeType ioType, const char* threadName, const char* addressName, XtpPackageFactoryBase* xtpPackageFactory)
		:m_XtpSubscriber(nullptr), m_XtpPackageFactory(xtpPackageFactory)
	{
		m_IOThread = IOThreadFactory::CreateIOThread(serverType, ioType, threadName, addressName);
		if (m_IOThread != nullptr)
		{
			m_IOThread->Subscribe(this);
		}
	}
	XtpProtocol::~XtpProtocol()
	{
		if (m_IOThread != nullptr)
		{
			delete m_IOThread;
			m_IOThread = nullptr;
		}
	}
	void XtpProtocol::SubscribeXtp(XtpSubscriber* xtpSubscriber)
	{
		m_XtpSubscriber = xtpSubscriber;
	}
	void XtpProtocol::UnSubscribeXtp()
	{
		m_XtpSubscriber = nullptr;
	}
	bool XtpProtocol::Init()
	{
		if (m_IOThread == nullptr)
			return false;
		return m_IOThread->Init();
	}

	bool XtpProtocol::Start()
	{
		if (m_IOThread == nullptr)
			return false;
		return m_IOThread->Start();
	}
	void XtpProtocol::Stop()
	{
		if (m_IOThread == nullptr)
			return;
		m_IOThread->Stop();
	}
	void XtpProtocol::Join()
	{
		if (m_IOThread == nullptr)
			return;
		m_IOThread->Join();
	}

	void XtpProtocol::OnConnect(SessionIDType sessionID, const char* ip, int port)
	{
		WriteLog(LogLevel::Info, "XtpProtocol::OnConnect SessionID:%lld, IP:%s, Port:%d", sessionID, ip, port);
		m_SessionPackageReaders.insert(std::make_pair(sessionID, XtpPackageReader::Allocate(m_XtpPackageFactory, sessionID, ip)));
		if (m_XtpSubscriber)
		{
			m_XtpSubscriber->OnXtpConnect(sessionID, ip, port);
		}
	}
	void XtpProtocol::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
	{
		WriteLog(LogLevel::Info, "XtpProtocol::OnDisConnect SessionID:%lld, IP:%s, Port:%d", sessionID, ip, port);
		if (m_SessionPackageReaders.find(sessionID) != m_SessionPackageReaders.end())
		{
			m_SessionPackageReaders[sessionID]->Free();
			m_SessionPackageReaders.erase(sessionID);
		}
		if (m_XtpSubscriber)
		{
			m_XtpSubscriber->OnXtpDisConnect(sessionID, ip, port);
		}
	}
	void XtpProtocol::OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer)
	{
		if (m_IOThread == nullptr)
			return;
		auto xtpPackageReader = m_SessionPackageReaders[sessionID];
		if (xtpPackageReader == nullptr)
		{
			WriteLog(LogLevel::Error, "Cannot Find XtpPackageReader for SessionID:%lld", sessionID);
			m_IOThread->DisConnect(sessionID);
			return;
		}
		xtpPackageReader->Append(buffer->GetData(), buffer->GetLength());
		buffer->Free();
		while (true)
		{
			XtpPackageBase* xtpPackage = nullptr;
			if (!xtpPackageReader->ParsePackage(xtpPackage))
			{
				m_IOThread->DisConnect(xtpPackageReader->m_SessionID);
				break;
			}
			else if (xtpPackage == nullptr)
			{
				break;
			}
			else if (m_XtpSubscriber != nullptr)
			{
				m_XtpSubscriber->OnXtpMessage(xtpPackage);
			}
		}
	}
	void XtpProtocol::DisConnect(SessionIDType sessionID)
	{
		if (m_IOThread == nullptr)
			return;
		m_IOThread->DisConnect(sessionID);
	}
	bool XtpProtocol::Send(XtpPackageBase* xtpPackage)
	{
		if (m_IOThread == nullptr)
			return false;
		Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
		buffer->SetLength(xtpPackage->MakePackage(buffer->GetData(), BuffSize));
		while (buffer->GetLength() > 0)
		{
			auto sendLen = m_IOThread->Send(xtpPackage->SessionID, buffer);
			if (sendLen < 0)
			{
				WriteLog(LogLevel::Warning, "XtpProtocol::Send Failed. sendLen:%d", sendLen);
				return false;
			}
			buffer->Shift(sendLen);
		}
		buffer->Free();
		return true;
	}
}

