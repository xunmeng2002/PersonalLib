#pragma once
#include <thread>
#include <atomic>
#include <string>
#include <chrono>
#include <mutex>
#include <condition_variable>

class ThreadBase
{
public:
	ThreadBase(const char* name, int milliSeconds = 100);
	virtual ~ThreadBase();
	
	virtual void SetTimeOut(int milliSeconds);
	virtual bool Start();
	virtual void Stop();
	virtual void Join();
	
protected:
	void ThreadFunc();
	virtual void ThreadInit();
	virtual void ThreadExit();


	virtual void Run() = 0;
	

protected:
	std::thread m_Thread;
	std::string m_ThreadName;
	std::atomic<bool> m_ShouldRun;
	
	std::chrono::milliseconds m_TimeOut;
	std::mutex m_Mutex;
	std::condition_variable m_ThreadConditionVariable;
};

