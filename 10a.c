#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;
    int pos=0;//

    fd = open("../files/regular10",
              O_CREAT | O_RDWR | O_TRUNC,
              0744);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, "1234567890", 10);

    pos = lseek(fd, 10, SEEK_CUR);//moving current pointer by 10 characrter

    if (pos == -1) {
        perror("lseek");
        return 1;
    }

    printf("New file pointer position = %d\n", pos);

    write(fd, "abcdefghij", 10);

    close(fd);

    return 0;
}
//to see cat regular10, will not work because it does not show null bytes
//use od -c regular10
