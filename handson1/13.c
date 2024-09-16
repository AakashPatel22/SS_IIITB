/*
============================================================================
Name : 13.c
Author : Aakash Patel (MT2024109)
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <time.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds); 

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        return 1;
    } else if (result == 0) {
        printf("No data available within 10 seconds.\n");
    } else { 
            printf("Data is available on stdin.\n");
    }

    return 0;
}
