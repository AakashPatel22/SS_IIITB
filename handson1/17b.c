/*
============================================================================
Name : 17b.c
Author : Aakash Patel (MT2024109)
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int ticket_number;

    fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; 

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to lock the file");
        close(fd);
        return 1;
    }
    printf("press enter to book ticket");
    getchar();
    read(fd, &ticket_number, sizeof(ticket_number));

    ticket_number++;

    printf("New Ticket Number: %d\n", ticket_number);

    lseek(fd, 0, SEEK_SET);

    write(fd, &ticket_number, sizeof(ticket_number));

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to unlock the file");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
//run this in two terminals simultaneously to see lock functionality.