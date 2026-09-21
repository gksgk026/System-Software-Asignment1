#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
    execle("/bin/ls", "ls", "-Rl", (char *)0, environ);

    perror("execle");
    return 0;
}
