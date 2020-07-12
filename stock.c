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
    int ar[7]={100, 180 ,260 ,310, 40, 535, 695};
    int max = 0; 
    int profit = 0;
    int index = 0;
    int index2 = 0;
    for(int i = 0; i < 6; i++){
        //looking at the back and start at the 1st index and compare those
        //2 elements and if the previous element is lower than the current
        //then subtract and save and it to profit
        int max = ar[i+1];
        if(max > ar[i]){
            profit =  profit + ar[i+1] - ar[i];    
        }
    }
    for(int i = 0; i < 6; i++){
        
        if(ar[i+1] > ar[i]){
            index = 0;
           index2 = i+1;
        }
        else{
           index2 = i+1;
           index = i;
        }
    }
    printf("profit %d %d %d ", profit, index, index2);
    return 0;
}




