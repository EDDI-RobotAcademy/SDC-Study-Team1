#ifndef __BOARD_READ_H__
#define __BOARD_READ_H__

#ifdef __cplusplus
extern "C" {
#endif

void read_content_from_file(int file_descriptor, char *read_content);
void read_board(board *board, int file_descriptor);


#ifdef __cplusplus
}
#endif

#endif
