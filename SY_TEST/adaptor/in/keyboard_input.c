#include <stdio.h>
#include <unistd.h>
#include "keyboard_input.h"

void get_user_keyboard_input(char* keyboard_input)
{

    read(0, keyboard_input, MAX_USER_KEYBOARD_INPUT);

}