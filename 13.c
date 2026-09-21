#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {

    fd_set rfds;//fd_set can hold set of file descriptor
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);//resetting all values inside fd_set
    FD_SET(0, &rfds);//since we are taking stdin, thats why adding 0 to fd set

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    retval = select(1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select");
    }
    else if (retval == 0) {
        printf("No data available within 10 seconds\n");
    }
    else {
        printf("Data is available within 10 seconds\n");
    }

    return 0;
}
//Because select() is designed to monitor multiple file descriptors at the same time.
//therefore we need fd set
//
