#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MSGSIZE 16
char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

int main()
{
    char inbuf[MSGSIZE];
    int p[2], i;
    int f = fork();

    int j = pipe(p);

    /* continued */
    /* write pipe */
    // close(p[0]);
    if (f == 0)
    {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    // close(p[1]);

    else if (f > 0)
    {
        for (i = 0; i < 3; i++)
        {
            /* read pipe */
            // close(p[1]);
           // wait(NULL);
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            // close(p[0]);
        }
    }
    return 0;
}