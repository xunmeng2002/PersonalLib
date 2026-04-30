#pragma once
#include "ThreadBase/ThreadBase.h"
#include "IO/IOBase.h"
#include "Types/Types.h"
#include "Buffer/Buffer.h"
#include "IO/Connect.h"
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

