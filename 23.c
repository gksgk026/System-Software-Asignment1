#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (!fork()) {
        printf("Child pid: %d, Parent pid: %d\n", getpid(), getppid());

	sleep(5);

        printf("Child pid: %d, Parent pid: %d\n", getpid(), getppid());
    }
    else {
        printf("Parent pid: %d\n", getpid());
    }
}

