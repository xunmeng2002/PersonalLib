#pragma once
#include <string>
#include <cstring>

void ParseProcessName(const char* fullProcessName, char* processName, int len);

std::string ItoA(int value);
std::string FtoA(double value);
void Erase(std::string& str, char a);

template<int N>
char* Strcpy(char(&dest)[N], const char* src)
{
    return strncpy(dest, src, sizeof(dest) - 1);
}


void PrintBytes(const char* name, char* src, int len);
void RemoveCharacter(char* src, int size, char c = ' ');

