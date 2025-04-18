#pragma once
#include <chrono>
#include "Types.h"

enum class TcpProtocolType : int
{
    Udp = '0',
    TcpSelect = '1',
    TcpEpoll = '2',
    TcpIocp = '3',
    Xtp = '4',
    Step = '5'
};

struct ShmPackage
{
    int ShmType;
    int Count;
    char Data[16];
};

extern TcpProtocolType g_ClientProtocolType;
extern TcpProtocolType g_ServerProtocolType;
extern const char* g_Address;
extern const char* g_IocpServerAddress;
extern const char* g_IocpClientAddress;
extern const char* g_ShmName;
extern const char* g_SemName;


void PrintTimeCost(const char* name, std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> startTime, std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> endTime);