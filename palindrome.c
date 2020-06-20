#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void palindrome()
{
    char input[1000];
    //ignoring space while scanning
    scanf(" %[^\t\n]s", input);
    printf("%s", input);
    char original[1000];
    //copying the original string in original
    memcpy(original, input, 1000);
   // printf("%s", original);
    int num = strlen(input);
    //reversing the string
    for (int i = 0; i < num / 2; i++)
    {
        char temp = input[i];
        input[i] = input[num - i - 1];
        input[num - i - 1] = temp;
    }
    //checking if the original string and reversed string are same
    if (strcmp(original, input) == 0)
    {
        printf("%s is a palindrome\n", original);
    }
    else
    {
        printf("%s is not a palindrome\n", original);
    }
}
int main()
{
    palindrome();
}

/*
#include <stdio.h> 
#include <string.h> 
void isPalindrome(char str[]) 
{  

int l = 0; 
int h = strlen(str) - 1; 

while (h > l) 
{
if(str[h]==' ')
{
h=h-1;
}
else if(str[l]==' ')
{
l=l+1;
}
else if (str[l++] != str[h--]) 
{ 
printf("%s is not a palindrome\n", str); 
return; 
} 
} 
printf("%s is a palindrome\n", str); 
} 

int main() 
{ 
    char input[1000];
    gets(input);

isPalindrome(input); 
return 0; 

}

*/