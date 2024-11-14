#pragma once
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


std::wstring GbkToUnicode(const std::string& str);
std::string UnicodeToGbk(const std::wstring& str);
std::wstring Utf8ToUnicode(const std::string& str);
std::string UnicodeToUtf8(const std::wstring& str);
std::string GbkToUtf8(const std::string& str);
std::string Utf8ToGbk(const std::string& str);

template <int N>
void TrunsferUtf8ToGbk(char (&src)[N])
{
    std::string gbk = Utf8ToGbk(src);
    memset(src, 0, N);
    memcpy(src, gbk.c_str(), gbk.length());
}
template <int N>
void TrunsferGbkUtf8(char (&src)[N])
{
    std::string utf8 = GbkToUtf8(src);
    memset(src, 0, N);
    memcpy(src, utf8.c_str(), utf8.length());
}

