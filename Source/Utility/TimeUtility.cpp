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
time_t GetTime(int date)
{
	tm dateTm;
	memset(&dateTm, 0, sizeof(dateTm));
	dateTm.tm_year = date / 10000 - 1900;
	dateTm.tm_mon = (date / 100) % 100 - 1;
	dateTm.tm_mday = date % 100;
	return mktime(&dateTm);
}
tm* GetTm(int date)
{
	auto t = GetTime(date);
	return localtime(&t);
}
int GetNextDate(int date)
{
	auto dateTime = GetTime(date);
	time_t nextDateTime = dateTime + 86400LL;
	tm* nextTm = localtime(&nextDateTime);
	return (nextTm->tm_year + 1900) * 10000 + (nextTm->tm_mon + 1) * 100 + nextTm->tm_mday;
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


void GetDateTimeFromUpdateTs(long long updateTs, int& date, int& hour, int& minute, int& second, int& milliSecond)
{
	milliSecond = (int)(updateTs % 1000LL);
	updateTs /= 1000LL;
	second = (int)(updateTs % 100LL);
	updateTs /= 100LL;
	minute = (int)(updateTs % 100LL);
	updateTs /= 100LL;
	hour = (int)(updateTs % 100LL);
	date = (int)(updateTs / 100LL);
}
int CalculateNextBarFromDayBar(int tradingDay, int barPeriod)
{
	if (barPeriod <= 1)
	{
		return tradingDay;
	}
	else if (barPeriod == 7)
	{
		auto t = GetTm(tradingDay);
		if (t->tm_wday != 0)
		{
			auto time = mktime(t);
			time += (7LL - t->tm_wday) * 86400LL;
			t = localtime(&time);
		}
		return (t->tm_year + 1900) * 10000 + (t->tm_mon + 1) * 100 + t->tm_mday;
	}
	else if (barPeriod == 30)
	{
		return (tradingDay / 100) * 100 + 31;
	}
	else if (barPeriod == 90)
	{
		auto t = GetTm(tradingDay);
		auto mon = t->tm_mon + 1;
		if (mon % 3 != 0)
		{
			mon = ((mon / 3) + 1) * 3;
		}
		return (t->tm_year + 1900) * 10000 + mon * 100 + 31;
	}
	else if (barPeriod >= 365)
	{
		return (tradingDay / 10000) * 10000LL + 1231;
	}
	else
	{
		auto t = GetTm(tradingDay);
		auto dayCount = t->tm_yday + 1;
		if (dayCount % barPeriod == 0)
			return tradingDay;
		auto nextBarDayCount = ((dayCount / barPeriod) + 1) * barPeriod;
		auto time = mktime(t);
		time += (nextBarDayCount - dayCount) * 86400LL;
		t = localtime(&time);
		return (t->tm_year + 1900) * 10000 + (t->tm_mon + 1) * 100 + t->tm_mday;
	}
	return tradingDay;
}
int CalculateMinutes(int hour, int minute)
{
	return hour * 60 + minute;
}
int CalculateMinutesTimeStamp(int minutes)
{
	return (minutes / 60) * 100 + minutes % 60;
}
int CalculateSeconds(int hour, int minute, int second)
{
	return hour * 3600 + minute * 60 + second;
}
int CalculateSecondsTimeStamp(int seconds)
{
	auto hour = (seconds / 3600);
	seconds %= 3600;
	auto minute = (seconds / 60);
	auto second = seconds % 60;
	return hour * 10000 + minute * 100 + second;
}


int CalculateNextBarDate(int barPeriod, int date)
{
	if (barPeriod == 1)
	{
		return date;
	}
	return CalculateNextBarFromDayBar(date, barPeriod);
}
long long CalculateNextMinuteBarTime(int barPeriod, long long updateTs)
{
	int date, hour, minute, second, milliSecond;
	GetDateTimeFromUpdateTs(updateTs, date, hour, minute, second, milliSecond);
	auto minutes = CalculateMinutes(hour, minute);
	if (second > 0 || milliSecond > 0)
	{
		minutes += 1;
	}
	auto flag = (minutes % barPeriod == 0) ? 0 : 1;
	int nextBarTimeMinutes = ((minutes / barPeriod) + flag) * barPeriod;
	if (nextBarTimeMinutes >= 1440)
	{
		date = GetNextDate(date);
		nextBarTimeMinutes -= 1440;
	}
	long long nextBarTimeStamp = CalculateMinutesTimeStamp(nextBarTimeMinutes);
	return date * 1000000000LL + nextBarTimeStamp * 100000LL;
}
long long CalculateNextSecondBarTime(int barPeriod, long long updateTs)
{
	int date, hour, minute, second, milliSecond;
	GetDateTimeFromUpdateTs(updateTs, date, hour, minute, second, milliSecond);
	auto seconds = CalculateSeconds(hour, minute, second);
	if (milliSecond > 0)
	{
		seconds += 1;
	}
	auto flag = (seconds % barPeriod == 0) ? 0 : 1;
	int nextBarTimeSeconds = ((seconds / barPeriod) + flag) * barPeriod;
	if (nextBarTimeSeconds >= 86400)
	{
		date = GetNextDate(date);
		nextBarTimeSeconds -= 86400;
	}
	long long nextBarTimeStamp = CalculateSecondsTimeStamp(nextBarTimeSeconds);
	return date * 1000000000LL + nextBarTimeStamp * 1000LL;
}

