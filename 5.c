#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int i = 0;
    char name[50];
    printf("pid: %d",getpid());

    while (1) {
        for (int j = 0; j < 5; j++) {

            sprintf(name, "../files/5/file%d", i++);

            int fd = creat(name, 0744);

            printf("Created %s, fd = %d\n", name, fd);
        }

        sleep(10);
    }

    return 0;
}
// ls -l proc/pid/fd, to see fd table
