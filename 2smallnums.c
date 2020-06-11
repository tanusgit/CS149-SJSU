/*
Write a program that reads a list of integers, 
and outputs the two smallest integers in the list, in ascending order.
The input begins with an integer indicating the number of integers that
follow. You can assume that the list will have at least 2 integers and 
less than 20 integers.
input: 5 10 5 3 21 2
output: 2 3
*/
#include <stdio.h>     
int main()
{
    const int num = 20;
    int values[num];
    int i = 0;
    int start = 0;
    int small1 = 0;
    int small2 = 0;
    while (1)
    { //taking user input
        scanf("%d", &values[i]);
        //the first value
        start = values[0];
        if (i >= start )
        {
            break;
        }
        i++;
    }
    
    small1 = values[1];
    for (int k = 0; k <= start; k++)
    {
        if (values[k] < small1)
        {
          
            small1 = values[k];
        }
    }
    for (int k = 0; k <= start; k++)
    {
        if (values[k] < small1)
        {
          
            small1 = values[k];
        }
    }
    
    printf("%d", small1);
    printf("\n");
    return 0;
}