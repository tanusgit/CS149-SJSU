#include <stdio.h>

int main(void)
{

    int a;
    int b;
    int c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a < b)
    {
        if (a < c)
        {
            printf("%d\n", a);
        }
        else
        {
            printf("%d\n", c);
        }
    }
    else
    {
        if (b < c)
        {
            printf("%d\n", b);
        }
        else
        {
            printf("%d\n", c);
        }
    }

    return 0;
}