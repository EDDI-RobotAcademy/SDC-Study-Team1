#ifndef __POST_WRITE_H__
#define __POST_WRITE_H__

#include "../format/make_file_from_format.h"
#include "../domain/model/board.h"
#include "../utility/input_message.h"

void post_write(unsigned int unique_id[], char title[], char writer[], char content[], int user_count);

#endif