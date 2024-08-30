/*
============================================================================
Name : p16A.c
Author : Aakash Patel (MT2024109)
Description : Write a program to perform mandatory locking.
a. Implement write lock
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("lc.txt", O_RDWR | O_CREAT, 0664);

    struct flock lock;
    lock.l_type = F_WRLCK;    
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;         
    lock.l_len = 0;           

    fcntl(fd, F_SETLKW, &lock);

    printf("Write lock applied. Press Enter to release lock...\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released.\n");
    close(fd);

    return 0;
}


