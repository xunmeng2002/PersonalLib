#include "Protocol.h"
#include "Logger.h"
#include "IOFactory.h"
#include <stdexcept>

Protocol::Protocol(ProtocolTypeType protocolType, ServerTypeType serverType, int milliSeconds, PackageFactory* packageFactory)
	:m_ProtocolType(protocolType), m_ServerType(serverType), m_MilliSeconds(milliSeconds), m_Subscriber(nullptr), m_PackageFactory(packageFactory), m_IOBase(nullptr), m_IOThread(nullptr)
{
}
Protocol::~Protocol()
{
	if (m_IOBase != nullptr)
	{
		delete m_IOBase;
		m_IOBase = nullptr;
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
	if (m_IOBase != nullptr)
	{
		delete m_IOBase;
	}
	m_IOBase = IOFactory::CreateIO(m_ServerType, address, m_MilliSeconds);
	m_IOBase->Subscribe(this);
	if (m_IOThread != nullptr)
	{
		m_IOThread->SetIO(m_IOBase);
	}
}
void Protocol::SetIOThread(IOThread* ioThread)
{
	m_IOThread = ioThread;
	if (m_IOBase != nullptr)
	{
		m_IOThread->SetIO(m_IOBase);
	}
}
void Protocol::SetTimeOut(int milliSeconds)
{
	m_MilliSeconds = milliSeconds;
	if (m_IOBase != nullptr)
	{
		m_IOBase->SetTimeOut(milliSeconds);
	}
}
bool Protocol::Start()
{
	if (m_IOThread != nullptr)
	{
		return m_IOThread->Start();
	}
	return false;
}
void Protocol::Stop()
{
	if (m_IOThread != nullptr)
	{
		m_IOThread->Stop();
	}
}
void Protocol::Join()
{
	if (m_IOThread != nullptr)
	{
		m_IOThread->Join();
	}
}
bool Protocol::Init()
{
	if (m_IOBase == nullptr)
		return false;
	return m_IOBase->Init();
}
IOBase* Protocol::GetIO()
{
	return m_IOBase;
}
IOThread* Protocol::GetIOThread()
{
	return m_IOThread;
}

void Protocol::DisConnect(SessionIDType sessionID)
{
	if (m_IOBase == nullptr)
		return;
	m_IOBase->DisConnect(sessionID);
}
bool Protocol::Send(Package* package)
{
	if (m_IOBase == nullptr)
		return false;
	Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
	buffer->SetLength(package->MakePackage(m_ProtocolType, buffer->GetData(), BuffSize));
	while (buffer->GetLength() > 0)
	{
		auto sendLen = m_IOBase->Send(package->SessionID, buffer);
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
		m_Subscriber->OnProtocolConnect(sessionID, ip, port);
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
		m_Subscriber->OnProtocolDisConnect(sessionID, ip, port);
	}
}
void Protocol::OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
	if (m_IOBase == nullptr)
		return;
	auto packageReader = m_SessionPackageReaders[sessionID];
	if (packageReader == nullptr)
	{
		WriteLog(LogLevel::Error, "Cannot Find PackageReader for SessionID:%lld", sessionID);
		m_IOBase->DisConnect(sessionID);
		return;
	}
	packageReader->Append(buffer->GetData(), buffer->GetLength());
	buffer->Free();
	while (true)
	{
		Package* package = nullptr;
		if (!packageReader->ParsePackage(package))
		{
			m_IOBase->DisConnect(sessionID);
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

