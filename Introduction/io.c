#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

/*

    This program opens a file, writes some text to it, and then syncs and
    closes it.

    To compile this program:

        gcc -g -Wall -o io io.c

    Run the program.  The first assert below will fail.  Use gdb to
    investigate.

    1) What is the value of the global variable errno at the point of the
       assertion failure?  Using a search engine, what is the meaning of
       this errno code?  Write your answers here:

    2) Using the getcwd(3) man page, modify the program so that the file
       (named 'file') that it creates is created in the running process'
       current working directory.  You will also need to use strcat(3).

    3) Using the man page for open(2), explain the meaning of the second
       and third parameters to the open call.
       * for the second parameter (O_creat) this creates file if there is not already one
       * * for the third parameter (O_trunc) if there is a file that already exists then it gets set to lenth 0.  So it deletes the previos info already stored.

    4) Using the malloc(3) man page, explain what malloc does.  How would you
       change the declaration of buffer so that malloc was no longer needed?
       Your answers should distinguish run-time from compile-time.
       * The malloc function allocates the address of memory in the pointer.    Malloc uses run-time because it essentially is able to allocate memory dynamically on its own without hard coding.
       

*/

int main(int argc, char *argv[]) {
	char path[80];
	getcwd(path, 80-6);
	strcat(path, "/file");
    int fd = open(path,
                  O_WRONLY | O_CREAT | O_TRUNC,
                  S_IRUSR | S_IWUSR);
    assert(fd >= 0);
    char *buffer;
    //char S[256] = "Tom";
    //strcat(s,  "42")
    assert((buffer = malloc(20 * sizeof(char))) != NULL);
    sprintf(buffer, "hello world\n");
    int rc = write(fd, buffer, strlen(buffer));
    assert(rc == (strlen(buffer)));
    free(buffer);
    fsync(fd);
    close(fd);
    return 0;
}

