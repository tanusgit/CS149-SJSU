#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int average(char *filename, int write_sum_fd, int write_count_fd)
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
    write(write_sum_fd, &sum, sizeof(sum));
    write(write_count_fd, &count, sizeof(count));

    //taking the average of the numbers
   // double avg = (sum / count);
    //displaying the average of the numbers
    //  printf("average: %lf\n", avg);
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[])
{
    int num_files = argc - 1;
    int fid1[num_files][2];
    int fid2[num_files][2];

    FILE *ptr;
    char temp[1000];
    int x;
    for (int i = 0; i < num_files; i++)
    {
        pipe(fid1[i]);
        pipe(fid2[i]);
        int pid = fork();
        if (pid < 0)
        {
            printf("Could not create fork");
            return 1;
        }
        if (pid == 0)
        {
            // close the read end in child.
            close(fid1[i][0]);
            close(fid2[i][0]);
            average(argv[i + 1], fid1[i][1], fid2[i][1]);
            close(fid1[i][1]); // close write end after writing.
            close(fid2[i][1]);
            // Exit once for each child process such that we keep only n processes.
            //  printf("kill [child] pid %d from [parent] pid %d\n", getpid(), getppid());
            return 0;
        }
        else
        {
            // Close the write end in parent.
            close(fid1[i][1]);
            close(fid2[i][1]);
            //  printf("Keeping the parent alive %d\n", getpid());
        }
    }
    for (int i = 0; i < num_files; i++)
    {
        wait(NULL);
    }
    double total_sum = 0;
    int total_count = 0;
    for (int i = 0; i < num_files; i++)
    {
        int count;
        double sum;
        read(fid1[i][0], &sum, sizeof(double));
        read(fid2[i][0], &count, sizeof(double));
        close(fid1[i][0]);
        close(fid2[i][0]);
        //printf("reading sum=%lf, count=%d\n", sum, count);
        total_sum += sum;
        total_count += count;
    }
    //printf("Final Average: %lf\n", total_sum/total_count);
    printf("%lf\n", total_sum / total_count);
}