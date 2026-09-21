#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

    struct stat info;

    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &info) == -1) {
        perror("stat");
        return 1;
    }

    printf("Inode number        : %lu\n", info.st_ino);
    printf("Number of hard links: %u\n", info.st_nlink);
    printf("UID                 : %u\n", info.st_uid);
    printf("GID                 : %u\n", info.st_gid);
    printf("Size                : %ld bytes\n", info.st_size);
    printf("Block size          : %d bytes\n", info.st_blksize);
    printf("Number of blocks    : %ld\n", info.st_blocks);

    printf("Last access time    : %s", ctime(&info.st_atime));
    printf("Last modification   : %s", ctime(&info.st_mtime));
    printf("Last status change  : %s", ctime(&info.st_ctime));

    return 0;
}
