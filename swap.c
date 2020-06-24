//void SwapValues(int* userVal1, int* userVal2)
//int b=10; 
//int *a=&b;
//value of b :10
//address of b (which is &b) : 1000
//value of a (which is address of b) : 1000
//value of *a (which is the value of b): 10

#include <stdio.h>
void SwapValues(int* userVal1, int* userVal2){
    int temp = *userVal1;
    *userVal1 = *userVal2;
    *userVal2 = temp; 
    printf("%d %d\n", userVal1, userVal2);

}

int main(void) {
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);

   /* Type your code here. Your code must call the function.  */
    SwapValues(a, b);
   return 0;
}