#include "write_post.h"
#include "form_test.h"
#include "ui/console/user_keyboard_input.h"

#include <stdio.h>

void write_post(void)
{
    char user_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char title_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char content_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char title_output_message[MAX_OUTPUT_MESSAGE] = {
        "제목을 입력하세요\n"
    };
    get_user_keyboard_input_with_message(title_output_message, title_keyboard_input);
    char user_output_message[MAX_OUTPUT_MESSAGE] = {
        "작성자를 입력하세요\n"
    };
    get_user_keyboard_input_with_message(user_output_message, user_keyboard_input);
    char content_output_message[MAX_OUTPUT_MESSAGE] = {
        "내용을 입력하세요\n"
    };
    get_user_keyboard_input_with_message(content_output_message, content_keyboard_input);
    
    test_form * tmp_form = init_test_form_with_id( test_form_unique_id, title_keyboard_input, user_keyboard_input, content_keyboard_input);
    printf("고유번호 -> %d,제목 -> %s 사용자 -> %s 내용 -> %s",tmp_form->unique_id,tmp_form->title,tmp_form->user,tmp_form->content);

}