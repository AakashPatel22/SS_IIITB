/*
============================================================================
Name : 3.c
Author : Aakash Patel (MT2024109)
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = creat("aak.txt", 0777);

    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    printf("File descriptor value: %d\n", fd);

    close(fd);

    return 0;
}
//o/p: File descriptor value: 3