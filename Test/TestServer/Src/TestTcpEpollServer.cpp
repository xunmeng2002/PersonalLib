#include "TestTcpEpollServer.h"
#ifdef LINUX
#include "TcpEpollServer.h"
#endif
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"


void TestTcpEpollServer()
{
    WriteLog(LogLevel::Info, "TestTcpEpollServer");

#ifdef LINUX
    IOThread* ioThread = new IOThread("TcpEpollServer");
    TcpEpollServer tcpEpollServer(g_Address, 100);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpEpollServer, ioThread);
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

