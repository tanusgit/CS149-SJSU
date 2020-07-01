#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int n = argc - 1;
    int i;
    int p;
    clock_t start;
    clock_t dur;
    FILE *ptr;

    for (i = 0; i < n; i++)
    {
        p = fork();
        if (p == 0)
        {
            start = clock();
            //printf("we are in the child process\n");
            printf("process id of the child process is:%d\n", getpid());
            fflush(stdin);
            printf("process id of the parent process is:%d\n", getppid());
            fflush(stdin);
            dur = clock() - start;
            //CLOCKS_PER_SECOND
            double time_taken = ((double)dur) / CLOCKS_PER_SEC;
            printf("time taken is:%lf\n", time_taken);
            fflush(stdin);
            //int to char in c/c++
            char d = i + '0';
            fflush(stdin);
            printf("in here\n");
            printf("%c\n", d);

            char arr[100];
            arr[0] = d;

            char narr[100] = ".out";
            strcat(arr, narr);
            fflush(stdin);
            int n_size = strlen(arr);
            printf("n size is:%d\n", n);
            int j;
            ptr = fopen(arr, "a");
            fprintf(ptr, "%s\n", "hello world");

            exit(0);
        }
    }

    for (i = 0; i < n; i++)
    {
        //printf("we are in the parent process\n");
        wait(NULL);
    }
}
