#include <stdio.h>
#include <stdlib.h>

void average();

int main(int argc, char* argv[])
{   
    char* filename = argv[1];
    average(filename);
}

void average(char* filename)
{
    double sum = 0;
    int count = 0;
    char buffer[1000];
    FILE *fp = fopen(filename, "r");

    //reading all the numbers and checking if reached end of file
    while (fscanf(fp, "%s", buffer) != EOF)
    {
        
        //converting string to int
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
}