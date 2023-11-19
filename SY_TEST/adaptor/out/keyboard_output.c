#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "keyboard_output.h"


void print_Message(const char* message)
{
    write(1, message, strlen(message));
}