#ifndef __FILE_CREATE_H__
#define __FILE_CREATE_H__

#define ERROR               (-1)

int file_open(char *filename, int option, unsigned int permission);
void file_close(int file_descriptor);

#endif