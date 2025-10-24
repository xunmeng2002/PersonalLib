#include "TestTcpEpollClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"


void TestTcpEpollClient()
{
    WriteLog(LogLevel::Info, "TestTcpEpollClient");
#ifdef LINUX
    //auto IP1 = "127.0.0.1";
    //auto IP2 = "192.168.2.29";
    //auto IP3 = "::1";
    //auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";
    //auto IP = "114.80.171.123";

    IOThread* ioThread = new IOThread("TcpEpollClient");
    TcpEpollClient tcpEpollClient(g_Address, 100);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpEpollClient, ioThread);
    ioThread->SetIO(&tcpEpollClient);

    if (!tcpEpollClient.Init())
    {
        WriteLog(LogLevel::Error, "TcpEpollClient Init Failed.");
        return;
    }
    ioThread->Start();
    ioThread->Join();
#endif
}
