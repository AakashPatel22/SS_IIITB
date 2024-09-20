/*
============================================================================
Name : 28.c
Author : Aakash Patel (MT2024109)
Description : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main(void) {
    key_t key = ftok(".", 'a');
    int msgqid;
    struct msqid_ds msgq;

    if (key == -1) {
        perror("Could not generate unique key");
        exit(EXIT_FAILURE);
    }

    msgqid = msgget(key, IPC_CREAT | 0666);

    if (msgqid == -1) {
        perror("Could not generate message queue");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgqid, IPC_STAT, &msgq) == -1) {
        perror("Could not get message queue stats");
        exit(EXIT_FAILURE);
    }

    printf("Current message queue permissions 0%o\n", msgq.msg_perm.mode);

    msgq.msg_perm.mode = 0766;

    if (msgctl(msgqid, IPC_SET, &msgq) == -1) {
        perror("Could not change the permissions for Message Queue");
        exit(EXIT_FAILURE);
    }

    printf("Changed Message Queue Permissions: 0%o\n", msgq.msg_perm.mode);

    exit(EXIT_SUCCESS);
}
