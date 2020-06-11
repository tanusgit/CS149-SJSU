/*
Write a program that first gets a list of integers from input. 
The input begins with an integer indicating the number of integers
that follow. Assume that the list will always contain less than 20
integers.

That list is followed by two more integers representing lower and 
upper bounds of a range. Your program should output all integers 
from the list that are within that range (inclusive of the bounds).
For coding simplicity, follow each output integer by a space, even 
the last one. The output ends with a newline.
*/
#include <stdio.h>
//input = 5 25 51 0 200 33
//0 50
//output = 25 0 33       
int main()
{
    const int num = 20;
    int values[num];
    int i = 0;
    int start = 0;
    int lower = 0;
    int upper = 0;
    while (1)
    { //taking user input
        scanf("%d", &values[i]);
        //the first value
        start = values[0];
        if (i >= start + 2)
        {
            break;
        }
        i++;
    }
    upper =  values[i];
    lower = values[i-1];
   // printf("upper and lower =  %d %d\n", upper, lower);
    for (int k = 1; k <= start; k++)
    {
        //checking if all the values except the first value is
        //within the range
        if (values[k] <= upper && values[k] >= lower)
        {
            //printing the values
            printf("%d ", values[k]);
        }
    }
    printf("\n");
    return 0;
}