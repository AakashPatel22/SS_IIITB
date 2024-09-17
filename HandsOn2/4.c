/*
============================================================================
Name : 4.c
Author : Aakash Patel (MT2024109)
Description : 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static __inline__ uint64_t rdtsc(void) {
    uint32_t lo, hi;
    __asm__ __volatile__ (
        "rdtsc" : "=a"(lo), "=d"(hi)
    );
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();

    printf("Time taken to execute 100 getppid() system calls: %lu CPU cycles\n", (end - start));

    return 0;
}
