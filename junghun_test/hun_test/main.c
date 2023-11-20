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
	char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char output_message[MAX_OUTPUT_MESSAGE] = {
        "txt파일 이름을 입력해주세요.\n"
    };

    get_user_keyboard_input_with_message(output_message, keyboard_input);
    printf("사용자 입력 데이터: %s\n", keyboard_input);
    
    int created_descriptor = created_file_descriptor(keyboard_input);
    

    printf("hi\n");
    return 0;
}
