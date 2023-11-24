#include <stdio.h>

// File Descriptor(파일 디스크립터)
// 0번 = 표준 입력
// 1번 = 표준 출력
// 2번 = 표준 에러

// Unix 핵심 철학: 모든 것은 파일이다.

#include <unistd.h>
#include <string.h>

#include <termios.h>
#include "input_message.h"

// 사용자 입력 받기
void get_user_keyboard_input(char *keyboard_input)
{
    read(0, keyboard_input, INPUT_MESSAGE);
    
    // 개행 문자 제거
    keyboard_input[strcspn(keyboard_input, "\n")] = '\0';
}

// 메시지 출력 이후 사용자 입력 받기
void get_user_keyboard_input_with_message(char *output_message, char *keyboard_input)
{
    write(1, output_message, strlen(output_message));
    
    get_user_keyboard_input(keyboard_input);
}



// 제목, 작성자명, 게시글 내용을 사용자가 입력하는 함수
void request_message(char *title, char *writer, char *content, int unique_id)
{   
    char user_keyboard_input[INPUT_MESSAGE];

    // 제목
    printf("제목을 입력하세요: \n");
    get_user_keyboard_input(user_keyboard_input);
    strcpy(title, user_keyboard_input);

    // 작성자명
    printf("작성자를 입력하세요: \n");
    get_user_keyboard_input(user_keyboard_input);
    strcpy(writer, user_keyboard_input);

    // 게시글 내용
    printf("내용을 입력하세요: \n");
    get_user_keyboard_input(user_keyboard_input);
    strcpy(content, user_keyboard_input);

}

