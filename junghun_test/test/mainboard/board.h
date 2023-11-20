#ifndef __BOARD_H__
#define __BOARD_H__

#include "utility/read_board.h"

typedef struct _Board board;

struct _Board {
    int unique_id;
    char title[100];
    char author[50];
    char content[500];
};




#endif