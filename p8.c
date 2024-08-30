/*
============================================================================
Name : p8.c
Author : Aakash Patel (MT2024109)
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("Aakash.txt", O_RDONLY);
    char buffer;
    ssize_t bytes_read;
    char line[256];
    int index = 0;

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((bytes_read = read(fd, &buffer, 1)) > 0) {
        if (buffer == '\n' || index == sizeof(line) - 1) {  
            line[index] = '\0';
            printf("%s\n", line);  
            index = 0;  
        } else {
            line[index++] = buffer;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading file");
    }

    close(fd);
    return 0;
}


