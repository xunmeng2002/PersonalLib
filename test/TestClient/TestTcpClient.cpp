#include "TestTcpClient.h"
#include "ClientIOSubscriberImpl.h"
#include "TestCommon/TestUtility/TestUtility.h"
#include <PersonalLib/Core/Logger/Logger.h>
#include <PersonalLib/Network/Network.h>


void TestTcpClient()
{
    WriteLog(LogLevel::Info, "TestTcpClient");
    IOThread* ioThread = new IOThread("TestTcpClient");
    auto io = IOFactory::CreateIO(ServerTypeType::Client, g_Address, g_IOModel);
    ClientIOSubscriberImpl clientIOSubscriberImpl(io, ioThread);
    ioThread->SetIO(io);

    if (!io->Init())
    {
        WriteLog(LogLevel::Error, "TcpClient Init Failed.");
        return;
    }
    ioThread->Start();
    ioThread->Join();
    delete io;
}
