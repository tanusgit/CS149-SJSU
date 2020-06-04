#include <stdio.h>

int main(void)
{

    int a;
    int b;
    int c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (a == b)
    {
        if (b == c)
        {
            printf("%d\n", a);
        }
    }
    else if (a < b)
    {
        if (a < c)
        {
            printf("%d\n", a);
        }
    }
    else if (b < a)
    {
        if (b < c)
        {
            printf("%d\n", b);
        }
    }
    else if (c < a)
    {
        if (c < b)
        {
            printf("%d\n", c);
        }
    }
    else
    {
        printf("%d\n", 0);
    }

    return 0;
}