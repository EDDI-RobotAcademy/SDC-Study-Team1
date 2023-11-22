#include "board_model.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// 연결 리스트의 첫 번째 게시글을 가리키는 포인터입니다.
Post *head = 0;

// 게시글에 부여할 유니크한 ID를 저장하는 변수입니다.
int unique_id = 0;

// 새로운 게시글을 생성하고 연결 리스트에 추가하는 함수입니다.
Post* create_post(char *title, char *content) 
{
    // 새로운 게시글을 위한 메모리를 할당받습니다.
    Post *post = malloc(sizeof(post));

    // 게시글에 유니크한 ID를 부여합니다.
    post->id = unique_id++;

    // 제목과 내용을 복사하여 저장합니다.
    post->title = strdup(title);
    post->content = strdup(content);

    // 다음 게시글을 가리키는 포인터를 NULL로 초기화합니다.
    post->next = 0;

    // 만약 첫 번째 게시글이 없다면, 새로운 게시글을 첫 번째 게시글로 설정합니다.
    if (head == 0) 
    {
        head = post;
    } 
    
    else 
    {
        // 그렇지 않다면, 연결 리스트의 마지막 게시글을 찾아 새로운 게시글을 추가합니다.
        Post *last = head;
        while (last->next != 0) {
            last = last->next;
        }
        last->next = post;
    }
    
    return post;
}