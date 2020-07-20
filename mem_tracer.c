#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
FILE* ptr = fopen(argv[1],"r" );
char** array[100][100];
int i = 0;
char* buffer;
    buffer = (char *) malloc (sizeof(char));
    size_t bufsize = 0;
    //size_t is always greater than 0
    int c;
while ((c = getline(&buffer,&bufsize,ptr))>=0)
    {
        printf("printing c %d\n", c);
        strcpy(&array[i++],buffer);
        
    }
    free(buffer);
    fclose(ptr);
     printf("%s\n", &array[0]);
     printf("%s", &array[1]);
   /* for(int j =0 ; j < 7; j++){
       // printf("inside forloop  ");
        printf("%s", array[j]);
    }*/
    
    return 0;


}

