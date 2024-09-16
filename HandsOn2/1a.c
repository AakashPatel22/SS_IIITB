/*
============================================================================
Name : 1a.c
Author : Aakash Patel (MT2024109)
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 15th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Timer expired (ITIMER_REAL)\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, signal_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        sleep(1);
    }
    
    return 0;
}
