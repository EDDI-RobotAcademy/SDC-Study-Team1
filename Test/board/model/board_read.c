#include "board_read.h"
#include "board.h"

#include <unistd.h>

#define BUDDY_PAGE_SIZE         (1)

void read_content_from_file(int file_descriptor, char *read_content)
{
    int read_bytes;

    while ((read_bytes = read(file_descriptor, read_content, BUDDY_PAGE_SIZE)) > 0)
    {
        write(1, read_content, read_bytes);
    }
    printf("\n");
}

void read_board(board *board, int file_descriptor) {
    // 파일에서 게시물 ID 읽기
    read(file_descriptor, &(board->unique_id), sizeof(int));

    // 파일에서 제목 읽기
    read_content_from_file(file_descriptor, board->title, sizeof(board->title));

    // 파일에서 작성자 읽기
    read_content_from_file(file_descriptor, board->author, sizeof(board->author));

    // 파일에서 내용 읽기
    read_content_from_file(file_descriptor, board->content, sizeof(board->content));
}


/*
void read_board(Post *post) {
    printf("게시물 ID: %d\n", post->unique_id);
    printf("제목: %s\n", post->title);
    printf("작성자: %s\n", post->author);
    printf("내용: %s\n", post->content);
}
*/
