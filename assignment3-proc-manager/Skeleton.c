#include "CommandNode.h"

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<errno.h>

void skeleton()
{
  //---------------------------
  //put commands in a data structure (e.g. linkedlist), which is used
  //for recording the start times and indices of the commands.
  //see the read_parse_file.c I provided for parsing each command
  //save the cmd in a node of the linkedlist

  //First command node (head of list)
  int index = 1;
  CommandNode *headCommand = (CommandNode *)malloc(sizeof(CommandNode));
  char command[20][20];
  CreateCommandNode(headCommand, command, index, NULL);
  int linesize;
  FILE *fp;
  int len;
  char line[100];
  //Later command nodes
  while ((linesize = getline(&line, &len, fp)) >= 0)
  {
    //.....
    index++;
    CommandNode *nextCommand1 = (CommandNode *)malloc(sizeof(CommandNode));
    CreateCommandNode(nextCommand1, command, index, NULL);
    InsertCommandAfter(headCommand, nextCommand1);
  }

  //---------------------------
  //fork the commands and record the start times

  CommandNode *headNode; /** This is the beginning of your linked list of CommandNodes **/
  CommandNode *tmpNode;

  tmpNode = headNode;

  while (tmpNode != NULL)
  {

    //save the startime!
    // tmpNode.starttime = starttime

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

      //
      //to compute the elapsed time you subtract
      //elapsedtime = finishtime - node.start_time
      //decide if you will restart
      //if (elapsedtime > 2) {
      //record the new starttime
      // node.starttime = new starttime
      // pid = fork();
      // if (pid < 0) //error
      // else if (pid == 0) { //child
      //See shell1_execvp.c for execvp usage
      // execvp(node.cmd);
      // } else if (pid > 0) {
      // node.pid = pid;
      // }
    }
  }
}