#include "post_adapter_out.h"
#include "../domain/model/board_model.h"
#include <stdio.h>

// 게시글을 출력하는 함수입니다.
void print_post(Post *post)
{
    // post가 NULL인 경우, 즉 게시글이 없는 경우에는 메시지를 출력하고 함수를 종료합니다.
    if (post == 0) 
    {
        printf("게시글이 없습니다.");
        return;
    }

    // 게시글의 ID, 제목, 내용을 출력합니다.
    printf("ID: %d", post->id);
    printf("제목: %s", post->title);
    printf("내용: %s", post->content);

}