// C program to read nth byte of a file and
// copy it to another file using lseek
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void func()
{

    // Open the file for READ only.
    int f_read = open("start.txt", O_RDONLY);

    // Open the file for WRITE and READ only.
    int f_write = open("end.txt", O_WRONLY);
    char c;
    while (read(f_read, &c, 1))
    { //skipping 2 characters from current position
        lseek(f_read, 2, SEEK_CUR);
        write(f_write, &c, 1);
    }
    close(f_write);
    close(f_read);
}

// Driver code
int main()
{
    // Calling for the function
    func();
    return 0;
}
