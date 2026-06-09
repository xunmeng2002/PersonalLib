#pragma once
#include <PersonalLib/Serialization/SerializationExport.h>
#include <string>
#include <cstring>
#include <codecvt>


class codecvt_gbk : public std::codecvt_byname<wchar_t, char, std::mbstate_t>
{
public:
    codecvt_gbk()
#ifdef WINDOWS
        :codecvt_byname("zh_CN")
#else
        : codecvt_byname("zh_CN.GB18030")
#endif
    {
    }
};


std::wstring SERIALIZATION_EXPORTS GbkToUnicode(const std::string& str);
std::string SERIALIZATION_EXPORTS UnicodeToGbk(const std::wstring& str);
std::wstring SERIALIZATION_EXPORTS Utf8ToUnicode(const std::string& str);
std::string SERIALIZATION_EXPORTS UnicodeToUtf8(const std::wstring& str);
std::string SERIALIZATION_EXPORTS GbkToUtf8(const std::string& str);
std::string SERIALIZATION_EXPORTS Utf8ToGbk(const std::string& str);

template <int N>
void TrunsferUtf8ToGbk(char (&src)[N])
{
    std::string gbk = Utf8ToGbk(src);
    memset(src, 0, N);
    memcpy(src, gbk.c_str(), gbk.length());
}
template <int N>
void TrunsferGbkToUtf8(char (&src)[N])
{
    std::string utf8 = GbkToUtf8(src);
    memset(src, 0, N);
    memcpy(src, utf8.c_str(), utf8.length());
}

