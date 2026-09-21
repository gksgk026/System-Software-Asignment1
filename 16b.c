#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;

    fd = open("../files/regular.txt", O_RDONLY);

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Waiting for critical section\n");

    fcntl(fd, F_SETLKW, &lock);

    printf("Inside critical section\n");
    printf("Press Enter to unlock\n");

    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Unlocked\n");

    close(fd);

    return 0;
}
