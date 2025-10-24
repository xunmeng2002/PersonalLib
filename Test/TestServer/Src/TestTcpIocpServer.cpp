#include "TestTcpIocpServer.h"
#ifdef WINDOWS
#include "TcpIocpServer.h"
#endif
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"
#include "IOFactory.h"


void TestTcpIocpServer()
{
    WriteLog(LogLevel::Info, "TestTcpIocpServer");
#ifdef WINDOWS
    IOThread* ioThread = new IOThread("TcpIocpServer");
    //TcpIocpServer* tcpIocpServer = new TcpIocpServer(g_IocpServerAddress, 5000);
    auto tcpIocpServer = (TcpBase*)IOFactory::CreateIO(ServerTypeType::Server, g_Address, 5000);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(tcpIocpServer, ioThread);
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

