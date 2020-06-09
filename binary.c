#include <stdio.h>
void div(int n);
int main(void)
{
    int num;
    //&num is the adress of the num
    scanf("%d", &num);
    div(7);
    return 0;
}

void div(int n)
{
    while(n > 1){
        div(n);
         int m = n / 2;
        printf("%d", m);
       
    }
    
        
    
    
}
