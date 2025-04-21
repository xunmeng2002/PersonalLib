#include "IOBase.h"
#include "IOUtility.h"
#include "TimeUtility.h"
#include "Logger.h"

using namespace std;

IOBase::IOBase(ServerTypeType serverType, const char* addressName, int milliSeconds)
	:m_ServerType(serverType), m_AddressName(addressName), m_TimeOut(chrono::milliseconds(milliSeconds)), m_IOSubscriber(nullptr), m_LastSessionIndex(0LL), m_Connected(false)
{
	ParseAddress(m_AddressName, m_Address, m_Port);
}
IOBase::~IOBase()
{
	DisConnectAll();
}
void IOBase::Subscribe(IOSubscriber* subscriber)
{
	m_IOSubscriber = subscriber;
}
void IOBase::UnSubscribe()
{
	m_IOSubscriber = nullptr;
}
void IOBase::SetTimeOut(int milliSeconds)
{
	m_TimeOut = std::chrono::milliseconds(milliSeconds);
}

void IOBase::RegisterFront(const char* address)
{
	ParseAddress(address, m_Address, m_Port);
}
void IOBase::DisConnect(SessionIDType sessionID)
{
	lock_guard<mutex> guard(m_DisConnectSessionIDsMutex);
	m_DisConnectSessionIDs.push_back(sessionID);
}
void IOBase::DoDisConnect()
{
	if (m_DisConnectSessionIDs.empty())
		return;

	lock_guard<mutex> guard(m_DisConnectSessionIDsMutex);
	for (auto sessionID : m_DisConnectSessionIDs)
	{
		auto connect = m_Connects[sessionID];
		if (connect == nullptr)
		{
			m_Connects.erase(sessionID);
		}
		else
		{
			RemoveConnect(connect);
		}
	}
	m_DisConnectSessionIDs.clear();
}
void IOBase::AddConnect(Connect* connect)
{
	WriteLog(LogLevel::Info, "New Connection. SessionID:%lld, RemoteAddress:%s, RemotePort:%d",
		connect->SessionID, connect->RemoteAddress, connect->RemotePort);
	if (m_ServerType == ServerTypeType::Client)
	{
		m_Connected = true;
	}
	{
		std::lock_guard<std::mutex> guard(m_ConnectsMutex);
		m_Connects.insert(std::make_pair(connect->SessionID, connect));
	}
	if (m_IOSubscriber)
	{
		m_IOSubscriber->OnConnect(connect->SessionID, connect->RemoteAddress, connect->RemotePort);
	}
}
void IOBase::RemoveConnect(Connect* connect)
{
	WriteLog(LogLevel::Info, "RemoveConnect. SessionID:%lld,  RemoteAddress:%s, RemotePort:%d",
		connect->SessionID, connect->RemoteAddress, connect->RemotePort);
	if (m_ServerType == ServerTypeType::Client)
	{
		m_Connected = false;
	}
	if (m_IOSubscriber)
	{
		m_IOSubscriber->OnDisConnect(connect->SessionID, connect->RemoteAddress, connect->RemotePort);
	}
	std::lock_guard<std::mutex> guard(m_ConnectsMutex);
	m_Connects.erase(connect->SessionID);
	connect->Free();
}
Connect* IOBase::GetConnect(SessionIDType sessionID)
{
	std::lock_guard<std::mutex> guard(m_ConnectsMutex);
	if (m_Connects.find(sessionID) == m_Connects.end())
	{
		WriteLog(LogLevel::Warning, "Connect not Exist For SessionID:%lld", sessionID);
		return nullptr;
	}
	return m_Connects[sessionID];
}


SessionIDType IOBase::GetSessionID()
{
	return GetMilliSecondTimeStamp() * 100LL + (++m_LastSessionIndex) % 100LL;
}
void IOBase::DisConnectAll()
{
	WriteLog(LogLevel::Info, "DisConnectAll");
	std::map<SessionIDType, Connect*> connects(m_Connects.begin(), m_Connects.end());
	for (auto& it : connects)
	{
		RemoveConnect(it.second);
	}
}


