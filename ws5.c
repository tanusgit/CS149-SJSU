#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(){
    fork();
    fork();
    //printing hello world from PID from the current process 4 times
    printf("hello world from PID %d\n", getpid());
return 0;
}