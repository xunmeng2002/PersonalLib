#include "Aspect/AspectTest.h"
#include <PersonalLib/Core/Aspect/Aspect.h>
#include <PersonalLib/Core/Aspect/AspectBefore.h>
#include <PersonalLib/Core/Aspect/AspectAfter.h>
#include <iostream>

void CoreFunc()
{
    std::cout << "core function called" << std::endl;
}
void TestAspect()
{
    Invoke<AA>(CoreFunc, "core_func");
    Invoke<AA, BB, CC>(CoreFunc, "core_func");
    //InvokeBefore<AA, BB, CC>(CoreFunc, "core_func");
    //InvokeAfter<AA, BB, CC>(CoreFunc, "core_func");
}

