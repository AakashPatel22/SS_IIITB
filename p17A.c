/*
Name: Aakash Bhavesh Patel
Roll No.: MT2024109
Problem 17, Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int ticket_number = 100;  

    fd = open("ticket.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    write(fd, &ticket_number, sizeof(ticket_number));
    close(fd);

    return 0;
}
//initializes ticket.txt with ticket no. 100
