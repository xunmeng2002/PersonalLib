#pragma once
#include <Spark/Core/CoreExport.h>

class CORE_EXPORTS AspectLogger
{
public:
	void Before(const char* funcName);
	void After(const char* funcName);
};


