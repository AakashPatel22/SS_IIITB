/*
Name: Aakash Bhavesh Patel
Roll No.: MT2024109
Problem 12, Write a program to find out the opening mode of a file. Use fcntl.
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example_file.txt", O_RDWR | O_CREAT, 0644);
    int flags = fcntl(fd, F_GETFL);

    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("File is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode.\n");
            break;
    }

    if (flags & O_APPEND) {
        printf("File is opened in append mode.\n");
    }

    if (flags & O_NONBLOCK) {
        printf("File is opened in non-blocking mode.\n");
    }

    if (flags & O_SYNC) {
        printf("File is opened in synchronous mode.\n");
    }

    close(fd);
    return 0;
}

