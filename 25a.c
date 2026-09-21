#include <stdio.h>
#include <unistd.h>

int main(void)
{
    execl("/bin/ls", "ls", NULL);

    printf("execl is not working\n");

    return 0;
}
