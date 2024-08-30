/*
============================================================================
Name : p29.c
Author : Aakash Patel (MT2024109)
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>

void print_policy(int policy) {
    switch(policy) {
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
    }
}

int main(int argc, char *argv[]) {
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0); 
    print_policy(policy);

    if (argc < 2) {
        printf("Usage: %s <SCHED_FIFO|SCHED_RR>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "SCHED_FIFO") == 0) {
        policy = SCHED_FIFO;
    } else if (strcmp(argv[1], "SCHED_RR") == 0) {
        policy = SCHED_RR;
    } else {
        printf("Invalid policy. Use SCHED_FIFO or SCHED_RR.\n");
        return 1;
    }

    param.sched_priority = sched_get_priority_min(policy);

    if (sched_setscheduler(0, policy, &param) == -1) {
        perror("sched_setscheduler failed");
        return 1;
    }

    printf("Scheduling policy changed to ");
    print_policy(policy);

    return 0;
}
