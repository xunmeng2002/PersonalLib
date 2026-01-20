#include "Logger.h"
#include "Buffer.h"
#include "LogData.h"
#include "Utility.h"
#include "TimeUtility.h"
#include <assert.h>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <filesystem>

constexpr unsigned int LogLineLength = 64 * 1024;
constexpr unsigned int MaxLogFormatLength = 1024;
constexpr unsigned int MaxLogLineContentLength = (LogLineLength - MaxLogFormatLength);

static std::map<LogLevel, std::string> s_LogLevelName = {
	{ LogLevel::Ignore, "IGNORE"},
	{ LogLevel::Debug, "DEBUG"},
	{ LogLevel::Info, "INFO"},
	{ LogLevel::Warning, "WARNING"},
	{ LogLevel::Error, "ERROR"},
	{ LogLevel::Critical, "CRITICAL"},
	{ LogLevel::Emergency, "EMERGENCY"},
};

thread_local char t_LogBuffer[LogLineLength];

Logger::Logger()
	:ThreadBase("Logger"), m_ProcessName(""), m_CreateLogFileTime(), m_LogData(nullptr)
{
}
Logger::~Logger()
{

}

Logger& Logger::GetInstance()
{
	static Logger instance;
	return instance;
}
WriteLogFunc& Logger::GetWriteLogFunc()
{
	static WriteLogFunc externLogger = nullptr;
	return externLogger;
}
LogLevel& Logger::GetLogLevel()
{
	static LogLevel logLevel = LogLevel::Info;
	return logLevel;
}
LogLevel& Logger::GetConsoleLogLevel()
{
	static LogLevel consoleLogLevel = LogLevel::Warning;
	return consoleLogLevel;
}
bool Logger::Init(const char* fullProcessName)
{
	ParseProcessName(fullProcessName, m_ProcessName, 128);
	m_LogData = new LogData();
	CreateLogDir("log");

	GetWriteLogFunc() = Logger::Write;
	return true;
}
void Logger::SetLogLevel(LogLevel logLevel, LogLevel logLevelConsole)
{
	GetLogLevel() = logLevel;
	GetConsoleLogLevel() = logLevelConsole;
}
void Logger::SetExternLogger(WriteLogFunc externLogger)
{
	GetWriteLogFunc() = externLogger;
}
void Logger::Write(LogLevel level, const char* file, int line, const char* func, const char* formatStr, ...)
{
	va_list va;
	va_start(va, formatStr);
	GetInstance().WriteToLog(level, file, line, func, formatStr, va);
	va_end(va);
	if (level >= GetConsoleLogLevel())
	{
		va_start(va, formatStr);
		GetInstance().WriteToConsole(level, formatStr, va);
		va_end(va);
	}
}
void Logger::ThreadInit()
{
	m_CreateLogFileTime = *GetLocalTm();
	CreateLogFile();
}
void Logger::ThreadExit()
{
	ThreadBase::ThreadExit();
	if (m_LogData)
	{
		delete m_LogData;
	}
	m_LogData = nullptr;
}
void Logger::Run()
{
	SwapInnerLogBuffers();
	FlushBuffers();

	static int count = 0;
	if (++count >= 120)
	{
		count = 0;
		auto currTime = *GetLocalTm();
		if (m_CreateLogFileTime.tm_mday != currTime.tm_mday)
		{
			m_CreateLogFileTime = currTime;
			CreateLogFile();
		}
	}
}

bool Logger::CreateLogDir(const std::string& path)
{
	return std::filesystem::create_directories(path);
}
void Logger::SwapInnerLogBuffers()
{
	std::unique_lock<std::mutex> lock(m_LogData->Mutex);
	if (m_LogData->LogBuffers.empty())
	{
		m_LogData->ConditionVariable.wait_for(lock, std::chrono::seconds(1));
		if (m_LogData->CurrBuffer->GetLength() > 0)
		{
			m_LogData->PushBuffer();
		}
	}
	m_LogData->InnerLogBuffers.swap(m_LogData->LogBuffers);
}
void Logger::FlushBuffers()
{
	for (auto& buffer : m_LogData->InnerLogBuffers)
	{
		fwrite(buffer->GetData(), buffer->GetLength(), 1, m_LogData->LogFile);
		buffer->Free();
	}
	m_LogData->InnerLogBuffers.clear();
	fflush(m_LogData->LogFile);
}

void Logger::WriteToLog(LogLevel level, const char* file, int line, const char* func, const char* format, va_list va)
{
	if (level < GetLogLevel())
		return;
	for (auto p = file; *p != '\0'; p++)
		if (*p == '\\' || *p == '/')
			file = p + 1;
	unsigned len1 = snprintf(t_LogBuffer, MaxLogFormatLength, "%s %d %s ", GetLocalDateTimeWithMilliSecond().c_str(), GetCurrentThreadID(), s_LogLevelName[level].c_str());

	unsigned len2 = vsnprintf(t_LogBuffer + len1, MaxLogLineContentLength, format, va);
	unsigned len3 = snprintf(t_LogBuffer + len1 + len2, LogLineLength - len1 - len2 - 1, "\t\t---%s:%d[%s]\n", file, line, func);
	unsigned len = len1 + len2 + len3;
	std::lock_guard<std::mutex> guard(m_LogData->Mutex);
	if (m_LogData->CurrBuffer->GetWriteBufferSize() < len)
	{
		m_LogData->PushBuffer();
	}
	m_LogData->CurrBuffer->Append(t_LogBuffer, len);
	m_LogData->ConditionVariable.notify_one();
}
void Logger::WriteToConsole(LogLevel level, const char* formatStr, va_list va)
{
	static char* logString = new char[LogLineLength] {0};
	int len = snprintf(logString, MaxLogFormatLength, "ThreadID[%06d] ", GetCurrentThreadID());
	len += vsnprintf(logString + len, LogLineLength - len -1, formatStr, va);

	printf("%s\n", logString);
}
void Logger::CreateLogFile()
{
	if (m_LogData->LogFile)
	{
		fclose(m_LogData->LogFile);
		m_LogData->LogFile = nullptr;
	}
	char timeBuff[32];
	strftime(timeBuff, 32, "%Y%m%d-%H%M%S", &m_CreateLogFileTime);
	char fileName[256];		
	snprintf(fileName, sizeof(fileName), "log/%s.%s.log", m_ProcessName, timeBuff);
	m_LogData->LogFile = fopen(fileName, "a+");
	assert(m_LogData->LogFile != nullptr);
}
uint32_t Logger::GetCurrentThreadID()
{
	auto id = std::this_thread::get_id();
	return *(uint32_t*)(&id);
}
