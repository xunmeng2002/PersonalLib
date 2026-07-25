#pragma once
#include <PersonalLib/TemplateLib/Buffer/Buffer.h>
#include <stdio.h>
#include <list>
#include <mutex>
#include <condition_variable>


template<unsigned SIZE>
class Buffer;
struct LogData
{
	LogData();
	~LogData();

	void PushBuffer();

	FILE* LogFile;
	Buffer<LogBuffSize>* CurrBuffer;
	std::list<Buffer<LogBuffSize>*> LogBuffers;
	std::list<Buffer<LogBuffSize>*> InnerLogBuffers;

	std::mutex Mutex;
	std::condition_variable ConditionVariable;
};