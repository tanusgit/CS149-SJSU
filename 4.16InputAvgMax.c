#include <stdio.h>
//15 20 0 5 -1
//10 20
int main(void)
{
    int sum = 0;
    int num;
    int avg;
    int max = 0;
    int count = 0;

    while (1)
    {
        scanf("%d", &num);
        if (num < 0)
            break;
        sum = sum + num;
        count++;
        if (num > max)
        {
            max = num;
        }
    }
    avg = sum / count;
    printf("%d %d\n", avg, max);
    return 0;
}
