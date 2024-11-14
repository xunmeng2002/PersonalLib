#include "MD5.h"
#include <iostream>
using namespace std;

int main()
{
    string src = "HelloWorldHelloWorldHelloWorldHelloWorldHelloWorldHelloWorld";

    string s = getMD5((const unsigned char*)src.c_str(), src.length());
    cout << s;
    return 0;
}