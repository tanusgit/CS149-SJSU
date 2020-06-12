/*
Write a program that reads a list of integers, 
and outputs the two smallest integers in the list, in ascending order.
The input begins with an integer indicating the number of integers that
follow. You can assume that the list will have at least 2 integers and 
less than 20 integers.
input: 5 1 8 91 23 7 output = 1 7
input: 5 10 5 3 21 2 output: 2 3

*/
#include <stdio.h>
#include <limits.h>
int main()
{
  const int num = 20;
  // int values[6] = {5, 1, 1, 91, 23, 7};
  int values[num];
  int i = 0;
  int start = 5;
  int small1 = 0;
  int small2 = INT_MAX;
  while (1)
  { //taking user input
    scanf("%d", &values[i]);
    //the first value
    start = values[0];
    if (i >= start)
    {
      break;
    }
    i++;
  }

  small1 = values[1];
  for (int k = 1; k <= start; k++)
  {
    if (values[k] < small1)
    {
      //checking the smallest value
      small1 = values[k];
    }
  }

  for (int k = 1; k <= start; k++)
  {
    if (values[k] != small1)
    {
      if (values[k] <= small2)
      {
        small2 = values[k];
      }
    }
  }
  //printing the 2 smallest numbers in ascending order as specified in the assignment
  printf("%d %d", small1, small2);
  printf("\n");
  return 0;
}