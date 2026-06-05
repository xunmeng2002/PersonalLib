#pragma once
#include "PersonalLib/Core/Thread/ThreadBase.h"
#include "PersonalLib/Network/IO/IOBase.h"
#include "PersonalLib/Types.h"
#include "PersonalLib/Core/Buffer/Buffer.h"
#include "PersonalLib/Network/IO/Connect.h"
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

