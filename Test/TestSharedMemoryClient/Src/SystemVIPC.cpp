#include "SystemVIPC.h"
#include <stdio.h>
#include <string.h>
#ifdef LINUX
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#endif


const int Key = 12345;
const int Size = 4096;

void TestSystemVIPC()
{
#ifdef LINUX
	int shmid = shmget(Key, Size, IPC_CREAT | 0666);
	if (shmid < 0)
	{
		perror("shmget");
		return;
	}
	printf("shmid:%d\n", shmid);

	printf("attach begin:\n");
	char* mem = (char*)shmat(shmid, nullptr, 0);
	printf("attach end: %d\n", (int)*mem);
	while (::strcmp(mem, "quit") != 0)
	{
		scanf("%s", mem);
	}
	printf("detach begin:\n");
	shmdt(mem);
	printf("detach end.\n");
#endif
}