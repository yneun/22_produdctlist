#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(void){
    Product p_list[100];
    int count = 0, menu, index=0;

#ifdef DEBUG
    printf("->Debuging mode\n");
    printf("Program have been started.\n\n");
#endif 
    count=loadData(p_list); 
    index=count;

    while(1){
        menu = selectMenu();
        if(menu==0) break;
        if(menu==1 || menu==3 ||menu==4)
            if(count==0) continue;
        if(menu==1){
            if(count>0) listProduct(p_list,index);
        }
        else if(menu==2){
            count += createProduct(&p_list[index++]);
        }
        else if(menu==3){
            int num = selectDataNo(p_list,index);
            if(num==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&p_list[(num-1)]);
        }
        else if(menu==4){
            int num = selectDataNo(p_list,index);
            if(num==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제:1) ");
            scanf("%d",&deleteok);
            if(deleteok==1){
                deleteProduct(&p_list[(num-1)]);
                count--;
                printf("=> 삭제됨!\n");
            }
        }
        else if(menu==5) saveData(p_list,index);
        else if(menu==6) searchName(p_list,index);
        else if(menu==7) searchPrice(p_list,index);
        else if(menu==8) searchOrigin(p_list,index);
    }
    printf("종료됨!\n");
    return 0;
}
