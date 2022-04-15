#include <stdio.h>

typedef struct{
    char name[40];
    char info[150];
    char weight[100];
    char origin[40];
    int price;
    int deliver;
} Product;

int createProduct(Product *p);
void readProduct(Product p);
void infoProduct(Product p);
int updateProduct(Product *p);
int deleteProduct(Product *p);
void searchName(Product *p,int count);
void searchPrice(Product *p,int count);
void searchOrigin(Product *p,int count);
int loadData(Product *p);
void listProduct(Product *p, int count);
int selectDataNo(Product *p, int count);
void saveData(Product *p,int count);
