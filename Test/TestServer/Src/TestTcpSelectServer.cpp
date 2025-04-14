#include "TestTcpSelectServer.h"
#include "TcpSelectServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"


void TestTcpSelectServer()
{
    WriteLog(LogLevel::Info, "TestTcpSelectServer");

    TcpSelectServer tcpSelectServer("TcpSelectServer", g_Address, 100);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpSelectServer);
    
    if (!tcpSelectServer.Init())
    {
        WriteLog(LogLevel::Error, "TcpSelectServer Init Failed.");
        return;
    }
    tcpSelectServer.Start();

    std::this_thread::sleep_for(std::chrono::seconds(60));
    tcpSelectServer.Stop();
    tcpSelectServer.Join();
}
