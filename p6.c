/*
Name: Aakash Bhavesh Patel
Roll No.: MT2024109
Problem 6, Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
*/
#include <unistd.h>

int main() {
    int n;
    char buffer[100];

    n=read(0, buffer, sizeof(buffer) - 1);

    write(1, buffer, n);

    return 0;
}
