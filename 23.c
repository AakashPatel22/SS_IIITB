/*
============================================================================
Name : 23.c
Author : Aakash Patel (MT2024109)
Description : Write a program to create a Zombie state of the running program.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
int main() {
    int pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid > 0) {
        printf("Parent process (PID: %d) is going to sleep.\n", getpid());

        sleep(30);
        wait(NULL);
        printf("Parent process is exiting.\n");
    } else {
        printf("Child process (PID: %d) is exiting to become a zombie.\n", getpid());

        exit(0);
    }

    return 0;
}
/*
Parent process (PID: 11734) is going to sleep.
Child process (PID: 11735) is exiting to become a zombie.
*/
