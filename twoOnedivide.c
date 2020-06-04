#include <stdio.h>
int main()
{
    int userNum;
    int x;
    scanf("%d", &userNum);
    scanf("%d", &x);
    int res = userNum / x;
    int res1 = res / x;
    int res2 = res1 / x;
    printf("%d %d %d\n", res, res1, res2);
    return 0;
}