/*
============================================================================
Name : 15.c
Author : Aakash Patel (MT2024109)
Description : 15. Write a simple program to send some data from parent to the child process.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefd[2];  
    pid_t pid;
    const char *message = "Hello from parent!";
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        close(pipefd[0]);  

        write(pipefd[1], message, strlen(message) + 1);  
        close(pipefd[1]); 

        wait(NULL);
    } else {
        // Child process
        close(pipefd[1]);  

        ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[bytes_read] = '\0';  
        printf("Child process received: %s\n", buffer);

        close(pipefd[0]);  
    }

    return 0;
}
