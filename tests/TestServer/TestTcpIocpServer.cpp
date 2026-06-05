#include "TestTcpIocpServer.h"
#ifdef WINDOWS
#include "PersonalLib/Network/Tcp/TcpIocp/TcpIocpServer.h"
#endif
#include "ServerIOSubscriberImpl.h"
#include "PersonalLib/Core/Logger/Logger.h"
#include "TestCommon/TestUtility/TestUtility.h"
#include "PersonalLib/Network/IO/IOThread.h"
#include "PersonalLib/Network/IO/IOFactory.h"


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

