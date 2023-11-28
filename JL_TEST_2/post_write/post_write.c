#include "post_write.h"

#include <stdio.h>
#include <stdlib.h>

void post_write(unsigned int unique_id[], char title[], char writer[], char content[], int user_count)
{
    Board *format;
    for (int i = 0; i < user_count; i++)
    {
        // 번호 부여
        unique_id[i] = i;

        // 작성자가 제목, 작성자명, 게시글을 입력하는 함수
        request_message(title, writer, content, unique_id[i]);

        // 입력한 내용을 txt 파일에 작성?저장? 뭐라고 해야 하지?
        format = create_post(unique_id[i], title, writer, content);
        write_format_to_file(format);
    }
    
}
   