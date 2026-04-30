#pragma once
#include <chrono>
#include "Types/Types.h"

enum class TcpProtocolType : int
{
    Shm = 0,
    Udp,
    TcpSelect,
    TcpEpoll,
    TcpIocp,
    Xtp,
    Step
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
extern const char* g_ShmName;
extern const char* g_SemName;


void PrintTimeCost(const char* name, std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> startTime, std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> endTime);