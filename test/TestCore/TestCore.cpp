#include "PersonalLib/Core/MD5/MD5.h"
#include "PersonalLib/Core/Logger/Logger.h"
#include "PersonalLib/Core/Aspect/Aspect.h"
#include "PersonalLib/Core/Aspect/AspectLogger.h"
#include "PersonalLib/Core/Aspect/AspectPerformance.h"
#include <iostream>
using namespace std;

void CalcalateMD5(const char* src, int len)
{
    string s = getMD5((const unsigned char*)src, len);
    WriteLog(LogLevel::Info, "getMD5 Result:%s", s.c_str());
}

int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();

    WriteLog(LogLevel::Info, "TestPersonalLib Start.");

    string src = "HelloWorldHelloWorldHelloWorldHelloWorldHelloWorldHelloWorld";

    Invoke<AspectLogger, AspectPerformance>(CalcalateMD5, "CalcalateMD5", src.c_str(), src.length());

    WriteLog(LogLevel::Info, "TestPersonalLib Stop.");

    this_thread::sleep_for(chrono::seconds(1));
    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();
    return 0;
}