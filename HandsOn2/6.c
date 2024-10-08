/*
============================================================================
Name : 6.c
Author : Aakash Patel (MT2024109)
Description : 6. Write a simple program to create three threads.
Date: 16th Sept, 2024.
============================================================================
*/
#include <pthread.h>
#include <stdio.h>

void* thread_function(void* arg) {
    printf("Thread %d\n is here", *((int*)arg));
    return NULL;
}

int main() {
    pthread_t threads[3];
    int i;

    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, &i);
        pthread_join(threads[i], NULL);
    }

    return 0;
}