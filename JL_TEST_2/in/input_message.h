#ifndef __INPUT_MESSAGE_H__
#define __INPUT_MESSAGE_H__

#define INPUT_MESSAGE     32

void get_user_keyboard_input(char *keyboard_input);
void get_user_keyboard_input_with_message(char *output_message, char *keyboard_input);

/*
void get_user_keyboard_hidden_input_with_message(
    char *output_message, char *keyboard_hidden_input);
*/

#endif