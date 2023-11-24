#include "../../adapter/out/read/read_content_file.h"
#include "../../adapter/in/create/create_post.h"
#include "../../ui/console/user_keyboard_input.h"
#include "read_board.h"
#include "file_create.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUDDY_PAGE_SIZE         4096

int file_total_length (int file_descriptor)
{
    // lseek의 리턴 값은 두 번째 인자부터 3번째 인자까지 file pointer를 이동한 숫자
    return lseek(file_descriptor, 0, SEEK_END);
}

int find_enter_line_for_format_count(char *buffer, int total_length)
{
    int i;
    int count = 0;

    for (i = 0; i < total_length; i++)
    {
        if (!strncmp(&buffer[i], "\n", 1))
        {
            count++;
        }
    }

    return count;
}

Board **set_test_form_with_read_contents(Board **test_format_array, int object_count, char *read_contents)
{
    int i;
    int field_count = 4;
    char title[32];
    char content[128];
    char writer[32];
    unsigned int unique_id;
    int board_count = 0;

    int start, finish;
    bool started = false;
    int read_contents_length = strlen(read_contents);

    // 읽은 내용을 1 바이트씩 순회
    for (i = 0; i < read_contents_length; i++)
    {
        // ":" 찾기
        // 왜 찾는가 ?
        // format이 아래와 같으니까
        // id:1,major:시고르원조,age:20,introduction:낵아 시고르원조다!,
        if (!started && !strncmp(&read_contents[i], ":", 1))
        {
            start = i;
            started = true;
        }

        // "," 찾기
        if (started && !strncmp(&read_contents[i], ",", 1))
        {
            finish = i;
            started = false;
            //printf("start = %d, finish = %d\n", start, finish);

            // ":" 과 "," 사이의 값이 객체에 배치해야하는 정보임
            if (field_count % 4 == 0)
            {
                char tmp_str[32] = { 0 };
                strncpy(tmp_str, &read_contents[start + 1], finish - start - 1);
                unique_id = atoi(tmp_str);
                //printf("unique_id = %d\n", unique_id);
            }

            if (field_count % 4 == 1)
            {
                char tmp_str[32] = { 0 };
                // major 배열이 기존 정보를 유지하고 있을 가능성이 있으므로
                // 전체 배열을 0 으로 초기화 시키는 작업임
                memset(title, 0x00, 32);
                strncpy(title, &read_contents[start + 1], finish - start - 1);
                //printf("title = %s\n", title);
            }

            if (field_count % 4 == 2)
            {
                char tmp_str[32] = { 0 };
                memset(writer, 0x00, 32);
                strncpy(writer, &read_contents[start + 1], finish - start - 1);
                //printf("writer = %s\n", writer);
            }

            if (field_count % 4 == 3)
            {
                char tmp_str[128] = { 0 };
                memset(content, 0x00, 128);
                strncpy(content, &read_contents[start + 1], finish - start - 1);
                //printf("itroduction: %s\n", content);

                test_format_array[board_count++] = init_test_form_with_id(unique_id, title, writer, content);
            }

            //if (field_count % 4 == 0) {
            //    test_format_array[field_count++ / 4] 
            // }

            field_count++;
        }
    }

    return test_format_array;
}

void read_target_id_content(Board **test_format_array, int object_count, int uniqueIdToFind) {
    

    for (int i = 0; i < object_count; i++) {
        if (test_format_array[i]->unique_id == uniqueIdToFind) {
            printf("게시글 id: %d\n", test_format_array[i]->unique_id);
            printf("제목: %s\n", test_format_array[i]->title);
            printf("작성자: %s\n", test_format_array[i]->writer);
            printf("내용: %s\n", test_format_array[i]->content);
            printf("\n");
            return; // 게시글을 찾았으므로 함수 종료
        }
    }

    // 게시글을 찾지 못한 경우
    printf("게시글을 찾을 수 없습니다.\n");
}

Board **read_file_to_format(int uniqueIdToFind)
{
    char read_contents[BUDDY_PAGE_SIZE] = { 0 };
    int object_count;
    int total_length;

    Board **test_format_array;

    // O_RDONLY: 읽기 전용
    int created_file_descriptor = read_file_descriptor();
    //read_content_from_file_and_print(created_file_descriptor, read_contents);
    read_content_from_file(created_file_descriptor, read_contents);
    //printf("read_contents: %s\n", read_contents);

    total_length = file_total_length(created_file_descriptor);
    file_close(created_file_descriptor);

    object_count = find_enter_line_for_format_count(read_contents, total_length);
    test_format_array = init_test_form_array(object_count);
    //printf("object_count: %d\n", object_count);

    test_format_array = set_test_form_with_read_contents(test_format_array, object_count, read_contents);
    //printf("test_format_array: 0x%x\n", test_format_array);
    read_target_id_content(test_format_array, object_count, uniqueIdToFind);
    for (int i = 0; i < object_count; ++i) {
    free(test_format_array[i]);
    }
    free(test_format_array);

    return test_format_array;

}

void read_board_with_target_id()
{
    char read_board_keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };

    char read_board_output_message[MAX_OUTPUT_MESSAGE] = {
        "원하는 게시물의 id를 입력해주세요.\n"
    };
    
    get_user_keyboard_input_with_message(read_board_output_message, read_board_keyboard_input);
    read_file_to_format(atoi(read_board_keyboard_input));
}
