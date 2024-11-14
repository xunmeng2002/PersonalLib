#include "IOThreadFactory.h"
#include "TimeUtility.h"
#ifdef LINUX
#include "TcpEpollClient.h"
#include "TcpEpollServer.h"
#elif defined WINDOWS
#include "TcpSelectClient.h"
#include "TcpSelectServer.h"
#endif
#include "SingleShm.h"
#include "ShmClient.h"
#include "ShmServer.h"



IOThread* IOThreadFactory::CreateIOThread(ServerTypeType serverType, IOTypeType ioType, const char* threadName, const char* addressName)
{
	if (serverType == ServerTypeType::Client)
	{
		switch (ioType)
		{
		case IOTypeType::Tcp:
#ifdef LINUX
			return new TcpEpollClient(threadName, addressName);
#elif defined WINDOWS
			return new TcpSelectClient(threadName, addressName);
#endif
		case IOTypeType::Udp:
			break;
		case IOTypeType::Shm:
			return new ShmClient(threadName, addressName);
		default:
			break;
		}
	}
	else
	{
		switch (ioType)
		{
		case IOTypeType::Tcp:
#ifdef LINUX
			return new TcpEpollServer(threadName, addressName);
#elif defined WINDOWS
			return new TcpSelectServer(threadName, addressName);
#endif
		case IOTypeType::Udp:
			break;
		case IOTypeType::Shm:
			return new ShmServer(threadName, addressName);
		default:
			break;
		}
	}
	return nullptr;
}