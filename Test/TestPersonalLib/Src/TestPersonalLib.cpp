#include "MD5.h"
#include "Logger.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();

    //WriteLog(LogLevel::Info, "TestPersonalLib Start.");

    string src = "HelloWorldHelloWorldHelloWorldHelloWorldHelloWorldHelloWorld";

    string s = getMD5((const unsigned char*)src.c_str(), (int)src.length());
    //WriteLog(LogLevel::Info, "getMD5 Result:%s", s.c_str());

    //WriteLog(LogLevel::Info, "TestPersonalLib Stop.");
    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();
    return 0;
}