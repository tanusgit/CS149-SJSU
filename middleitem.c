#include <stdio.h>

int main(void) {
   const int num = 9;
   int values[num];
   int limit;
   scanf("%d", &limit);  
   if(limit > 9){
       printf("Too many inputs");
       return 1;
   }
    for(int i = 0; i < limit; i++){
        scanf("%d", &values[i]);
        if(values[i] < 0){
            break;
        }
    }
    int mid = (limit)/2;
    printf("%d", values[mid]);
   return 0;
}
