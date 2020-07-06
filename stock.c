//test cases
//num of days
//arrays with stock price
//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0git 
#include <stdio.h>

int main()
{
    //
    int days;
    int array[days];
  //  scanf("%d", &test);
    scanf("%d", &days);
    for(int i = 0; i< days; i++){
        scanf("%d", &array[i]);
    }
    int start = array[0];
    int max = array[0];
    int maxposition = 0;
    for(int i = 0; i < days; i++){
        //getting the max value in the array
        if(array[i] > max){
            max = array[i];
            maxposition = i;
        }
    }
    //got the max value poition in the array
    //now check the max profit == max value - all the values
    int maxprofit = max - start;
    int maxprofitpos = 0;
    for(int i = 0; i < days; i++){
        if(max- array[i] > maxprofit){
            maxprofit = max- array[i];
            maxprofitpos = i;
        }
    }
    //got max profit and its position

    printf("maximum profit = %d, and days include %d", maxprofit, maxprofitpos);
    
    
    



    return 0;
}