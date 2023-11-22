#include "create_post.h"
#include "../../../ui/console/user_keyboard_input.h"
#include "../../../api/service/write_post.h"
#include "../../../api/service/make_file_from_format.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>



#define BUDDY_PAGE_SIZE     4096
#define MAX_TEXT_LENGTH     128

char title[MAX_TEXT_LENGTH];
char writer[MAX_TEXT_LENGTH];
char content[MAX_TEXT_LENGTH];



// 연결 리스트의 첫 번째 게시글을 가리키는 포인터
Board *head = NULL;

// 게시글에 부여할 번호를 저장하는 변수
unsigned int unique_id;

// 새로운 게시글을 생성하고 연결 리스트에 추가하는 함수
Board* create_post(void) 
{   

    get_user_keyboard_input_with_message("제목을 입력하세요: ", title);
    get_user_keyboard_input_with_message("작성자를 입력하세요: ", writer);
    get_user_keyboard_input_with_message("내용을 입력하세요: ", content);

    // post 라는 게시글 구조체 생성
    // 새로운 게시글을 위한 메모리를 할당
    Board *post = (Board *)malloc(sizeof(Board));

    // 문자열 길이 계산
    int title_length = strlen(title) + 1;
    int writer_length = strlen(writer) + 1;
    int content_length = strlen(content) + 1;

    // 게시글 고유 번호 부여
    post->unique_id = unique_id++;

    // 제목, 작성자, 내용을 복사하여 저장
    post->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(post->title, title, title_length);

    post->writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(post->writer, writer, writer_length);

    post->content = (char *)malloc(sizeof(char) * content_length);
    strncpy(post->content, content, content_length);

    
    // 입력한 내용을 .txt 파일로 저장
    int created_file_descriptor = 0;
    write_post_in_file(created_file_descriptor, content);

    return post;
}

 // char filename[FILENAME_MAX];
    // sprintf(filename, "/proj/TEAM_1/SDC-Study-Team1/SY_TEST/test2/create_file/post_%d.txt", post->unique_id);  // 파일명 생성

    // FILE *file = fopen(filename, "w");  // 파일 열기

    // if (file == NULL) 
    // {
    //     printf("파일을 열 수 없습니다.");
    //     return NULL;
    // }

    // // 저장 경로와 파일명 설정
    // char filepath[BUDDY_PAGE_SIZE];
    // sprintf(filepath, "/proj/TEAM_1/SDC-Study-Team1/SY_TEST/test2/create_file/post_%d.txt", post->unique_id);

    // // 파일 열기
    // int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    // if (fd == -1) 
    // {
    //     printf("파일을 열 수 없습니다.");
    //     return NULL;
    // }

    // // 파일에 게시글 내용 저장
    // dprintf(fd, "제목: %s", post->title);
    // dprintf(fd, "작성자: %s", post->writer); 
    // dprintf(fd, "내용: %s", post->content);

    // // 파일 닫기
    // close(fd);