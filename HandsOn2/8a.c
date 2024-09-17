/*
============================================================================
Name : 8a.c
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

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    _exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    int *ptr = NULL;
    *ptr = 42;

    return 0;
}
