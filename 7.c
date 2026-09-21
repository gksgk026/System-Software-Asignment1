#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char buf[128];
    int n;

    fd1 = open("../files/file1", O_RDONLY);

    if (fd1 == -1) {
        perror("open source");
        return 1;
    }

    fd2 = open("../files/file2", O_WRONLY | O_CREAT | O_TRUNC, 0744);

    if (fd2 == -1) {
        perror("open destination");
        return 1;
    }

    while ((n = read(fd1, buf, sizeof(buf))) > 0) {
        write(fd2, buf, n);
    }

    printf("Copying finished\n");

    close(fd1);
    close(fd2);

    return 0;
}
