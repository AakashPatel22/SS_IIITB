/*
============================================================================
Name : 14.c
Author : Aakash Patel (MT2024109)
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("FIFO/pipe\n");
    } else if (S_ISSOCK(mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;

    if (stat(argv[1], &file_stat) == 0) {
        print_file_type(file_stat.st_mode);
    } else {
        perror("Error getting file status");
        return 1;
    }

    return 0;
}
