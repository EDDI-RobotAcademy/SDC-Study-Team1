#include "create_post.h"

#include <stdlib.h>
#include <string.h>


// 연결 리스트의 첫 번째 게시글을 가리키는 포인터
//Board *head = NULL;

// 게시글에 부여할 번호를 저장하는 변수
//unsigned int unique_id;

// 새로운 게시글을 생성하고 연결 리스트에 추가하는 함수
// Board* create_post(int unique_id, char *title, char *writer, char *content) 
// {   
//     // post 라는 게시글 구조체 생성
//     // 새로운 게시글을 위한 메모리를 할당
//     Board *post = (Board *)malloc(sizeof(post));

//     // 문자열 길이 계산
//     int title_length = strlen(title) + 1;
//     int writer_length = strlen(writer) + 1;
//     int content_length = strlen(content) + 1;

//     // 게시글 고유 번호 부여
//     post->unique_id = unique_id++;

//     // 제목, 작성자, 내용을 복사하여 저장
//     post->title = (char *)malloc(sizeof(char) * title_length);
//     strncpy(post->title, title, title_length);

//     post->writer = (char *)malloc(sizeof(char) * writer_length);
//     strncpy(post->writer, writer, writer_length);

//     post->content = (char *)malloc(sizeof(char) * content_length);
//     strncpy(post->content, content, content_length);


//     return post;
// }

unsigned int test_form_unique_id = 0;

int increment_test_form_unique_id(void)
{
    return test_form_unique_id++;
}

Board *init_test_form_with_id(unsigned int id, char *title, char *writer, char *content)
{
    Board *tmp_Board = (Board *)malloc(sizeof(Board));
    int title_length = strlen(title) + 1;
    int writer_length = strlen(writer) + 1;
    int content_length = strlen(content) + 1;

    tmp_Board->unique_id = id;
    tmp_Board->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(tmp_Board->title, title, title_length);

    tmp_Board->writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(tmp_Board->writer, writer, writer_length);
    
    tmp_Board->content =
        (char *)malloc(sizeof(char) * content_length);
    strncpy(tmp_Board->content, content, content_length);

    return tmp_Board;
}

Board *init_test_form(char *title, char *writer, char *content)
{
    Board *tmp_Board = (Board *)malloc(sizeof(Board));
    int title_length = strlen(title) + 1;
    int content_length = strlen(content) + 1;
    int writer_length = strlen(writer) + 1;

    tmp_Board->unique_id = increment_test_form_unique_id();
    tmp_Board->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(tmp_Board->title, title, title_length);

    tmp_Board->writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(tmp_Board->writer, writer, writer_length);

    tmp_Board->content =
        (char *)malloc(sizeof(char) * content_length);
    strncpy(tmp_Board->content, content, content_length);

    return tmp_Board;
}

Board **init_test_form_array(int count)
{
    Board **tmp_Board = (Board **)malloc(sizeof(Board *) * count);

    return tmp_Board;
}