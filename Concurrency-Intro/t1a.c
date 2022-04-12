#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int max;
volatile int counter = 0; // shared global variable
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *arg) {
    char *letter = arg;
    int i; // stack (private per thread) 


    fprintf(stderr, "%s: begin\n", letter);


    for (i = 0; i < max; i++) {

        pthread_mutex_lock(&mutex1);
        counter = counter + 1; // shared: only one
        pthread_mutex_unlock(&mutex1);
        printf("%s increments counter\n", letter);
    }


    fprintf(stderr, "%s: done\n", letter);
    return NULL;
}
                                                                             
int main(int argc, char *argv[]) {                    
    if (argc != 2) {
	fprintf(stderr, "usage: main-first <loopcount>\n");
	exit(1);
    }
    max = atoi(argv[1]);

    pthread_t p1, p2;
    fprintf(stderr, "main: begin [counter = %d] [%p]\n", counter, 
	   &counter);
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
    fprintf(stderr, "main: done\n [counter: %d]\n [should: %d]\n", 
	   counter, max*2);
    return 0;
}

