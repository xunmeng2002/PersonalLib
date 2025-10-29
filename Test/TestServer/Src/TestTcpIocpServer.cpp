#include "TestTcpIocpServer.h"
#ifdef WINDOWS
#include "TcpIocpServer.h"
#endif
#include "ServerIOSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"
#include "IOFactory.h"


void TestTcpIocpServer()
{
    WriteLog(LogLevel::Info, "TestTcpIocpServer");
#ifdef WINDOWS
    IOThread* ioThread = new IOThread("TcpIocpServer");
    auto addressName = g_Address + 6;
    TcpIocpServer* tcpIocpServer = new TcpIocpServer(addressName, 5000);
    ServerIOSubscriberImpl serverIOSubscriberImpl(tcpIocpServer, ioThread);
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
#endif
}

