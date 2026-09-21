#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd;

    fd = open("../files/regular.txt", O_RDWR);

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Before entering critical section\n");

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
