#pragma once
#include "SocketInit.h"



class SocketNotify
{
public:
	SocketNotify();
	~SocketNotify();

	bool Init();
	bool Notify();
	bool Consume();
	SOCKET GetReadSocket();

private:
	bool CreateSocketPair();

private:
	SOCKET m_Sockets[2];

	std::string m_IP;
	addrinfo* m_AddressInfo;
	char m_ReceiveBuffer[16];
};


