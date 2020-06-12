/*
One lap around a standard high-school running track is exactly 0.25 miles. Write a program that 
takes a number of miles as input, and outputs the number of laps.

Output each floating-point value with two digits after the decimal point, which can be achieved as follows:
printf("%0.2lf", yourValue);
input : 1.5
output: 6.00
double MilesToLaps(double userMiles)
*/
#include <stdio.h>

double MilesToLaps(double userMiles)
{
  double lap;
  lap = userMiles / .25;
  return lap;
}

int main(void)
{
  double mile = 0.0;
  scanf("%lf", &mile);
  double lap = MilesToLaps(mile);
  printf("%0.2lf\n", lap);
  return 0;
}
