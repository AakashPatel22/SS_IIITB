/*
============================================================================
Name : 20_reader.c
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

    int fd = open(fifo_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];

    read(fd, buffer, sizeof(buffer));

    printf("Reader: Received message from FIFO: %s\n", buffer);

    close(fd);

    return 0;
}
