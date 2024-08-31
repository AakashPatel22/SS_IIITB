/*
============================================================================
Name : 27c.c
Author : Aakash Patel (MT2024109)
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *envp[] = {NULL};

    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    perror("execle failed");
    return 1;
}
