#include "TcpEpollClient.h"
#include "Logger.h"


TcpEpollClient::TcpEpollClient(const char* threadName, const char* addressName)
	:TcpEpollBase(ServerTypeType::Client, threadName, addressName)
{
}
TcpEpollClient::~TcpEpollClient()
{
}

