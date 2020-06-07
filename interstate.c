#include <stdio.h>
int main()
{
    printNum(99);
}
//I-90 is primary, going east/west.
//290
//I-290 is auxiliary, serving I-90, going east/west.
//0
//0 is not a valid interstate highway number.
//valid 1-999
void printNum(int num)
{
    if (num < 1 || num > 999)
    {
        printf("%d is not a valid interstate highway number.\n");
    }
    else if (num >= 1 || num <= 99)
    {
        if (num % 2 == 0)
        {
            printf("I-%d is auxiliary, serving I-90, going east/west.\n");
        }
        else
        {
            printf("I-%d is primary, going east/west.\n", num);
        }
    }
    else if (num >= 100 || num <= 999)
    {       
            int num2 = 55;
            printf("I-%d is auxiliary, serving I-%d, going east/west.", num, num2);
    }
}

