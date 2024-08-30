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
#include <stdlib.h>

int main() {
    int fd, selection;
    
    struct {
        int record_id;
        int value;
    } record;

    fd = open("records.txt", O_RDWR);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    printf("Select record number: 1, 2, 3\n");
    scanf("%d", &selection);

    struct flock lock;
    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = (selection - 1) * sizeof(record); 
    lock.l_len = sizeof(record); 
    lock.l_pid = getpid();

    lseek(fd, (selection - 1) * sizeof(record), SEEK_SET);
    read(fd, &record, sizeof(record));

    printf("Entering critical section\n");

    fcntl(fd, F_SETLKW, &lock);

    printf("Current value of record %d: %d\n", record.record_id, record.value);
    record.value++;

    lseek(fd, -1 * sizeof(record), SEEK_CUR);
    write(fd, &record, sizeof(record));

    printf("To update the record, press enter\n");
    getchar();  
    getchar();  

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Record %d updated with new value: %d\n", record.record_id, record.value);

    close(fd);

    return 0;
}
