#include "board_service.h"
#include "../adapter/in/post_adapter_in.h"
#include "../adapter/out/post_adapter_out.h"
#include "../adapter/domain/model/board_model.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read 함수를 사용하기 위해 추가

#define MAX_TITLE_LENGTH 100

// 게시글을 파일에 저장하는 함수입니다.
void save_post(Post* post) 
{
    FILE *file = fopen("post.txt", "w");
    if (file == 0) 
    {
        printf("파일을 열 수 없습니다.");

        return;
    }

    fprintf(file, "%d,%s,%s", post->id, post->title, post->content);
    fclose(file);
}

// 파일에서 게시글을 읽어오는 함수입니다.
Post* load_post() 
{
    FILE *file = fopen("post.txt", "r");
    if (file == 0) 
    {
        printf("파일을 열 수 없습니다.");
        return 0;
    }

    Post *post = (Post*)malloc(sizeof(Post));
    fscanf(file, "%d%[^]%[^]", &post->id, post->title, post->content);
    fclose(file);

    return post;
}

// 사용자로부터 게시글을 입력받아 저장하고 출력하는 함수입니다.
void process_post() 
{
    Post* post = input_post();  // 사용자로부터 게시글을 입력받습니다.
    if (post == 0) 
    {
        printf("게시글 생성에 실패했습니다.");

        return;
    }

    save_post(post);  // 게시글을 파일에 저장합니다.
    Post* loaded_post = load_post();  // 파일에서 게시글을 읽어옵니다.
    if (loaded_post == 0) 
    {
        printf("게시글 로딩에 실패했습니다.");
        return;
    }

    print_post(loaded_post);  // 게시글을 출력합니다.
}

// 게시글을 수정하는 함수입니다.
void modify_post() 
{
    Post* post = load_post();  // 파일에서 게시글을 읽어옵니다.
    if (post == 0) 
    {
        printf("게시글 로딩에 실패했습니다.");
        return;
    }

    Post* new_post = input_post();  // 사용자로부터 새 게시글을 입력받습니다.
    if (new_post == 0) 
    {
        printf("게시글 생성에 실패했습니다.");
        return;
    }

    post->id = new_post->id;
    strcpy(post->title, new_post->title);
    strcpy(post->content, new_post->content);

    save_post(post);  // 수정된 게시글을 파일에 저장합니다.
}

// 게시글을 삭제하는 함수입니다.
void delete_post() 
{
    char title[MAX_TITLE_LENGTH];
    printf("삭제할 게시글의 제목을 입력해주세요: ");
    int len = read(STDIN_FILENO, title, MAX_TITLE_LENGTH - 1);  // 사용자로부터 입력을 받습니다.
    title[len] = '\0';  // 문자열의 끝을 표시합니다.

    Post* post = load_post();  // 파일에서 게시글을 읽어옵니다.
    if (post == 0 || strcmp(post->title, title) != 0) 
    {
        printf("해당 제목의 게시글이 없습니다.");
        return;
    }

    remove("post.txt");  // 게시글 파일을 삭제합니다.
    
}