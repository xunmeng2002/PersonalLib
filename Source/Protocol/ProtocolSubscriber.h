#pragma once
#include "Package.h"

class ProtocolSubscriber
{
public:
	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) {}
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) = 0;
	virtual void OnMessage(Package* package) = 0;
};