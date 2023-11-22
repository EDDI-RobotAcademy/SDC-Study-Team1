#include "../format_test/form_test.h"
#include "../ui/console/user_keyboard_input.h"
#include "../data_repo/data_store.h"
#include "../list_post/post_list.h"
#include "post_read.h"
#include <stdio.h>
#define MAX_OUTPUT_MESSAGE          512
void post_read(test_form **data_storage)
{
    
        post_list(data_storage);
        int i=0;
        char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
        char output_message[MAX_OUTPUT_MESSAGE] = {"열람할 게시물 번호를 입력하시오\n"};
        get_user_keyboard_input_with_message(output_message, keyboard_input);
        i=atoi(keyboard_input);
        if(test_form_unique_id!=0)
        {
            
            printf("게시글 번호 << %d >>\n",data_storage[i]->unique_id);
            printf("게시글 제목 << %s >>\n",data_storage[i]->title);
            printf("게시글 내용 << %s >>\n",data_storage[i]->content);
        }
        
        
    
    

}