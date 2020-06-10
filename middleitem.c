#include <stdio.h>
//input 2 3 4 8 11 -1
//output 4
int main()
{
    const int num = 10;
    int values[num];
    int i = 0;
    int mid = 0;
    while (1)
    {
        scanf("%d", &values[i]);
        if (values[i] < 0)
        {
            break;
        }
        else if (i > 8)
        {
            printf("Too many inputs\n");
            return 1;
        }
        i++;
    }
    mid = (i /2);
    printf("%d", values[mid]);
    printf("\n");
    return 0;
}

/*
 int limit;
    scanf("%d", &limit);
if(limit > 9){
       printf("Too many inputs");
       return 1;
   }
    for(int i = 0; i < limit; i++){
        scanf("%d", &values[i]);
        if(values[i] < 0){
            break;
        }
    }
    int mid = (limit)/2;
    printf("%d", values[mid]);
*/