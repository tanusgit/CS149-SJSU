#include <stdio.h>
void printNum(int num);
int main()
{
    printNum(919);
    return 0;
}
//Odd numbers (like the 5 or 95) go north/south,
//90
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
        printf("%d is not a valid interstate highway number.\n", num);
    }
    else if (num >= 1 && num <= 99)
    {
        if (num % 2 == 0)
        {
            printf("I-%d is primary, going east/west.\n", num);
        }
        else
        {
            printf("I-%d is primary, going north/south.\n", num);
        }
    }
    else // if is not needed here as we have already covered the half
    //valid inputs in the above if statement
    //as if (num >= 100 && num <= 999)
    {
        int num2 = num % 100;
        printf("I-%d is auxiliary, serving I-%d, going east/west.\n", num, num2);
    }
}
