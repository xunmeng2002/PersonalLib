#include "TestTcpEpollServer.h"
#ifdef LINUX
#include "Tcp/TcpEpoll/TcpEpollServer.h"
#endif
#include "ServerIOSubscriberImpl.h"
#include "Logger/Logger.h"
#include "TestUtility/TestUtility.h"
#include "IO/IOThread.h"


void TestTcpEpollServer()
{
    WriteLog(LogLevel::Info, "TestTcpEpollServer");

#ifdef LINUX
    IOThread* ioThread = new IOThread("TcpEpollServer");
    auto addressName = g_Address + 6;
    TcpEpollServer tcpEpollServer(addressName, 100);
    ServerIOSubscriberImpl serverIOSubscriberImpl(&tcpEpollServer, ioThread);
    ioThread->SetIO(&tcpEpollServer);

    if (!tcpEpollServer.Init())
    {
        WriteLog(LogLevel::Error, "TcpEpollServer Init Failed.");
        return;
    }
    ioThread->Start();

    std::this_thread::sleep_for(std::chrono::seconds(60));
    ioThread->Stop();
    ioThread->Join();
#endif
}

