#pragma once
#include <list>
#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include "ThreadBase.h"
#include "LoggerInterface.h"

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
	bool Init(const char* fullProcessName);
	void SetLogLevel(LogLevel logLevel = LogLevel::Info, LogLevel logLevelConsole = LogLevel::Warning);
	static void WriteLogFunc(LogLevel level, const char* file, int line, const char* func, const char* formatStr, ...);

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
	uint32_t GetCurrentThreadID();

private:
	static Logger m_Instance;

	char m_ProcessName[128];
	tm m_CreateLogFileTime;
	LogData* m_LogData;
	static LogLevel s_LogLevel;
	static LogLevel s_LogLevelConsole;
};

extern WriteLogFunc g_WriteLogFunc;

#define WriteLog(level, formatStr, ...)\
	if (g_WriteLogFunc != nullptr)\
		(g_WriteLogFunc)(level, __FILE__, __LINE__, __func__, formatStr, ##__VA_ARGS__);


#define WriteErrorLog(errorID, errorMsg)\
	if (g_WriteLogFunc != nullptr)\
		(g_WriteLogFunc)(LogLevel::Error, __FILE__, __LINE__, __func__, "ErrorID:[%d], ErrorMsg:[%s].", errorID, errorMsg);
