#pragma once
#include "CoreExport.h"
#include <chrono>

using namespace std::chrono;

class CORE_EXPORTS AspectLogger
{
public:
	void Before(const char* funcName);
	void After(const char* funcName);
};


