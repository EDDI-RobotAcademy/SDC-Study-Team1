#ifndef __BOARD_H__
#define __BOARD_H__

extern unsigned int unique_id;

typedef struct _Board Board;

// 게시글 구조체
struct _Board
{
    int unique_id;  // 게시글 번호
    char *title;    // 제목
    char *writer;   // 작성자
    char *content;  // 내용
    
    struct Board *next; // 다음 게시글 
};

Board* create_post(int unique_id, char *title, char *writer, char *content);

#endif