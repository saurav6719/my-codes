#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
sem_t empty, full;
int in = 0, out = 0;

void *producer(void *arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        item = rand() % 100; // Generate random item
        sem_wait(&empty);    // Wait for empty slot
        buffer[in] = item;   // Add item to buffer
        printf("Produced item %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(&full);     // Signal that buffer is not empty
        usleep(rand() % 100000); // Simulate some delay
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);     // Wait for item to be available
        item = buffer[out];  // Consume item from buffer
        printf("Consumed item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(&empty);    // Signal that buffer has empty space
        usleep(rand() % 100000); // Simulate some delay
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Join threads
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
