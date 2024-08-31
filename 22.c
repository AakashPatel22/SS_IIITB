/*
============================================================================
Name : 22.c
Author : Aakash Patel (MT2024109)
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    int pid;
    char parent_msg[] = "Parent process writing to file.\n";
    char child_msg[] = "Child process writing to file.\n";

    fd = open("OPp22.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        printf("Failed to open the file.\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        write(fd, child_msg, strlen(child_msg));
    } else {
        write(fd, parent_msg, strlen(parent_msg));
    }

    close(fd);

    return 0;
}
/*
Parent process writing to file.
Child process writing to file.
*/