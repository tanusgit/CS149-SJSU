#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<errno.h>
#include "CommandNode.h"
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
int main(int argc,char* argv[])
{
	int n=argc-1;
	int i;
	int p;
	clock_t start;
    clock_t end;
	clock_t dur;
	FILE* ptr;
	FILE* newptr;
	extern int errno;
	
	for(i=0;i<n;i++)
	{
		p=fork();
		if(p==0)
		{
			start=clock();
			//printf("we are in the child process\n");
			printf("process id of the child process is:%d\n",getpid());
			fflush(stdin);
			printf("process id of the parent process is:%d\n",getppid());
			fflush(stdin);
            end = clock();
			dur=clock()-start;
			//CLOCKS_PER_SECOND
			double time_taken = ((double)dur)/CLOCKS_PER_SEC;
			printf("time taken is:%lf\n",time_taken);
			fflush(stdin);
			CommandNode* head;
			head= (CommandNode*)malloc(sizeof(CommandNode));
			CreateCommandNode(head,"hello world",i,NULL);
			head->PID=getpid();
			head->starttime=clock();
			head->index=i;
			//int to char in c/c++
			char d=i+'0';
			fflush(stdin);
			printf("in here\n");
			printf("%c\n",d);
			char arr[100];
			char copyarr[1000];
			arr[0]=d;
			copyarr[0]=d;
			fflush(stdin);
			char outfile[1000]=".out";
			char errfile[1000]=".err";
			strcat(arr,outfile);  //i.out
			strcat(copyarr,errfile);//i.err
			int len_errorfile=strlen(copyarr);
			int len_outfile=strlen(arr);
			for(i=0;i<len_outfile;i++)
			{
				printf("%c",arr[i]);
			}
			printf("\n");
			fflush(stdin);
			for(i=0;i<len_errorfile;i++)
			{
				printf("%c",copyarr[i]);
			}
			printf("\n");

			fflush(stdin);
			int n_size=strlen(arr);
			printf("n size is:%d\n",n);
			int j;
			//opening file in append mode
            //ptr is for a.out file
			ptr=fopen(arr,"a");
			if(time_taken<2)
			{   //Starting command 1: child 2353 pid of parent 2234
                //Finished at 90, runtime duration 1
				fprintf(ptr,"Starting command 1: child 2353 pid of parent 2234\nFinished at %ld, runtime duration %lf\n",end, time_taken );
				
			}
			fclose(ptr);
            //newptr is for error file
			newptr=fopen(copyarr,"a");

			{
                //Exited with exitcode = 0
                //spawning too fast
				fprintf(newptr,"Exited with exitcode = 0\nspawning too fast\n");
				

			}
			fclose(newptr);
			

			exit(0);


		}


	}
	
	for(i=0;i<n;i++)
	{
		//printf("we are in the parent process\n");
		wait(NULL);

	}
	


}