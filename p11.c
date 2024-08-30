/*
============================================================================
Name : p11.c
Author : Aakash Patel (MT2024109)
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd, fd_dup, fd_dup2, fd_fcntl;

    fd = open("eg.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

    fd_dup = dup(fd);

    fd_dup2 = dup2(fd, fd_dup + 1); 

    fd_fcntl = fcntl(fd, F_DUPFD, 0);

    write(fd, "Original FD\n", 12);

    write(fd_dup, "Duplicated with dup\n", 20);
    
    write(fd_dup2, "Duplicated with dup2\n", 21);
    
    write(fd_fcntl, "Duplicated with fcntl\n", 22);
    
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}

