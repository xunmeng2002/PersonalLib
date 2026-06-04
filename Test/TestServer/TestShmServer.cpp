#include "TestShmServer.h"
#include "ServerIOSubscriberImpl.h"
#include "Core/Logger/Logger.h"
#include "TestCommon/TestUtility/TestUtility.h"
#include "Network/IO/IOThread.h"
#include "Network/Shm/ShmServer.h"


void TestShmServer()
{
    WriteLog(LogLevel::Info, "TestShmServer");

    IOThread* ioThread = new IOThread("ShmServer");
    auto addressName = g_Address + 6;
    ShmServer shmServer(addressName, 100);
    ServerIOSubscriberImpl serverIOSubscriberImpl(&shmServer, ioThread);
    ioThread->SetIO(&shmServer);

    if (!shmServer.Init())
    {
        WriteLog(LogLevel::Error, "ShmServer Init Failed.");
        return;
    }
    ioThread->Start();

    std::this_thread::sleep_for(std::chrono::seconds(60));
    ioThread->Stop();
    ioThread->Join();
}

