#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int i, j, k;

    if (!(i = fork())) {
        sleep(1);
    }
    else {
        if (!(j = fork())) {
            sleep(3);
        }
        else {
            if (!(k = fork())) {
                sleep(10);
            }
            else {
                waitpid(j, NULL, 0);
            }
        }
    }
}

// here child-1 is in zombie state for 2 second
// since, parent waited only for child-2, ans exicted before termination of child-3 therefore child-3 become orphan process
