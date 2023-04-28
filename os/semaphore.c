#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
// Declare semaphores
sem_t chopstick[5];

void *philosopher(void *arg) {
    int id = *(int *) arg;
    int right = id;
    int left = (id + 1) % 5;

    while (1) {
        // Pick up right chopstick
        sem_wait(&chopstick[right]);

        // Pick up left chopstick
        if (sem_trywait(&chopstick[left]) == -1) {
            // Left chopstick is not available, release right chopstick
            sem_post(&chopstick[right]);
            continue;
        }

        // Eat
        sleep(1);
        printf("Philosopher %d is eating\n", id);

        // Put down left chopstick
        sem_post(&chopstick[left]);

        // Put down right chopstick
        sem_post(&chopstick[right]);

        // Think
  
        printf("Philosopher %d is thinking\n", id);
    }
}

int main() {
    // Initialize semaphores
    for (int i = 0; i < 5; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    // Create philosopher threads
    pthread_t philosopher_thread[5];
    int philosopher_id[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++) {
        pthread_create(&philosopher_thread[i], NULL, philosopher, &philosopher_id[i]);
    }

    // Wait for philosopher threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(philosopher_thread[i], NULL);
    }

    // Destroy semaphores
    for (int i = 0; i < 5; i++) {
        sem_destroy(&chopstick[i]);
    }

    return 0;
}

