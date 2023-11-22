#include "delete_post.h"
#include "../create/create_post.h"

#include <stdio.h>
#include <stdlib.h>

#define FILENAME_MAX        4096

void delete_post(void)
{
    // 게시글을 삭제하기 위한 코드를 작성합니다.
    // 구조체를 이용하여 게시글을 관리하고, unique_id를 기반으로 게시글을 식별하여 삭제합니다.
    // 삭제할 파일명을 생성하고 remove() 함수를 사용하여 파일을 삭제합니다.
    char filename[FILENAME_MAX];
    sprintf(filename, "%s_%d.txt", "post", unique_id);

    if (remove(filename) == 0) 
    {
        printf("게시글이 삭제되었습니다.");
    } 
    
    else 
    {
        printf("게시글 삭제에 실패하였습니다.");
    }
}