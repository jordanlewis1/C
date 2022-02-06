#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

/*

    This program creates two threads.  Each thread increments a shared
    counter by 1 for the number of times indicated by the passed in command
    line argument.

    To compile:

        gcc -g -Wall -o threads threads -pthread

    1) What is the purpose of the -pthread argument here?  Why is it
       necessary? 

    2) What code does each thread run?

    3) How many total threads will be running immediately after the second
       pthread_create call has completed?

    4) Explain what pthread_join does.

    5) If the program is run thusly:

           ./threads 42

       What should the output be?  Is the correct output produced?

    6) Explain what happens, and why it happens, when the program is run
       thusly:

           ./threads 100000

*/

volatile int counter = 0; 
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        counter++;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "usage: ./threads <loops>\n"); 
        exit(1); 
    } 
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    assert(pthread_create(&p1, NULL, worker, NULL) == 0);
    assert(pthread_create(&p2, NULL, worker, NULL) == 0);
    assert(pthread_join(p1, NULL) == 0);
    assert(pthread_join(p2, NULL) == 0);
    printf("Final value   : %d\n", counter);
    return 0;
}

