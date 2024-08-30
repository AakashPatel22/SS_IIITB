/*
============================================================================
Name : p6.c
Author : Aakash Patel (MT2024109)
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 25th Aug, 2024.
============================================================================
*/
#include <unistd.h>

int main() {
    int n;
    char buffer[100];

    n=read(0, buffer, sizeof(buffer) - 1);

    write(1, buffer, n);

    return 0;
}
//i/p: Aakash is learning Linux
//o/p: Aakash is learning Linux