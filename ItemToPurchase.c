#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ItemToPurchase.h"
void MakeItemBlank(ItemToPurchase* ptr)
{
    
    ptr->itemPrice=0;
    ptr->itemQuantity=0;
    strcpy(ptr->itemName,"none");
}

void PrintItemCost(ItemToPurchase temp1, ItemToPurchase temp2)
{
    int a=temp1.itemQuantity;
    int b=temp2.itemQuantity;
    int c=temp1.itemPrice;
    int d=temp2.itemPrice;
    int e=a*c;
    int f=b*d;
    int price;
    price=a*c+b*d;
    printf("%s %d @ $%d = $%d\n", temp1.itemName, a, c, e);
    printf("%s %d @ $%d = $%d\n", temp2.itemName, b, d, f);
    printf("\nTotal: $%d\n",price);
}
