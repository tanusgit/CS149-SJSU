#include <stdio.h>
int main() {
    //1%2 gives 1
    for (int i = 0; i < 7; i++){
        for(int j =0; j < i+1; j++){
            if((i%2) == 0){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
        
    }
    
    return 0;
}