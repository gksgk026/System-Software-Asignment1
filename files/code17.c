#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct {
    int ticket_no;
} db;

int main() {

    int fd;

    db.ticket_no = 10;

    fd = open("../files/db", O_CREAT | O_RDWR | O_TRUNC, 0744);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, &db, sizeof(db));

    close(fd);

    return 0;
}
