#include "TcpUtility.h"
#include "Platform.h"
#include "Logger.h"
#include <string.h>
#include <mutex>

using namespace std;


void ParseIPAddress(const std::string& addressName, std::string& ip, std::string& port)
{
	auto index = addressName.find(':', 0);
	ip = addressName.substr(0, index);
	port = addressName.substr(index + 1);
}
int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo)
{
	struct addrinfo hints;
	::memset(&hints, 0, sizeof(hints));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	auto ret = getaddrinfo(ip, port, &hints, &addrInfo);
	WriteLog(LogLevel::Info, "GetAddrinfo: IP:%s Port:%s GetAddrinfo ret:%d", ip, port, ret);
	return ret;
}
int GetClientAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo, int serverAddressFamily)
{
	struct addrinfo hints;
	::memset(&hints, 0, sizeof(hints));
	hints.ai_flags = 0;
	hints.ai_family = serverAddressFamily;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	auto ret = getaddrinfo(ip, port, &hints, &addrInfo);
	WriteLog(LogLevel::Info, "GetClientAddrinfo: IP:%s Port:%s GetAddrinfo ret:%d", ip, port, ret);
	return ret;
}
int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags)
{
	static mutex getnameinfoMutex;
	lock_guard<mutex> guard(getnameinfoMutex);
	char ipBuff[NI_MAXHOST]{ 0 };
	char portBuff[NI_MAXSERV]{ 0 };
	auto ret = getnameinfo(sockAddr, len, ipBuff, NI_MAXHOST, portBuff, NI_MAXSERV, NI_NUMERICHOST);
	ip = ipBuff;
	port = portBuff;
	return ret;
}

bool SetSockUnblock(SOCKET socketID, unsigned long unblock)
{
#ifdef  WINDOWS
	if (::ioctlsocket(socketID, FIONBIO, &unblock) == SOCKET_ERROR)
	{
		WriteLog(LogLevel::Error, "ioctlsocket FIONBIO:%d, Failed. ErrorID:%d", unblock, GetLastError());
		return false;
	}
	WriteLog(LogLevel::Info, "ioctlsocket FIONBIO:%d Success.", unblock);
#endif //  WINDOWS
#ifdef LINUX
	if (ioctl(socketID, FIONBIO, &unblock) == SOCKET_ERROR)
	{
		WriteLog(LogLevel::Error, "ioctl FIONBIO:%d Failed. ErrorID:%d", unblock, GetLastError());
		return false;
	}
	WriteLog(LogLevel::Info, "ioctl FIONBIO:%d Success.", unblock);
#endif // LINUX
	return true;
}
bool SetSockReuse(SOCKET socketID, int resue)
{
	if (::setsockopt(socketID, SOL_SOCKET, SO_REUSEADDR, (char*)&resue, sizeof(int)) == SOCKET_ERROR)
	{
		WriteLog(LogLevel::Error, "setsockopt SO_REUSEADDR:%d Failed. ErrorID:%d", resue, GetLastError());
		return false;
	}
	WriteLog(LogLevel::Info, "setsockopt SO_REUSEADDR:%d Success.", resue);
	return true;
}
bool SetSockNodelay(SOCKET socketID, int nodelay)
{
	if (::setsockopt(socketID, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(int)) == SOCKET_ERROR)
	{
		WriteLog(LogLevel::Error, "setsockopt TCP_NODELAY:%d Failed. ErrorID:%d", nodelay, GetLastError());
		return false;
	}
	WriteLog(LogLevel::Info, "setsockopt TCP_NODELAY:%d Success.", nodelay);
	return true;
}
bool SetSockIPV6Only(SOCKET socketID, int ipv6Only)
{
	if (::setsockopt(socketID, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&ipv6Only, sizeof(int)) == SOCKET_ERROR)
	{
		WriteLog(LogLevel::Error, "setsockopt IPV6_V6ONLY:%d Failed. ErrorID:%d", ipv6Only, GetLastError());
		return false;
	}
	WriteLog(LogLevel::Error, "setsockopt IPV6_V6ONLY:%d Success.", ipv6Only);
	return true;
}
bool Bind(SOCKET socketID, addrinfo* bindAddressInfo)
{
	if (::bind(socketID, bindAddressInfo->ai_addr, int(bindAddressInfo->ai_addrlen)) == SOCKET_ERROR)
	{
		WriteLog(LogLevel::Error, "Bind Failed. ErrorID:%d", GetLastError());
		return false;
	}
	return true;
}
bool Listen(SOCKET socketID, int backLog)
{
	if (listen(socketID, backLog) == SOCKET_ERROR)
	{
		WriteLog(LogLevel::Error, "Listen Failed. ErrorID:%d", GetLastError());
		return false;
	}
	return true;
}