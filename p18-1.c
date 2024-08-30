/*
Name: Aakash Bhavesh Patel
Roll No.: MT2024109
Problem 18, Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
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

