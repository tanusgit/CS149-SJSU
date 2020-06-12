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
int Contains(char a[], char c)
{
  for (int i = 0; i < strlen(a); i++)
  {
    if (a[i] == c){
      return 0;
    }
  }
  return 1;
}
int main(void)
{
  //20 is the number of the strings in the array
  //10 is the length of the string
  int numofString = 20;
  int stringLength = 10;
  char str[numofString][stringLength];
  for(int i = 0; i < numofString; ++i) {
    for (int j = 0; j < stringLength; ++j) {
      str[i][j] = '\0';
    }
  }
  int i = 0;
  int len = 0;
  char c;
  scanf("%d", &len);
  while (1)
  {
    scanf("%s", str[i]);
    if (i >= len)
    {
      break;
    }
    i++;
  }
  //getting the first character(0) of the last string
  c = str[i][0];
  //printf("character %c\n", c);
  for (int k = 0; k < i; k++)
  { //printf("%s\n", str[k]);
    if (Contains(str[k], c) == 0)
    {
     
      printf("%s\n", str[k]);
    }
  }
  return 0;
}
