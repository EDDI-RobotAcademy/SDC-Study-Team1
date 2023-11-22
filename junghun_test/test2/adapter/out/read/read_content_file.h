#ifndef __READ_CONTENT_FILE_H__
#define __READ_CONTENT_FILE_H__

#include <stdbool.h>

void read_content_from_file_and_print(int, char *);
void read_content_from_file(int file_descriptor, char *read_content);
void reset_file_pointer(int);
int read_file_descriptor();

#endif