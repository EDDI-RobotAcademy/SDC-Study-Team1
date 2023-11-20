#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/stat.h>

#include "ui/console/user_keyboard_input.h"
#include "file_io/how_to_make_file.h"

#define BUDDY_PAGE_SIZE (1)

typedef struct _Board board;

struct _Board {
    int unique_id;
    char title[100];
    char author[50];
    char content[500];
};

void read_content_from_stdin(char *read_content, size_t size) {
    read(STDIN_FILENO, read_content, size);
}

void read_content_from_file(int file_descriptor, char *read_content, size_t size) {
    int read_bytes;

    while ((read_bytes = read(file_descriptor, read_content, size)) > 0) {
        write(STDOUT_FILENO, read_content, read_bytes);
    }
    printf("\n");
}

void readBoard(board *post, int file_descriptor) {
    read(file_descriptor, &(post->unique_id), sizeof(int));
    read_content_from_file(file_descriptor, post->title, sizeof(post->title));
    read_content_from_file(file_descriptor, post->author, sizeof(post->author));
    read_content_from_file(file_descriptor, post->content, sizeof(post->content));
}

void write_content_to_file(int file_descriptor, const char *write_content, size_t size) {
    write(file_descriptor, write_content, size);
}

void writeBoardToFile(const board *post, int file_descriptor) {
    write(file_descriptor, &(post->unique_id), sizeof(int));
    write_content_to_file(file_descriptor, post->title, sizeof(post->title));
    write_content_to_file(file_descriptor, post->author, sizeof(post->author));
    write_content_to_file(file_descriptor, post->content, sizeof(post->content));
}

void showBoardList(board *posts, int count) {
    printf("===== 게시물 리스트 =====\n");
    for (int i = 0; i < count; ++i) {
        printf("%d. %s\n", posts[i].unique_id, posts[i].title);
    }
    printf("=========================\n");
}

void addBoard(board *posts, int *count, int file_descriptor) {
    board newPost;
    newPost.unique_id = (*count) + 1;

    printf("제목: ");
    read_content_from_stdin(newPost.title, sizeof(newPost.title));

    printf("작성자: ");
    read_content_from_stdin(newPost.author, sizeof(newPost.author));

    printf("내용: ");
    read_content_from_stdin(newPost.content, sizeof(newPost.content));

    writeBoardToFile(&newPost, file_descriptor);
    posts[*count] = newPost;
    (*count)++;
}

void editBoard(board *posts, int count, int file_descriptor) {
    int editID;
    printf("수정할 게시물의 ID를 입력하세요: ");
    scanf("%d", &editID);

    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (posts[i].unique_id == editID) {
            found = 1;

            printf("새로운 제목: ");
            read_content_from_stdin(posts[i].title, sizeof(posts[i].title));

            printf("새로운 작성자: ");
            read_content_from_stdin(posts[i].author, sizeof(posts[i].author));

            printf("새로운 내용: ");
            read_content_from_stdin(posts[i].content, sizeof(posts[i].content));

            // 파일에 수정된 내용 반영
            lseek(file_descriptor, i * sizeof(board), SEEK_SET);
            writeBoardToFile(&posts[i], file_descriptor);

            printf("게시물이 수정되었습니다.\n");
            break;
        }
    }

    if (!found) {
        printf("해당 ID의 게시물을 찾을 수 없습니다.\n");
    }
}

void deleteBoard(board *posts, int *count, int file_descriptor) {
    int deleteID;
    printf("삭제할 게시물의 ID를 입력하세요: ");
    scanf("%d", &deleteID);

    int found = 0;
    for (int i = 0; i < *count; ++i) {
        if (posts[i].unique_id == deleteID) {
            found = 1;

            // 해당 게시물을 배열에서 삭제
            for (int j = i; j < (*count) - 1; ++j) {
                posts[j] = posts[j + 1];
            }
            (*count)--;

            // 파일에서도 해당 게시물을 삭제
            lseek(file_descriptor, 0, SEEK_SET);
            ftruncate(file_descriptor, 0);
            for (int j = 0; j < *count; ++j) {
                writeBoardToFile(&posts[j], file_descriptor);
            }

            printf("게시물이 삭제되었습니다.\n");
            break;
        }
    }

    if (!found) {
        printf("해당 ID의 게시물을 찾을 수 없습니다.\n");
    }
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

    if (!found) {
        printf("해당 ID의 게시물을 찾을 수 없습니다.\n");
    }
}

int main() {
    int choice;
    int postCount = 0;
    board posts[100]; // 최대 100개의 게시물을 저장할 수 있는 배열
    int create_file_descriptor = file_open("/home/eddi/proj/SDC-Study-Team1/test/board_list/board.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (create_file_descriptor == -1) {
        perror("파일 열기 실패");
        exit(EXIT_FAILURE);
    }

    do {
        printf("\n===== 게시판 프로그램 =====\n");
        printf("1. 게시물 리스트 보기\n");
        printf("2. 게시물 추가하기\n");
        printf("3. 게시물 수정하기\n");
        printf("4. 게시물 삭제하기\n");
        printf("5. 특정 게시물 읽기\n");
        printf("6. 프로그램 종료\n");
        printf("===========================\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showBoardList(posts, postCount);
                break;
            case 2:
                addBoard(posts, &postCount, create_file_descriptor);
                break;
            case 3:
                editBoard(posts, postCount, create_file_descriptor);
                break;
            case 4:
                deleteBoard(posts, &postCount, create_file_descriptor);
                break;
            case 5:
                readBoard(posts, postCount);
                break;
        }
    } while (choice != 6);

    // 파일 디스크립터 닫기
    file_close(create_file_descriptor);

    return 0;
}

