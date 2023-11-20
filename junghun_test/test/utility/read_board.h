#ifndef __READ_BOARD_H__
#define __READ_BOARD_H__

#include <unistd.h>


void read_content_from_stdin(char *read_content, size_t size);
void read_content_from_file(int file_descriptor, char *read_content, size_t size)


#endif