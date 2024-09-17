/*
============================================================================
Name : 3.c
Author : Aakash Patel (MT2024109)
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_STACK, &limit) == 0) {
        printf("Current Stack Size:\n");
        printf("  Soft limit: %ld\n", limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", limit.rlim_max);
    } else {
        perror("getrlimit");
        return 1;
    }

    limit.rlim_cur = 16 * 1024 * 1024;  // 16 MB
    limit.rlim_max = 32 * 1024 * 1024;  // 32 MB

    if (setrlimit(RLIMIT_STACK, &limit) == 0) {
        printf("New Stack Size limits set successfully.\n");

        if (getrlimit(RLIMIT_STACK, &limit) == 0) {
            printf("Updated Stack Size:\n");
            printf("  Soft limit: %ld\n", limit.rlim_cur);
            printf("  Hard limit: %ld\n", limit.rlim_max);
        }
    } else {
        perror("setrlimit");
    }

    return 0;
}
