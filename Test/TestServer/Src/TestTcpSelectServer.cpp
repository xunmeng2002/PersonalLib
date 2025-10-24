#include "TestTcpSelectServer.h"
#include "TcpSelectServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"


void TestTcpSelectServer()
{
    WriteLog(LogLevel::Info, "TestTcpSelectServer");

    IOThread* ioThread = new IOThread("TcpSelectServer");
    auto tcpAddress = g_Address + 6;
    TcpSelectServer* tcpSelectServer = new TcpSelectServer(tcpAddress, 1000);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(tcpSelectServer, ioThread);
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
