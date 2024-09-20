/*
============================================================================
Name : 25.c
Author : Aakash Patel (MT2024109)
Description : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main(void) {
    key_t key = ftok(".", 'a');
    int msgid;
    struct msqid_ds msqstat;

    if (key == -1) {
        perror("Could not generate unique key for message queue");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1) {
        perror("Could not create message queue with the unique key");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgid, IPC_STAT, &msqstat) == -1) {
        perror("Could not get message queue stats");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue Information-\n");
    printf("a. Access Permissions: %o\n", msqstat.msg_perm.mode);
    printf("b. UID = %d\t GID = %d\n", msqstat.msg_perm.uid, msqstat.msg_perm.gid);
    printf("c. Time of last message sent = %s", ctime(&msqstat.msg_stime));
    printf("c. time of last message received = %s", ctime(&msqstat.msg_rtime));
    printf("d. time of last change in the message queue = %s", ctime(&msqstat.msg_ctime));
    printf("e. Size of the queue = %lu\n", msqstat.__msg_cbytes);
    printf("f. Number of messages in the queue = %lu\n", msqstat.msg_qnum);
    printf("g. Maximum number of bytes involved = %lu\n", msqstat.msg_qbytes);
    printf("h. PID of msgsnd = %d\t PID of msgrcv = %d\n", msqstat.msg_lspid, msqstat.msg_lrpid);
}