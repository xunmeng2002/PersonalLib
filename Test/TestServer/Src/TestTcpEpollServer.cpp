#include "TestTcpEpollServer.h"
#ifdef LINUX
#include "TcpEpollServer.h"
#endif
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"



void TestTcpEpollServer()
{
    WriteLog(LogLevel::Info, "TestTcpEpollServer");

#ifdef LINUX
    TcpEpollServer tcpEpollServer("TcpEpollServer", g_Address);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpEpollServer);

    if (!tcpEpollServer.Init())
    {
        WriteLog(LogLevel::Error, "TcpEpollServer Init Failed.");
        return;
    }
    tcpEpollServer.Start();

    std::this_thread::sleep_for(std::chrono::seconds(80));
    tcpEpollServer.Stop();
    tcpEpollServer.Join();
#endif
}

