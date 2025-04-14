#include "TcpEpollClient.h"
#include "Logger.h"


TcpEpollClient::TcpEpollClient(const char* threadName, const char* addressName, int milliSeconds)
	:TcpEpollBase(ServerTypeType::Client, threadName, addressName, milliSeconds)
{
}
TcpEpollClient::~TcpEpollClient()
{
}

