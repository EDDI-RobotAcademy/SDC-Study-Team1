#include "board.h"



int choice;
    int postCount = 0;
    board posts[100]; // 최대 100개의 게시물을 저장할 수 있는 배열
    int file_descriptor = open("board.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (file_descriptor == -1) {
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
                addBoard(posts, &postCount, file_descriptor);
                break;
            case 3:
                editBoard(posts, postCount, file_descriptor);
                break;
            case 4:
                deleteBoard(posts, &postCount, file_descriptor);
                break;
            case 5:
                readSelectedBoard(posts, postCount);
                break;
        }
    } while (choice != 6);

    // 파일 디스크립터 닫기
    close(file_descriptor);