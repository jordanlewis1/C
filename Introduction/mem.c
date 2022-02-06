#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*

    This program uses malloc(3) to dynamically allocate memory for an int
    variable.  The variable is initialized to the value passed in on the
    command line.

    To compile:

        gcc -g -Wall -o mem mem.c

    Press Ctrl-c to terminate the program.

    1) Explain the line 'int *p;'.  What does p contain?

    2) Explain the line '*p = *p + 1;'.

    3) After running the program, what was its process id and what was the
       starting address of the memory block returned by malloc?  Do these
       values change each time the program is run?  Explain.

*/
int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "usage: ./mem <value>\n"); 
        exit(1); 
    } 
    int *p; 
    p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p);
    *p = atoi(argv[1]); // assign value to addr stored in p
    while (1) {
        sleep(1);
        *p = *p + 1;
        printf("(%d) value of p: %d\n", getpid(), *p);
    }
    return 0;
}

