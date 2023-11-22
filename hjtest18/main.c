#include "ui/console/user_keyboard_input.h"
#include "format_test/form_test.h"
#include "data_repo/data_store.h"
#include "write_post/post_write.h"
#include "list_post/post_list.h"
#include "read_post/post_read.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_OUTPUT_MESSAGE          512

int main (void)
{
    
    char output_message[MAX_OUTPUT_MESSAGE] = {
        "0번. 게시물 조회\n"
        "1번. 게시물 작성\n"
        "2번. 게시물 삭제\n"
        "3번. 게시물 읽기\n"
        "4번. 게시물 수정\n"
        "5번. 프로그램 종료\n"

    };
    
    test_form **data_storage=init_test_form_array(10);
    
    
    int i=0;
    do{
        char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
        get_user_keyboard_input_with_message(output_message, keyboard_input);
        i=atoi(keyboard_input);
    switch(i)
    {
        case 0: 
            printf("-----게시물 조회하기-----\n");
            post_list(data_storage);
            break;
        case 1: 
            printf("-----게시물 작성하기-----\n");
            post_write(data_storage);
            break;
        case 2: 
            printf("2번 실행\n");
            break;
        case 3: 
            printf("-----열람할 게시물 번호를 입력하시오-----\n");
            post_read(data_storage);
            break;
        case 4: 
            printf("4번 실행\n");
            break;
        case 5: 
            printf("프로그램을 종료합니다\n");
            break; 
        default:    
            printf("입력 오류 다시 입력하세요\n");
    }
    }while(i!=5);
    printf("현재 전역변수 1이어야함 ->%d\n 제목 %s\n  작성자 %s\n, 내용 %s\n", test_form_unique_id, \
     data_storage[0]->title,data_storage[0]->user,data_storage[0]->content );
    
    // get_user_keyboard_hidden_input_with_message(password_message, keyboard_input);
    // printf("실제 사용자가 입력한 값은: %s\n", keyboard_input);

    return 0;
}
