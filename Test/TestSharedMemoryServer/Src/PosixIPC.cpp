#include "PosixIPC.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef LINUX
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#endif
#include <string.h>
#include <algorithm>


#define SHM_SIZE 1024 // 共享内存大小
#define SHM_NAME "myshm" // 共享内存名称

void TestPosixIPC()
{
    auto a = std::max(12, 34);
#ifdef LINUX
    int fd;
    char* shmaddr;
    fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        exit(1);
    }
    // 调整共享内存区域的大小
    if (ftruncate(fd, SHM_SIZE) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // 映射共享内存区域到进程地址空间中
    shmaddr = (char*)mmap(nullptr, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shmaddr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    while (::strcmp(shmaddr, "quit") != 0)
    {
        printf("client: %s\n", shmaddr);
        sleep(3);
    }
    // 解除共享内存区域与进程地址空间的映射关系
    if (munmap(shmaddr, SHM_SIZE) == -1) {
        perror("munmap");
        exit(1);
    }

    // 删除共享内存区域的文件名并释放资源
    if (shm_unlink(SHM_NAME) == -1) {
        perror("shm_unlink");
        exit(1);
    }
#endif
}

