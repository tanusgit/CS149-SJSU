2.8
#include <stdio.h>

int main(void) {
   int currentPrice;
   int lastMonthsPrice;
   //taking user input
   scanf("%d", &currentPrice);
   scanf("%d", &lastMonthsPrice);
   //displaying the result
   printf("This house is $%d. The change is $%d"
   " since last month.\nThe estimated monthly mortgage is $%lf.\n", currentPrice, currentPrice-lastMonthsPrice, (currentPrice * 0.051) / 12 );
   

   return 0;
}