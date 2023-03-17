#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg)
{
    int tid = *((int *) arg);
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution\n");

    return 0;
}

