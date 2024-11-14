#pragma once

#include <chrono>
#include <string>


time_t GetTime(const char* date);
void GetPreTradingDay(const char* tradingDay, char* preTradingDay);
void GetPreYearDay(const char* tradingDay, char* preYearDay);
void GetNextTradingDay(const char* tradingDay, char* nextTradingDay);

time_t GetTime();
tm* GetUtcTm();
tm* GetLocalTm();
std::string GetUtcDateTime();
std::string GetUtcDate();
std::string GetUtcTime();
std::string GetUtcDateTimeWithMilliSecond();
std::string GetLocalDateTime();
void GetLocalDateTime(char* date, char* time);
std::string GetLocalDate();
std::string GetLocalTime();
std::string GetLocalDateTimeWithMilliSecond();
long long GetMilliSecondTimeStamp();

std::string GetLocalDateFromUnixTimeStamp(long long timeStamp);
std::string GetLocalTimeFromUnixTimeStamp(long long timeStamp);

time_t GetTimeFromString(std::string dateTime, std::string format = "%04d%02d%02d-%02d:%02d:%02d");
std::string ToUtcDateTime(time_t* time);
std::string ToUtcDate(time_t* time);
std::string ToUtcTime(time_t* time);
std::string ToLocalDateTime(time_t* time);
std::string ToLocalDate(time_t* time);
std::string ToLocalTime(time_t* time);


template<typename T>
long long GetDuration(std::chrono::steady_clock::time_point& start)
{
	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<T>(end - start).count();
}
