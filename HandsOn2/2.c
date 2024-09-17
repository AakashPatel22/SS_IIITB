/*
============================================================================
Name : 2.c
Author : Aakash Patel (MT2024109)
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
Date: 16th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;
    
    if (getrlimit(resource, &limit) == 0) {
        printf("%s: \n", name);
        printf("  Soft limit: %ld\n", limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU Time");
    print_limit(RLIMIT_FSIZE, "Maximum File Size");
    print_limit(RLIMIT_DATA, "Data Segment Size");
    print_limit(RLIMIT_STACK, "Stack Size");
    print_limit(RLIMIT_CORE, "Core File Size");
    print_limit(RLIMIT_RSS, "Resident Set Size");
    print_limit(RLIMIT_NPROC, "Number of Processes");
    print_limit(RLIMIT_NOFILE, "Number of Open Files");
    print_limit(RLIMIT_MEMLOCK, "Locked Memory Size");
    print_limit(RLIMIT_AS, "Address Space Size");

    return 0;
}
