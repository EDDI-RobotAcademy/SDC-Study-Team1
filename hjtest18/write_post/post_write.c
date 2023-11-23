#include "../format_test/form_test.h"
#include "../ui/console/user_keyboard_input.h"
#include "../data_repo/data_store.h"
#include "post_write.h"
#define MAX_OUTPUT_MESSAGE          512
void post_write(test_form **data_storage)
{
    
    test_form* tmp_form;
    char title_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char user_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char content_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };

    char title_output_message[MAX_OUTPUT_MESSAGE] = {"제목을 작성하세요\n" };
    get_user_keyboard_input_with_message(title_output_message, title_keyboard_input);

    char user_output_message[MAX_OUTPUT_MESSAGE] = {"작성자를 작성하세요\n" };
    get_user_keyboard_input_with_message(user_output_message, user_keyboard_input);  

    char content_output_message[MAX_OUTPUT_MESSAGE] = {"내용을 작성하세요\n" };
    get_user_keyboard_input_with_message(content_output_message, content_keyboard_input);    

    tmp_form = init_test_form_with_id( test_form_unique_id, title_keyboard_input,  user_keyboard_input, content_keyboard_input);
    save_data(data_storage,tmp_form);
    
}