#include "CommandNode.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void PrintCommand(CommandNode *cmd) {
  printf("Command index: %d:", cmd->index);
  for (int i = 0; i < 20; i++)
    printf("%s ", cmd->command[i]);
  printf("\n");
}

CommandNode *ReadCommands(const char* filename)
{
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  char newString[20][20];
  int i, j, ctr;

  fp = fopen(filename, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  int index = 1;
  CommandNode *headCommand = (CommandNode *)malloc(sizeof(CommandNode));
  char command[20][20];
  // Head node
  CreateCommandNode(headCommand, command, index, NULL);

  while ((read = getline(&line, &len, fp)) != -1)
  {
    for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++)
        newString[i][j] = 0;

    j = 0;
    ctr = 0;
    for (i = 0; i <= (strlen(line)); i++)
    {
      // if space or NULL found, assign NULL into newString[ctr]
      if (line[i] == ' ' || line[i] == '\0')
      {
        newString[ctr][j] = '\0';
        ctr++; //for next word
        j = 0; //for next word, init index to 0
      }
      else
      {
        newString[ctr][j] = line[i];
        j++;
      }
    }
    CommandNode *nextCommand1 = (CommandNode *)malloc(sizeof(CommandNode));
    ++index;
    CreateCommandNode(nextCommand1, newString, index, NULL);
    InsertCommandAfter(headCommand, nextCommand1);
    PrintCommand(nextCommand1);
  }

  fclose(fp);
  free(line);
  return headCommand;
}

int main(int argc, char *argv[])
{
  clock_t start;
  clock_t end;
  clock_t dur;
  CommandNode *headNode = ReadCommands("cmdfile.txt");
  CommandNode *tmpNode;

  tmpNode = headNode;

  while (tmpNode != NULL)
  {
    struct timespec start, finish;
    double elapsed;
    clock_t t;
    t = clock();
    clock_gettime(CLOCK_MONOTONIC, &start);
    //printf("start %ld\n", start.tv_sec);
    tmpNode->starttime = (long long)start.tv_sec;

    //clock_gettime(CLOCK_MONOTONIC, &finish);
    //printf("finish %ld\n", finish.tv_sec);
    //printf("CLOCKSPERSEC %ld\n", CLOCKS_PER_SEC);
    //double time_taken = ((double)t)*1000.0/CLOCKS_PER_SEC; // in seconds 
    elapsed = (finish.tv_sec - start.tv_sec);

    int pid = fork();

    if (pid < 0)
    {
      fprintf(stderr, "error forking");
      exit(2);
    }
    else if (pid == 0)
    {                              /*child */
                                   //See shell1_execvp.c for execvp usage
      execvp(tmpNode->command[0], tmpNode->command); /*executes the command in the specific node */
    }
    else if (pid > 0)
    { /* parent goes to the next node */

      tmpNode->PID = pid;
      int fdout = open("%d.out", tmpNode->index);
      int fderr = open("%d.err", tmpNode->index);
      fprintf(fdout, "Starting command INDEX %d: child PID %d of parent PPID %d.\n", tmpNode->index, pid, getpid());
      tmpNode = tmpNode->nextCommandPtr;
    }
  } /*end of while loop*/

  //---------------------------

  //Final while loop: waits until anything has completed,
  //this will exit (wait returns -1)
  //when there is no more child process. Then your parent process exits.
  CommandNode *node;
  int pid;
  int status;
  while ((pid = wait(&status)) >= 0)
  {
    if (pid > 0)
    {
      //finishtime = get the finish time
      //search your linked list for the node that corresponds to pid
      //The function FindNode was provided
      //node=FindNode(pid)

      //signal handling
      int fdout = open("%d.out", node->index);
      int fderr = open("%d.err", node->index);

      fprintf(stderr, "Process with PID %d terminated.\n", pid);
      if (WIFEXITED(status))
      {
        fprintf(fderr, "Child %d terminated normally with exit code: %d\n",
                pid, WEXITSTATUS(status));
      }
      else if (WIFSIGNALED(status))
      {
        fprintf(fderr, "Child %d terminated abnormally with signal number: %d\n",
                pid, WTERMSIG(status));
      }
    }
  }

  return 0;
}
