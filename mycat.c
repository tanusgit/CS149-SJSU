#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#define BUFFSIZE 4096
void err_sys(const char *err)
{
    perror(err);
    exit(1);
}
int main(void)
{
    int n;
    char buf[BUFFSIZE];
    //STDIN_FILENO = file descriptor
    //buf = area to put input
    //BUFFSIZE = how any bytes are going inside
    //read() return 0 on reaching end of file
    //read() return -1 on error
    //read() return -1 on signal interrupt
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        //   printf("%d bytes\n", n);
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");
        if (n < 0)
            err_sys("read error");
            fprintf(stderr, "Bytes: %d\n", n);

    exit(0);
}
