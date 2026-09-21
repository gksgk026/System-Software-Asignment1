#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    struct stat fileStat;

    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    if (lstat(argv[1], &fileStat) == -1) {
        perror("lstat");
        return 1;
    }

    if (S_ISREG(fileStat.st_mode))
        printf("Regular file\n");

    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");

    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic link\n");

    else if (S_ISFIFO(fileStat.st_mode))
        printf("FIFO file\n");

    else if (S_ISCHR(fileStat.st_mode))
        printf("Character device file\n");

    else if (S_ISBLK(fileStat.st_mode))
        printf("Block device file\n");

    else if (S_ISSOCK(fileStat.st_mode))
        printf("Socket file\n");

    else
        printf("Unknown file type\n");

    return 0;
}
