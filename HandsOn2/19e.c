/*
============================================================================
Name : 19e.c
Author : Aakash Patel (MT2024109)
Description : 19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
d. mknod system call
e. mkfifo library function
Date: 21th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    
    char name[20];

    printf("Enter the name of pipe : ");
    scanf("%s",name);

    mkfifo(name, 0666);
    
    return 0;
}