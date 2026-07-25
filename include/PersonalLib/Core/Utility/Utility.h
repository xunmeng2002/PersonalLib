#pragma once
#include <PersonalLib/Core/CoreExport.h>
#include <PersonalLib/Types.h>
#include <string>
#include <cstring>


class CORE_EXPORTS Utility
{
public:
    static void ParseProcessName(const char* fullProcessName, char* processName, int len);

    static std::string ItoA(int value);
    static std::string FtoA(double value);

    template<int N>
    static char* Strcpy(char(&dest)[N], const char* src)
    {
        if (src == nullptr)
            return nullptr;
        return strncpy(dest, src, sizeof(dest) - 1);
    }


    static void PrintBytes(const char* name, char* src, int len);
    static void RemoveCharacter(char* src, int size, char c = ' ');

    static ProtocolTypeType GetConfigProtocolType(const std::string& configProtocolType);
};