#include "make_file_from_format.h"

#include "file_create.h"
#include "write_post.h"

#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>

#define BUDDY_PAGE_SIZE             4096

#define START_INDEX                 0

void adjust_write_contents_from_format(char *contents, Board *format)
{
    sprintf(contents, "title:%s\n writer:%s\n content:%s\n", 
        format->title, format->writer, format->content);
    printf("contents: %s\n", contents);
}

// 반환문 없어서 노란줄 뜨는 중..
bool write_format_to_file(Board *format, int file_descriptor)
{
    char write_contents[BUDDY_PAGE_SIZE] = { 0 };

    int created_file_descriptor = file_open(
        "/proj/TEAM_1/SDC-Study-Team1/SY_TEST/test2/create_file/post_%d.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    adjust_write_contents_from_format(write_contents, format);

    write_post_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);
}

/*
void adjust_write_contents_from_format(char *contents, Board *format)
{
    int unique_id_size;
    int title_length, writer_length, content_length;

    sprintf(contents, "unique_id:%d\n title:%s\n writer:%s\n content:%s\n", 
        format->unique_id, format->title, format->writer, format->content);
    printf("contents: %s\n", contents);
}
*/