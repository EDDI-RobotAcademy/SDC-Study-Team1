#include "board_command_table.h"
#include "func1/func1.h"
#include "func2/func2.h"
#include "list_board.h"
void choose_menu(void (**board_menu)(void))
{
    board_menu[0] = list_board;
    board_menu[1] = func2;
    
}