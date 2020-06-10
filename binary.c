#include <stdio.h>
//6 = 011
void bin(int n) 
{ 
     printf("%d", n % 2); 
        if (n > 1) 
        bin(n/2);    
}  
int main(void) 
{ 
    int num;
    scanf("%d", &num);
    bin(num);
    printf("\n");
} 
