#ifndef __BOARD_H__
#define __BOARD_H__

#include <stdio.h>
#include <stdlib.h>


extern int unique_id;

typedef struct _Board board;
struct _Board
{
    int unique_id;
    char *major;
    int age;
    char *self_introduction;
};

void reset_board(struct _Board *board);
void add_board(struct _Board *board);
void view_boards(const struct _Board *board);
void edit_board(struct _Board *board, int unique_id);
void delete_board(struct _Board *board, int unique_id);

#endif