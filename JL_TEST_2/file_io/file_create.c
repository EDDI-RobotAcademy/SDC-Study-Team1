#include "file_create.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

// 파일 생성
int file_open(char *filename, int option, unsigned int permission)
{
    // filename: 파일 경로, option: 파일에 대한열기 옵션, permission: 파일 접근 권한
    int fd_descriptor = open(filename, option, permission);

    if (fd_descriptor == ERROR)
    {
        printf("open() System Call error!\n");
        return ERROR;
    }

    return fd_descriptor;
}

// 파일 닫기
void file_close(int file_descriptor)
{
    close(file_descriptor);
}