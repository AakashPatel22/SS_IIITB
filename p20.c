/*
============================================================================
Name : p20.c
Author : Aakash Patel (MT2024109)
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int current_priority;
    int new_priority;

    current_priority = getpriority(PRIO_PROCESS, 0); 

    printf("Current priority: %d\n", current_priority);

    new_priority = nice(5);  

    current_priority = getpriority(PRIO_PROCESS, 0);

    printf("New priority after using nice: %d\n", current_priority);

    return 0;
}
//Current priority: 0
//New priority after using nice: 5
