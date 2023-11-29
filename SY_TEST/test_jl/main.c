#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


#include "utility/input_message.h"
#include "file_io/file_create.h"
#include "in/write_post_in_file.h"
#include "domain/model/board.h"
#include "format/make_file_from_format.h"
#include "post_write/post_write.h"
#include "out/creat_post.h"
#define MAX_OUTPUT_MESSAGE      256






int main (void)
{
    char keyboard_input[INPUT_MESSAGE] = { 0 };
    char output_message[MAX_OUTPUT_MESSAGE] = {
        "0번. 게시물 조회\n"
        "1번. 게시물 작성\n"
        "2번. 게시물 삭제\n"
        "3번. 게시물 읽기\n"
        "4번. 게시물 수정\n"
        "5번. 프로그램 종료\n"

    };

    
    // // 게시판 생성 및 사용자의 작성 
    // Board *format;
    // char title[SLAB_CACHE]; // 제목
    // char writer[SLAB_CACHE]; // 작성자
    // char content[SLAB_CACHE]; // 게시글 내용
    // unsigned int unique_id[SLAB_CACHE]; //게시글 번호
    

    int i;
    do{
        get_user_keyboard_input_with_message(output_message, keyboard_input);
        i = atoi(keyboard_input);
        
        switch(i)
        {
        case 0: 
            // 게시물 조회
            printf("사용자가 선택한 작업: %s\n", keyboard_input);
            //post_list(data_storage);
            break;
        case 1: 
            // 게시물 작성
            printf("사용자가 선택한 작업: %s\n", keyboard_input);
            create_post();
            break;
        case 2: 
            // 게시물 삭제
            printf("2번 실행\n");
            break;
        case 3: 
            // 게시물 읽기
            printf("-----열람할 게시물 번호를 입력하시오-----\n");
            //post_read(data_storage);
            break;
        case 4: 
            // 게시물 수정
            printf("4번 실행\n");
            break;
        case 5: 
            // 프로그램 종료
            printf("프로그램을 종료합니다\n");
            break; 
        default:    
            printf("입력 오류 다시 입력하세요\n");
        }
    } while(i!=5);
    //printf("현재 전역변수 1이어야함 ->%d\n 제목 %s\n  작성자 %s\n, 내용 %s\n", test_form_unique_id,
    //data_storage[0]->title,data_storage[0]->user,data_storage[0]->content );

    



    //사용자가 실행할 작업 선택
    get_user_keyboard_input_with_message(output_message, keyboard_input);
    printf("사용자가 선택한 작업: %d\n", atoi(keyboard_input));


    // 게시판 생성 및 사용자의 작성
    
    
    
   

    return 0;
}
