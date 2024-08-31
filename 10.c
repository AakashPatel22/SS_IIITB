/*
============================================================================
Name : 10.c
Author : Aakash Patel (MT2024109)
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
    off_t offset;

    fd = open("eg.txt", O_RDWR | O_CREAT, 0644);
    
    write(fd, "1234567890", 10);

    offset = lseek(fd, 10, SEEK_CUR);
    printf("lseek moved the file pointer to offset: %ld\n", offset);

    write(fd, "abcdefghij", 10);

    close(fd);

    return 0;
}
//od -c eg.txt (octal dump)
/*
0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   a   b   c   d   e   f   g   h   i   j
0000036
*/

