#pragma once
#include <string>
#ifdef LINUX
#include <semaphore.h>
#endif


class Sem
{
public:
	Sem(const char* name);
	~Sem();
	bool Init();
	bool Lock();
	bool UnLock();

	std::string m_SemName;
#ifdef LINUX
	sem_t* m_Sem;
#endif
#ifdef WINDOWS
	void* m_Sem;
#endif
};

