#include <stdio.h>
int main() {
    //1%2 gives 1
    for (int i = 0; i < 7; i++) {
        for (int j = 2; j < i+3; j++) {
                printf("*");
        }
        printf("\n");
    }
    return 0;
    /*
      // outer loop to handle number of rows 
        //  n in this case 
        for (int i=0; i<n; i++) 
        { 
  
            // inner loop to handle number spaces 
            // values changing acc. to requirement 
            for (int j=n-i; j>1; j--) 
            { 
                // printing spaces 
                System.out.print(" "); 
            } 
   
            //  inner loop to handle number of columns 
            //  values changing acc. to outer loop 
            for (int j=0; j<=i; j++ ) 
            { 
                // printing stars 
                System.out.print("* "); 
            } 
   
            // ending line after each row 
            System.out.println(); 
        } 
    } 
    */
}