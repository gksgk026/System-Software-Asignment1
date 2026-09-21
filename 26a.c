#include <stdio.h>
#include <unistd.h>

int main(void)
{
    execl("/bin/ls", "ls", "-Rl", NULL);

    perror("execl");
    return 0;
}
//exec(path,arg0,arg1,...,NULL or (char *)0)
//NULL: specify end of parameter list
