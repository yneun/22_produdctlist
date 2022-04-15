#include <stdio.h>
#include "product.h"

int selectMenu(){
    int menu;
    printf("\n-----상품 선택-----\n");
    printf("1. 상품 조회\n");
    printf("2. 새상품 추가\n");
    printf("3. 상품 수정\n");
    printf("4. 상품 삭제\n");
    printf("5. 상품 저장\n");
    printf("6. 상품이름 검색\n");
    printf("7. 상품가격 검색\n");
    printf("8. 상품원산지 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
