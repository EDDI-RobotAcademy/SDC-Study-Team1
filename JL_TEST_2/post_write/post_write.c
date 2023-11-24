#include "post_write.h"

#include <stdio.h>
#include <stdlib.h>

void post_write(unsigned int unique_id, char *title, char *writer, char *content, Board *format)
{
    // 작성자가 제목, 작성자명, 게시글을 입력하는 함수
    request_message(title, writer, content, unique_id);

    // 입력한 내용을 txt 파일에 작성?저장? 뭐라고 해야 하지?
    format = create_post(unique_id, title, writer, content);
    write_format_to_file(format);
    
}
   