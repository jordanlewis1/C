#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "zemaphore.h"

zem_t s;

void *child(void *arg) {
    sleep(4);
    printf("child\n");
    zem_post(&s); // signal here: child is done
    return NULL;
}

int main(int argc, char *argv[]) {
    zem_init(&s, 0); 
    printf("parent: begin\n");
    pthread_t c;
    pthread_create(&c, NULL, child, NULL);
    zem_wait(&s); // wait here for child
    printf("parent: end\n");
    return 0;
}
    
