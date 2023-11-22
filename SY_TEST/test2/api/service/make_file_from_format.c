#include "make_file_from_format.h"

#include "../file_io/file_create.h"
#include "../in/write_post.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUDDY_PAGE_SIZE             4096

#define START_INDEX                 0
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

void adjust_write_contents_from_format(char *contents, Board *format)
{
    //int unique_id_size;
    int title_length, writer_length, content_length;

    sprintf(contents, "title:%s\n writer:%s\n content:%s\n", 
        format->title, format->writer, format->content);
    printf("contents: %s\n", contents);
}

// 반환문 없어서 노란줄 뜨는 중..
bool write_format_to_file(Board *format)
{
    char write_contents[BUDDY_PAGE_SIZE] = { 0 };

    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team1/"
        "JL_TEST_2/test_file/테스트용게시판.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    adjust_write_contents_from_format(write_contents, format);

    write_post_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);
}