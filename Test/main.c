#include "ui/console/user_keyboard_input.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_OUTPUT_MESSAGE          128

int main (void)
{
    char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char output_message[MAX_OUTPUT_MESSAGE] = {
        "0번. 게시물 조회\n"
        "1번. 게시물 작성\n"
        "2번. 게시물 삭제\n"
        "3번. 게시물 읽기\n"
    };
    get_user_keyboard_input_with_message(output_message, keyboard_input);
    printf("사용자 입력: %d\n", atoi(keyboard_input));


    return 0;
}
