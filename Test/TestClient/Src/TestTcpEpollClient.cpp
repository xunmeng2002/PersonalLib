#include "TestTcpEpollClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"


void TestTcpEpollClient()
{
    WriteLog(LogLevel::Info, "TestTcpEpollClient");
#ifdef LINUX
    //auto IP1 = "127.0.0.1";
    //auto IP2 = "192.168.2.29";
    //auto IP3 = "::1";
    //auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";
    //auto IP = "114.80.171.123";

    TcpEpollClient tcpEpollClient("TcpEpollClient", g_Address);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpEpollClient);

    if (!tcpEpollClient.Init())
    {
        WriteLog(LogLevel::Error, "TcpEpollClient Init Failed.");
        return;
    }
    tcpEpollClient.Start();
    tcpEpollClient.CheckClientConnect();

    
    std::this_thread::sleep_for(std::chrono::seconds(80));
    tcpEpollClient.Stop();
    tcpEpollClient.Join();
#endif
}
