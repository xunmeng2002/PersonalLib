#include <iostream>
#include <set>
#include <string.h>
#include "Logger/Logger.h"
#include "TestShmServer.h"
#include "TestTcpSelectServer.h"
#include "TestTcpEpollServer.h"
#include "TestTcpIocpServer.h"
#include "TestXtpServer.h"
#include "TestStepServer.h"
#include "TestUtility.h"
#include "IO/IOFactory.h"

int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();
    SocketInit::GetInstance().Init();

    switch (g_ServerProtocolType)
    {
    case TcpProtocolType::Shm:
        TestShmServer();
        break;
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
        TestTcpIocpServer();
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
