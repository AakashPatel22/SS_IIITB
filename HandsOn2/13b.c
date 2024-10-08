/*
============================================================================
Name : 13b.c
Author : Aakash Patel (MT2024109)
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int pid;
    printf("Enter PID of the first program: ");
    scanf("%d", &pid);

    printf("Sending SIGSTOP to process %d\n", pid);
    kill(pid, SIGSTOP);  // Send SIGSTOP

    return 0;
}