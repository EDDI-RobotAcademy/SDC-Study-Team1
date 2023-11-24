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
};

//Board* create_post(int unique_id, char *title, char *writer, char *content);
int increment_test_form_unique_id(void);
Board *init_test_form_with_id(unsigned int id, char *title, char *writer, char *content);
Board *init_test_form(char *, char *, char *);
Board **init_test_form_array(int count);

#endif