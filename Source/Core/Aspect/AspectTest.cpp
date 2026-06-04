#include "AspectTest.h"
#include "Aspect/Aspect.h"
#include "Aspect/AspectBefore.h"
#include "Aspect/AspectAfter.h"
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

