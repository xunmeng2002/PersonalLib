#include "TcpEpollClient.h"
#include "Logger.h"


TcpEpollClient::TcpEpollClient(const char* addressName, int milliSeconds)
	:TcpEpollBase(ServerTypeType::Client, addressName, milliSeconds)
{
}
TcpEpollClient::~TcpEpollClient()
{
}

