#include <stdio.h>
#include <thread>
#include <chrono>
#include <string.h>
#include "TestUtility.h"
#include "Logger.h"
#include "SystemVIPC.h"
#include "PosixIPC.h"
#include "ShmSubscriberImpl.h"
#include "SingleShm.h"
#include "Sem.h"
#include "IOThreadFactory.h"

using namespace std;


static void TestShm()
{
	auto shmServer = IOThreadFactory::CreateIOThread(ServerTypeType::Server, IOTypeType::Shm, "ShmServer", g_ShmName);
	ShmSubscriberImpl* shmSubscriberImpl = new ShmSubscriberImpl(shmServer, ServerTypeType::Server);

	if (!shmServer->Init())
	{
		WriteLog(LogLevel::Error, "ShmServer Init Failed.");
		return;
	}
	shmServer->Start();

	while (!shmSubscriberImpl->m_Connected)
	{
		this_thread::sleep_for(chrono::seconds(1));
	}

	std::this_thread::sleep_for(chrono::seconds(300));
	shmServer->Stop();
	shmServer->Join();
	delete shmServer;
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
	TestShm();
	//TestSem();


	this_thread::sleep_for(chrono::seconds(5));
	Logger::GetInstance().Stop();
	Logger::GetInstance().Join();
	return 0;
}

