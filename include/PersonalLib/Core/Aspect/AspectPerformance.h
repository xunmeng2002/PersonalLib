#pragma once
#include <chrono>

using namespace std::chrono;

class AspectPerformance
{
public:
	AspectPerformance();
	void Before(const char* funcName);
	void After(const char* funcName);
private:
	time_point<system_clock, microseconds> m_StartTimePoint;
	time_point<system_clock, microseconds> m_EndTimePoint;
};



