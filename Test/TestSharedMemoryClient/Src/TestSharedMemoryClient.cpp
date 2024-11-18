#include <stdio.h>
#include <thread>
#include <chrono>
#include <string.h>
#include "Logger.h"
#include "IOThreadFactory.h"
#include "TestUtility.h"
#include "SystemVIPC.h"
#include "PosixIPC.h"
#include "SingleShm.h"
#include "ShmSubscriberImpl.h"
#include "Sem.h"

using namespace std;



static void TestShm()
{
	auto shmClient = IOThreadFactory::CreateIOThread(ServerTypeType::Client, IOTypeType::Shm, "ShmClient", g_Address);
	ShmSubscriberImpl* shmSubscriberImpl = new ShmSubscriberImpl(shmClient, ServerTypeType::Client);

	if (!shmClient->Init())
	{
		WriteLog(LogLevel::Error, "ShmClient Init Failed.");
		return;
	}
	shmClient->Start();

	while (!shmSubscriberImpl->m_Connected)
	{
		this_thread::sleep_for(chrono::seconds(1));
	}

	char sendBuff[128]{ 0 };
	ShmPackage shmPackage;
	for (auto i = 0; i < 10; ++i)
	{
		memset(&shmPackage, 0, sizeof(ShmPackage));
		shmPackage.ShmType = (int)ServerTypeType::Client;
		shmPackage.Count = i;
		sprintf(shmPackage.Data, "Count[%d]", i);
		memcpy(sendBuff, &shmPackage, sizeof(ShmPackage));

		int sendLen = 0;
		while (sendLen < sizeof(ShmPackage))
		{
			sendLen += shmClient->Send(shmSubscriberImpl->m_SessionID, sendBuff + sendLen, sizeof(ShmPackage) - sendLen);
		}
		memset(sendBuff, 0, 128);
	}

	std::this_thread::sleep_for(chrono::seconds(10));
	shmClient->Stop();
	shmClient->Join();
	delete shmClient;
}
static void TestSingleShm()
{
	SingleShm* singleShm = new SingleShm(ServerTypeType::Client, "SingleShm", g_ShmName);
	ShmSubscriberImpl* shmSubscriberImpl = new ShmSubscriberImpl(singleShm, ServerTypeType::Client);

	if (!singleShm->Init())
	{
		WriteLog(LogLevel::Error, "SingleShm Init Failed.");
		return;
	}
	singleShm->Start();

	while (!shmSubscriberImpl->m_Connected)
	{
		this_thread::sleep_for(chrono::seconds(1));
	}

	char sendBuff[128]{ 0 };
	ShmPackage shmPackage;
	for (auto i = 0; i < 10; ++i)
	{
		memset(&shmPackage, 0, sizeof(ShmPackage));
		shmPackage.ShmType = (int)ServerTypeType::Client;
		shmPackage.Count = i;
		sprintf(shmPackage.Data, "Count[%d]", i);
		memcpy(sendBuff, &shmPackage, sizeof(ShmPackage));

		int sendLen = 0;
		while (sendLen < sizeof(ShmPackage))
		{
			sendLen += singleShm->Send(shmSubscriberImpl->m_SessionID, sendBuff + sendLen, sizeof(ShmPackage) - sendLen);
		}
		memset(sendBuff, 0, 128);
	}

	std::this_thread::sleep_for(chrono::seconds(10));
	singleShm->Stop();
	singleShm->Join();
	delete singleShm;
	delete shmSubscriberImpl;
}
static void TestSem()
{
	Sem sem(g_SemName);
	sem.Init();
	auto result = sem.Lock();
	WriteLog(LogLevel::Info, "Sem.Lock() result:%d", result);

	this_thread::sleep_for(chrono::seconds(10));
	result = sem.UnLock();
	WriteLog(LogLevel::Info, "Sem.UnLock() result:%d", result);
}


int main(int argc, char* argv[])
{
	Logger::GetInstance().Init(argv[0]);
	Logger::GetInstance().SetLogLevel(LogLevel::Debug, LogLevel::Info);
	Logger::GetInstance().Start();

	//TestSystemVIPC();
	//TestPosixIPC();
	//TestShm();
	//TestSem();
	TestSingleShm();

	this_thread::sleep_for(chrono::seconds(5));
	Logger::GetInstance().Stop();
	Logger::GetInstance().Join();
	return 0;
}

