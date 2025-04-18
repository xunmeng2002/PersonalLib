#include "TestTcpIocpServer.h"
#include "TcpIocpServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"


void TestTcpIocpServer()
{
    WriteLog(LogLevel::Info, "TestTcpIocpServer");

    IOThread* ioThread = new IOThread("TcpIocpServer");
    TcpIocpServer* tcpIocpServer = new TcpIocpServer(g_IocpServerAddress, 5000);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(tcpIocpServer);
    ioThread->SetIO(tcpIocpServer);

    if (!tcpIocpServer->Init())
    {
        WriteLog(LogLevel::Error, "TcpIocpServer Init Failed.");
        return;
    }
    ioThread->Start();

    std::this_thread::sleep_for(std::chrono::seconds(60));
    ioThread->Stop();
    ioThread->Join();
}

