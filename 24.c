/*
============================================================================
Name : 24.c
Author : Aakash Patel (MT2024109)
Description : Write a program to create an orphan process.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid > 0) {
        printf("Parent process (PID: %d) is exiting.\n", getpid());
        exit(0);
    } else {
        sleep(5);
        printf("Child process (PID: %d) is now an orphan\n", getpid());
    }

    return 0;
}
/*
Parent process (PID: 11596) is exiting.
Child process (PID: 11597) is now an orphan
*/