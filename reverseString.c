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
#include<stdio.h>
#include<string.h>

void reverse(){
    char str[50];
    int m = 0;
    //strlen() return the length of a string
    while(1){
        fgets(str, 50, stdin);
        printf("%s", str);
        m++;
    }
   int num = strlen(str);
    for(int i = num; i >= 0; i--){
        printf("%c",(char)str[i]);
    }
}
int main(){
    reverse("Hello there");
    return 0;
}