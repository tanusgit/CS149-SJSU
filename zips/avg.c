#include <stdio.h>
#include <stdlib.h>

int average();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("error: please enter file with numbers.\n");
        return 1;
    }
    char *filename = argv[1];
    int value = average(filename);

    return value;
}

int average(char *filename)
{
    double sum = 0;
    int count = 0;
    char buffer[1000];
    //opening the file for reading
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("file not found.\n");
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
    //taking the average of the numbers
    double avg = (sum / count);
    //displaying the average of the numbers
    printf("%lf", avg);
    fclose(fp);
    return 0;
}