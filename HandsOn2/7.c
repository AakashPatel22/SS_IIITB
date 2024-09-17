/*
============================================================================
Name : 7.c
Author : Aakash Patel (MT2024109)
Description : 7. Write a simple program to print the created thread ids.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self();  
    printf("Thread ID: %lu\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int i;

    for (i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished execution\n");

    return 0;
}
