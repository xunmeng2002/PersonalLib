#include "TestTcpIocpClient.h"
#ifdef WINDOWS
#include "TcpIocpClient.h"
#endif
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"


void TestTcpIocpClient()
{
    WriteLog(LogLevel::Info, "TestTcpIocpClient");

#ifdef WINDOWS
    IOThread* ioThread = new IOThread("TcpIocpClient");
    TcpIocpClient* tcpIocpClient = new TcpIocpClient(g_IocpClientAddress, g_IocpServerAddress, 5000);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(tcpIocpClient);
    ioThread->SetIO(tcpIocpClient);

    if (!tcpIocpClient->Init())
    {
        WriteLog(LogLevel::Error, "TcpIocpClient Init Failed.");
        return;
    }
    ioThread->Start();

    std::this_thread::sleep_for(std::chrono::seconds(60));
    ioThread->Stop();
    ioThread->Join();
#endif
}