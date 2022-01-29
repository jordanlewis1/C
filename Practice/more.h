/*
    The #ifndef/#define/#endif ensure that no recursive inclusions of this
    .h file occur.  It's standard practice to do this with all .h files.

    Typically, .h files are used to define those things that need to be
    defined/included for the associated .c files.  Thus, they will include
    #define and #include directives, as well as the function prototypes for
    the functions defined in the .c file.
*/

#ifndef _MORE_H
#define _MORE_H

#include <stdio.h>

void func(int);

#endif
