#include "Aspect/AspectTest.h"
#include <PersonalLib/Core/Aspect/Aspect.h>
#include <PersonalLib/Core/Aspect/AspectBefore.h>
#include <PersonalLib/Core/Aspect/AspectAfter.h>
#include <iostream>

using namespace std;

void CoreFunc()
{
    cout << "core function called" << endl;
}
void TestAspect()
{
    Invoke<AA>(CoreFunc, "core_func");
    Invoke<AA, BB, CC>(CoreFunc, "core_func");
    //InvokeBefore<AA, BB, CC>(CoreFunc, "core_func");
    //InvokeAfter<AA, BB, CC>(CoreFunc, "core_func");
}

