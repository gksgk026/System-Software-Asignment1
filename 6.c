#include <stdio.h>
#include <unistd.h>

int main() {
    char buf[100];
    int n;

    n = read(0, buf, sizeof(buf));

    if (n > 0) {
        write(1, buf, n);
    }

    return 0;
}
