#include "Protocol.h"
#include "Logger.h"
#include "IOThreadFactory.h"
#include <stdexcept>

Protocol::Protocol(ProtocolTypeType protocolType, ServerTypeType serverType, const char* threadName, PackageFactory* packageFactory)
	:m_ProtocolType(protocolType), m_ServerType(serverType), m_ThreadName(threadName), m_Subscriber(nullptr), m_PackageFactory(packageFactory), m_IOThread(nullptr)
{
}
Protocol::~Protocol()
{
	if (m_IOThread != nullptr)
	{
		delete m_IOThread;
		m_IOThread = nullptr;
	}
}
void Protocol::Subscribe(ProtocolSubscriber* subscriber)
{
	m_Subscriber = subscriber;
}
void Protocol::UnSubscribe()
{
	m_Subscriber = nullptr;
}
void Protocol::RegisterFront(const char* address)
{
	if (m_IOThread != nullptr)
	{
		delete m_IOThread;
	}
	m_IOThread = IOThreadFactory::CreateIOThread(m_ServerType, m_ThreadName.c_str(), address);
	m_IOThread->Subscribe(this);
}
bool Protocol::Init()
{
	if (m_IOThread == nullptr)
		return false;
	return m_IOThread->Init();
}
	
bool Protocol::Start()
{
	if (m_IOThread == nullptr)
		return false;
	return m_IOThread->Start();
}
void Protocol::Stop()
{
	if (m_IOThread == nullptr)
		return;
	m_IOThread->Stop();
}
void Protocol::Join()
{
	if (m_IOThread == nullptr)
		return;
	m_IOThread->Join();
}

void Protocol::DisConnect(SessionIDType sessionID)
{
	if (m_IOThread == nullptr)
		return;
	m_IOThread->DisConnect(sessionID);
}
bool Protocol::Send(Package* package)
{
	if (m_IOThread == nullptr)
		return false;
	Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
	buffer->SetLength(package->MakePackage(m_ProtocolType, buffer->GetData(), BuffSize));
	while (buffer->GetLength() > 0)
	{
		auto sendLen = m_IOThread->Send(package->SessionID, buffer);
		if (sendLen < 0)
		{
			WriteLog(LogLevel::Warning, "Protocol::Send Failed. sendLen:%d", sendLen);
			return false;
		}
		buffer->Shift(sendLen);
	}
	buffer->Free();
	return true;
}

void Protocol::OnConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "Protocol::OnConnect SessionID:%lld, IP:%s, Port:%d", sessionID, ip, port);
	m_SessionPackageReaders.insert(std::make_pair(sessionID, PackageReader::Allocate(m_ProtocolType, m_PackageFactory, sessionID, ip)));
	if (m_Subscriber)
	{
		m_Subscriber->OnConnect(sessionID, ip, port);
	}
}
void Protocol::OnDisConnect(SessionIDType sessionID, const char* ip, int port)
{
	WriteLog(LogLevel::Info, "Protocol::OnDisConnect SessionID:%lld, IP:%s, Port:%d", sessionID, ip, port);
	if (m_SessionPackageReaders.find(sessionID) != m_SessionPackageReaders.end())
	{
		m_SessionPackageReaders[sessionID]->Free();
		m_SessionPackageReaders.erase(sessionID);
	}
	if (m_Subscriber)
	{
		m_Subscriber->OnDisConnect(sessionID, ip, port);
	}
}
void Protocol::OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
	if (m_IOThread == nullptr)
		return;
	auto packageReader = m_SessionPackageReaders[sessionID];
	if (packageReader == nullptr)
	{
		WriteLog(LogLevel::Error, "Cannot Find PackageReader for SessionID:%lld", sessionID);
		m_IOThread->DisConnect(sessionID);
		return;
	}
	packageReader->Append(buffer->GetData(), buffer->GetLength());
	buffer->Free();
	while (true)
	{
		Package* package = nullptr;
		if (!packageReader->ParsePackage(package))
		{
			m_IOThread->DisConnect(sessionID);
			break;
		}
		else if (package == nullptr)
		{
			break;
		}
		else if (m_Subscriber != nullptr)
		{
			m_Subscriber->OnMessage(package);
		}
	}
}

