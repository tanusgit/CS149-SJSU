#include <stdio.h>
void SortArray(int arr[], int n)
{
    int i;
    int j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    SortArray(arr, n);

    int k;

    for (k = 0; k < n; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}