#include "IOThread.h"
#include "TimeUtility.h"



IOThread::IOThread(const char* threadName, const char* addressName, int milliSeconds)
	:ThreadBase(threadName, milliSeconds), m_AddressName(addressName), m_IOSubscriber(nullptr), m_LastSessionIndex(0LL)
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
SessionIDType IOThread::GetSessionID()
{
	return GetMilliSecondTimeStamp() * 100LL + (++m_LastSessionIndex) % 100LL;
}
