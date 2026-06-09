#include <PersonalLib/Network/IO/IOFactory.h>
#ifdef LINUX
#include "Tcp/TcpEpoll/TcpEpollClient.h"
#include "Tcp/TcpEpoll/TcpEpollServer.h"
#elif defined WINDOWS
#include "Tcp/TcpIocp/TcpIocpClient.h"
#include "Tcp/TcpIocp/TcpIocpServer.h"
#endif
#include "Tcp/TcpSelect/TcpSelectClient.h"
#include "Tcp/TcpSelect/TcpSelectServer.h"
#include "Shm/SingleShm.h"
#include "Shm/ShmClient.h"
#include "Shm/ShmServer.h"
#include <PersonalLib/Core/Utility/TimeUtility.h>
#include <PersonalLib/Network/Tcp/SocketInit.h>


IOBase* IOFactory::CreateIO(ServerTypeType serverType, const char* address, IOModelType ioModel, int milliSeconds)
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
		{
			switch (ioModel)
			{
			case IOModelType::Select:
				return new TcpSelectClient(addressName, milliSeconds);
#ifdef LINUX
			case IOModelType::Epoll:
				return new TcpEpollClient(addressName, milliSeconds);
#endif
#if defined WINDOWS
			case IOModelType::Iocp:
				return new TcpIocpClient(addressName, milliSeconds);
#endif
			default:
				return new TcpSelectClient(addressName, milliSeconds);
			}
		}
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
		{
			switch (ioModel)
			{
			case IOModelType::Select:
				return new TcpSelectServer(addressName, milliSeconds);
#ifdef LINUX
			case IOModelType::Epoll:
				return new TcpEpollServer(addressName, milliSeconds);
#endif
#if defined WINDOWS
			case IOModelType::Iocp:
				return new TcpIocpServer(addressName, milliSeconds);
#endif
			default:
				return new TcpSelectServer(addressName, milliSeconds);
			}
		}
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