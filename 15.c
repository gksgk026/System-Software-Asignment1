#include <stdio.h>

extern char **environ;

int main() {
    int i = 0;

    while (environ[i] != NULL) {
        printf("envVar[%d]: %s\n", i, environ[i]);
        i++;
    }

    return 0;
}
