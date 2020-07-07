#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemToPurchase.h"
int main()
{
  ItemToPurchase item1;
  MakeItemBlank(&item1);
  ItemToPurchase item2;
  MakeItemBlank(&item2);
  char name[100];
  int price;
  int quant;
  char c;

  printf("Item 1\n");
  printf("Enter the item name:\n");
  fgets(name, sizeof name, stdin);
  // Remove newline from the name.
  char *newlinepos;
  if ((newlinepos=strchr(name, '\n')) != NULL)
    *newlinepos = '\0';
  strcpy(item1.itemName, name);

  printf("Enter the item price:\n");
  scanf("%d", &price);
  item1.itemPrice = price;

  printf("Enter the item quantity:\n");
  scanf("%d", &quant);
  item1.itemQuantity = quant;

  c = getchar();
  while (c != '\n' && c != EOF)
  {
    c = getchar();
  }
  printf("\n");
  printf("Item 2\n");
  printf("Enter the item name:\n");
  fflush(stdin);
  fgets(name, sizeof name, stdin);

  // Remove newline from the name.
  if ((pos=strchr(name, '\n')) != NULL)
    *pos = '\0';

  strcpy(item2.itemName, name);

  printf("Enter the item price:\n");
  scanf("%d", &price);
  item2.itemPrice = price;

  printf("Enter the item quantity:\n");
  scanf("%d", &quant);
  item2.itemQuantity = quant;

  printf("\n");
  printf("TOTAL COST\n");
  PrintItemCost(item1, item2);
  return 0;
}