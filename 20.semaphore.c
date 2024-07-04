#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, full, empty;
int buff[10];
int in = 0, out = 0;

void* producer(void* arg) {
    int item;
    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("\nEnter an item\n");
        scanf("%d", &item);
        buff[(in + 1) % 10] = item;
        in = (in + 1) % 10;
        sem_post(&mutex);
        sem_post(&full);
    }
}

void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        printf("\nConsumed item is: %d\n", buff[(out + 1) % 10]);
        out = (out + 1) % 10;
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 10);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, producer, NULL);
    sleep(2);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
