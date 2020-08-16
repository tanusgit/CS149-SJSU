#include <stdio.h>
#include <string.h>

int main()
{

    int a[] = {1, 2, 3, 4, 5, 6, 7};//7 elements len = 7
    //sort the array
    //1, 2, 3, 4, 6
    //a[4] != 5
    //a[4] != a[4]+1
    //add all the elements
    
    for (int i = 0; i < 6; i++)
    {
        if (a[i + 1] != a[i] + 1)
        {
            printf("%d" , a[i ]+ 1);
        };
    }
}