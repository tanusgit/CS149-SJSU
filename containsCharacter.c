/*
Write a program that reads an integer, a list of words, and
a character. The integer signifies how many words are in
the list. The output of the program is every word in the
list that contains the character at least once. Assume at least 
one word in the list will contain the given character. Assume that 
the list will always contain less than 20 words. Each word will always
contain less than 10 characters and no spaces.
input = 4 hello zoo sleep drizzle z
output= 
zoo
drizzle
*/
#include <stdio.h>
#include <string.h>
int Contains(char* a, int size, char c){

}
int main(void) {
   //20 is the number of the strings in the array
   //10 is the length of the string
   int numofString = 20;
   int stringLength = 10;
   char str[numofString][stringLength];
   int i = 0;
   int len;
   scanf("%d", &len);
   while(1){
       scanf("%s", str[i]); 
       if(i > len+1){
           break;
       }
       i++;
       
   }
    for(int k = 0; k < i; k++){
      if(str[k].Contains('z') == 1){
          printf("%s ", str[k]);
      }
        
    }
   return 0;
}
