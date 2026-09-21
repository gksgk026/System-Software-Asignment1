#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char ch;

    fd = open("../files/14/regular", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    while (read(fd, &ch, 1) > 0) {//reading fd and storing 1 character to ch
        write(1, &ch, 1);//writing content of ch to std_output
    }

    close(fd);

    return 0;
}
