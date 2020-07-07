#include <stdio.h>
void sorting(int array[], int len)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len-1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}
int main()
{
  int arr[] = {2, 4, 5, 1, 3, 7, 10, 9, 8};
  int len = sizeof(arr) / sizeof(int);
  sorting(arr, len);
  for (int i = 0; i < 9; i++)
  {
    printf("%d  ", arr[i]);
  }

  //wave
    //incrementing i for 2 position as we need to swap every 2 contiguous elements
    //so i should always start after 2 position from the starting position
    //for example first i is 0th index then i should be 2nd index
    //logic= take first 2 elemnts and swap then take next 2 elements and swap in a sorted array
    for (int i = 0; i < 8; i= i+2)
    {
     //sawpping 2 contiguous elements
      int temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
    }
  
//printing wave
 printf("printing wave\n");
  for (int i = 0; i < 9; i++)
  {
   
    printf("%d  ", arr[i]);
  }
}