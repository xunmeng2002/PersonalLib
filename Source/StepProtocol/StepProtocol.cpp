#include "StepProtocol.h"
#include "Logger.h"
#include "IOThreadFactory.h"


namespace step
{
	StepProtocol::StepProtocol(ServerTypeType serverType, IOTypeType ioType, const char* threadName, const char* addressName, StepPackageFactoryBase* stepPackageFactory)
		:m_StepSubscriber(nullptr), m_StepPackageFactory(stepPackageFactory)
	{
		m_IOThread = IOThreadFactory::CreateIOThread(serverType, ioType, threadName, addressName);
		if (m_IOThread != nullptr)
		{
			m_IOThread->Subscribe(this);
		}
	}
	StepProtocol::~StepProtocol()
	{
		if (m_IOThread != nullptr)
		{
			delete m_IOThread;
			m_IOThread = nullptr;
		}
	}
	void StepProtocol::SubscribeStep(StepSubscriber* stepSubscriber)
	{
		m_StepSubscriber = stepSubscriber;
	}
	void StepProtocol::UnSubscribeStep()
	{
		m_StepSubscriber = nullptr;
	}
	bool StepProtocol::Init()
	{
		if (m_IOThread == nullptr)
			return false;
		return m_IOThread->Init();
	}
	
	bool StepProtocol::Start()
	{
		if (m_IOThread == nullptr)
			return false;
		return m_IOThread->Start();
	}
	void StepProtocol::Stop()
	{
		if (m_IOThread == nullptr)
			return;
		m_IOThread->Stop();
	}
	void StepProtocol::Join()
	{
		if (m_IOThread == nullptr)
			return;
		m_IOThread->Join();
	}

	void StepProtocol::DisConnect(SessionIDType sessionID)
	{
		if (m_IOThread == nullptr)
			return;
		m_IOThread->DisConnect(sessionID);
	}
	bool StepProtocol::Send(StepPackageBase* stepPackage)
	{
		if (m_IOThread == nullptr)
			return false;
		Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
		buffer->SetLength(stepPackage->MakePackage(buffer->GetData(), BuffSize));
		while (buffer->GetLength() > 0)
		{
			auto sendLen = m_IOThread->Send(stepPackage->SessionID, buffer);
			if (sendLen < 0)
				return false;
			buffer->Shift(sendLen);
		}
		buffer->Free();
		return true;
	}

	void StepProtocol::OnConnect(SessionIDType sessionID, const char* ip, int port)
	{
		WriteLog(LogLevel::Info, "StepProtocol::OnConnect SessionID:%lld, IP:%s, Port:%d", sessionID, ip, port);
		m_SessionPackageReaders.insert(std::make_pair(sessionID, StepPackageReader::Allocate(m_StepPackageFactory, sessionID, ip)));
		if (m_StepSubscriber)
		{
			m_StepSubscriber->OnStepConnect(sessionID, ip, port);
		}
	}
	void StepProtocol::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
	{
		WriteLog(LogLevel::Info, "StepProtocol::OnDisConnect SessionID:%lld, IP:%s, Port:%d", sessionID, ip, port);
		if (m_SessionPackageReaders.find(sessionID) != m_SessionPackageReaders.end())
		{
			m_SessionPackageReaders[sessionID]->Free();
			m_SessionPackageReaders.erase(sessionID);
		}
		if (m_StepSubscriber)
		{
			m_StepSubscriber->OnStepDisConnect(sessionID, ip, port);
		}
	}
	void StepProtocol::OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer)
	{
		if (m_IOThread == nullptr)
			return;
		auto stepPackageReader = m_SessionPackageReaders[sessionID];
		if (stepPackageReader == nullptr)
		{
			WriteLog(LogLevel::Error, "Cannot Find StepPackageReader for SessionID:%lld", sessionID);
			m_IOThread->DisConnect(sessionID);
			return;
		}
		stepPackageReader->Append(buffer->GetData(), buffer->GetLength());
		buffer->Free();
		while (true)
		{
			StepPackageBase* stepPackage = nullptr;
			if (!stepPackageReader->ParsePackage(stepPackage))
			{
				m_IOThread->DisConnect(stepPackageReader->m_SessionID);
				break;
			}
			else if (stepPackage == nullptr)
			{
				break;
			}
			else if (m_StepSubscriber != nullptr)
			{
				m_StepSubscriber->OnStepMessage(stepPackage);
			}
		}
	}
}
