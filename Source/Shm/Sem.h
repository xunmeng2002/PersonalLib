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
	unsigned m_TimeOutMilliSecond;
#ifdef LINUX
	sem_t* m_Sem;
#endif
#ifdef WINDOWS
	void* m_Sem;
#endif
};

