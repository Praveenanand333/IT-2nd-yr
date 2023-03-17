#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

void *producer(void *arg) {
    while (true) {
        int item = rand() % 10 + 1;

        // wait until buffer is not full
        while (count == BUFFER_SIZE) {
            printf("Buffer is full, producer is waiting...\n");
            sleep(1);
        }

        // add item to buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        printf("Producer produced item %d\n", item);
        sleep(1);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    while (true) {
        // wait until buffer is not empty
        while (count == 0) {
            printf("Buffer is empty, consumer is waiting...\n");
            sleep(1);
        }

        // remove item from buffer
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;

        printf("Consumer consumed item %d\n", item);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main() {
    // create threads
    pthread_t prod_thread, cons_thread;
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // wait for threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    return 0;
}

