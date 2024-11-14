#include "MD5.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    HINSTANCE hinst = LoadLibraryA("PersonalLib.dll");


    string src = "HelloWorldHelloWorldHelloWorldHelloWorldHelloWorldHelloWorld";

    string s = getMD5((const unsigned char*)src.c_str(), src.length());
    cout << s;
    return 0;
}