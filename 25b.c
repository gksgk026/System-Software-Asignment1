#include <stdio.h>
#include <unistd.h>

int main(void){

    execl("../files/code25b", "code25b", "Gaurav", NULL);

    perror("execl");
    return 0;
}
