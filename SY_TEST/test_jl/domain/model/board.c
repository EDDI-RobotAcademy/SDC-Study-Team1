#include "board.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 연결 시켜야 하는데....
//Board *head = NULL;

// 게시글에 부여할 번호를 저장하는 변수
unsigned int unique_id;

// 새로운 게시글을 생성하고 연결 리스트에 추가하는 함수
Board* create_post(int unique_id, char *title, char *writer, char *content) 
{   
    // post 라는 게시글 구조체 생성
    // 새로운 게시글을 위한 메모리를 할당
    Board *post = (Board *)malloc(sizeof(post));

    // 문자열 길이 계산
    int title_length = strlen(title) + 1;
    int writer_length = strlen(writer) + 1;
    int content_length = strlen(content) + 1;

    // 게시글 고유 번호 부여
    //post->unique_id = (head == NULL)? 0: head->unique_id + 1;
    post->unique_id = unique_id;

    // 제목, 작성자, 내용을 복사하여 저장
    post->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(post->title, title, title_length);

    post->writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(post->writer, writer, writer_length);

    post->content = (char *)malloc(sizeof(char) * content_length);
    strncpy(post->content, content, content_length);

    return post;
}