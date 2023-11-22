#include <stdio.h>
#include <fcntl.h>

#include "file_io/how_to_make_file.h"
#include "file_io/how_to_write_content.h"
#include "file_io/how_to_read_content.h"

#include "format_test/form_test.h"
#include "format_test/make_file_from_format.h"


#include "ui/console/user_keyboard_input.h"

#define MAX_OUTPUT_MESSAGE          128


int main (void)
{
    test_form *format;

    
    char title_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char user_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char self_introduction_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    
    char read_board_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    
    // char title_output_message[MAX_OUTPUT_MESSAGE] = {
    //     "제목을 입력해주세요.\n"
    // };
    // get_user_keyboard_input_with_message(title_output_message, title_keyboard_input);
    
    // char user_output_message[MAX_OUTPUT_MESSAGE] = {
    //     "작성자을 입력해주세요.\n"
    // };
    // get_user_keyboard_input_with_message(user_output_message, user_keyboard_input);

    // char self_introduction_output_message[MAX_OUTPUT_MESSAGE] = {
    //     "내용을 입력해주세요.\n"
    // };
    // get_user_keyboard_input_with_message(self_introduction_output_message, self_introduction_keyboard_input);

    // format = init_test_form(title_keyboard_input, user_keyboard_input, self_introduction_keyboard_input);
    // write_format_to_file(format);
    
    

    char read_board_output_message[MAX_OUTPUT_MESSAGE] = {
        "읽어볼 게시물의 제목을 입력하세요.\n"
    };
    get_user_keyboard_input_with_message(read_board_output_message, read_board_keyboard_input);
    read_file_to_format(read_board_keyboard_input);

    
    

    

    return 0;
}
