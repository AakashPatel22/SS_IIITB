/*
============================================================================
Name : 1.c
Author : Aakash Patel (MT2024109)
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>    
#include <sys/stat.h>  
#include <stdlib.h>    
#include <errno.h>     

int main() {
    if (symlink("original.txt", "soft_link.txt") == -1) {
        perror("Error creating soft link");
        exit(EXIT_FAILURE);
    } else {
        printf("Soft link created: soft_link.txt -> original.txt\n");
    }

    if (link("original.txt", "hard_link.txt") == -1) {
        perror("Error creating hard link");
        exit(EXIT_FAILURE);
    } else {
        printf("Hard link created: hard_link.txt -> original.txt\n");
    }

    if (mkfifo("my_fifo", 0666) == -1) {
        if (errno != EEXIST) { 
            perror("Error creating FIFO");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("FIFO created: my_fifo\n");
    }

    return 0;
}
/* Shell Command
ln -s original_file.txt soft_link.txt   # Create soft link
ln original_file.txt hard_link.txt      # Create hard link
mkfifo my_fifo                          # Create FIFO
*/