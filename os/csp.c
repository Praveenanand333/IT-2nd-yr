#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

int turn = 0;
int flag[2] = {0, 0};

void lock(int id) {
    flag[id] = 1;
    turn = 1 - id;

    while (flag[1 - id] && turn == 1 - id) {
        // Busy wait
    }
}

void unlock(int id) {
    flag[id] = 0;
}

void* critical_section(void* arg) {
    int id = *(int*) arg;
    lock(id);
    // Critical section code here
    printf("Thread %d is in the critical section.\n", id);
    unlock(id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1};

    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, critical_section, &thread_ids[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
