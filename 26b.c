#include <stdio.h>
#include <unistd.h>

int main(void)
{
    execlp("ls", "ls", "-Rl", (char *)0);

    perror("execlp");
    return 0;
}
//execlp(file,arg0,arg1,...,NULL)
//execlp serches file name in PATH
