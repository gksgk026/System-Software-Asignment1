#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("../files/14/regular", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("fd = %d\n", fd);

    close(fd);

    return 0;
}
