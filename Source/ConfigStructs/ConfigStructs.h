#pragma once
#include <string>

struct TimeZone
{
	std::string StartTime;
	std::string EndTime;
};

struct IPAddressField
{
	int AddressType;
	std::string IPString;
	int IP;
	int Port;
};