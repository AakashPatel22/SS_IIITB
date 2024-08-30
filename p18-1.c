/*
============================================================================
Name : p18-1.c
Author : Aakash Patel (MT2024109)
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int i, fd;
    
    struct {
        int record_id;
        int value;
    } records[3];

    for (i = 0; i < 3; i++) {
        records[i].record_id = i + 1;
        records[i].value = 0;
    }

    fd = open("records.txt", O_RDWR | O_CREAT, 0644);

    write(fd, records, sizeof(records));
    close(fd);

    return 0;
}

