#include "Logger/LogData.h"
#include "Buffer/Buffer.h"
#include "MemCache/MemCacheTemplateSingleton.h"

LogData::LogData()
{
	LogFile = nullptr;
	CurrBuffer = Buffer<LogBuffSize>::Allocate();
}
LogData::~LogData()
{
	if (LogFile)
	{
		fclose(LogFile);
		LogFile = nullptr;
	}
	CurrBuffer->Free();
	for (auto& logBuffer : LogBuffers)
	{
		logBuffer->Free();
	}
	LogBuffers.clear();

	for (auto& logBuffer : InnerLogBuffers)
	{
		logBuffer->Free();
	}
	InnerLogBuffers.clear();
}
void LogData::PushBuffer()
{
	LogBuffers.push_back(CurrBuffer);
	CurrBuffer = Buffer<LogBuffSize>::Allocate();
}
