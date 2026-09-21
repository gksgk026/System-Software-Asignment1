#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    int fd;

    fd = open("../files/newfile", O_WRONLY);

    if (!fork()) {
        write(fd, "This is child process...\n", 26);
    }
    else {
        write(fd, "This is parent process...\n", 27);
    }

    wait(0);//tells the parent, wait until your child finishes
}
