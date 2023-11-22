#include "../format_test/form_test.h"
#include "../ui/console/user_keyboard_input.h"
#include "../data_repo/data_store.h"
#include "post_list.h"
#include <stdio.h>

void post_list(test_form **data_storage)
{
    
    
    
    int i=0;
    if(test_form_unique_id==0)
    {
        printf("게시물이 존재하지 않습니다\n"); 
    }
    else
    { 
        for(i=0;i< test_form_unique_id;i++)
        {
            printf("게시글 번호 << %d >>\n",data_storage[i]->unique_id);
            printf("게시글 제목 << %s >>\n",data_storage[i]->title);
           
        
        }
    }
    

}