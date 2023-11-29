#ifndef __INPUT_MESSAGE_H__
#define __INPUT_MESSAGE_H__

#define INPUT_MESSAGE     256

void get_user_keyboard_input(char *keyboard_input);
void get_user_keyboard_input_with_message(char *output_message, char *keyboard_input);
void request_message(char *title, char *writer, char *content, int unique_id);

#endif