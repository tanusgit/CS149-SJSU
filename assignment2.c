#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int num = argc - 1;
    //creating file pointer
    FILE *ptr;
    //c pointing to nothing 
    char *c = NULL;
    //each line can only content 100bytes as we have given 100 to add_size
    //if not specified the size getline allocates space according to the 
    //string length
    //int add_size = 0 also works fine , no need to do malloc
    //char c = null works fine. 
    //getline calls realloc if the specified bytes are not enough
    int add_size = 100;
    //c1 pointing to (char*)malloc(add_size)
    char *c1 = (char*)malloc(add_size);
    c1[0] = 'a';
    c1[1] = 'b';
    c1[2] = '\0';
    // Reusing the memory allocated for 'ab' printing.
    printf("c1 before=%s\n", c1);
    size_t size = add_size;
    int line;
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        //fopen takes filename and open mode
        ptr = fopen(argv[i + 1], "r");
        printf("file name = %s \n", argv[i+1]);
       // getline returns string length upon sucess and -1 upon failure
        while ((line = getline(&c1, &size, ptr)) != -1)
        {
            if( c1[line-1] == '\n' )
                c1[line-1] = 0;
            double d = atof(c1);
            printf("line = %d, size = %lu,  %s, converted value = %f", line, size, c1, d);
            sum = sum +d;
            count++;
        }
        fclose(ptr);
    }
    printf("average is %f", (sum/count));

return 0;
}