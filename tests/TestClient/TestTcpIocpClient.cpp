#include "TestTcpIocpClient.h"
#ifdef WINDOWS
#include "PersonalLib/Network/Tcp/TcpIocp/TcpIocpClient.h"
#endif
#include "ClientIOSubscriberImpl.h"
#include "PersonalLib/Core/Logger/Logger.h"
#include "TestCommon/TestUtility/TestUtility.h"
#include "PersonalLib/Network/IO/IOThread.h"


void TestTcpIocpClient()
{
    WriteLog(LogLevel::Info, "TestTcpIocpClient");

#ifdef WINDOWS
    IOThread* ioThread = new IOThread("TcpIocpClient");
    auto addressName = g_Address + 6;
    TcpIocpClient* tcpIocpClient = new TcpIocpClient(addressName, 5000);
    ClientIOSubscriberImpl clientIOSubscriberImpl(tcpIocpClient, ioThread);
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