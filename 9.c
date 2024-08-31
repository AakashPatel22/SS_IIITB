/*
============================================================================
Name : 9.c
Author : Aakash Patel (MT2024109)
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) < 0) {
        perror("Error getting file status");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Inode: %ld\n", (long)fileStat.st_ino);
    printf("Number of hard links: %ld\n", (long)fileStat.st_nlink);
    printf("User ID (UID): %d\n", fileStat.st_uid);
    printf("Group ID (GID): %d\n", fileStat.st_gid);
    printf("File size: %ld bytes\n", (long)fileStat.st_size);
    printf("Block size: %ld bytes\n", (long)fileStat.st_blksize);
    printf("Number of blocks: %ld\n", (long)fileStat.st_blocks);
    printf("Last access time: %s", ctime(&fileStat.st_atime));
    printf("Last modification time: %s", ctime(&fileStat.st_mtime));
    printf("Last status change time: %s", ctime(&fileStat.st_ctime));

    return 0;
}
/*
File: file1.txt
Inode: 535104
Number of hard links: 1
User ID (UID): 1000
Group ID (GID): 1000
File size: 0 bytes
Block size: 4096 bytes
Number of blocks: 0
Last access time: Sat Aug 31 13:56:03 2024
Last modification time: Sat Aug 31 13:56:03 2024
Last status change time: Sat Aug 31 13:56:03 2024
*/