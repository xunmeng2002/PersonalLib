#include "IOFactory.h"
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
#include "SocketInit.h"


IOBase* IOFactory::CreateIO(ServerTypeType serverType, const char* address, int milliSeconds)
{
	IOTypeType ioType;
	if (strncmp(address, "tcp", 3) == 0)
	{
		ioType = IOTypeType::Tcp;
	}
	else if (strncmp(address, "udp", 3) == 0)
	{
		ioType = IOTypeType::Udp;
	}
	else if (strncmp(address, "shm", 3) == 0)
	{
		ioType = IOTypeType::Shm;
	}
	else
	{
		char errorMsg[256]{ 0 };
		sprintf(errorMsg, "Invalid Address:%s", address);
		throw std::logic_error(errorMsg);
	}
	auto addressName = address + 6;

	if (serverType == ServerTypeType::Client)
	{
		switch (ioType)
		{
		case IOTypeType::Tcp:
#ifdef LINUX
			return new TcpEpollClient(addressName, milliSeconds);
#elif defined WINDOWS
			return new TcpSelectClient(addressName, milliSeconds);
#endif
		case IOTypeType::Udp:
			break;
		case IOTypeType::Shm:
			return new ShmClient(addressName, milliSeconds);
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
			return new TcpEpollServer(addressName, milliSeconds);
#elif defined WINDOWS
			return new TcpSelectServer(addressName, milliSeconds);
#endif
		case IOTypeType::Udp:
			break;
		case IOTypeType::Shm:
			return new ShmServer(addressName, milliSeconds);
		default:
			break;
		}
	}
	return nullptr;
}