#include <iostream>
#include <set>
#include <string.h>
#include "Logger.h"
#include "TestTcpSelectServer.h"
#include "TestTcpEpollServer.h"
#include "TestXtpServer.h"
#include "TestStepServer.h"
#include "TestUtility.h"


int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();

    switch (g_ProtocolType)
    {
    case TcpProtocolType::Udp:
        //TestUdpServer();
        break;
    case TcpProtocolType::TcpSelect:
        TestTcpSelectServer();
        break;
    case TcpProtocolType::TcpEpoll:
        TestTcpEpollServer();
        break;
    case TcpProtocolType::TcpIocp:
        //TestTcpIOCPServer();
        break;
    case TcpProtocolType::Xtp:
        TestXtpServer();
        break;
    case TcpProtocolType::Step:
        TestStepServer();
        break;
    default:
        break;
    }

    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();
	return 0;
}
