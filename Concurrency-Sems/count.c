#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* Un-comment the following #define to use "zemaphores" rather than
   semaphores on the Apple platform.  The original code uses zemaphores
   rather than semaphores on the Apple platform.
*/
//#define USE_ZEMAPHORE_APPLE

#ifndef USE_ZEMAPHORE_APPLE
#include <semaphore.h>
#else
#ifdef linux
#include <semaphore.h>
#elif __APPLE__
#include "zemaphore.h"
#endif
#endif

sem_t mutex;
volatile int counter = 0;

void *child(void *arg) {
    int i;
    for (i = 0; i < 10000000; i++) {
        sem_wait(&mutex);
        counter++;
        sem_post(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    sem_init(&mutex, 0, 1); 
    pthread_t c1, c2;
    pthread_create(&c1, NULL, child, NULL);
    pthread_create(&c2, NULL, child, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);
    printf("result: %d (should be 20000000)\n", counter);
    return 0;
}
    
