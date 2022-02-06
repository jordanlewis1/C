#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*

    This program prints the sizes in bytes of those files passed to it as
    command line arguments.

    To compile this program:

        gcc -g -Wall -o fs fs.c

    Example runs:

        ./fs fs.c
        ./fs *.c

    1) What is the meaning of the '&sb' parameter passed to the stat call?
       Use the stat(2) man page to help you interpret this expression.

    2) Using gdb and the man page documentation for stat(2), what is the
       blocksize and number of blocks of fs.c?

*/

int main(int argc, char *argv[]) {
    int i;
    struct stat sb;

    if (argc == 1) {
        fprintf(stderr, "Usage: ./fs file...\n");
        exit(1);
    }

    for (i = 1; i < argc; i++) {
        if (!stat(argv[i], &sb))
            printf("%s: %ld\n", argv[i], sb.st_size);
        else
            printf("%s: not found\n", argv[i]);
    }

    return 0;
}
