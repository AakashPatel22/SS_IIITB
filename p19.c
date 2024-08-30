/*
============================================================================
Name : p19.c
Author : Aakash Patel (MT2024109)
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main (void){
    int i, nano;
    unsigned long long int start, end;
    start = rdtsc();
    for(i=0; i<=9999; i++)
        getppid();
    end=rdtsc();
    nano=(end-start)/3.3;
    printf("func takes %d nano sec\n",nano);
}