#include "TestShmClient.h"
#include "ClientIOSubscriberImpl.h"
#include "Logger.h"
#include "TestUtility.h"
#include "IOThread.h"
#include "ShmClient.h"



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