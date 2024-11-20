#include "IOThread.h"
#include "TimeUtility.h"

using namespace std;

IOThread::IOThread(ServerTypeType serverType, const char* threadName, const char* addressName, int milliSeconds)
	:ThreadBase(threadName, milliSeconds), m_ServerType(serverType), m_AddressName(addressName), m_IOSubscriber(nullptr), m_LastSessionIndex(0LL)
{
}
void IOThread::Subscribe(IOSubscriber* subscriber)
{
	m_IOSubscriber = subscriber;
}
void IOThread::UnSubscribe()
{
	m_IOSubscriber = nullptr;
}
void IOThread::DisConnect(SessionIDType sessionID)
{
	lock_guard<mutex> guard(m_DisConnectSessionIDsMutex);
	m_DisConnectSessionIDs.push_back(sessionID);
}
SessionIDType IOThread::GetSessionID()
{
	return GetMilliSecondTimeStamp() * 100LL + (++m_LastSessionIndex) % 100LL;
}
