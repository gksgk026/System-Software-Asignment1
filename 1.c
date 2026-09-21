#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {

    if (symlink("../files/regular", "../files/softlink") == -1) {
        perror("symlink");
    } else {
        printf("Soft link created\n");
    }


    if (link("../files/regular", "../files/hardlink") == -1) {
        perror("link");
    } else {
        printf("Hard link created\n");
    }


    if (mkfifo("../files/myfifo", 0744) == -1) {
        perror("mkfifo");
    } else {
        printf("FIFO created\n");
    }

    return 0;
}
