#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd, fd1;

    fd = open("../files/14/regular", O_WRONLY | O_APPEND);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    fd1 = fcntl(fd, F_DUPFD, 3);

    if (fd1 == -1) {
        perror("fcntl");
        return 1;
    }

    printf("Original fd = %d\n", fd);
    printf("Duplicate fd = %d\n", fd1);

    write(fd, "by fd\n", 6);

    write(fd1,"by fd1\n", 7);

    close(fd1);
    close(fd);

    return 0;
}
//fd1 = fcntl(fd, F_DUPFD, x):gives the lowest available file descriptor >= x
