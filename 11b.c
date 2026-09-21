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

    fd1 = dup2(fd, 10);

    if (fd1 == -1) {
        perror("dup2");
        return 1;
    }

    printf("Original fd = %d\n", fd);
    printf("Duplicate fd = %d\n", fd1);

    write(fd, "by fd\n", 6);

    write(fd1, "by fd1\n", 7);

    close(fd1);
    close(fd);

    return 0;
}

//dup(fd):chooses the lowest available file descriptor automatically.
//dyp2(fd,x):here we can choose the exact new descriptor number
