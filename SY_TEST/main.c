#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adaptor/in/keyboard_input.h"
#include "adaptor/out/keyboard_output.h"

int main()
{

    char choice [10];

    while (1) 
    {
        print_Message("===== 게시판 메뉴 =====\n");
        print_Message("1. 리스트 출력\n");
        print_Message("2. 게시글 조회\n");
        print_Message("3. 게시글 수정\n");
        print_Message("4. 게시글 삭제\n");
        print_Message("5. 종료\n");

        print_Message("\n메뉴를 선택하세요: \n");

        if (strcmp(choice, "5") == 0)

        {
            print_Message("프로그램을 종료합니다.");
            break;
            return 0;
        }
        
        get_user_keyboard_input(choice);

        
    }

    return 0;
}