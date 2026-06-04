#pragma once
#include "Core/Thread/ThreadBase.h"
#include "Network/IO/IOBase.h"
#include "Types.h"
#include "Core/Buffer/Buffer.h"
#include "Network/IO/Connect.h"
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

