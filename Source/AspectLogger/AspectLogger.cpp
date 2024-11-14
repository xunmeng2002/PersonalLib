#include "AspectLogger.h"
#include "Logger.h"



void AspectLogger::Before(const char* funcName)
{
	WriteLog(LogLevel::Info, "Before Call %s", funcName);
}
void AspectLogger::After(const char* funcName)
{
	WriteLog(LogLevel::Info, "After Call %s", funcName);
}

