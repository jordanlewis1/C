/*
   To compile initially:
       gcc -g -o hello hello.c
   To fix the problem with the printf:
       See manpage for printf(3).  Specifically, the l length modifier and
       the d conversion specifier.
   To fix the problem with the implicit declaration of hello:
       Un-comment hello's prototype.
   Run hello:
       ./hello
   Explain the output.
   Run again, using your name for argv[1]:
       ./hello Tom
   What happened?!?  Let's use gdb to figure this out.
   Run again, using your name and your favorite number (for argv[2]).
       ./hello Tom 42
   Uncomment the call to func.
   To fix the problem with the implicit declaration of func:
       Un-comment the include for more.h
   To fix the linker problem:
       gcc -g -o hello hello.c more.c
   Run again, using your name and your favorite number:
       ./hello Tom 42
*/

/*
    This is how constants are defined in C.  The convention is to use only
    uppercase letters, numerals, and the underscore character in names.
*/
#define FAVE 42

// <...> tells include to look in system include directories
#include <stdio.h>
#include <stdlib.h>
// "..." tells include to look in the current working directory
#include "more.h"

// Function prototype
int hello(char *, int);

int main(int argc, char *argv[]) {
    long fave = FAVE;
    printf("Favorite number is %ld\n", fave);
    func(fave);
    return hello(argv[1], atoi(argv[2]));
}

int hello(char *name, int count) {
    printf("Hello %s!\nCount is %d\n", name, count);
    return 0;
}
