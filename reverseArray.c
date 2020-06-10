//input: 5 2 4 6 8 10
//output: 10 8 6 4 2
#include <stdio.h>
int main(void)
{
    int limit;
    int num = 20;
    int values[num];
    scanf("%d", &limit);

    for (int i = 0; i < limit; i++)
    {
        scanf("%d", &values[i]);
    }
    for (int i = limit - 1; i >= 0; i--)
    {
        printf("%d ", values[i]);
    }
    printf("\n");
    return 0;
}