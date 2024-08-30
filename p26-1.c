/*
============================================================================
Name : p26-1.c
Author : Aakash Patel (MT2024109)
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/
// target
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello, %s! This is the target program.\n", argv[1]);
    return 0;
}
