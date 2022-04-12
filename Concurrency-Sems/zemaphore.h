#ifndef __zemaphore_h__
#define __zemaphore_h__

typedef struct __zem_t {
    int value;
    pthread_cond_t  cond;
    pthread_mutex_t lock;
} zem_t;

void zem_init(zem_t *z, int value) {
    z->value = value;
    pthread_cond_init(&z->cond, NULL);
    pthread_mutex_init(&z->lock, NULL);
}

void zem_wait(zem_t *z) {
    pthread_mutex_lock(&z->lock);
    while (z->value <= 0)
        pthread_cond_wait(&z->cond, &z->lock);
    z->value--;
    pthread_mutex_unlock(&z->lock);
}

void zem_post(zem_t *z) {
    pthread_mutex_lock(&z->lock);
    z->value++;
    pthread_cond_signal(&z->cond);
    pthread_mutex_unlock(&z->lock);
}

#ifdef __APPLE__
typedef zem_t sem_t;

#define Sem_wait(s)    zem_wait(s)
#define Sem_post(s)    zem_post(s)
#define Sem_init(s, v) zem_init(s, v)
#endif

#endif // __zemaphore_h__
