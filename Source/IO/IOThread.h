#pragma once
#include "ThreadBase.h"
#include "IOBase.h"
#include "Types.h"
#include "Buffer.h"
#include "Connect.h"
#include <string>
#include <mutex>
#include <list>
#include <map>



class IOThread : public ThreadBase
{
public:
	IOThread(const char* threadName);
	~IOThread();
	void SetIO(IOBase* io);

protected:
	virtual void Run() override;
	virtual void ThreadExit() override;

private:
	IOBase* m_IO;
};

