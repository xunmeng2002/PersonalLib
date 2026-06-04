#include "Platform/Platform.h"
#ifdef LINUX
#include <unistd.h>



int GetLastError()
{
    return errno;
}
int WSAGetLastError()
{
    return errno;
}
#endif
