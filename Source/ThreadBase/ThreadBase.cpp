#include <functional>
#include "ThreadBase/ThreadBase.h"
#include "Logger/Logger.h"


ThreadBase::ThreadBase(const char* name, int milliSeconds)
	:m_ShouldRun(false), m_TimeOut(milliSeconds)
{
	m_ThreadName = name;
}
ThreadBase::~ThreadBase()
{
	Stop();
	Join();
}

void ThreadBase::SetTimeOut(int milliSeconds)
{
	m_TimeOut = std::chrono::milliseconds(milliSeconds);
}
bool ThreadBase::Start()
{
	if (m_ShouldRun.load())
		return false;

	m_ShouldRun.store(true);
	m_Thread = std::thread(std::bind(&ThreadBase::ThreadFunc, this));
	return true;
}
void ThreadBase::Stop()
{
	m_ShouldRun.store(false);
}
void ThreadBase::Join()
{
	if (m_Thread.joinable())
		m_Thread.join();
}

void ThreadBase::ThreadFunc()
{
	ThreadInit();
	while (m_ShouldRun.load())
	{
		Run();
	}
	ThreadExit();
}
void ThreadBase::ThreadInit()
{
	WriteLog(LogLevel::Info, "Thread:%s Start", m_ThreadName.c_str());
}
void ThreadBase::ThreadExit()
{
	WriteLog(LogLevel::Info, "Thread:%s Exit", m_ThreadName.c_str());
}

