/*
============================================================================
Name : p26-2.c
Author : Aakash Patel (MT2024109)
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/
// executor
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <executable_name> <input>\n", argv[0]);
        return 1;
    }

    char *args[] = {argv[1], argv[2], NULL};

    printf("Executing the target program '%s' with input '%s'...\n", argv[1], argv[2]);

    execvp(args[0], args);
       
    printf("This line will not be printed if execvp is successful.\n");

    return 0;
}

