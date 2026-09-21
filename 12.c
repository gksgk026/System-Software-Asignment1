#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd, flags;

    fd = open("../files/14/regular", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);//returns the file status flags of fd, which contains access mode and other status, as bitmask

    if (flags == -1) {
        perror("fcntl");
        return 1;
    }

    switch (flags & O_ACCMODE) {

        case O_RDONLY:
            printf("File opened in READ ONLY mode\n");
            break;

        case O_WRONLY:
            printf("File opened in WRITE ONLY mode\n");
            break;

        case O_RDWR:
            printf("File opened in READ WRITE mode\n");
            break;
    }

    close(fd);

    return 0;
}
// flags: contains sequence of bit for each flag
// O_ACCMODE[00000011]: contains sequence of bit where access mode is active
//flags & O_ACCMODE: unmasks other set bit 

//O_RDONLY = 00000000
//O_WRONLY = 00000001
//O_RDWR   = 00000010
//O_ACCMODE= 00000011
