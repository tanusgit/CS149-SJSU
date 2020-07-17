#include <stdio.h>

int main()
{
    int array[7] = {9, 3, 4, 1, 3, 8, 10};
    int min = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            int temp = 0;
            if (array[i] > array[j])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        printf(" %d, ", array[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        min = min + array[i];
    }
    printf("min of 4 elements = %d", min);
    return 0;
}