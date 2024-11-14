#include "TestTcpSelectClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"


void TestTcpSelectClient()
{
    WriteLog(LogLevel::Info, "TestTcpSelectClient");

    //auto IP1 = "127.0.0.1";
    //auto IP2 = "192.168.2.29";
    //auto IP3 = "::1";
    //auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";
    //auto IP = "114.80.171.123";

    TcpSelectClient tcpSelectClient("TcpSelectClient", g_Address);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpSelectClient);

    if (!tcpSelectClient.Init())
    {
        WriteLog(LogLevel::Error, "TcpSelectClient Init Failed.");
        return;
    }
    tcpSelectClient.Start();
    tcpSelectClient.CheckClientConnect();

    std::this_thread::sleep_for(std::chrono::seconds(80));
    tcpSelectClient.Stop();
    tcpSelectClient.Join();
}
