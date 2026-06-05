#include "PersonalLib/Network/IO/IOFactory.h"
#include "PersonalLib/Core/Utility/TimeUtility.h"
#ifdef LINUX
#include "PersonalLib/Network/Tcp/TcpEpoll/TcpEpollClient.h"
#include "PersonalLib/Network/Tcp/TcpEpoll/TcpEpollServer.h"
#elif defined WINDOWS
#include "PersonalLib/Network/Tcp/TcpIocp/TcpIocpClient.h"
#include "PersonalLib/Network/Tcp/TcpIocp/TcpIocpServer.h"
#endif
#include "PersonalLib/Network/Tcp/TcpSelect/TcpSelectClient.h"
#include "PersonalLib/Network/Tcp/TcpSelect/TcpSelectServer.h"
#include "PersonalLib/Network/Shm/SingleShm.h"
#include "PersonalLib/Network/Shm/ShmClient.h"
#include "PersonalLib/Network/Shm/ShmServer.h"
#include "PersonalLib/Network/Tcp/SocketInit.h"


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