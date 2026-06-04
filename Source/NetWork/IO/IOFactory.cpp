#include "Network/IO/IOFactory.h"
#include "Core/Utility/TimeUtility.h"
#ifdef LINUX
#include "Network/Tcp/TcpEpoll/TcpEpollClient.h"
#include "Network/Tcp/TcpEpoll/TcpEpollServer.h"
#elif defined WINDOWS
#include "Network/Tcp/TcpIocp/TcpIocpClient.h"
#include "Network/Tcp/TcpIocp/TcpIocpServer.h"
#endif
#include "Network/Tcp/TcpSelect/TcpSelectClient.h"
#include "Network/Tcp/TcpSelect/TcpSelectServer.h"
#include "Network/Shm/SingleShm.h"
#include "Network/Shm/ShmClient.h"
#include "Network/Shm/ShmServer.h"
#include "Network/Tcp/SocketInit.h"


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
			return new TcpIocpClient(addressName, milliSeconds);
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
			return new TcpIocpServer(addressName, milliSeconds);
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