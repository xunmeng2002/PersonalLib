#include "Sem.h"
#include "Logger.h"
#ifdef WINDOWS
#include <Windows.h>
#endif
#ifdef LINUX
#include <unistd.h>
#include <fcntl.h>
#endif


Sem::Sem(const char* name, unsigned timeOutMilliSecond)
	:m_SemName(name), m_Sem(nullptr)
{
#ifdef WINDOWS
	m_TimeOutMilliSecond = timeOutMilliSecond;
#endif
#ifdef LINUX
	m_TimeOutTimeSpec.tv_sec = timeOutMilliSecond / 1000;
	m_TimeOutTimeSpec.tv_nsec = (timeOutMilliSecond % 1000) * 1000000;
#endif
}
Sem::~Sem()
{
	if (m_Sem != nullptr)
	{
#ifdef WINDOWS
		CloseHandle(m_Sem);
#endif
#ifdef LINUX
		sem_close(m_Sem);
		sem_unlink(m_SemName.c_str());
#endif
		m_Sem = nullptr;
	}
}
bool Sem::Init()
{
#ifdef WINDOWS
	m_Sem = CreateSemaphoreA(NULL, 1, 1, m_SemName.c_str());
	if (m_Sem == nullptr)
	{
		WriteLog(LogLevel::Error, "CreateSemaphoreA Failed. LastError:%d", GetLastError());
		m_Sem = OpenSemaphoreA(SEMAPHORE_ALL_ACCESS, FALSE, m_SemName.c_str());
		if (m_Sem == nullptr)
		{
			WriteLog(LogLevel::Error, "OpenSemaphoreA Failed. LastError:%d", GetLastError());
		}
	}
	if (m_Sem == nullptr)
	{
		WriteLog(LogLevel::Info, "Create Or Open Semaphore Success.");
		return false;
	}
#endif
#ifdef LINUX
	m_Sem = sem_open(m_SemName.c_str(), O_CREAT, 0666, 1);
	if (m_Sem == nullptr)
	{
		m_Sem = sem_open(m_SemName.c_str(), O_EXCL, 0666, 1);
		if (m_Sem == nullptr)
		{
			WriteLog(LogLevel::Warning, "sem_open Failed. ErrNo:%d", errno);
			return false;
		}
	}
#endif
	return true;
}
bool Sem::Lock()
{
#ifdef WINDOWS
	return WaitForSingleObject(m_Sem, m_TimeOutMilliSecond) == WAIT_OBJECT_0;
#endif
#ifdef LINUX
	return sem_timedwait(m_Sem, &m_TimeOutTimeSpec) == 0;
#endif
}
bool Sem::UnLock()
{
	bool result;
#ifdef WINDOWS
	result = ReleaseSemaphore(m_Sem, 1, NULL);
#endif
#ifdef LINUX
	result = sem_post(m_Sem) == 0;
#endif
	if (!result)
	{
		WriteLog(LogLevel::Error, "Sem UnLock Failed.");
	}
	return result;
}

