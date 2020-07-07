typedef struct item {
char itemName [51];
int itemPrice;
int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase *temp);
void PrintItemCost(ItemToPurchase temp1, ItemToPurchase temp2); 