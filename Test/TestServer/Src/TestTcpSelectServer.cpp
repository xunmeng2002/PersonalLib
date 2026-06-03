#include "TestTcpSelectServer.h"
#include "Tcp/TcpSelect/TcpSelectServer.h"
#include "ServerIOSubscriberImpl.h"
#include "Logger/Logger.h"
#include "TestUtility/TestUtility.h"
#include "IO/IOThread.h"


void TestTcpSelectServer()
{
    WriteLog(LogLevel::Info, "TestTcpSelectServer");

    IOThread* ioThread = new IOThread("TcpSelectServer");
    auto addressName = g_Address + 6;
    TcpSelectServer* tcpSelectServer = new TcpSelectServer(addressName, 1000);
    ServerIOSubscriberImpl serverIOSubscriberImpl(tcpSelectServer, ioThread);
    ioThread->SetIO(tcpSelectServer);
    
    if (!tcpSelectServer->Init())
    {
        WriteLog(LogLevel::Error, "TcpSelectServer Init Failed.");
        return;
    }
    ioThread->Start();

    std::this_thread::sleep_for(std::chrono::seconds(60));
    ioThread->Stop();
    ioThread->Join();
}
