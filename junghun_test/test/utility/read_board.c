#include "read_board.h"
#include "mainboard/board.h"



void read_content_from_stdin(char *read_content, size_t size) {
    read(0, read_content, size);
}

void read_content_from_file(int file_descriptor, char *read_content, size_t size) {
    int read_bytes;

    while ((read_bytes = read(file_descriptor, read_content, size)) > 0) {
        write(1, read_content, read_bytes);
    }
    printf("\n");
}

void readSelectedBoard(board *posts, int count) {
    int readID;
    printf("읽을 게시물의 ID를 입력하세요: ");
    scanf("%d", &readID);

    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (posts[i].unique_id == readID) {
            found = 1;

            printf("\n===== 선택한 게시물 =====\n");
            printf("게시물 ID: %d\n", posts[i].unique_id);
            printf("제목: %s\n", posts[i].title);
            printf("작성자: %s\n", posts[i].author);
            printf("내용: %s\n", posts[i].content);
            printf("=========================\n");
            break;
        }
    }

void readBoard(board *post, int file_descriptor) {
    read(file_descriptor, &(post->unique_id), sizeof(int));
    read_content_from_file(file_descriptor, post->title, sizeof(post->title));
    read_content_from_file(file_descriptor, post->author, sizeof(post->author));
    read_content_from_file(file_descriptor, post->content, sizeof(post->content));
}

