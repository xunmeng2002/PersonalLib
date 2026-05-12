#pragma once
#include <list>
#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include "Logger/LoggerInterface.h"
#include "ThreadBase/ThreadBase.h"

struct LogData;
class Logger : public ThreadBase
{
private:
	Logger();
	~Logger();
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

public:
	static Logger& GetInstance();
	static WriteLogFunc& GetWriteLogFunc();
	static LogLevel& GetLogLevel();
	static LogLevel& GetConsoleLogLevel();
	bool Init(const char* fullProcessName);
	void SetLogLevel(LogLevel logLevel = LogLevel::Info, LogLevel logLevelConsole = LogLevel::Warning);
	static void SetExternLogger(WriteLogFunc externLogger);
	static void Write(LogLevel level, const char* file, int line, const char* func, const char* formatStr, ...);


protected:
	virtual void ThreadInit() override;
	virtual void ThreadExit() override;
	virtual void Run() override;

	bool CreateLogDir(const std::string& path);
	void SwapInnerLogBuffers();
	void FlushBuffers();
	void WriteToLog(LogLevel level, const char* file, int line, const char* func, const char* format, va_list va);
	void WriteToConsole(LogLevel level, const char* formatStr, va_list va);
	void CreateLogFile();
	long long GetCurrentThreadID();

private:
	char m_ProcessName[128];
	tm m_CreateLogFileTime;
	LogData* m_LogData;
};


#define WriteLog(level, formatStr, ...)\
	if (Logger::GetWriteLogFunc() != nullptr)\
		Logger::GetWriteLogFunc()(level, __FILE__, __LINE__, __func__, formatStr, ##__VA_ARGS__);


#define WriteErrorLog(errorID, errorMsg)\
	if (Logger::GetWriteLogFunc() != nullptr)\
		Logger::GetWriteLogFunc()(LogLevel::Error, __FILE__, __LINE__, __func__, "ErrorID:[%d], ErrorMsg:[%s].", errorID, errorMsg);
