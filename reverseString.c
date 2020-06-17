/*
Write a program that takes in a line of text as input, 
and outputs that line of text in reverse. You may assume 
that each line of text will not exceed 50 characters.The 
program repeats, ending when the user enters "Quit", "quit", 
or "q" for the line of text. 
Ex: If the input is:
Hello there
Hey
quit
output:
ereht olleH
yeH
*/
#include <stdio.h>
#include <string.h>

void reverse()
{   
    //one string won't be more than 50 chracters
    char str[50];
    
    //strlen() return the length of a string
    while (1)
    {
        //scanf("%s", str);
        scanf(" %[^\n]",str);
        //printf("Orig:%s\n", str);
        //strcmp() takes 2 string as input and returns a boolean 0 if
        //they are same
        if (strcmp(str, "q") == 0 || strcmp(str, "quit") == 0 ||
            strcmp(str, "Quit") == 0)
        {
            break;
        }
        int num = strlen(str);
        for (int i = 0; i < num/2; ++i)
        {
            char temp = str[i];
            str[i] = str[num-i-1];
            str[num-i-1] = temp;
        }
        printf("%s\n", str);
    }
}
int main()
{
    reverse();
    return 0;
}