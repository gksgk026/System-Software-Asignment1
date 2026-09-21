#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("../files/regular", O_CREAT | O_EXCL | O_RDWR, 0744);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File created successfully, fd = %d\n", fd);

    close(fd);

    return 0;
}
