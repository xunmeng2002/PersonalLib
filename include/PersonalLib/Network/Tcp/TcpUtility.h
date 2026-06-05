#pragma once
#include "PersonalLib/Network/Tcp/SocketInit.h"
#include <string>


void ParseIPAddress(const std::string& addressName, std::string& ip, std::string& port);
int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo);
int GetClientAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo, int serverAddressFamily);
int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags = NI_NUMERICHOST);

SOCKET CreateSocket(int family);
bool SetSockUnblock(SOCKET socketID, unsigned long unblock = 1);
bool SetSockReuse(SOCKET socketID, int resue = 1);
bool SetSockNodelay(SOCKET socketID, int nodelay = 1);
bool SetSockIPV6Only(SOCKET socketID, int ipv6Only = 0);
bool Bind(SOCKET socketID, addrinfo* bindAddressInfo);
bool Listen(SOCKET socketID, int backLog = 5);

bool InitSocket(SOCKET socketID);
SOCKET PrepareSocket(int family);

