#include <stdio.h>
#include <thread>
#include <chrono>
#include <string.h>
#include "Logger.h"
#include "IOFactory.h"
#include "TestUtility.h"
#include "Buffer.h"
#include "SystemVIPC.h"
#include "PosixIPC.h"
#include "SingleShm.h"
#include "ShmSubscriberImpl.h"
#include "Sem.h"

using namespace std;



static void TestShm()
{
	IOThread* ioThread = new IOThread("ShmClient");
	auto shmClient = IOFactory::CreateIO(ServerTypeType::Client, g_Address);
	ioThread->SetIO(shmClient);
	ShmSubscriberImpl* shmSubscriberImpl = new ShmSubscriberImpl(shmClient, ServerTypeType::Client);

	if (!shmClient->Init())
	{
		WriteLog(LogLevel::Error, "ShmClient Init Failed.");
		return;
	}
	ioThread->Start();

	while (!shmSubscriberImpl->m_Connected)
	{
		this_thread::sleep_for(chrono::seconds(1));
	}

	ShmPackage shmPackage;
	for (auto i = 0; i < 10; ++i)
	{
		Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
		memset(&shmPackage, 0, sizeof(ShmPackage));
		shmPackage.ShmType = (int)ServerTypeType::Client;
		shmPackage.Count = i;
		sprintf(shmPackage.Data, "Count[%d]", i);
		sendBuff->Append((char*)&shmPackage, sizeof(ShmPackage));
		shmClient->Send(shmSubscriberImpl->m_SessionID, sendBuff);
	}

	std::this_thread::sleep_for(chrono::seconds(10));
	ioThread->Stop();
	ioThread->Join();
	delete shmClient;
}
static void TestSingleShm()
{
	IOThread* ioThread = new IOThread("SingleShm");
	SingleShm* singleShm = new SingleShm(ServerTypeType::Client, g_ShmName);
	ioThread->SetIO(singleShm);
	ShmSubscriberImpl* shmSubscriberImpl = new ShmSubscriberImpl(singleShm, ServerTypeType::Client);

	if (!singleShm->Init())
	{
		WriteLog(LogLevel::Error, "SingleShm Init Failed.");
		return;
	}
	ioThread->Start();

	while (!shmSubscriberImpl->m_Connected)
	{
		this_thread::sleep_for(chrono::seconds(1));
	}

	ShmPackage shmPackage;
	for (auto i = 0; i < 10; ++i)
	{
		Buffer<BuffSize>* sendBuff = new Buffer<BuffSize>();
		memset(&shmPackage, 0, sizeof(ShmPackage));
		shmPackage.ShmType = (int)ServerTypeType::Client;
		shmPackage.Count = i;
		sprintf(shmPackage.Data, "Count[%d]", i);
		sendBuff->Append((char*)&shmPackage, sizeof(ShmPackage));
		singleShm->Send(shmSubscriberImpl->m_SessionID, sendBuff);
	}

	std::this_thread::sleep_for(chrono::seconds(10));
	ioThread->Stop();
	ioThread->Join();
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

