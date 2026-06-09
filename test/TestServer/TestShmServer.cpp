#include "TestShmServer.h"
#include "ServerIOSubscriberImpl.h"
#include "TestCommon/TestUtility/TestUtility.h"
#include <PersonalLib/Core/Logger/Logger.h>
#include <PersonalLib/Network/Network.h>



void TestShmServer()
{
    IOThread* ioThread = new IOThread("ShmServer");
    auto io = IOFactory::CreateIO(ServerTypeType::Server, g_Address);
    ServerIOSubscriberImpl serverIOSubscriberImpl(io, ioThread);
    ioThread->SetIO(io);

    if (!io->Init())
    {
        WriteLog(LogLevel::Error, "ShmServer Init Failed.");
        return;
    }
    ioThread->Start();
    ioThread->Join();
    delete io;
}

