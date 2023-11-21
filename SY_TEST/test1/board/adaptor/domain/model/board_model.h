#ifndef __BOARD_MODEL_H__
#define __BOARD_MODEL_H__


typedef struct _Post Post;

// 게시글을 나타내는 구조체입니다.
// id: 게시글의 유니크한 ID
// title: 게시글의 제목
// content: 게시글의 내용
// next: 다음 게시글을 가리키는 포인터
struct _Post
{
    int id;
    char *title;
    char *content;
    struct Post *next;
};

Post* create_post(char *title, char *content);

#endif