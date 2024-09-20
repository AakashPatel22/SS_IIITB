/*
============================================================================
Name : 5.c
Author : Aakash Patel (MT2024109)
Description : 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/resource.h>

void printLimit(char* lim_name, int lim_val) {
    errno = 0;
    long limit = sysconf(lim_val);
    if (limit < 0) {
        if (errno != 0)
            printf("There was an error in getting %s limit: %s\n", lim_name, strerror(errno));
        else
            printf("%s: Not supported\n", lim_name);
    } else {
        printf("%s: %ld\n", lim_name, limit);
    }
}

int main(void) {
    struct rlimit lim;

    printLimit("Maximum length of the arguments to the exec family of functions : ", _SC_ARG_MAX);
    printf("Maximum number of simultaneous process per user id\n");
    if (getrlimit(RLIMIT_NPROC, &lim) == 0) {
        if (lim.rlim_cur == RLIM_INFINITY)
            printf("Soft Limit = unlimited");
        else
            printf("Soft Limit = %lu\n", lim.rlim_cur);

        if (lim.rlim_max == RLIM_INFINITY)
            printf("Hard Limit = unlimited\n");
        else
            printf("Hard Limit = %lu\n", lim.rlim_max);
    }
    printLimit("Number of clock ticks (jiffy) per second : ", _SC_CLK_TCK);
    printLimit("Maximum number of open files : ", _SC_OPEN_MAX);
    printLimit("Size of a page : ", _SC_PAGESIZE);
    printLimit("Total number of pages in the physical memory : ", _SC_PHYS_PAGES);
    printLimit("Number of currently available pages in the physical memory : ", _SC_AVPHYS_PAGES);
}