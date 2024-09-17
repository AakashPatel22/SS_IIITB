/*
============================================================================
Name : 8f.c
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
#include <sys/time.h>

void sigvtalrm_handler(int signum) {
    printf("Caught SIGVTALRM (Virtual Timer)\n");
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, sigvtalrm_handler);

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1);

    return 0;
}
