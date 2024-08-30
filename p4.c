/*
============================================================================
Name : p4.c
Author : Aakash Patel (MT2024109)
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 25th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *filename = "existing_file.txt";

    int fd = open(filename, O_RDWR | O_CREAT | O_EXCL);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    } else {
        printf("File opened successfully with file descriptor: %d\n", fd);
        
        close(fd);
    }

    return 0;
}
