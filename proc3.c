//importing all libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
typedef struct command_struct
{
    char command[20][20];
    int index;
    int PID;
    int starttime;
    struct command_struct *nextCommandPtr;
} CommandNode;
void CreateCommandNode(CommandNode *thisNode, char cmd[20][20], int ind, CommandNode *nextCmd)
{

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            thisNode->command[i][j] = cmd[i][j];
    thisNode->index = ind;
    thisNode->nextCommandPtr = nextCmd;
    return;
}
void InsertCommandAfter(CommandNode *thisNode, CommandNode *newNode)
{
    CommandNode *tmpNext = NULL;

    tmpNext = thisNode->nextCommandPtr;
    thisNode->nextCommandPtr = newNode;
    newNode->nextCommandPtr = tmpNext;
    return;
}
CommandNode *GetNextCommand(CommandNode *thisNode)
{
    return thisNode->nextCommandPtr;
}
CommandNode *FindCommand(CommandNode *cmd, int pid)
{
    CommandNode *tmpNext = cmd;
    while (tmpNext != NULL)
    {
        if (tmpNext->PID == pid)
        {
            return tmpNext;
        }
        tmpNext = tmpNext->nextCommandPtr;
    }
    return NULL;
}
//a parse function to get the command input in the desired format
char **get_input(char *input)
{
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;
    parsed = strtok(input, separator);
    while (parsed != NULL)
    {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

char line[1024];
char *cmd[1024];
//variable for the start time
clock_t start_time;
//variable for the end time
clock_t end_time;
extern int errno;
char arr[100];

char outfile[1000];

int main(int argc, char *argv[])
{
    char *line_buff = NULL;
    size_t line_buff_size = 0;
    int line_size = 0;
    int flag = 0;
    ///end of the necessary variables
    FILE *ptr;
    FILE *newptr;
    ptr = fopen(argv[1], "r");
    int index;
    index = 1;
    clock_t start_time, end_time;
    double duration;
    int temp_time;
    struct timeval start, end, start_new, end_new;
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
        line_size++;
    }
    int count = 0;
    CommandNode *tt = NULL;
    tt = head;
    pid_t process_id;
    pid_t p_process_id;
    while (tt != NULL)
    {
        start_time = clock();
        gettimeofday(&start, NULL);
        int a;
        a = fork();
        if (a == 0)
        {

            process_id = getpid();
            p_process_id = getppid();

            char temp[20];
            strcpy(temp, tt->command);
            int u = strlen(temp);
            temp[u - 1] = '\0';
            char **cmd;
            cmd = get_input(temp);
            int index_temp = tt->index;
            char d = index_temp + '0';
            fflush(stdin);
            arr[0] = d;
            arr[1] = '\0';
            fflush(stdin);
            strcpy(outfile, ".out");
            strcat(arr, outfile); //i.out
            
            newptr = fopen(arr, "a");
            fprintf(newptr, "Starting command %d: child %d pid of parent %d\n", tt->index, process_id, p_process_id);
            fclose(newptr);
            execvp(cmd[0], cmd);
            exit(0);
        }
        else
        {
            //printf("In parent process\n");
            wait(NULL);
            end_time = clock();
            gettimeofday(&end, NULL);
            long seconds = (end.tv_sec - start.tv_sec);
            long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        hell:

            if (micros > 2000000)
            {
                int pp;
                pp = fork();
                if (pp == 0)
                {
                    char **t_cmd;
                    char temp_new[20];
                    strcpy(temp_new, tt->command);
                    int uu = strlen(temp_new);
                    temp_new[uu - 1] = '\0';
                    t_cmd = get_input(temp_new);
                    execvp(t_cmd[0], t_cmd);
                }
                else if (pp > 0)
                {
                    gettimeofday(&start_new, NULL);
                    wait(NULL);
                    gettimeofday(&end_new, NULL);
                    long new_seconds = (end_new.tv_sec - start_new.tv_sec);
                    long micros = ((new_seconds * 1000000) + end_new.tv_usec) - (start_new.tv_usec);
                    if (micros > 2000000)
                    {
                        goto hell;
                    }
                }
            }

            char d = tt->index + '0';
            char e = tt->index + '0';
            char copyarr[1000];
            char errfile[1000];
            char outfile[1000];
            char narr[1000];
            copyarr[0] = d;
            copyarr[1] = '\0';
            fflush(stdin);
            narr[0] = e;
            narr[1] = '\0';
            fflush(stdin);
            strcpy(outfile, ".out");
            strcat(narr, outfile);
            fflush(stdin);
            strcpy(errfile, ".err");
            strcat(copyarr, errfile);
          
            if (flag == 0)
            {
                FILE *pptr;
                pptr = fopen(narr, "a");
                fprintf(pptr, "run duration%f\n", duration);
                fclose(pptr);
            }
            
            ptr = fopen(copyarr, "a");
            {
                fprintf(ptr, "Exited with exit code = %d\n", errno);
                fprintf(ptr, "spawning too fast");
                fclose(ptr);
            }
            tt = tt->nextCommandPtr;
        }
    }
}
