#pragma once
#include <iostream>

using std::cout;
using std::endl;

struct AA
{
    void Before(const char* funcName) { cout << funcName << ": AA Before" << endl; }
    void After(const char* funcName) { cout << funcName << ": AA After" << endl; }
};
struct BB
{
    void Before(const char* funcName) { cout << funcName << ": BB Before" << endl; }
    void After(const char* funcName) { cout << funcName << ": BB After" << endl; }
};
struct CC
{
    void Before(const char* funcName) { cout << funcName << ": CC Before" << endl; }
    void After(const char* funcName) { cout << funcName << ": CC After" << endl; }
};


void CoreFunc();
void TestAspect();
