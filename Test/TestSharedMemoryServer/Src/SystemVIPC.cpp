#include "SystemVIPC.h"
#include <stdio.h>
#include <string.h>
#ifdef LINUX
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>  
#endif
 



const int Key = 12345;
const int Size = 4096;

void ClearShm(int key)
{
#ifdef LINUX
	int shmid = shmget(key, Size, IPC_CREAT);
	shmctl(shmid, IPC_RMID, nullptr);
#endif
}

void TestSystemVIPC()
{
#ifdef LINUX
	int shmid = shmget(12345, Size, IPC_CREAT | 0666);
	if (shmid < 0)
	{
		perror("shmget");
		return;
	}
	printf("shmid:%d\n", shmid);

	printf("attach begin:\n");
	char* mem = (char*)shmat(shmid, nullptr, 0);
	printf("errno:%d\n", errno);
	printf("attach end: %d\n", (int)*mem);
	while (::strcmp(mem, "quit") != 0)
	{
		printf("client: %s\n", mem);
		sleep(3);
	}
	printf("detach begin:\n");
	shmdt(mem);
	printf("detach end.\n");

	shmctl(shmid, IPC_RMID, nullptr);
#endif
}

