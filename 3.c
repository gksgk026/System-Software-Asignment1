#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = creat("../files/regular_01", 0744);

    printf("fd = %d\n", fd);

    close(fd);

    return 0;
}
