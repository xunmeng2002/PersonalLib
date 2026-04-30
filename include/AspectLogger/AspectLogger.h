#pragma once
#include <chrono>

using namespace std::chrono;

class AspectLogger
{
public:
	void Before(const char* funcName);
	void After(const char* funcName);
};


