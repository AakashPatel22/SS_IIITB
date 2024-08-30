/*
============================================================================
Name : p27e.c
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

    char *args[] = {"ls", "-Rl", NULL};

    execvp("ls", args);

    perror("execvp failed");
    return 1;
}
