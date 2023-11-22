#include "board/service/board_service.h"
#include <stdio.h>

// 메뉴를 출력하고 사용자로부터 선택을 입력받는 함수입니다.
int get_menu_selection() 
{
    printf("1. 게시글 생성\n2. 게시글 수정\n3. 게시글 삭제\n4. 종료\n메뉴 선택: ");

    int selection;
    scanf("%d", &selection);
    return selection;
}

int main() {
    while (1) {
        int selection = get_menu_selection();

        switch (selection) {
        case 1:
            process_post();
            break;
        case 2:
            modify_post();
            break;
        case 3:
            delete_post();
            break;
        case 4:
            printf("프로그램을 종료합니다.");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 선택해주세요.");
        }
    }

    return 0;
}

/* 
adapter 
in
조회 게시물리스트를 볼 수 있게 요청 
작성 게시물을 입력요청
삭제 기존의 게시물을 삭제 요구
읽기 3번을 누르면 게시물 리스트를 띄워준 상태에서 읽고 싶은 게시물 번호를 입력한다 (돌아가기는 일단 보류)
수정 게시물 리스트를 띄워준 상태에서 수정하고 싶은 게시물 번호를 입력

서비스 어플리케이션<--- 이것도 그냥 out폴더로 치면 됩니다 정확히 못나누겠음 완벽한 이해가 안돼있기에... (out폴더로 한꺼번에)
조회 저장돼있는 모든 게시물txt파일의 고유번호와 제목 데이터를 가지고 온다 
작성 게시물 내용, 제목, 작성자 입력받고 txt로 저장
삭제 선택된 게시물 삭제
읽기 empty 없음
수정 선택한 게시물을 열어서 수정후 저장

out  
조회 게시물 리스트 화면에 출력 (문구 출력 후 초기화면 리턴)
작성 작성완료 (문구 출력 후 초기화면 리턴)
삭제 삭제완료 (문구 출력 후 초기화면 리턴)
읽기 선택한 게시물 오픈 (문구 출력 후 초기화면 리턴)
수정 이것도 없고 (문구 출력 후 초기화면 리턴)

******fix.1 - 서비스 어플리케이션, out 분할하려 하니 복잡해져서 그냥 out으로 통합******


(문구 출력 후 초기화면 리턴)
이거는 이제 일단 부가적인거고 오늘 goto문을 배우면 한번 해보도록하죠 일단 제 기능에 집중...

비번도 일단 나중에 생각.... 남의 게시물 삭제 가능 ㅋ다른 조 염탐 ㄱ

일단 메인에서 함수포인터를 제대로 쓴건지 모르겠지만 함수포인터 미정 안되면 제어무능로


board----domain----model(구조체)
  |    |
  |    |
  |    |
  |    └----adapter─────────────in
  |            |             └──-out
  |            |
  |            └──---application-----service──── 게시판 출력
  |                                          ├── 게시글 작성
  |                                          ├── 게시글 조회
  |                                          ├── 게시글 삭제
  |                                          └── 게시글 수정
  └── main.c
*/          
