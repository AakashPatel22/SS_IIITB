/*
============================================================================
Name : 21.c
Author : Aakash Patel (MT2024109)
Description : Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        printf("This is the child process. My PID is %d, and my parent's PID is %d.\n", getpid(), getppid());
    } else {
        printf("This is the parent process. My PID is %d, and my child's PID is %d.\n", getpid(), pid);
    }

    return 0;
}
/*
This is the parent process. My PID is 11184, and my child's PID is 11185.
This is the child process. My PID is 11185, and my parent's PID is 11184.
*/
