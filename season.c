/*
The dates for each season are:
Spring: March 20 - June 20
Summer: June 21 - September 21
Autumn: September 22 - December 20
Winter: December 21 - March 19
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char Month[50];
    int Day;

    scanf("%s", Month);
    //&Day is the address of day
    scanf("%d", &Day);
    printf("%s %d\n", Month, Day);
    //strcmp is used to compare two strings
    // if (strcmp(Month, "March") == 0)
    if (Day < 1 || Day > 31)
    {
        printf("Invalid");
    }
    else if ((strcmp(Month, "December") != 0) && (strcmp(Month, "September") != 0) &&
             (strcmp(Month, "June") != 0) && (strcmp(Month, "March") != 0))
    {
        printf("Invalid");
    }
    else if (strcmp(Month, "March") == 0)
    {
        if (Day > 19)
        {
            printf("Spring");
        }
        else
        {
            printf("winter");
        }
    }
    else if (strcmp(Month, "June") == 0)
    {
        if (Day < 21)
        {
            printf("Spring");
        }
        else
        {
            printf("Summer");
        }
    }

    else if (strcmp(Month, "September") == 0)
    {
        if (Day < 22)
        {
            printf("Summer");
        }
        else
        {
            printf("Autumn");
        }
    }

    else if (strcmp(Month, "December") == 0)
    {
        if (Day < 21)
        {
            printf("Autumn");
        }
        else
        {
            printf("Winter");
        }
    }

    return 0;
}