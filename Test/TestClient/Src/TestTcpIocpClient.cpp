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
    TcpIocpClient* tcpIocpClient = new TcpIocpClient(g_IocpServerAddress, 5000);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(tcpIocpClient, ioThread);
    ioThread->SetIO(tcpIocpClient);

    if (!tcpIocpClient->Init())
    {
        WriteLog(LogLevel::Error, "TcpIocpClient Init Failed.");
        return;
    }
    ioThread->Start();
    ioThread->Join();
#endif
}