/*
Name: Aakash Bhavesh Patel
Roll No.: MT2024109
Problem 4, Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/
#include <stdio.h>
#include <fcntl.h>

int main(){
    char* filename = "aak.txt";
     // int fd= open(filename, O_RDWR);
    int fd = open(filename, O_CREAT | O_EXCL, 0644);

    if(fd==-1){
        // perror("open error");
        perror("File already exists");
        return 1;
    }

    printf("File Descriptor value with O_RDWR: %d\n", fd);
}