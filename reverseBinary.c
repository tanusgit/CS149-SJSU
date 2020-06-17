//void IntegerToReverseBinary(int integerValue, char binaryValue[])
//void ReverseString(char inputString[], char reversedString[])
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void IntegerToReverseBinary(int integerValue, char binaryValue[])
{
    int r = integerValue % 2;
    sprintf(binaryValue, "%d", r);
    //printf("\n The string for the num is %s", binaryValue);
    // printf("%d", m);
    if (integerValue > 1)
    {
        IntegerToReverseBinary(integerValue / 2, binaryValue + 1);
    }
}

void ReverseString(char inputString[], char reversedString[])
{
    int num = strlen(inputString);
    for (int i = 0; i < num; ++i)
    {
        reversedString[i] = inputString[num - i - 1];
    }
    reversedString[num] = '\0';
}

int main(void)
{
    char binaryValue[100];
    char value[100];
    int input;
    scanf("%d", &input);
    IntegerToReverseBinary(input, binaryValue);
   // printf("\n The string for the num is %s\n", binaryValue);
    ReverseString(binaryValue, value);
   // printf("\n The reverse string for the num is %s\n", value);
   printf("%s\n", value);
    return 0;
}
