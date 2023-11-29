#include "make_file_from_format.h"

#include "../file_io/file_create.h"
#include "../in/write_post_in_file.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUDDY_PAGE_SIZE             4096

#define START_INDEX                 0

// 게시판 내용 문자열로 변환해서 출력
void write_contents_from_format(char *contents, Board *format)
{
    //int unique_id_size;
    //int title_length, writer_length, content_length;

    sprintf(contents, "unique_id:%d, title:%s, writer:%s, content:%s\n", 
        format->unique_id, format->title, format->writer, format->content);

    printf("contents: %s\n", contents);
}


// txt 파일에 사용자가 입력한 내용을 적는 함수
void write_format_to_file(Board *format)
{
    // 지정된 크기의 문자 배열 초기화 
    // 파일에 쓸 내용 저장
    char write_contents[BUDDY_PAGE_SIZE] = { 0 };

    // 파일 생성
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team1/"
        "JL_TEST_2/test_file/테스트용게시판.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    // 게시판(Board) 데이터를 문자열로 변환 write_contents 배열에 저장
    write_contents_from_format(write_contents, format);

    // 파일에 쓴 내용 성공 실패 여부 확인(?)
    write_post_in_file(created_file_descriptor, write_contents);

    // 파일 닫기
    file_close(created_file_descriptor);
}