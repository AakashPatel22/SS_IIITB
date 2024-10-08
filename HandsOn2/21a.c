/*
============================================================================
Name : 21a.c
Author : Aakash Patel (MT2024109)
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 19th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_PATH1 "myfifo1"
#define FIFO_PATH2 "myfifo2"

int main(int argc, char** argv) {
    mkfifo(FIFO_PATH1, 0666);
    mkfifo(FIFO_PATH2, 0666);

    char inBuff[100] = {0};
    char outBuff[] = "Message from first program";
    int fifo1 = open(FIFO_PATH1, O_WRONLY);
    int fifo2 = open(FIFO_PATH2, O_RDONLY);


    printf("Sending message to second process...\n");
    if (write(fifo1, outBuff, strlen(outBuff) + 1) < 0) {
        perror("Could not write to the fifo1");
        exit(EXIT_FAILURE);
    }
    printf("Message sent successfully\n");

    printf("Reading message from second process...\n");
    if (read(fifo2, inBuff, sizeof(inBuff) - 1) < 0) {
        perror("Could not read from the fifo2");
        exit(EXIT_FAILURE);
    }
    printf("Message received: %s\n", inBuff);

    close(fifo1);
    close(fifo2);
}
