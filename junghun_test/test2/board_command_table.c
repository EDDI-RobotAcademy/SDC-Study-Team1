#include "board_command_table.h"
#include "adapter/in/create/create_post.h"
#include "adapter/in/delete/delete_post.h"

void choose_menu(void (**board_menu)(void))
{
    board_menu[1] = create_post;
    board_menu[2] = delete_post;
    
}