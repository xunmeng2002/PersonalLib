#pragma once

#ifdef LINUX
#include <errno.h>

int GetLastError();
int WSAGetLastError();
#endif

