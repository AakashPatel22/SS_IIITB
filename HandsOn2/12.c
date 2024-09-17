/*
============================================================================
Name : 12.c
Author : Aakash Patel (MT2024109)
Description : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child
        sleep(1); 
        printf("Child sending SIGKILL to parent (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL);
        while (1) {
            sleep(5); 
        }
    } else if (pid > 0) {
        // Parent
        printf("Parent process (PID: %d) exiting\n", getpid());
        exit(0);
    } else {
        perror("fork");
        exit(1);
    }
}