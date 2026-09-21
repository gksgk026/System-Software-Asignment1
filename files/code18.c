#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct train {
    int train_num;
    int ticket_count;
};

int main() {
    struct train db[3];

    for (int i = 0; i < 3; i++) {
        db[i].train_num = i + 1;
        db[i].ticket_count = 0;
    }

    int fd = open("record.txt", O_CREAT | O_RDWR | O_TRUNC, 0744);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, db, sizeof(db));

    close(fd);

    printf("Three records created successfully\n");

    return 0;
}
