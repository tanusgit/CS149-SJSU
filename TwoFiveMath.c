#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    double x;
    double y;
    double z;
    scanf("%lf", &x);
    scanf("%lf", &y);
    scanf("%lf", &z);
    double res = pow(x, z);
    double res2 = pow(x, pow(y, 2));
    double aby = fabs(y);
    double res3 = sqrt(pow(x * y, z));
    printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", res, res2, aby, res3);
    return 0;
}