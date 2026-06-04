#include "TestShmClient.h"
#include "ClientIOSubscriberImpl.h"
#include "Core/Logger/Logger.h"
#include "TestUtility/TestUtility.h"
#include "Network/IO/IOThread.h"
#include "Network/Shm/ShmClient.h"



void TestShmClient()
{
    IOThread* ioThread = new IOThread("ShmClient");
    auto addressName = g_Address + 6;
    ShmClient shmClient(addressName, 100);
    ClientIOSubscriberImpl clientIOSubscriberImpl(&shmClient, ioThread);
    ioThread->SetIO(&shmClient);

    if (!shmClient.Init())
    {
        WriteLog(LogLevel::Error, "ShmClient Init Failed.");
        return;
    }
    ioThread->Start();
    ioThread->Join();
}