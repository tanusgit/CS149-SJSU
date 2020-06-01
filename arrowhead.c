#include <stdio.h>
int main(void) {
    //input is 0 1. 0 is body, 1 is head
    int baseInt = 0;
    int headInt = 1;
    
    for (int i = 0; i < 3; i++){
        for(int j =0; j < 4; j++){
            printf("%d ", baseInt);
        }
        printf("\n");
    }
    
     for (int i = 0; i < 4; i++){
        for(int j =0; j < i+1; j++){
            if(j < 2){
                printf("%d ", baseInt);
            }
            printf("%d ", headInt);
        }
        printf("\n");
    }
     for (int i = 3; i > 0; i--){
        for(int j =0; j < i ; j++){
            printf("%d ", headInt);
        }
        printf("\n");
    }
    
    return 0;
}
