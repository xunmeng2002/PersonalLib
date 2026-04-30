#pragma once
#include "Package.h"

class ProtocolSubscriber
{
public:
	virtual void OnProtocolConnect(SessionIDType sessionID, const char* ip, int port) {}
	virtual void OnProtocolDisConnect(SessionIDType sessionID, const char* ip, int port) = 0;
	virtual void OnMessage(Package* package) = 0;
};