/*
Write a program that first gets a list of integers 
from input. The input begins with an integer indicating 
the number of integers that follow. Then, get the last value
from the input, which indicates a threshold. Output all integers
less than or equal to that last threshold value. Assume that the list
will always contain less than 20 integers.
*/


#include <stdio.h>
//input = 5 50 60 140 200 75 100
//output = 50 60 75
int main()
{
    const int num = 20;
    int values[num];
    int i = 0;
    int start = 0;
    while (1)
    { //taking user input
        scanf("%d", &values[i]);
        //storing the number of values to chcek inside start
        start = values[0];
        if (i >= start + 1)
        {
            break;
        }
        i++;
    }
    // printf("%d %d\n", start, values[i]);
    for (int k = 1; k <= start; k++)
    {
        //checking if all the values except the first value is
        //less then the last value user entered
        if (values[k] < values[i])
        {
            //printing the values
            printf("%d ", values[k]);
        }
    }
    printf("\n");
    return 0;
}