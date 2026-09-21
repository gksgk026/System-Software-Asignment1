#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *args[] = {"ls", "-Rl", (char *)0};

    execvp("ls", args);

    perror("execvp");
    return 0;
}
