#include <stdio.h>
#include <string.h>
void missing(int a[], int len);
int main()
{

    int a[6] = {1, 2, 3, 4, 5, 6};//7 elements len = 7
    //sort the array
    //1, 2, 3, 4, 6
    //a[4] != 5
    //a[4] != a[4]+1
    //add all the elements in the array and then substract from the 
    //sum of the elements of the entire array
    int sum = 0;
    int sum2 = 0;
    for (int i = 1; i < 8; i++)
    {
        sum = sum + i;
    }
    printf("entire array sum = %d\n", sum);
    for(int i = 0; i < 6; i++){
        sum2 = sum2 + a[i];
    }
    printf("missing element array sum = %d\n", sum2);
    printf("missing element in the array = %d\n", (sum - sum2));
    missing(a, 6);
    
}

void missing(int a[], int len){

    for (int i = 0; i < len - 1; i++)
    {
        if (a[i + 1] != a[i] + 1)
        {
            printf("%d" , a[i ]+ 1);
        }
    }
    printf("%d", a[len-1]+1);
} 