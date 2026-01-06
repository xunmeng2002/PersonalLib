#include <iostream>
#include <set>
#include <string.h>
#include <thread>
#include "Logger.h"
#include "TestShmClient.h"
#include "TestTcpSelectClient.h"
#include "TestTcpEpollClient.h"
#include "TestTcpIocpClient.h"
#include "TestXtpClient.h"
#include "TestStepClient.h"
#include "TestUtility.h"



int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();
    SocketInit::GetInstance().Init();

    switch (g_ClientProtocolType)
    {
    case TcpProtocolType::Shm:
        TestShmClient();
        break;
    case TcpProtocolType::Udp:
        //TestUdpClient();
        break;
    case TcpProtocolType::TcpSelect:
        TestTcpSelectClient();
        break;
    case TcpProtocolType::TcpEpoll:
        TestTcpEpollClient();
        break;
    case TcpProtocolType::TcpIocp:
        TestTcpIocpClient();
        break;
    case TcpProtocolType::Xtp:
        TestXtpClient();
        break;
    case TcpProtocolType::Step:
        TestStepClient();
        break;
    default:
        break;
    }

    //std::this_thread::sleep_for(std::chrono::seconds(10));
    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();

	return 0;
}
