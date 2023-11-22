#ifndef __MAKE_FILE_FROM_FORMAT_H__
#define __MAKE_FILE_FROM_FORMAT_H__

#include "../../adapter/in/create/create_post.h"

#include <stdbool.h>

void adjust_write_contents_from_format(char *, Board *);
bool write_format_to_file(Board *format, int file_descriptor);

#endif