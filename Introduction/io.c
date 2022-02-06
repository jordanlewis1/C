#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

/*

    This program opens a file, writes some text to it, and then syncs and
    closes it.

    To compile this program:

        gcc -g -Wall -o io io.c

    Run the program.  The assert below will fail.  Use gdb to investigate.

    1) What is the value of the global variable errno at the point of the
       assertion failure?  Using a search engine, what is the meaning of
       this errno code?  Write your answers here:

    2) Using the getcwd(3) man page, modify the program so that the file
       (named 'file') that it creates is created in the running process'
       current working directory.

    3) Using the man page for open(2), explain the meaning of the second
       and third parameters to the open call.

*/

int main(int argc, char *argv[]) {
    int fd = open("/root/file",
                  O_WRONLY | O_CREAT | O_TRUNC,
                  S_IRUSR | S_IWUSR);
    assert(fd >= 0);
    char buffer[20];
    sprintf(buffer, "hello world\n");
    int rc = write(fd, buffer, strlen(buffer));
    assert(rc == (strlen(buffer)));
    fsync(fd);
    close(fd);
    return 0;
}

