/*
Given a sorted list of integers, output the middle integer. Assume the number of integers is always odd.
(where a negative indicates the end).
The maximum number of list values for any test case should not exceed 9. If exceeded, output "Too many inputs".

Hint: First read the data into an array. Then, based on the array's size, find the middle item. 
Ex: If the input is:2 3 4 8 11 -1
output = 4
*/

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