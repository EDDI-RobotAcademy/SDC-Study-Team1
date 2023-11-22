#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


#include "utility/input_message.h"
#include "file_io/file_create.h"
#include "in/write_post.h"
#include "domain/model/board.h"
#include "format/make_file_from_format.h"

#define MAX_OUTPUT_MESSAGE      256
#define SLAB_CACHE      256 


void write_board(void)
{
    printf("게시물 작성\n");
}


int main (void)
{
    char keyboard_input[INPUT_MESSAGE] = { 0 };
    char output_message[MAX_OUTPUT_MESSAGE] = {
        "0번. 게시물 조회\n"
        "1번. 게시물 작성\n"
        "2번. 게시물 삭제\n"
        "3번. 게시물 읽기\n"
        "4번. 게시물 수정\n"
        "5번. 프로그램 종료\n"

    };

    get_user_keyboard_input_with_message(output_message, keyboard_input);
    printf("사용자가 선택한 작업: %d\n", atoi(keyboard_input));

    /*
    get_user_keyboard_input(keyboard_input);
    printf("게시물 작성: %s\n", keyboard_input);
    */

    
    // 게시판에 사용자가 글 작성
    Board *format;
    char title[SLAB_CACHE];
    char writer[SLAB_CACHE];
    char content[SLAB_CACHE];
    int unique_id = 0;
    
    // 제목
    printf("제목을 입력하세요: \n");
    get_user_keyboard_input(keyboard_input);
    strcpy(title, keyboard_input);

    // 작성자
    printf("작성자를 입력하세요: \n");
    get_user_keyboard_input(keyboard_input);
    strcpy(writer, keyboard_input);

    // 내용
    printf("내용을 입력하세요: \n");
    get_user_keyboard_input(keyboard_input);
    strcpy(content, keyboard_input);

    format = create_post(unique_id, title, writer, content);
    write_format_to_file(format);

    
    /*
    Board *format;
    int unique_id = 0;
    char title[SLAB_CACHE];
    strcpy(title, keyboard_input);
    char writer[SLAB_CACHE2] = "김똥개";
    char content[SLAB_CACHE3] = "집에 가고 싶다";
    */

    // 경로는 맞춰서 수정할 것
    /*
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team1/"
        "JL_TEST_2/test_file/테스트용게시판.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    */

    // 파일 디스크립터 확인용 출력
    /*
    printf("생성된 파일 디스크립터: %d\n", created_file_descriptor);
    */

    /*
    format = create_post(unique_id, title, writer, content);
    write_format_to_file(format);
    file_close(created_file_descriptor);
    */

    return 0;
}
