/*
============================================================================
Name : 28.c
Author : Aakash Patel (MT2024109)
Description : Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (max_priority == -1 || min_priority == -1) {
        perror("sched_get_priority_max/min failed for SCHED_FIFO");
        return 1;
    }
    printf("SCHED_FIFO: Max priority = %d, Min priority = %d\n", max_priority, min_priority);

    max_priority = sched_get_priority_max(SCHED_RR);
    min_priority = sched_get_priority_min(SCHED_RR);
    if (max_priority == -1 || min_priority == -1) {
        perror("sched_get_priority_max/min failed for SCHED_RR");
        return 1;
    }
    printf("SCHED_RR: Max priority = %d, Min priority = %d\n", max_priority, min_priority);

    return 0;
}
