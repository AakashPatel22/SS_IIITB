/*
============================================================================
Name : 8b.c
Author : Aakash Patel (MT2024109)
Description : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("\nCaught SIGINT: Interrupt signal (Ctrl+C)\n");
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("Press Ctrl+C to trigger SIGINT\n");
        sleep(1);
    }

    return 0;
}