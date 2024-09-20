/*
============================================================================
Name : 16.c
Author : Aakash Patel (MT2024109)
Description : 16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 19th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int parent_to_child[2];  
    int child_to_parent[2];  
    pid_t pid;
    char parent_msg[] = "Hello from parent!";
    char child_msg[] = "Hello from child!";
    char buffer[100];

    // Create pipes
    if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process

        // Close unused ends
        close(parent_to_child[0]);  
        close(child_to_parent[1]);  

        // Send message to child
        write(parent_to_child[1], parent_msg, strlen(parent_msg) + 1);  // +1 to include null terminator
        close(parent_to_child[1]);  

        // Receive message from child
        read(child_to_parent[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(child_to_parent[0]);  

    } else {
        // Child process

        // Close unused ends
        close(parent_to_child[1]);  
        close(child_to_parent[0]);  

        // Receive message from parent
        read(parent_to_child[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(parent_to_child[0]);  

        // Send message to parent
        write(child_to_parent[1], child_msg, strlen(child_msg) + 1);  // +1 to include null terminator
        close(child_to_parent[1]);  
    }

    return 0;
}

/*
o/p :
Child received: Hello from parent!
Parent received: Hello from child!
*/
