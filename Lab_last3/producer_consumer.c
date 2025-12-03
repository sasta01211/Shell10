#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty; // counts empty slots
sem_t full;  // counts filled slots
pthread_mutex_t mutex;

/*
 Producer-Consumer using POSIX semaphores and mutex
 Compile: gcc -o prod_cons producer_consumer.c -lpthread
*/
void *producer(void *arg) {
    int id = *(int*)arg;
    for(int i=0;i<10;i++){
        sem_wait(&empty);            // wait for empty slot
        pthread_mutex_lock(&mutex);  // enter critical section

        buffer[in] = id*100 + i;     // produce an item (example value)
        printf("Producer %d produced %d at index %d\n", id, buffer[in], in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);             // signal full slot
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg) {
    int id = *(int*)arg;
    for(int i=0;i<10;i++){
        sem_wait(&full);             // wait for filled slot
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumer %d consumed %d from index %d\n", id, item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);            // signal empty slot
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    int pid = 1, cid = 1;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, &pid);
    pthread_create(&cons, NULL, consumer, &cid);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}
