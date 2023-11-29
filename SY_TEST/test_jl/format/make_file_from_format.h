#ifndef __MAKE_FILE_FROM_FORMAT_H__
#define __MAKE_FILE_FROM_FORMAT_H__

#include "../domain/model/board.h"
#include <stdbool.h>

void write_contents_from_format(char *, Board *);
void write_format_to_file(Board *);

#endif