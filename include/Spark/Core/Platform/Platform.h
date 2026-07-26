#pragma once
#include <Spark/Core/CoreExport.h>

#ifdef LINUX
#include <errno.h>

int CORE_EXPORTS GetLastError();
int CORE_EXPORTS WSAGetLastError();
#endif

