//importing all libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include "CommandNode.h"

int main(int argc, char *argv[])
{

    //declaring all necessary variables for getline statement
    char *line_buff = NULL;
    size_t line_buff_size = 0;
    int line_size = 0;
    ///end of the necessary variables
    FILE *ptr;
    FILE *newptr;
    ptr = fopen(argv[1], "r");
    int index;
    index = 1;

    CommandNode *head = NULL;
    int linesize;
    head = (CommandNode *)malloc(sizeof(CommandNode));
    CreateCommandNode(head, "hello world", index, NULL);
    while (linesize = getline(&line_buff, &line_buff_size, ptr) >= 0)
    {

        index = index + 1;
        CommandNode *temp = (CommandNode *)malloc(sizeof(CommandNode));
        CreateCommandNode(temp, line_buff, index, NULL);
        InsertCommandAfter(head, temp);
    }
    int count = 0;
    CommandNode *tt = head;
    int a;
    while (tt != NULL)
    {
        tt->starttime = clock();
        a = fork();
        if (a == 0)
        {
            tt->command;
            clock_t end = clock();
            clock_t dur = end - (tt->starttime);
            //CLOCKS_PER_SECOND
            double time_taken = ((double)dur) / CLOCKS_PER_SEC;
            int index_temp = tt->index;
            char d = index_temp + 1 + '0';
            fflush(stdin);
            char arr[100];
            char copyarr[1000];
            arr[0] = d;
            arr[1] = '\0';
            copyarr[0] = d;
            copyarr[1] = '\0';
            fflush(stdin);
            char outfile[1000] = ".out";
            char errfile[1000] = ".err";
            strcat(arr, outfile);     //i.out
            strcat(copyarr, errfile); //i.err

            fflush(stdin);

            //opening file in append mode
            //ptr is for a.out file
            ptr = fopen(arr, "a");
            if (time_taken < 2)
            {   //Starting command 1: child 2353 pid of parent 2234
                //Finished at 90, runtime duration 1
                fprintf(ptr, "Starting command 1: child %d pid of parent %d\nFinished at %ld, runtime duration %lf\n", getpid(), getppid(), end, time_taken);
            }
            fclose(ptr);
            //newptr is for error file
            newptr = fopen(copyarr, "a");

            {
                //Exited with exitcode = 0
                //spawning too fast
                fprintf(newptr, "Exited with exitcode = 0\nspawning too fast\n");
            }
            fclose(newptr);
            exit(0);
        }
        else if (a > 0)
        {
            wait(NULL);
            tt = tt->nextCommandPtr;
        }
    }
}
