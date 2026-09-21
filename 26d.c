#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *args[] = {"ls", "-Rl", (char *)0};

    execv("/bin/ls", args);

    perror("execv");
    return 0;
}
