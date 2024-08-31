/*
============================================================================
Name : 5.c
Author : Aakash Patel (MT2024109)
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>

int main() {
    int file_descriptors[5];
    char* file_names[5] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

    for (int index = 0; index < 5; index++) {
        file_descriptors[index] = open(file_names[index], O_CREAT | O_RDWR , 0644);
        if (file_descriptors[index] == -1) {
            perror("Error opening file");
        } else {
            printf("Created file: %s with file descriptor: %d\n", file_names[index], file_descriptors[index]);
        }
    }

    while(1);

    return 0;
}
/*
total 0
lrwx------ 1 aakash aakash 64 Aug 31 14:19 0 -> /dev/pts/1
lrwx------ 1 aakash aakash 64 Aug 31 14:19 1 -> /dev/pts/1
lrwx------ 1 aakash aakash 64 Aug 31 14:19 2 -> /dev/pts/1
lrwx------ 1 aakash aakash 64 Aug 31 14:19 3 -> /home/aakash/Desktop/IIITB/SS/LinuxCodes/file1.txt
lrwx------ 1 aakash aakash 64 Aug 31 14:19 4 -> /home/aakash/Desktop/IIITB/SS/LinuxCodes/file2.txt
lrwx------ 1 aakash aakash 64 Aug 31 14:19 5 -> /home/aakash/Desktop/IIITB/SS/LinuxCodes/file3.txt
lrwx------ 1 aakash aakash 64 Aug 31 14:19 6 -> /home/aakash/Desktop/IIITB/SS/LinuxCodes/file4.txt
lrwx------ 1 aakash aakash 64 Aug 31 14:19 7 -> /home/aakash/Desktop/IIITB/SS/LinuxCodes/file5.txt
*/
