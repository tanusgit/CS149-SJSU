//test cases
//num of days
//arrays with stock price
//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0git 

//7 days                 
//100 180 260 310 40 535 695
//output (0 3) (4 6)
#include <stdio.h>

int main()
{
    
    int days;
    scanf("%d", &days);


    int array[days];
    for(int i = 0; i< days; i++){
        scanf("%d", &array[i]);
    }
   
    int profit;
    int indexmin;
    int indexmax;
    for(int j =0; j < days; j++){
    for(int i = 0; i< days; i++){
         int min= array[i];
        int max = array[i+1];
        indexmin = i;
        if(min < max){
          i++;
        }
        else{
          indexmax = i-1;
          profit = array[i-1]-min;
          min = array[i];
        }
    }
    }
    printf("profit = %d\n", profit);
     printf("days = %d %d\n", indexmin, indexmax);





    /*
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

    printf("maximum profit = %d, and days include %d", maxprofit, maxprofitpos);*/

    return 0;
}