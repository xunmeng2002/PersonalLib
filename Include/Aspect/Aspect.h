#pragma once
#include <functional>
#include <string>

using namespace std;


template <typename Func, typename... Args>
struct Aspect
{
    Aspect(Func& f, const std::string& funcName)
        : m_Func(std::forward<Func>(f)), m_FuncName(funcName)
    {
    }

    template <typename T>
    void Invoke(Args&&... args, T&& aspect)
    {
        aspect.Before(m_FuncName.c_str());
        m_Func(std::forward<Args>(args)...); //core code
        aspect.After(m_FuncName.c_str());
    }

    template <typename T, typename... AP>
    void Invoke(Args&&... args, T&& aspect, AP&&... aspects)
    {
        aspect.Before(m_FuncName.c_str());
        Invoke(std::forward<Args>(args)..., AP()...);
        aspect.After(m_FuncName.c_str());
    }
private:
    Func m_Func;
    std::string m_FuncName;
};

template <typename... AP, typename... Args, typename Func>
void Invoke(Func&& f, const std::string& funcName, Args&&... args)
{
    Aspect<Func, Args...> asp(std::forward<Func>(f), funcName);
    asp.Invoke(std::forward<Args>(args)..., AP()...);
}
