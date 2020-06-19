#include <stdio.h>
#include <stdlib.h>
//create one child for each input files
/*
extend assgt 1 such that you crate one child process per input fle 
each child process will process its input file same as you did in assgt 1 
and then you still need to send the results from each child back to the parent 
we. are going to see today how you can do that with pipes 
and then the parent combines the avg results and prints them out 
you want the opening to happen within each child process 
for assgt2 


fork and then open


if you did open and then fork then the child would get the same file that was open in the parent. you dont need this here in the assgt 2 
you could fork and then open each file in the child independently 
each child will inherit the array of parameters (which are the filenames you want to open) 
each child will know I am the i’th child, so I will open the i’th file 

**==parent child p .c for assignment 2


both parents and child cannot write and read for assignment 2
parent should read and child should write


question:
For the pipe, if the reading side of the pipe will wait unit the 
writing completed. Why we still need to put the wait at the end 
of code? Is that just for forcing parent process to wait until 
child process finished and then clean up all the resource that 
child process was used? 
ans: yes
*/

int main(int argc, char *argv[])
{ // 0 is the read end of the pipe and 1 is the write end of the pipe
    int pipefd[2];
    int value;
    char *filename = argv[1];
    //creating pipe
    pipe(pipefd);
    int p = fork();

    if (p == 0)
    { //in child
        double sum = 0;
        int count = 0;
        char buffer[1000];
        //opening the file for writing and reading
        FILE *fp = fopen(filename, "r+");
        if (fp == NULL) // (!fp) is the same thing
        {
            printf("avg: cannot open file.\n");
            return 1;
        }
        //reading all the numbers till end of file
        while (fscanf(fp, "%s", buffer) != EOF)
        { //converting string to float
            float x = atof(buffer);
            //adding all the numbers
            sum = sum + x;
            count++;
        }
        if (count == 0)
        {
            fclose(fp);
            return 0;
        }
        //taking the average of the numbers
        double avg = (sum / count);
        printf("testing if avg is being calculated %lf\n", avg);
        //now write the falue in the file
        fprintf(fp, "%lf\n", avg);
        fclose(fp);
    }
    else if (p > 0)
    {
        double value;
        //opening the file for writing
        FILE *fp = fopen(filename, "r");
        fscanf(fp, "%lf", &value);
        printf("in parent ");
        printf("average  %lf\n", value);
        fclose(fp);
    }
}