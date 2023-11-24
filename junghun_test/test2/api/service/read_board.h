#ifndef __MAKE_FORMAT_FROM_FILE_H__
#define __MAKE_FORMAT_FROM_FILE_H__

#include "../../adapter/in/create/create_post.h"

#define MAX_USER_KEYBOARD_INPUT     32
#define MAX_OUTPUT_MESSAGE      128

Board **read_file_to_format(int target_id);
void read_target_id_content(Board **test_format_array, int object_count, int uniqueIdToFind);

#endif