#include "board_command_table.h"
#include "func1/func1.h"
#include "func2/func2.h"
#include "write_post.h"
void choose_menu(void (**board_menu)(void))
{
    //board_menu[0] = list_post;
    board_menu[1] = write_post;
    
}