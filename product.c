#include <stdio.h>
#include "product.h"

int selectMenu(){
    int menu;
    printf("\n---상품 관련 기능 선택---\n");
    printf("1. 전체상품 조회\n");
    printf("2. 새상품 추가\n");
    printf("3. 상품 내용 수정\n");
    printf("4. 상품 삭제\n");
    printf("5. 현재 상품 모두 저장\n");
    printf("6. 이름으로 상품 검색\n");
    printf("7. 가격으로 상품 검색\n");
    printf("8. 원산지로 상품 검색\n");
    printf("0. 종료\n\n");
    printf("=> 선택할 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
