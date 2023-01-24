#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

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

int max;
int loops;
int *buffer;

int use  = 0;
int fill = 0;

sem_t empty;
sem_t full;
sem_t mutex;

#define CMAX (10)
int consumers = 1;

void do_fill(int value) {
    buffer[fill] = value;
    fill++;
    if (fill == max)
        fill = 0;
}

int do_get() {
    int tmp = buffer[use];
    use++;
    if (use == max)
        use = 0;
    return tmp;
}

void *producer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        // Swap the following sem_wait() calls.
        sem_wait(&mutex);
        sem_wait(&empty);
        //sem_wait(&mutex);
        do_fill(i);
        sem_post(&mutex);
        sem_post(&full);
    }

    // end case
    for (i = 0; i < consumers; i++) {
        // Swap the following sem_wait() calls.
        sem_wait(&mutex);
        sem_wait(&empty);
        //sem_wait(&mutex);
        do_fill(-1);
        sem_post(&mutex);
        sem_post(&full);
    }

    return NULL;
}
                                                                               
void *consumer(void *arg) {
    int tmp = 0;
    while (tmp != -1) {
        // Swap the following sem_wait() calls.
        sem_wait(&mutex);
        sem_wait(&full);
        //sem_wait(&mutex);
        tmp = do_get();
        sem_post(&mutex);
        sem_post(&empty);
        printf("%lld %d\n", (long long int) arg, tmp);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
	fprintf(stderr, "usage: %s <buffersize> <loops> <consumers>\n", argv[0]);
	exit(1);
    }
    max   = atoi(argv[1]);
    loops = atoi(argv[2]);
    consumers = atoi(argv[3]);
    assert(consumers <= CMAX);

    buffer = (int *) malloc(max * sizeof(int));
    assert(buffer != NULL);
    int i;
    for (i = 0; i < max; i++) {
        buffer[i] = 0;
    }

    sem_init(&empty, 0, max); // max are empty 
    sem_init(&full, 0, 0);    // 0 are full
    sem_init(&mutex, 0, 1);   // mutex

    pthread_t pid, cid[CMAX];

    pthread_create(&pid, NULL, producer, NULL); 
    for (i = 0; i < consumers; i++) {
        pthread_create(&cid[i], NULL, consumer, (void *) (long long int) i); 
    }

    pthread_join(pid, NULL); 
    for (i = 0; i < consumers; i++) {
        pthread_join(cid[i], NULL); 
    }
    return 0;
}

