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
int average();

int main(int argc, char *argv[])
{   // 0 is the read end of the pipe and 1 is the write end of the pipe
    int pipefd[2];
    int value;
    char *filename;
    //creating pipe
    pipe(pipefd);
    int p = fork();
    if (p == 0)
    {
        printf("in child");

       value =  average(filename);

    }
    else if (p != 0)
    {
        printf("in parent");
        for (int i = 0; i < argc; i++)
        {
            filename = argv[i];
            value = average(filename);
            printf("\n");
        }
    }

    if (argc != 2)
    {
        return 0;
    }

    return value;
}






int average(char *filename)
{
    double sum = 0;
    int count = 0;
    char buffer[1000];
    //opening the file for reading
    FILE *fp = fopen(filename, "r");

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
    //displaying the average of the numbers
    printf("%lf", avg);
    fclose(fp);
    return 0;
}






-----------------------------------

    if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
  
    // Parent process 
    else if (p > 0) 
    { 
        char concat_str[100]; 
  
        close(fd1[0]);  // Close reading end of first pipe 
  
        // Write input string and close writing end of first 
        // pipe. 
        write(fd1[1], input_str, strlen(input_str)+1); 
        close(fd1[1]); 
  
        // Wait for child to send a string 
        wait(NULL); 
  
        close(fd2[1]); // Close writing end of second pipe 
  
        // Read string from child, print it and close 
        // reading end. 
        read(fd2[0], concat_str, 100); 
        printf("Concatenated string %s\n", concat_str); 
        close(fd2[0]); 
    } 
  
    // child process 
    else
    { 
        close(fd1[1]);  // Close writing end of first pipe 
  
        // Read a string using first pipe 
        char concat_str[100]; 
        read(fd1[0], concat_str, 100); 
  
        // Concatenate a fixed string with it 
        int k = strlen(concat_str); 
        int i; 
        for (i=0; i<strlen(fixed_str); i++) 
            concat_str[k++] = fixed_str[i]; 
  
        concat_str[k] = '\0';   // string ends with '\0' 
  
        // Close both reading ends 
        close(fd1[0]); 
        close(fd2[0]); 
  
        // Write concatenated string and close writing end 
        write(fd2[1], concat_str, strlen(concat_str)+1); 
        close(fd2[1]); 
  
        exit(0); 
    } 
} 