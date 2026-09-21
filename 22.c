#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (!fork()) {
        printf("Child pid: %d\n", getpid());
    }
    else {
	printf("Parent pid: %d\n", getpid());
        sleep(100);
    }
}

// check status using top -p pid comand
