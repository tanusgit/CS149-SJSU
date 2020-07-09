//importing all libraries
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>
#include<string.h>
#include<errno.h>
#include "CommandNode.h"
typedef struct command_struct {
   char command[20][20];
   int index;
   int PID;
   int starttime;
   struct command_struct* nextCommandPtr;
} CommandNode;


void CreateCommandNode(CommandNode* thisNode, char cmd[20][20], int ind, CommandNode* nextCmd) {
   //this is useful if you store a string (char *): strcpy(thisNode->command, cmd);
   for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++)
         thisNode->command[i][j] = cmd[i][j];
   thisNode->index = ind;
   thisNode->nextCommandPtr = nextCmd;
   return;
}

//insert node newNode after thisNode 
void InsertCommandAfter(CommandNode* thisNode, CommandNode* newNode) {
   CommandNode* tmpNext = NULL;
   
   tmpNext = thisNode->nextCommandPtr;
   thisNode->nextCommandPtr = newNode;
   newNode->nextCommandPtr = tmpNext;
   return;
}

//get next command node in linked list
CommandNode* GetNextCommand(CommandNode* thisNode) {
   return thisNode->nextCommandPtr;
}

//find a command based on the pid
CommandNode* FindCommand(CommandNode* cmd, int pid) {
   CommandNode* tmpNext = cmd;
   while (tmpNext != NULL) {
       if (tmpNext->PID == pid) { return tmpNext; }
       tmpNext = tmpNext->nextCommandPtr;
   }
   return NULL;
}
char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

char line[1024];
char *cmd[1024];
clock_t start_time;
clock_t end_time;
extern int errno;
int main(int argc,char* argv[])
{

	//declaring all necessary variables for getline statement
	char* line_buff=NULL;
	size_t line_buff_size=0;
	int line_size=0;
	///end of the necessary variables
	FILE* ptr;
	FILE* newptr;
	ptr=fopen(argv[1],"r");
	int index;
	index=1;
	clock_t start_time,end_time;
	double duration;
	int temp_time;


	CommandNode* head=NULL;
	int linesize;
	head=(CommandNode*)malloc(sizeof(CommandNode));
	CreateCommandNode(head,"hello world",index,NULL);
	while(linesize=getline(&line_buff,&line_buff_size,ptr)>=0)
	{
		//printf("%s",line_buff);
		index=index+1;
		CommandNode* temp=(CommandNode*)malloc(sizeof(CommandNode));
		CreateCommandNode(temp,line_buff,index,NULL);
		InsertCommandAfter(head,temp);
		line_size++;

	}
	int count=0;
	CommandNode* tt=NULL;
	/*
	while(tt!=NULL)
	{
		count=count+1;
		tt=tt->nextCommandPtr;
	}
	printf("%d\n",count);
	*/
	//creating n children from one parent
	
	int a;
	tt=head;
	while(tt!=NULL)
	{
		tt->starttime=clock();
		start_time=clock();
		
		a=fork();
		if(a<0)
		{
			printf("fork failed\n");
		}
		if(a==0)
		{
			char temp[20];
			strcpy(temp,tt->command);
			int u=strlen(temp);
			temp[u-1]='\0';
			char** cmd;
			cmd=get_input(temp);
			execvp(cmd[0],cmd);
			

			exit(0);
		}
		if(a>0)
		{
			printf("child pid is:%d\n",getpid());
			printf("parent pid is:%d\n",getppid());
			wait(NULL);
			end_time=clock();
			double duration=(double)(end_time-start_time)/CLOCKS_PER_SEC;
			int index_temp = tt->index;
            char d = index_temp + '0';
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
            newptr = fopen(arr, "a");
            if (duration< 2)
            {   //Starting command 1: child 2353 pid of parent 2234
                //Finished at 90, runtime duration 1
                fprintf(newptr, "Starting command %d: child %d pid of parent %d\nFinished at %ld, runtime duration %lf\n", tt->index,getpid(), getppid(), end_time, duration);
            }
            fclose(newptr);
            //newptr is for error file
            newptr = fopen(copyarr, "a");

            {
                //Exited with exitcode = 0
                //spawning too fast
                fprintf(newptr, "Exited with error code:%d\n",errno);
                fprintf(newptr,"spawning too fast");
            }
            fclose(newptr);

		}
		tt=tt->nextCommandPtr;

	}


}
// "we are working on execvp command.this is tough thing."

//*(*a)
//a=oxff15

