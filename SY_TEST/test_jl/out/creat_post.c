#include "creat_post.h"
#include "../format/make_file_from_format.h"
#include "../domain/model/board.h"

// user 수 임의로 지정함
#define MAX_USER_NUMBER     5
#define SLAB_CACHE      256 

#include <stdio.h>

    void creat_post(void)
    {   
        Board *format;
        char title[SLAB_CACHE]; // 제목
        char writer[SLAB_CACHE]; // 작성자
        char content[SLAB_CACHE]; // 게시글 내용
        unsigned int unique_id[SLAB_CACHE]; //게시글 번호
    
    

        // 작성자 3명(USER_NUMBER)이라 가정하고 for문 작성해봄
    
        for (int i = 0; i < MAX_USER_NUMBER; i++)
            {
                // 게시글의 번호 부여
                unique_id[i] = i;

                // 작성자가 제목, 작성자명, 게시글을 입력하는 함수
                request_message(title, writer, content, unique_id[i]);

                // 입력한 내용을 txt 파일에 작성?저장? 뭐라고 해야 하지?
                format = create_post(unique_id[i], title, writer, content);
                write_format_to_file(format);
        
            }
    
    }