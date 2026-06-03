#pragma once
#include <chrono>
#include <string>
#include "Types.h"

time_t GetTime();
time_t GetTime(const char* date);
time_t GetTime(int date);
tm* GetTm(int date);
tm* GetUtcTm();
tm* GetLocalTm();

void GetPreTradingDay(const char* tradingDay, char* preTradingDay);
int GetPreTradingDay(int tradingDay);
int GetPreDate(int date);
void GetNextTradingDay(const char* tradingDay, char* nextTradingDay);
int GetNextTradingDay(int tradingDay);
int GetNextDate(int date);

int DateAdd(int date, int count);
int HourAdd(int hourTime, int count);
long long MinuteAdd(long long minuteTime, int count);

void GetPreYearDay(const char* tradingDay, char* preYearDay);

std::string GetUtcDate();
std::string GetUtcTime();
std::string GetUtcDateTime();
std::string GetUtcDateTimeWithMilliSecond();

std::string GetLocalDate();
std::string GetLocalTime();
std::string GetLocalDateTime();
void GetLocalDateTime(char* date, char* time);
std::string GetLocalDateTimeWithMilliSecond();
long long GetMilliSecondTimeStamp();
void GetDateTimeFromTimeStamp(const Int64Type& timeStamp, DateType& date, TimeType& time);

int GetTimeFromTimeString(const char* time);
time_t GetTimeFromString(std::string dateTime, std::string format = "%04d%02d%02d-%02d:%02d:%02d");
std::string ToUtcDate(time_t* time);
std::string ToUtcTime(time_t* time);
std::string ToUtcDateTime(time_t* time);
std::string ToLocalDate(time_t* time);
std::string ToLocalTime(time_t* time);
std::string ToLocalDateTime(time_t* time);


void GetDateTimeFromUpdateTs(long long updateTs, int& date, int& hour, int& minute, int& second, int& milliSecond);
int CalculateNextBarFromDayBar(int tradingDay, int barPeriod);
int CalculateMinutes(int hour, int minute);
int CalculateMinutesTimeStamp(int minutes);
int CalculateSeconds(int hour, int minute, int second);
int CalculateSecondsTimeStamp(int seconds);

int CalculateNextBarDate(int barPeriod, int date);
long long CalculateNextMinuteBarTime(long long updateTs);
long long CalculateNextSecondBarTime(int barPeriod, long long updateTs);

void CalculateRealMinuteBarTime(const char* exchangeID, const char* instrumentID, int calculateBarTime, int& realBarTime, int& realUpdateTs);

template<typename T>
long long GetDuration(std::chrono::steady_clock::time_point& start)
{
	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<T>(end - start).count();
}
