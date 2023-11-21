#include "post_adapter_in.h"
#include "../domain/model/board_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

// 사용자로부터 게시글의 제목과 내용을 입력받아 게시글을 생성하는 함수입니다.
Post* input_post() 
{
    // 제목과 내용을 저장할 문자열을 선언합니다.
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];

    // 파일을 생성하거나, 이미 존재한다면 내용을 비우고 다시 쓸 수 있는 모드로 열습니다.
    int fd = open("input.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) 
    { // 파일 열기에 실패하면 에러 메시지를 출력하고 NULL을 반환합니다.
        perror("Failed to open file");
        return NULL;
    }

    // 사용자에게 제목을 입력하라는 메시지를 출력하고, 파일에서 제목을 읽어옵니다.
    printf("제목을 입력해주세요: ");
    read(fd, title, MAX_TITLE_LENGTH);
    title[strcspn(title, "")] = '\0';  // 마지막의 개행 문자를 제거합니다.

    // 사용자에게 내용을 입력하라는 메시지를 출력하고, 파일에서 내용을 읽어옵니다.
    printf("내용을 입력해주세요: ");
    read(fd, content, MAX_CONTENT_LENGTH);
    content[strcspn(content, "")] = '\0';  // 마지막의 개행 문자를 제거합니다.

    // 파일을 닫습니다.
    close(fd);

    // 제목과 내용을 가지는 게시글을 생성하고 반환합니다.
    return create_post(title, content);
}