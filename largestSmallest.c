/*Your program must define and call the following two functions. 
The LargestNumber function should return the largest number of the three input values. 
The SmallestNumber function should return the smallest number of the three input values.
int LargestNumber(int userNum1, int userNum2, int userNum3)
int SmallestNumber(int userNum1, int userNum2, int userNum3)
input: 7 15 3
largest: 15 
smallest: 3
*/
#include <stdio.h>
int LargestNumber(int userNum1, int userNum2, int userNum3)
{
  if (userNum1 > userNum2)
  {
    if (userNum1 > userNum3)
    {
      return userNum1;
    }
    else
    {
      return userNum3;
    }
  }
  else
  {
    if (userNum2 > userNum3)
    {
      return userNum2;
    }
    else
    {
      return userNum3;
    }
  }
}
int SmallestNumber(int userNum1, int userNum2, int userNum3)
{
  if (userNum1 < userNum2)
  {
    if (userNum1 < userNum3)
    {
      return userNum1;
    }
    else
    {
      return userNum3;
    }
  }
  else
  {
    if (userNum2 < userNum3)
    {
      return userNum2;
    }
    else
    {
      return userNum3;
    }
  }
}

int main(void)
{
  int a =0;
  int b = 0;
  int c = 0;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  int largest = LargestNumber(a, b, c);
  printf("largest: %d\n", largest);
  int smallest = SmallestNumber(a, b, c);
  printf("smallest: %d\n", smallest);

  return 0;
}