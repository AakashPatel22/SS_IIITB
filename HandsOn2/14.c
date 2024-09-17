/*
============================================================================
Name : 14.c
Author : Aakash Patel (MT2024109)
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe_fds[2];  
    const char *msg = "Hello, how are you?";
    size_t msg_length = strlen(msg) + 1;
    
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    write(pipe_fds[1], msg, msg_length);
    close(pipe_fds[1]);

    char buf[100];
    ssize_t read_bytes = read(pipe_fds[0], buf, sizeof(buf) - 1);
    if (read_bytes == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buf[read_bytes] = '\0';  
    printf("Message received from pipe: %s\n", buf);

    close(pipe_fds[0]);

    return 0;
}
