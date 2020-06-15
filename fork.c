#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void add(){
    printf("add = %d\n", 4+5 );
}
void sub(){
    printf("multiplication = %d\n", 4*5 );
}
int main(int argc, char *argv[])
{
    fork();
    fprintf(stderr, "hello\n");
    add();
    sub();
    return 0;
}
