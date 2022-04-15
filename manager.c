#include <stdio.h>
#include <string.h>
#include "manager.h"

int loadData(Product *p){
    FILE *fp;
    int i=0;

    fp=fopen("product.txt","rt");
    if(fp==NULL){
        printf("=> 파일 없음\n");
        return i;
    }
    else{
    for(;i<100;i++){
        fscanf(fp,"%s",p[i].name);
        if(feof(fp)) break;
        fscanf(fp,"%s",p[i].info);
        fscanf(fp,"%s",p[i].weight);
        fscanf(fp,"%s",p[i].origin);
        fscanf(fp,"%d",&p[i].price);
        fscanf(fp,"%d",&p[i].deliver);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
#ifdef DEBUG
    printf("로딩된 총 상품의 개수: %d\n",i);
#endif
    return i;
    }
}


void listProduct(Product *p, int count){
    printf("==============================\n");
    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue;
        printf("%2d ",i+1);
        readProduct(p[i]);
    }
    printf("\n");
};


int selectDataNo(Product *p, int count){
    int num;
    listProduct(p,count);
    printf("원하는 상품의 해당번호는 (취소 시 '0')? ");
    scanf("%d",&num);
    return num;
};


void saveData(Product *p,int count){
    FILE *fp;
    fp=fopen("product.txt","wt"); //wt = write text

    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue;
        fprintf(fp,"%s %s %s %s %d %d\n",p[i].name,p[i].info,p[i].weight,p[i].origin,p[i].price,p[i].deliver);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
#ifdef DEBUG
    printf("총 저장된 상품의 개수: %d\n",count);
#endif
};


int createProduct(Product *p){
    printf("상품의 이름은? ");
    getchar();
    scanf("%[^\n]s", p->name);

    printf("상품의 세부사항은? ");
    getchar();
    scanf("%[^\n]s", p->info);

    printf("판매단위는? ");
    scanf("%s", p->weight);

    printf("원산지는? ");
    scanf("%s", p->origin);

    printf("가격은? ");
    scanf("%d", &p->price);

    printf("배송방법은? (새벽배송/택배배송) ");
    scanf("%d", &p->deliver);
    printf("=> 추가됨!\n");
    return 1;
};


void readProduct(Product p){
    printf("    %s \n",p.name);
    printf("    %s \n",p.info);
    printf("    %d \n",p.price);
};


void infoProduct(Product p){
    printf("    %s \n",p.name);
    printf("    %s \n",p.info);
    printf("    %d \n",p.price);
    printf("    원산지: %s \n",p.origin);
    printf("    판매단위: %s \n",p.weight);
    char method[20];
    if(p.deliver==1) strcpy(method,"새벽배송");
    else strcpy(method,"택배배송");
    printf("    배송방법: %s \n",method);
};


int updateProduct(Product *p){
    printf("상품의새로운 이름은? ");
    getchar();
    scanf("%[^\n]s", p->name);

    printf("상품의 새로운 세부사항은? ");
    getchar();
    scanf("%[^\n]s", p->info);

    printf("새로운 판매단위는? ");
    scanf("%s", p->weight);

    printf("새로운 상품의 원산지는? ");
    scanf("%s", p->origin);

    printf("새로운 상품의 가격은? ");
    scanf("%d", &p->price);

    printf("새로운 상품의 배송방법은? (새벽배송/택배배송) ");
    scanf("%d", &p->deliver);
    printf("=> 추가됨!\n");
    return 1;
};


int deleteProduct(Product *p){
    p->price=-1;
    return 1;
};


void searchName(Product *p,int count){
    int stime=0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s",search);

    printf("=====================================\n");
    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue;
        if(strstr(p[i].name,search)){
            printf("%2d ",i+1);
            infoProduct(p[i]);
            stime++;
        }
    }
    if(stime==0) printf("=> 검색된 데이터가 존재하지 않음");
    printf("\n");
};


void searchPrice(Product *p,int count){
    int stime=0;
    int search;

    printf("검색할 가격은? ");
    scanf("%d",&search);

    printf("=====================================\n");
    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue;
        if(p[i].price==search){
            printf("%2d ",i+1);
            infoProduct(p[i]);
            stime++;
        }
    }
    if(stime==0) printf("=> 검색된 데이터 없음!");
	    printf("\n");
            stime++;
};


void searchOrigin(Product *p,int count){
    int stime=0;
    char search[20];

    printf("검색할 원산지는? ");
    scanf("%s",search);

    printf("=====================================\n");
    for(int i=0;i<count;i++){
        if(p[i].price==-1) continue;
        if(strstr(p[i].origin,search)){
            printf("%2d ",i+1);
            infoProduct(p[i]);
            stime++;
        }
    }
    if(stime==0) printf("=> 검색된 데이터 없음!");
    printf("\n");
            stime++;
};
