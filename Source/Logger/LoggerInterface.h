#ifndef __LOGGER_INTERFACE_H__
#define __LOGGER_INTERFACE_H__

enum class LogLevel : int
{
	Ignore = 0,
	Debug = 1,
	Info = 2,
	Warning = 3,
	Error = 4,
	Critical = 5,
	Emergency = 6,
};

typedef void (*WriteLogFunc)(LogLevel level, const char* fileName, int lineNo, const char* funcName, const char* formatStr, ...);

#endif // __LOGGER_INTERFACE_H__