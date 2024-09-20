/*
============================================================================
Name : 20_writer.c
Author : Aakash Patel (MT2024109)
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 19th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>     
#include <sys/stat.h>   

int main() {
    const char *fifo_name = "myfifo";

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    int fd = open(fifo_name, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    const char *message = "Hello from the writer program!";
    write(fd, message, sizeof(char) * (strlen(message) + 1)); 

    printf("Writer: Sent message to FIFO\n");

    close(fd);

    return 0;
}
