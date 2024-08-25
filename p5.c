/*
Name: Aakash Bhavesh Patel
Roll No.: MT2024109
Problem 5, Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/
#include <stdio.h>
#include <fcntl.h>

int main() {
    int file_descriptors[5];
    char* file_names[5] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

    for (int index = 0; index < 5; index++) {
        file_descriptors[index] = open(file_names[index], O_CREAT | O_RDWR | O_EXCL, 0644);
        if (file_descriptors[index] == -1) {
            perror("Error opening file");
        } else {
            printf("Created file: %s with file descriptor: %d\n", file_names[index], file_descriptors[index]);
        }
    }

    while(1);

    return 0;
}
