#include "Platform.h"
#ifdef LINUX
#include <unistd.h>



int GetLastError()
{
    return errno;
}
#endif
