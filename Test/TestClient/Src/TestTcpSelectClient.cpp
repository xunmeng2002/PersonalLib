#include "TestTcpSelectClient.h"
#include "ClientIOSubscriberImpl.h"
#include "Tcp/TcpSelect/TcpSelectClient.h"
#include "Logger/Logger.h"
#include "TestUtility/TestUtility.h"
#include "IO/IOThread.h"
#include "IO/IOFactory.h"


void TestTcpSelectClient()
{
    WriteLog(LogLevel::Info, "TestTcpSelectClient");

    //auto IP1 = "127.0.0.1";
    //auto IP2 = "192.168.2.29";
    //auto IP3 = "::1";
    //auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";
    //auto IP = "114.80.171.123";

    IOThread* ioThread = new IOThread("TcpSelectClient");
    auto addressName = g_Address + 6;
    TcpSelectClient* tcpSelectClient = new TcpSelectClient(addressName, 1000);
    ClientIOSubscriberImpl clientIOSubscriberImpl(tcpSelectClient, ioThread);
    ioThread->SetIO(tcpSelectClient);

    if (!tcpSelectClient->Init())
    {
        WriteLog(LogLevel::Error, "TcpSelectClient Init Failed.");
        return;
    }
    ioThread->Start();
    ioThread->Join();
}
