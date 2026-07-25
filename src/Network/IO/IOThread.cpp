#include <PersonalLib/Network/IO/IOThread.h>
#include <PersonalLib/Network/IO/IOUtility.h>
#include <PersonalLib/Core/Utility/TimeUtility.h>
#include <PersonalLib/Core/Logger/Logger.h>

using namespace std;

IOThread::IOThread(const char* threadName)
	:ThreadBase(threadName), m_IO(nullptr)
{
}
IOThread::~IOThread()
{
	if (m_IO)
		delete m_IO;
}

void IOThread::SetIO(IOBase* io)
{
	m_IO = io;
}
void IOThread::Run()
{
	if (m_IO)
		m_IO->HandleIOEvent();
}
void IOThread::ThreadExit()
{
	ThreadBase::ThreadExit();
	m_IO->DisConnectAll();
}

