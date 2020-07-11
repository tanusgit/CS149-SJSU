//test cases
//num of days
//arrays with stock price
//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0git 

//7 days                 
//100 180 260 310 40 535 695
//output (0 3) (4 6)
#include <stdio.h>
#include <stdio.h>
int main() {
    int ar[6]={7,1,5,3,6,4};
    int max = 0; 
    int profit = 0;
    for(int i = 0; i < 5; i++){
        //looking at the back and start at the 1st index and compare those
        //2 elements and if the previous element is lower than the current
        //then subtract and save and it to profit
        int max = ar[i+1];
        if(max > ar[i]){
            profit =  profit + ar[i+1] - ar[i];
              
        }
    }
    printf("profit %d ", profit);
    return 0;
}




