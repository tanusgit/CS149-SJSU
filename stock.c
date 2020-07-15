//test cases
//num of days
//arrays with stock price
//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0git

//7 days
//100 180 260 310 40 535 695
//output (0 3) (4 6)
#include <stdio.h>
#include <stdio.h>

struct keep {
    int min;
    int max;
};

void calculate(int arr[], int num)
{
    int min =0;
    int max = 0;
     struct keep k[20];
    for (int i = 0; i < num; i++)
    {
        if(arr[i] > arr[i+1]){
           min = i+1; 
           max = i;
           k[i].min = min;
           k[i].max = max;  
        }
        else if(arr[i] < arr[i+1]){
            min = i;
            max = i+1;
            k[i].min = min;
            k[i].max = max; 
        } 
         printf("printing struct %d %d\n", k[i].min, k[i].max); 
    }

   

}

int main()
{
    int ar[7] = {100, 180, 260, 310, 40, 535, 695};
    calculate(ar, 7);
    return 0;
    int max = 0;
    int profit = 0;
    int index = 0;
    int index2 = 0;
    for (int i = 0; i < 6; i++)
    {
        //looking at the back and start at the 1st index and compare those
        //2 elements and if the previous element is lower than the current
        //then subtract and save and it to profit
        int max = ar[i + 1];
        if (max > ar[i])
        {
            profit = profit + ar[i + 1] - ar[i];
        }
    }
    return 0;
}
