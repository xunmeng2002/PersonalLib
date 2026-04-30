#include "Utility/Utility.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>



void ParseProcessName(const char* fullProcessName, char* processName, int len)
{
#if WINDOWS
	const char* temp = strrchr(fullProcessName, '\\');
	temp = temp == nullptr ? fullProcessName : ++temp;
	temp = strtok((char*)temp, ".");
#endif
#if LINUX
	const char* temp = strrchr(fullProcessName, '/');
	temp = temp == nullptr ? fullProcessName : ++temp;
#endif
	strncpy(processName, temp, len);
}


std::string ItoA(int value)
{
	static char buff[32];
	sprintf(buff, "%d", value);
	return std::string(buff);
}
std::string FtoA(double value)
{
	static char buff[32];
	sprintf(buff, "%f", value);
	return std::string(buff);
}
void Erase(std::string& str, char a)
{
	str.erase(std::remove(str.begin(), str.end(), a), str.end());
}


void PrintBytes(const char* name, char* src, int len)
{
	std::ofstream ofs("temp.log", std::ios::app);
	char buff[1024] = { 0 };
	int index = sprintf(buff, "%s:", name);
	for (auto i = 0; i < len; ++i)
	{
		index += sprintf(buff + index, "%02X ", (unsigned char)src[i]);
	}
	ofs << buff << std::endl;
}

void RemoveCharacter(char* src, int size, char c)
{
	auto read = src;
	auto write = src;
	for (auto i = 0; i < size; ++i, ++read)
	{
		if (*read != c)
		{
			*write = *read;
			++write;
		}
	}
	*write = '\0';
}

ProtocolTypeType GetConfigProtocolType(const std::string& configProtocolType)
{
	if (configProtocolType == "step")
	{
		return ProtocolTypeType::Step;
	}
	else if (configProtocolType == "xtp")
	{
		return ProtocolTypeType::Xtp;
	}
	return ProtocolTypeType::Xtp;
}

