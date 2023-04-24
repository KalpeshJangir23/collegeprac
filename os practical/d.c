#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 // number of philosophers

sem_t forks[N];

void *philosopher(void *arg) {
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % N;

    while (1) {
        printf("Philosopher %d is thinking\n", id);

        // wait for forks
        sem_wait(&forks[left]);
        sem_wait(&forks[right]);

        printf("Philosopher %d is eating\n", id);
        sleep(1); // simulate eating

        // release forks
        sem_post(&forks[left]);
        sem_post(&forks[right]);
    }
}

int main() {
    pthread_t tid[N];
    int id[N];

    // initialize semaphores
    for (int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // create philosopher threads
    for (int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &id[i]);
    }

    // wait for philosopher threads to finish
    for (int i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }

    // destroy semaphores
    for (int i = 0; i < N; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
