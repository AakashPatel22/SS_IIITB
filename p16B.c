/*
Name: Aakash Bhavesh Patel
Roll No.: MT2024109
Problem 16, Write a program to perform mandatory locking.
b. Implement read lock
*/ 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("lc.txt", O_RDWR | O_CREAT, 0664);

    struct flock lock;
    lock.l_type = F_RDLCK;    
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;         
    lock.l_len = 0;           

    fcntl(fd, F_SETLKW, &lock);

    printf("Read lock applied. Press Enter to release lock...\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released.\n");
    close(fd);

    return 0;
}
