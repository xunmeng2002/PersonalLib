#include "TimeUtility.h"
#include <iostream>
#include <ctime>
#include <time.h>
#include <cstring>
#include <sys/timeb.h>

thread_local char t_DateTimeBuff[32];
using namespace std::chrono;

time_t GetTime(const char* date)
{
	auto dateInt = atoi(date);
	tm dateTm;
	memset(&dateTm, 0, sizeof(dateTm));
	dateTm.tm_year = dateInt / 10000 - 1900;
	dateTm.tm_mon = (dateInt / 100) % 100 - 1;
	dateTm.tm_mday = dateInt % 100;
	return mktime(&dateTm);
}

void GetPreTradingDay(const char* tradingDay, char* preTradingDay)
{
	auto dateTime = GetTime(tradingDay);

	time_t lastTradingDay = dateTime - 86400LL;
	tm* lastTradingDayTm = localtime(&lastTradingDay);
	while (lastTradingDayTm->tm_wday == 0 || lastTradingDayTm->tm_wday == 6)
	{
		lastTradingDay = lastTradingDay - 86400LL;
		lastTradingDayTm = localtime(&lastTradingDay);
	}
	strftime(preTradingDay, 9, "%Y%m%d", lastTradingDayTm);
}
void GetPreYearDay(const char* tradingDay, char* preYearDay)
{
	auto dateTime = GetTime(tradingDay);

	time_t preYearDayTime = dateTime - 86400LL * 365LL;
	tm* preYearDayTm = localtime(&preYearDayTime);
	strftime(preYearDay, 9, "%Y%m%d", preYearDayTm);
}
void GetNextTradingDay(const char* tradingDay, char* nextTradingDay)
{
	auto dateTime = GetTime(tradingDay);

	time_t nextTradingDayTime = dateTime + 86400LL;
	tm* nextTradingDayTm = localtime(&nextTradingDayTime);
	while (nextTradingDayTm->tm_wday == 0 || nextTradingDayTm->tm_wday == 6)
	{
		nextTradingDayTime = nextTradingDayTime + 86400LL;
		nextTradingDayTm = localtime(&nextTradingDayTime);
	}
	strftime(nextTradingDay, 9, "%Y%m%d", nextTradingDayTm);
}

time_t GetTime()
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	return std::chrono::system_clock::to_time_t(now);
}
tm* GetUtcTm()
{
	time_t t = GetTime();
	return gmtime(&t);
}
tm* GetLocalTm()
{
	time_t t = GetTime();
	return localtime(&t);
}
std::string GetUtcDateTime()
{
	auto t = GetTime();
	auto localTm = gmtime(&t);
	strftime(t_DateTimeBuff, 32, "%Y%m%d-%H:%M:%S", localTm);
	return std::string(t_DateTimeBuff);
}
std::string GetUtcDate()
{
	auto t = GetTime();
	auto localTm = gmtime(&t);
	strftime(t_DateTimeBuff, 32, "%Y%m%d", localTm);
	return std::string(t_DateTimeBuff);
}
std::string GetUtcTime()
{
	auto t = GetTime();
	auto localTm = gmtime(&t);
	strftime(t_DateTimeBuff, 32, "%H:%M:%S", localTm);
	return std::string(t_DateTimeBuff);
}
std::string GetUtcDateTimeWithMilliSecond()
{
	auto now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	time_t t = std::chrono::system_clock::to_time_t(now);
	int milliSecond = now.time_since_epoch().count() % 1000;
	auto localTm = gmtime(&t);
	auto len = strftime(t_DateTimeBuff, 32, "%Y%m%d-%H:%M:%S", localTm);
	sprintf(t_DateTimeBuff + len, ".%03u", milliSecond);
	return std::string(t_DateTimeBuff);
}
std::string GetLocalDateTime()
{
	auto t = GetTime();
	auto localTm = localtime(&t);
	strftime(t_DateTimeBuff, 32, "%Y%m%d-%H:%M:%S", localTm);
	return std::string(t_DateTimeBuff);
}
void GetLocalDateTime(char* date, char* time)
{
	auto t = GetTime();
	auto localTm = localtime(&t);
	strftime(date, 9, "%Y%m%d", localTm);
	strftime(time, 9, "%H:%M:%S", localTm);
}
std::string GetLocalDate()
{
	auto t = GetTime();
	auto localTm = localtime(&t);
	strftime(t_DateTimeBuff, 32, "%Y%m%d", localTm);
	return std::string(t_DateTimeBuff);
}
std::string GetLocalTime()
{
	auto t = GetTime();
	auto localTm = localtime(&t);
	strftime(t_DateTimeBuff, 32, "%H:%M:%S", localTm);
	return std::string(t_DateTimeBuff);
}
std::string GetLocalDateTimeWithMilliSecond()
{
	auto now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	time_t t = std::chrono::system_clock::to_time_t(now);
	int milliSecond = now.time_since_epoch().count() % 1000;
	auto localTm = localtime(&t);
	auto len = strftime(t_DateTimeBuff, 32, "%Y%m%d-%H:%M:%S", localTm);
	sprintf(t_DateTimeBuff + len, ".%03u", milliSecond);
	return std::string(t_DateTimeBuff);
}
long long GetMilliSecondTimeStamp()
{
	time_point<system_clock, milliseconds> startTime = time_point_cast<milliseconds>(system_clock::now());
	time_t time = startTime.time_since_epoch().count() / 1000;
	int ms = startTime.time_since_epoch().count() % 1000;
	auto len = strftime(t_DateTimeBuff, 32, "%Y%m%d%H%M%S", localtime(&time));
	sprintf(t_DateTimeBuff + len, "%03u", ms);
	return atoll(t_DateTimeBuff);
}


std::string GetLocalDateFromUnixTimeStamp(long long timeStamp)
{
	time_t time = timeStamp / 1000000000LL;
	auto len = strftime(t_DateTimeBuff, 32, "%Y%m%d", localtime(&time));
	return std::string(t_DateTimeBuff);
}
std::string GetLocalTimeFromUnixTimeStamp(long long timeStamp)
{
	time_t time = timeStamp / 1000000000LL;
	auto len = strftime(t_DateTimeBuff, 32, "%H:%M:%S", localtime(&time));
	return std::string(t_DateTimeBuff);
}

time_t GetTimeFromString(std::string dateTime, std::string format)
{
	tm t;
	int len = sscanf(dateTime.c_str(), format.c_str(), &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min, &t.tm_sec);
	t.tm_year -= 1900;
	t.tm_mon -= 1;

	return mktime(&t);
}
std::string ToUtcDateTime(time_t* time)
{
	strftime(t_DateTimeBuff, 32, "%Y%m%d-%H:%M:%S", gmtime(time));
	return std::string(t_DateTimeBuff);
}
std::string ToUtcDate(time_t* time)
{
	strftime(t_DateTimeBuff, 32, "%Y%m%d", gmtime(time));
	return std::string(t_DateTimeBuff);
}
std::string ToUtcTime(time_t* time)
{
	strftime(t_DateTimeBuff, 32, "%H:%M:%S", gmtime(time));
	return std::string(t_DateTimeBuff);
}
std::string ToLocalDateTime(time_t* time)
{
	strftime(t_DateTimeBuff, 32, "%Y%m%d-%H:%M:%S", localtime(time));
	return std::string(t_DateTimeBuff);
}
std::string ToLocalDate(time_t* time)
{
	strftime(t_DateTimeBuff, 32, "%Y%m%d", localtime(time));
	return std::string(t_DateTimeBuff);
}
std::string ToLocalTime(time_t* time)
{
	strftime(t_DateTimeBuff, 32, "%H:%M:%S", localtime(time));
	return std::string(t_DateTimeBuff);
}
