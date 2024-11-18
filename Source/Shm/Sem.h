#pragma once
#include <string>
#ifdef LINUX
#include <semaphore.h>
#endif


class Sem
{
public:
	Sem(const char* name, unsigned timeOutMilliSecond = 100);
	~Sem();
	bool Init();
	bool Lock();
	bool UnLock();

	std::string m_SemName;
#ifdef LINUX
	sem_t* m_Sem;
	timespec m_TimeOutTimeSpec;
#endif
#ifdef WINDOWS
	void* m_Sem;
	unsigned m_TimeOutMilliSecond;
#endif
};

