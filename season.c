/*
The dates for each season are:
Spring: March 20 - June 20
Summer: June 21 - September 21
Autumn: September 22 - December 20
Winter: December 21 - March 19
*/
#include <stdio.h>
#include <string.h>

int main(void) {
   char Month[50];
   int Day;
   
   scanf("%s", &Month); 
   scanf("%d", &Day); 
   //strcmp is used to compare two strings
  // if (strcmp(Month, "March") == 0) 
   if (strcmp(Month, "March") == 0) {
       if(Day >20){
           printf("Spring");
       }

   }

   return 0;
}