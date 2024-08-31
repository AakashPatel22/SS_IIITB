/*
============================================================================
Name : 25.c
Author : Aakash Patel (MT2024109)
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    int a,b,c;
    if(!(a=fork()))
        sleep(1);
    else
        if(!(b=fork()))
            sleep(3);
        else
            if(!(c=fork()))
                sleep(10);
            else
                waitpid(b,NULL,0);
}